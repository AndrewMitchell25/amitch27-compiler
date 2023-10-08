#include "expr.h"
#include <stdio.h>
#include <stdlib.h>

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right ) {
    struct expr *e = malloc(sizeof(*e));
    e->kind = kind;
    e->literal_value = 0;
    e->left = left;
    e->right = right;
    return e;
}

struct expr * expr_create_value( int value ) {
    struct expr *e = expr_create(EXPR_VALUE,0,0);
    e->literal_value = value;
    return e;
}


int expr_evaluate( struct expr *e ) {
    if(!e) return 0;
    int l = expr_evaluate(e->left);
    int r = expr_evaluate(e->right);
    switch(e->kind) {
        case EXPR_VALUE: return e->literal_value;
        case EXPR_ADD: return l+r;
        case EXPR_SUB: return l-r;
        case EXPR_MUL: return l*r;
        case EXPR_DIV:
            if(r==0) {
                printf("error: divide by zero\n");
                exit(1);
            }
            return l/r;
    }
    return 0;
}

void expr_print( struct expr *e ) {
    if(!e) return;
    printf("(");
    expr_print(e->left);
    switch(e->kind) {
        case EXPR_VALUE: printf("%d",e->literal_value); break;
        case EXPR_ADD: printf("+"); break;
        case EXPR_SUB: printf("-"); break;
        case EXPR_MUL: printf("*"); break;
        case EXPR_DIV: printf("/"); break;
    }
    expr_print(e->right);
    printf(")");
}
