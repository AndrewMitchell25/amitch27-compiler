#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.h"
#include "symbol.h"
#include "scope.h"
#include "type.h"

int expr_error = 0;

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right, int level ) {
    struct expr *e = malloc(sizeof(*e));
    e->kind = kind;
    e->literal_value = 0;
    e->left = left;
    e->right = right;
    e->has_parens = 0;
    e->level = level;
    return e;
}

struct expr * expr_create_value( int value ) {
    struct expr *e = expr_create(EXPR_VALUE,0,0, 10);
    e->literal_value = value;
    return e;
}

struct expr * expr_create_name( const char *n ){
    struct expr *e = expr_create(EXPR_NAME,0,0, 10);
    e->name = n;
    return e;
}

struct expr * expr_create_integer_literal( int c ){
    struct expr *e = expr_create(EXPR_INTEGER_LITERAL,0,0, 10);
    e->literal_value = c;
    return e;
}

struct expr * expr_create_float_literal( float c ){
    struct expr *e = expr_create(EXPR_FLOAT_LITERAL,0,0, 10);
    e->float_literal = c;
    return e;
}

struct expr * expr_create_boolean_literal( int c ){
    struct expr *e = expr_create(EXPR_BOOLEAN_LITERAL,0,0, 10);
    e->literal_value = c;
    return e;
}
struct expr * expr_create_char_literal( char c ){
    struct expr *e = expr_create(EXPR_CHAR_LITERAL,0,0, 10);
    e->literal_value = c;
    return e;
}
struct expr * expr_create_string_literal( const char *str ){
    struct expr *e = expr_create(EXPR_STRING_LITERAL,0,0, 10);
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
    int left_parens = 0;
    int right_parens = 0;
    if(e->kind == EXPR_NOT) {
        printf("!"); 
        if(e->left->has_parens){
            printf("(");
            expr_print(e->left);
            printf(")");
        } else {
            expr_print(e->left);
        }
        return;
    } else if(e->kind == EXPR_NEGATIVE) {
        printf("-");
        if(e->left->has_parens){
            printf("(");
            expr_print(e->left);
            printf(")");
        } else {
            expr_print(e->left);
        }
        return;
    } else if(e->kind == EXPR_POSITIVE) {
        printf("+");
        expr_print(e->left);
        return;
    } else if(e->kind == EXPR_ARRAY_INIT) {
        printf("{");
        expr_print(e->left);
        if(e->right){
            printf(",");
            expr_print(e->right);
        }
        printf("}");
        return;
    } 
    if(e->left && e->level < 10 && e->left->level < 10 && e->left->has_parens && (e->level > e->left->level)) {
        left_parens = 1;
    }
    if(e->right && e->level < 10 && e->right->level < 10 && e->right->has_parens && (e->level >= e->right->level)) {
        right_parens = 1;
    }
    if(left_parens) {
        printf("(");
        expr_print(e->left);
        printf(")");
    } else {
        expr_print(e->left);
    }
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
                printf(",");
                expr_print(e->right);
            }
            return;
        case EXPR_SUBSCRIPT:
            printf("[");
            expr_print(e->right);
            printf("]");
            return;
        default: break;
    }
    if(right_parens) {
        printf("(");
        expr_print(e->right);
        printf(")");
    } else {
        expr_print(e->right);
    }
}

void expr_resolve( struct expr *e ) {
    if(!e) return;
    if(e->kind == EXPR_NAME) {
        e->symbol = scope_lookup(e->name);
    } else {
        expr_resolve( e->left );
        expr_resolve( e->right );
    }
}

struct type * expr_typecheck(struct expr *e) {
    if(!e) return 0;
    struct type *left = expr_typecheck(e->left);
    struct type *right = expr_typecheck(e->right);
    struct type *result;

    switch(e->kind) {
        case EXPR_NAME:
            if(e->symbol){
                result = e->symbol->type;
            } else {
                result = type_create(TYPE_UNDEFINED, 0, 0, 0);
            }
            break;
        case EXPR_INTEGER_LITERAL:
            result = type_create(TYPE_INTEGER, 0, 0, 0);
            break;
        case EXPR_FLOAT_LITERAL:
            result = type_create(TYPE_FLOAT, 0, 0, 0);
            break;
        case EXPR_STRING_LITERAL:
            result = type_create(TYPE_STRING, 0, 0, 0);
            break;
        case EXPR_CHAR_LITERAL:
            result = type_create(TYPE_CHARACTER, 0, 0, 0);
            break;
        case EXPR_BOOLEAN_LITERAL:
            result = type_create(TYPE_BOOLEAN, 0, 0, 0);
            break;
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_MUL:
        case EXPR_DIV:
        case EXPR_MOD:
        case EXPR_EXP:
            if((left->kind != TYPE_INTEGER || right->kind != TYPE_INTEGER) &&
                (left->kind != TYPE_FLOAT || right->kind != TYPE_FLOAT)) {
                printf("type error: cannot ");
                if(e->kind == EXPR_ADD) {
                    printf("add ");
                } else if(e->kind == EXPR_SUB) {
                    printf("subtract ");
                } else if(e->kind == EXPR_MUL) {
                    printf("multiply ");
                } else if(e->kind == EXPR_DIV) {
                    printf("divide ");
                } else if(e->kind == EXPR_MOD) {
                    printf("modulo ");
                } else if(e->kind == EXPR_EXP) {
                    printf("exponent ");
                }
                printf("type ");
                type_print(left);
                printf(" (");
                expr_print(e->left);
                printf(") to type ");
                type_print(right);
                printf(" (");
                expr_print(e->right);
                printf(")\n");
                expr_error = 1;
            }
            if(e->kind == EXPR_EXP){
                result = type_create(TYPE_FLOAT, 0, 0, 0);
            } else {
                result = type_create(left->kind, 0, 0, 0);
            }
            break;

        case EXPR_OR: 
        case EXPR_AND:
            if(left->kind != TYPE_BOOLEAN || right->kind != TYPE_BOOLEAN){
                printf("type error: cannot ");
                if(e->kind == EXPR_OR) {
                    printf("or ");
                } else {
                    printf("and ");
                }
                type_print(left);
                printf(" (");
                expr_print(e->left);
                printf(") to a ");
                type_print(right);
                printf(" (");
                expr_print(e->right);
                printf(")\n");
                expr_error = 1;
            }
            result = type_create(TYPE_BOOLEAN, 0, 0, 0);
            break;
        case EXPR_CALL:
            if(left->kind != TYPE_FUNCTION) {
                printf("type error: cannot call ");
                expr_print(e->left);
                printf(" which is a ");
                type_print(left);
                printf(" not a function\n");
                expr_error = 1;
                result = type_create(TYPE_INTEGER, 0, 0, 0);
                break;
            }
            struct param_list * p = left->params;
            struct expr * r = e->right;
            while(r || p){
                if(!r) {
                    printf("type error: too few arguments to function %s - needs ", e->left->symbol->name);
                    param_list_print(p);
                    printf("\n");
                    expr_error = 1;
                    p = 0;
                } else if(!p) {
                    printf("type error: too many arguments to function %s - ", e->left->symbol->name);
                    expr_print(r);
                    printf("\n");
                    expr_error = 1;
                    r = 0;
                } else {
                    struct type *tr = expr_typecheck(r);
                    if(!type_equals(tr, p->type)) {
                        printf("type error: argument type mismatch when calling function %s - ", e->left->symbol->name);
                        expr_print(r->left);
                        printf(" which is type ");
                        type_print(tr);
                        printf(" and %s which is type ", p->name);
                        type_print(p->type);
                        printf("\n");
                        expr_error = 1;
                    }
                    r = r->right;
                    p = p->next;
                }
            }
            result = e->left->symbol->type->subtype;
            break;
        case EXPR_ARG:
            result = left;
            break;
        case EXPR_EQUALS_EQUALS:
        case EXPR_NOT_EQUALS:
        case EXPR_GREATER:
        case EXPR_GREATER_EQUAL:
        case EXPR_LESS:
        case EXPR_LESS_EQUAL:
            if(!type_equals(left, right)){
                printf("type error: cannot compare ");
                type_print(left);
                printf(" (");
                expr_print(e->left);
                printf(") to a ");
                type_print(right);
                printf(" (");
                expr_print(e->right);
                printf(")\n");
                expr_error = 1;
            }
            if(left->kind == TYPE_VOID ||
                left->kind == TYPE_ARRAY ||
                left->kind == TYPE_FUNCTION) {
                printf("type error: cannot compare ");
                type_print(left);
                printf(" (");
                expr_print(e->left);
                printf(") to a ");
                type_print(right);
                printf(" (");
                expr_print(e->right);
                printf(")\n");
                expr_error = 1;
            }
            result = type_create(TYPE_BOOLEAN, 0, 0, 0);
            break;
        case EXPR_PLUS_PLUS:
        case EXPR_MINUS_MINUS:
            if(left->kind != TYPE_INTEGER) {
                printf("type error: cannot");
                if(e->kind == EXPR_PLUS_PLUS) {
                    printf(" increment ");
                } else {
                    printf(" decrement ");
                }
                expr_print(e->left);
                printf(" which is a ");
                type_print(left);
                printf(" not an integer\n");
                expr_error = 1;
            }
            result = type_create(TYPE_INTEGER, 0, 0, 0);
            break;
        case EXPR_ASSIGN:
            if(!type_equals(left, right)) {
                printf("type error: cannot assign ");
                type_print(right);
                printf(" (");
                expr_print(e->right);
                printf(") to ");
                type_print(left);
                printf(" (");
                expr_print(e->left);
                printf(")\n");
                expr_error = 1;
            }
            result = type_create(left->kind, 0, 0, 0);
            break;
        case EXPR_SUBSCRIPT:
            if(left->kind != TYPE_ARRAY || right->kind != TYPE_INTEGER){
                printf("type error: cannot index array ");
                expr_print(e->left);
                printf(" with ");
                expr_print(e->right);
                printf(" which is type ");
                type_print(right);
                printf(" and should be type integer\n");
                expr_error = 1;
            }
            result = type_create(left->subtype->kind, 0, 0, 0);
            break;
        case EXPR_ARRAY_INIT:
            result = type_create(TYPE_ARRAY, 0, 0, 0);
            break;
        case EXPR_NEGATIVE:
        case EXPR_POSITIVE:
            if(left->kind != TYPE_INTEGER && left->kind != TYPE_FLOAT) {
                printf("type error: cannot make ");
                expr_print(e->left);
                printf(" which is type ");
                type_print(left);
                if(e->kind == EXPR_NEGATIVE) {
                    printf(" negative\n");
                } else {
                    printf(" positive\n");
                }
                expr_error = 1;
            }
            result = type_create(left->kind, 0, 0, 0);
            break;
        case EXPR_NOT:
            if(left->kind != TYPE_BOOLEAN) {
                printf("type error: cannot not ");
                expr_print(e->left);
                printf(" which is type ");
                type_print(left);
                printf(" but should be type boolean\n");
                expr_error = 1;
            }
            result = type_create(TYPE_BOOLEAN, 0, 0, 0);
            break;
        default:
            break;
    }       

    type_delete(left);
    type_delete(right);

    return result;
}

int expr_type_error() {
    return expr_error;
}