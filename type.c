#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "param_list.h"
#include "expr.h"


struct type * type_create( type_t kind, struct type *subtype, struct param_list *params, struct expr *expr ){
    struct type * t = malloc(sizeof(*t));
    t->kind = kind;
    t->subtype = subtype;
    t->params = params;
    t->expr = expr;
    return t;
}

void type_print( struct type *t ){
    if(!t) return;

    switch(t->kind) {
        case TYPE_VOID: printf("void"); break;
        case TYPE_BOOLEAN: printf("boolean"); break;
        case TYPE_CHARACTER: printf("char"); break;
        case TYPE_INTEGER: printf("integer"); break;
        case TYPE_FLOAT: printf("float"); break;
        case TYPE_STRING: printf("string"); break;
        case TYPE_ARRAY: 
            printf("array ["); 
            expr_print(t->expr);
            printf("] ");
            type_print(t->subtype);
            break;
        case TYPE_FUNCTION: 
            printf("function "); 
            type_print(t->subtype);
            printf(" (");
            param_list_print(t->params);
            printf(")");
            break;
    }

}

int type_equals(struct type *a, struct type *b) {
    if(!a && !b) return 1;
    if(!a || !b) return 0;
    if(a->kind != b->kind) return 0;
    if(a->kind == TYPE_ARRAY) {
        return type_equals(a->subtype, b->subtype);
    }
    if(a->kind == TYPE_FUNCTION) {
        return (type_equals(a->subtype, b->subtype) && param_list_equals(a->params, b->params));
    }
    return 1;
}