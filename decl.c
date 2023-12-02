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
                d->value->kind != EXPR_NAME &&
                d->value->kind != EXPR_VALUE
            )) {
            printf("type error: cannot initialize global variable (%s) to non-constant value ", d->symbol->name);
            expr_print(d->value);
            printf("\n");
            decl_error = 1;
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

void decl_codegen( struct decl *d ) {
    if(!d) return;
    if(d->symbol->kind == SYMBOL_GLOBAL){
        if(d->type->kind != TYPE_FUNCTION) {
            printf(".data\n");
        } else {
            printf(".text\n");
        }
        printf(".global %s\n", d->symbol->name);
        switch(d->type->kind) {
            case TYPE_INTEGER:
                printf("%s: .quad ", d->symbol->name);
                if(d->value) {
                    expr_print(d->value);
                } else {
                    printf("0");
                }
                printf("\n");
                break;
            case TYPE_STRING:
                printf("%s: .string ", d->symbol->name);
                if(d->value) {
                    printf("%s", d->value->string_literal);
                } else {
                    printf("\"\"");
                }
                printf("\n");
                break;
            case TYPE_BOOLEAN:
                printf("%s: .quad ", d->symbol->name);
                if(d->value) {
                    printf("%d", d->value->literal_value);
                } else {
                    printf("0");
                }
                printf("\n");
                break;
            case TYPE_CHARACTER:
                printf("%s: .quad ", d->symbol->name);
                if(d->value) {
                    printf("%d", d->value->literal_value);
                } else {
                    printf("0");
                }
                printf("\n");
                break;
            case TYPE_ARRAY:
                break;
            case TYPE_FUNCTION:
                printf("%s:\n", d->symbol->name);
                //prologue
                printf("PUSHQ %%rbp\n");
                printf("MOVQ %%rsp, %%rbp\n");
                //save arguments to stack
                for(int i = 0; i < d->func_params; i++){
                    printf("PUSHQ %s\n", decl_arg_regs[i]);
                }
                //allocate local variables on stack
                printf("SUBQ $%d, %%rsp\n", d->func_locals * 8);

                //save callee saved registers
                printf("PUSHQ %%rbx\n");
                printf("PUSHQ %%r12\n");
                printf("PUSHQ %%r13\n");
                printf("PUSHQ %%r14\n");
                printf("PUSHQ %%r15\n");
                
                //body
                printf("##############\n");
                stmt_codegen(d->code, d->symbol->name);
                printf("##############\n");
                //epilogue
                printf(".%s_epilogue:\n", d->symbol->name);
                printf("POPQ %%r15\n");
                printf("POPQ %%r14\n");
                printf("POPQ %%r13\n");
                printf("POPQ %%r12\n");
                printf("POPQ %%rbx\n");
                printf("MOVQ %%rbp, %%rsp\n");
                printf("POPQ %%rbp\n");
                printf("RET\n");
                break;
        }
    } else if(d->symbol->kind == SYMBOL_LOCAL && d->value){
        expr_codegen(d->value);
        printf("MOVQ %s, %s\n", scratch_name(d->value->reg), symbol_codegen(d->symbol));
        scratch_free(d->value->reg);
    }
    decl_codegen(d->next);
}