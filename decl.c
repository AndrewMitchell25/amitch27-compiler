#include <stdio.h>
#include <stdlib.h>
#include "decl.h"
#include "expr.h"
#include "type.h"
#include "stmt.h"
#include "indent.h"
#include "symbol.h"
#include "scope.h"
#include <string.h>
#include "encoder.h"
#include "scratch.h"

int decl_error = 0;

struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next ) {
    struct decl * d = malloc(sizeof(*d));
    d->name = name;
    d->type = type;
    d->value = value;
    d->code = code;
    d->next = next;
    return d;
}

void decl_print( struct decl *d, int indent ) {
    if(!d) return;
    print_indent(indent);
    printf("%s: ", d->name);
    type_print(d->type);
    if(d->value) {
        printf(" = ");
        if(d->value->kind == EXPR_ARG) {
            printf("{");
            expr_print(d->value);
            printf("}");
        } else {
            expr_print(d->value);
        }
        printf(";");
    } else if(d->code) {
        printf(" = {\n");
        stmt_print(d->code, indent + 1);
        print_indent(indent);
        printf("}\n");
    } else {
        printf(";");
    }
    printf("\n");
    decl_print(d->next, indent);

}

void decl_resolve( struct decl *d ) { 
    if(!d) return;
    if(scope_level() == 0) {
        scope_enter();
    }
    symbol_t kind = scope_level() > 1 ? SYMBOL_LOCAL : SYMBOL_GLOBAL;
    d->symbol = symbol_create(kind,d->type,d->name);
    expr_resolve(d->value);
    expr_resolve(d->type->expr);
    scope_bind(d->name, d->symbol);
    if(d->code) {
        scope_enter();
        param_list_resolve(d->type->params);
        scope_enter();
        stmt_resolve(d->code);
        d->func_params = scope_get_params();
        d->func_locals = scope_get_locals();
        scope_exit();
        scope_exit();
    }
    decl_resolve(d->next);
}

void decl_typecheck(struct decl *d){
    if(!d) return;
    if(d->type->kind == TYPE_ARRAY){
        if(!d->type->expr){
            printf("type error: cannot declare an array (%s) with null size\n", d->symbol->name);
            decl_error = 1;
        } else if(d->type->expr->kind != EXPR_INTEGER_LITERAL && d->symbol->kind == SYMBOL_GLOBAL) {
            printf("type error: cannot declare an array (%s) with variable size\n", d->symbol->name);
            decl_error = 1;
        }
        if(d->type->subtype->kind == TYPE_FUNCTION) {
            printf("type error: cannot declare array (%s) of type ", d->symbol->name);
            type_print(d->type->subtype);
            printf("\n");
            decl_error = 1;
        }
        if(d->symbol->kind == SYMBOL_LOCAL && d->value) {
            printf("type error: cannot declare local array (%s) with initial values\n", d->symbol->name);
            decl_error = 1;
        }
    } else if(d->type->kind == TYPE_FUNCTION) {
        if(d->symbol->kind != SYMBOL_GLOBAL) {
            printf("type error: cannot declare a function (%s) inside another function\n", d->symbol->name);
            decl_error = 1;
        }
        if(d->func_params > 6) {
            printf("type error: cannot have more than 6 parameters in function (%s)\n", d->symbol->name);
            decl_error = 1;
        }
        param_list_typecheck(d->type->params);
        if(d->type->subtype->kind == TYPE_FUNCTION || d->type->subtype->kind == TYPE_ARRAY) {
            printf("type error: cannot return type ");
            type_print(d->type->subtype);
            printf(" from a function (%s)\n", d->symbol->name);
            decl_error = 1;
        }
    }

    if(d->value) {
        if(d->symbol->kind == SYMBOL_GLOBAL &&
            (d->value->kind != EXPR_INTEGER_LITERAL &&
                d->value->kind != EXPR_STRING_LITERAL &&
                d->value->kind != EXPR_BOOLEAN_LITERAL &&
                d->value->kind != EXPR_CHAR_LITERAL &&
                d->value->kind != EXPR_FLOAT_LITERAL &&
                //d->value->kind != EXPR_NAME &&
                d->value->kind != EXPR_VALUE &&
                d->value->kind != EXPR_ARRAY_INIT &&
                d->value->kind != EXPR_PLUS_PLUS &&
                d->value->kind != EXPR_MINUS_MINUS &&
                d->value->kind != EXPR_POSITIVE &&
                d->value->kind != EXPR_NEGATIVE
            )) {
            printf("type error: cannot initialize global variable (%s) to non-constant value ", d->symbol->name);
            expr_print(d->value);
            printf("\n");
            decl_error = 1;
        } 
        if(d->symbol->kind == SYMBOL_GLOBAL &&
            (d->value->kind == EXPR_PLUS_PLUS ||
                d->value->kind == EXPR_MINUS_MINUS ||
                d->value->kind == EXPR_POSITIVE ||
                d->value->kind == EXPR_NEGATIVE
            )) {
            if(d->value->left && (d->value->left->kind != EXPR_INTEGER_LITERAL && d->value->kind != EXPR_FLOAT_LITERAL)){
                expr_print(d->value->left);
                printf("type error: cannot initialize global variable (%s) to non-constant value ", d->symbol->name);
                expr_print(d->value);
                printf("\n");
                decl_error = 1;
            }
        }
        struct type *t = expr_typecheck(d->value);
        if(!type_equals(t, d->symbol->type)){
            printf("type error: cannot assign ");
            type_print(t);
            printf(" (");
            expr_print(d->value);
            printf(") to ");
            type_print(d->symbol->type);
            printf(" (%s)\n", d->symbol->name);
            decl_error = 1;
        }
    }
    if(d->code){
        struct stmt * s = d->code;
        while(s){
            struct type *t = stmt_typecheck(s);
            if(s->kind == STMT_RETURN) {
                if(!type_equals(t, d->type->subtype)){
                    printf("type error: cannot return type ");
                    type_print(t);
                    printf(" (");
                    expr_print(s->expr);
                    printf(") in a function (%s) that returns ", d->symbol->name);
                    type_print(d->type->subtype);
                    printf("\n");
                    decl_error = 1;
                }
            }
            s = s->next;
        }
    }
    decl_typecheck(d->next);
}

int decl_type_error() {
    return decl_error;
}

char * decl_arg_regs[6] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};

void decl_codegen( FILE * file, struct decl *d ) {
    if(!d) return;
    if(d->symbol->kind == SYMBOL_GLOBAL){
        if(d->type->kind != TYPE_FUNCTION) {
            fprintf(file, ".data\n");
        } else {
            fprintf(file, ".text\n");
        }
        fprintf(file, ".global %s\n", d->symbol->name);
        switch(d->type->kind) {
            case TYPE_INTEGER:
                fprintf(file, "%s: .quad ", d->symbol->name);
                if(d->value) {
                    fprintf(file, "%d", d->value->literal_value);
                } else {
                    fprintf(file, "0");
                }
                fprintf(file, "\n");
                break;
            case TYPE_STRING:
                fprintf(file, "%s: .string ", d->symbol->name);
                if(d->value) {
                    fprintf(file, "%s", d->value->string_literal);
                } else {
                    fprintf(file, "\"\"");
                }
                fprintf(file, "\n");
                break;
            case TYPE_BOOLEAN:
                fprintf(file, "%s: .quad ", d->symbol->name);
                if(d->value) {
                    fprintf(file, "%d", d->value->literal_value);
                } else {
                    fprintf(file, "0");
                }
                fprintf(file, "\n");
                break;
            case TYPE_CHARACTER:
                fprintf(file, "%s: .quad ", d->symbol->name);
                if(d->value) {
                    fprintf(file, "%d", d->value->literal_value);
                } else {
                    fprintf(file, "0");
                }
                fprintf(file, "\n");
                break;
            case TYPE_ARRAY:
                if(d->type->subtype->kind == TYPE_INTEGER){
                    fprintf(file, "%s: .quad ", d->symbol->name);
                    decl_array_init_print(file, d->value);
                    fprintf(file, "\n");
                } else {
                    printf("error: array not implemented\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case TYPE_FUNCTION:
                if(d->code) {
                    fprintf(file, "%s:\n", d->symbol->name);
                    //prologue
                    fprintf(file, "PUSHQ %%rbp\n");
                    fprintf(file, "MOVQ %%rsp, %%rbp\n");
                    //save arguments to stack
                    for(int i = 0; i < d->func_params; i++){
                        fprintf(file, "PUSHQ %s\n", decl_arg_regs[i]);
                    }
                    //allocate local variables on stack
                    fprintf(file, "SUBQ $%d, %%rsp\n", d->func_locals * 8);

                    //save callee saved registers
                    fprintf(file, "PUSHQ %%rbx\n");
                    fprintf(file, "PUSHQ %%r12\n");
                    fprintf(file, "PUSHQ %%r13\n");
                    fprintf(file, "PUSHQ %%r14\n");
                    fprintf(file, "PUSHQ %%r15\n");
                    
                    //body
                    fprintf(file, "##############\n");
                    stmt_codegen(file, d->code, d->symbol->name);
                    fprintf(file, "##############\n");
                    //epilogue
                    fprintf(file, ".%s_epilogue:\n", d->symbol->name);
                    fprintf(file, "POPQ %%r15\n");
                    fprintf(file, "POPQ %%r14\n");
                    fprintf(file, "POPQ %%r13\n");
                    fprintf(file, "POPQ %%r12\n");
                    fprintf(file, "POPQ %%rbx\n");
                    fprintf(file, "MOVQ %%rbp, %%rsp\n");
                    fprintf(file, "POPQ %%rbp\n");
                    fprintf(file, "RET\n");
                }
                break;
            default:
                printf("runtime error: case not handled\n");
                decl_print(d, 0);
                printf("\n");
                exit(EXIT_FAILURE);
        }
    } else if(d->symbol->kind == SYMBOL_LOCAL && d->value){
        expr_codegen(file, d->value);
        fprintf(file, "MOVQ %s, %s\n", scratch_name(d->value->reg), symbol_codegen(d->symbol));
        scratch_free(d->value->reg);
    }
    decl_codegen(file, d->next);
}

void decl_array_init_print(FILE * file, struct expr * e) {
    if(e->kind == EXPR_ARRAY_INIT){
        decl_array_init_print(file, e->left);
        if(e->right){
            fprintf(file, ", ");
            decl_array_init_print(file, e->right);
        }
    } else if(e->kind == EXPR_ARG) {
        decl_array_init_print(file, e->left);
        if(e->right){
            fprintf(file, ", ");
            decl_array_init_print(file, e->right);
        }
    } else {
        fprintf(file, "%d", e->literal_value);
    }
}