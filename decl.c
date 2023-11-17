#include <stdio.h>
#include <stdlib.h>
#include "decl.h"
#include "expr.h"
#include "type.h"
#include "stmt.h"
#include "indent.h"
#include "symbol.h"
#include "scope.h"

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