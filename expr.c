#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.h"

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

struct expr * expr_create_name( const char *n ){
    struct expr *e = expr_create(EXPR_NAME,0,0);
    e->name = n;
    return e;
}

struct expr * expr_create_integer_literal( int c ){
    struct expr *e = expr_create(EXPR_INTEGER_LITERAL,0,0);
    e->literal_value = c;
    return e;
}

struct expr * expr_create_float_literal( float c ){
    struct expr *e = expr_create(EXPR_FLOAT_LITERAL,0,0);
    e->float_literal = c;
    return e;
}

struct expr * expr_create_boolean_literal( int c ){
    struct expr *e = expr_create(EXPR_BOOLEAN_LITERAL,0,0);
    e->literal_value = c;
    return e;
}
struct expr * expr_create_char_literal( char c ){
    struct expr *e = expr_create(EXPR_CHAR_LITERAL,0,0);
    e->literal_value = c;
    return e;
}
struct expr * expr_create_string_literal( const char *str ){
    struct expr *e = expr_create(EXPR_STRING_LITERAL,0,0);
    e->string_literal = str;
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
        case EXPR_MOD: return l%r;
        case EXPR_EXP: /*TODO*/;
        case EXPR_BOOLEAN_LITERAL: return e->literal_value;
        default: return 0;
    }
}

void expr_print( struct expr *e ) {
    if(!e) return;
    //printf("%d", e->kind);
    if(e->kind == EXPR_NOT) {
        printf("!"); 
        printf("(");
        expr_print(e->left);
        printf(") ");
        return;
    }
    if(e->kind == EXPR_NEGATIVE) {
        printf("-");
        expr_print(e->left);
        return;
    }
    if(e->kind == EXPR_POSITIVE) {
        printf("+");
        expr_print(e->left);
        return;
    }
    if(e->kind == EXPR_ARRAY_INIT) {
        printf("{");
        expr_print(e->left);
        if(e->right){
            printf(", ");
            expr_print(e->right);
        }
        printf("}");
        return;
    }
    expr_print(e->left);
    switch(e->kind) {
        case EXPR_VALUE: printf("%d",e->literal_value); break;
        case EXPR_ADD: printf("+"); break;
        case EXPR_SUB: printf("-"); break;
        case EXPR_MUL: printf("*"); break;
        case EXPR_DIV: printf("/"); break;
        case EXPR_MOD: printf("%%"); break;
        case EXPR_EXP: printf("^"); break;
        case EXPR_GREATER_EQUAL: printf(">="); break;
        case EXPR_GREATER: printf(">"); break;
        case EXPR_LESS_EQUAL: printf("<="); break;
        case EXPR_LESS: printf("<"); break;
        case EXPR_NOT_EQUALS: printf("!="); break;
        case EXPR_EQUALS_EQUALS: printf("=="); break;
        case EXPR_OR: printf("||"); break;
        case EXPR_AND: printf("&&"); break;
        case EXPR_PLUS_PLUS: printf("++"); break;
        case EXPR_MINUS_MINUS: printf("--"); break;
        case EXPR_ASSIGN: printf("="); break;
        case EXPR_NAME: printf("%s", e->name); break;
        case EXPR_INTEGER_LITERAL: printf("%d", e->literal_value); break;
        case EXPR_STRING_LITERAL: printf("%s", e->string_literal); break;
        case EXPR_BOOLEAN_LITERAL: e->literal_value ? printf("true") : printf("false"); break;
        case EXPR_CHAR_LITERAL: 
            switch(e->literal_value){
                case 7: printf("'\\a'"); break;
                case 8: printf("'\\b'"); break;
                case 9: printf("'\\t'"); break;
                case 10: printf("'\\n'"); break;
                case 11: printf("'\\v'"); break;
                case 12: printf("'\\f'"); break;
                case 13: printf("'\\r'"); break;
                case 27: printf("'\\e'"); break;
                case 34: printf("'\\\"'"); break;
                case 39: printf("'\\\''"); break;
                case 92: printf("'\\\\'"); break;
                default: printf("'%c'", e->literal_value); break;
            }
            break;
        case EXPR_FLOAT_LITERAL: printf("%g", e->float_literal); break;
        case EXPR_CALL: 
            printf("(");
            expr_print(e->right);
            printf(")");
            return;
        case EXPR_ARG: 
            if(e->right){
                printf(", ");
                expr_print(e->right);
            }
            return;
        case EXPR_SUBSCRIPT:
            printf(" [");
            expr_print(e->right);
            printf("]");
            return;
        default: break;
    }
    expr_print(e->right);
}
