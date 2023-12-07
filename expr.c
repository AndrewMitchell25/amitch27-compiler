#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.h"
#include "symbol.h"
#include "scope.h"
#include "type.h"
#include "scratch.h"
#include "label.h"

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
                printf(") with a ");
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
                printf("type error: cannot call (");
                expr_print(e->left);
                printf(") which is type ");
                type_print(left);
                printf(" not a function\n");
                expr_error = 1;
                result = type_create(TYPE_UNDEFINED, 0, 0, 0);
                break;
            }
            struct param_list * p = left->params;
            struct expr * r = e->right;
            while(r || p){
                if(!r) {
                    printf("type error: too few arguments to function (%s) - needs ", e->left->symbol->name);
                    param_list_print(p);
                    printf("\n");
                    expr_error = 1;
                    p = 0;
                } else if(!p) {
                    printf("type error: too many arguments to function (%s) - ", e->left->symbol->name);
                    expr_print(r);
                    printf("\n");
                    expr_error = 1;
                    r = 0;
                } else {
                    struct type *tr = expr_typecheck(r);
                    if(!type_equals(tr, p->type)) {
                        printf("type error: argument type mismatch when calling function (%s) - (", e->left->symbol->name);
                        expr_print(r->left);
                        printf(") which is type ");
                        type_print(tr);
                        printf(" and (%s) which is type ", p->name);
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
        case EXPR_PRINT_ARG:
            result = left;
            break;
        case EXPR_EQUALS_EQUALS:
        case EXPR_NOT_EQUALS:
        case EXPR_GREATER:
        case EXPR_GREATER_EQUAL:
        case EXPR_LESS:
        case EXPR_LESS_EQUAL:
            if(!type_equals(left, right)){
                printf("type error: cannot compare type ");
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
            if(left->kind == TYPE_VOID ||
                left->kind == TYPE_ARRAY ||
                left->kind == TYPE_FUNCTION) {
                printf("type error: cannot compare type ");
                type_print(left);
                printf(" (");
                expr_print(e->left);
                printf(") with type ");
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
                    printf(" increment (");
                } else {
                    printf(" decrement (");
                }
                expr_print(e->left);
                printf(") which is type ");
                type_print(left);
                printf(" not an integer\n");
                expr_error = 1;
            }
            result = type_create(TYPE_INTEGER, 0, 0, 0);
            break;
        case EXPR_ASSIGN:
            if(!type_equals(left, right)) {
                printf("type error: cannot assign type ");
                type_print(right);
                printf(" (");
                expr_print(e->right);
                printf(") to type ");
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
                printf("type error: cannot index array (");
                expr_print(e->left);
                printf(") with (");
                expr_print(e->right);
                printf(") which is type ");
                type_print(right);
                printf(" and should be type integer\n");
                expr_error = 1;
            }
            result = type_copy(left->subtype);
            break;
        case EXPR_ARRAY_INIT: ;
            struct type *eait = expr_array_init_type(e);
            if(eait){
                result = type_create(TYPE_ARRAY, eait, 0, 0);
                type_delete(eait);
            } else {
                printf("type error: cannot initialize array to multiple types (");
                expr_print(e);
                printf(")\n");
                expr_error = 1;
                result = type_create(TYPE_ARRAY, left, 0, 0);
            }
            break;
        case EXPR_NEGATIVE:
        case EXPR_POSITIVE:
            if(left->kind != TYPE_INTEGER && left->kind != TYPE_FLOAT) {
                printf("type error: cannot make (");
                expr_print(e->left);
                printf(") which is type ");
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
                printf("type error: cannot not (");
                expr_print(e->left);
                printf(") which is type ");
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

struct type * expr_array_init_type(struct expr *e) {

    struct type * left = expr_typecheck(e->left);
    struct type * right = expr_typecheck(e->right);
    if(type_equals(left, right) || !right) {
        return type_create(left->kind, left->subtype, 0, 0);
    }
    return 0;
}

char * arg_regs[6] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};

void expr_codegen( FILE * file, struct expr *e ) {
    if(!e) return;
    //expr_print(e);
    switch(e->kind) {
        case EXPR_NAME:
            e->reg = scratch_alloc();
            if((e->symbol->type->kind == TYPE_ARRAY || e->symbol->type->kind == TYPE_STRING) && e->symbol->kind == SYMBOL_GLOBAL) {
                fprintf(file, "LEAQ %s, %s\n", symbol_codegen(e->symbol), scratch_name(e->reg));
            } else {
                fprintf(file, "MOVQ %s, %s\n", symbol_codegen(e->symbol), scratch_name(e->reg));
            }
            break;
        case EXPR_ARG:
            ;
            struct expr * curr = e;
            int i = 0;
            while(curr && i < 6) {
                expr_codegen(file, curr->left);
                fprintf(file, "MOVQ %s, %s\n", scratch_name(curr->left->reg), arg_regs[i]);
                scratch_free(curr->left->reg);
                curr = curr->right;
                i++;
            }
            if(i >= 6) {
                printf("runtime error: too many arguments");
                exit(EXIT_FAILURE);
            }
            break;
        case EXPR_INTEGER_LITERAL:
        case EXPR_BOOLEAN_LITERAL:
        case EXPR_CHAR_LITERAL:
            e->reg = scratch_alloc();
            fprintf(file, "MOVQ $%d, %s\n", e->literal_value, scratch_name(e->reg));
            break;
        case EXPR_STRING_LITERAL:
            e->reg = scratch_alloc();
            int l = label_create();
            const char *l_name = label_name(l);
            fprintf(file, ".data\n");
            fprintf(file, "%s: .string %s\n", l_name, e->string_literal);
            fprintf(file, ".text\n");
            fprintf(file, "LEAQ %s, %s\n", l_name, scratch_name(e->reg));
            free((void *)l_name);
            break;
        case EXPR_ADD:
            expr_codegen(file, e->left);
            expr_codegen(file, e->right);
            fprintf(file, "ADDQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_SUB:
            expr_codegen(file, e->left);
            expr_codegen(file, e->right);
            fprintf(file, "SUBQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->left->reg));
            e->reg = e->left->reg;
            scratch_free(e->right->reg);
            break;
        case EXPR_MUL:
            expr_codegen(file, e->left);
            expr_codegen(file, e->right);
            fprintf(file, "MOVQ %s, %%rax\n", scratch_name(e->left->reg));
            fprintf(file, "IMULQ %s\n", scratch_name(e->right->reg));
            scratch_free(e->left->reg);
            scratch_free(e->right->reg);
            e->reg = scratch_alloc();
            fprintf(file, "MOVQ %%rax, %s\n", scratch_name(e->reg));
            break;
        case EXPR_DIV:
            expr_codegen(file, e->left);
            expr_codegen(file, e->right);
            fprintf(file, "MOVQ %s, %%rax\n", scratch_name(e->left->reg));
            fprintf(file, "CQO\n");
            fprintf(file, "IDIVQ %s\n", scratch_name(e->right->reg));
            scratch_free(e->left->reg);
            scratch_free(e->right->reg);
            e->reg = scratch_alloc();
            fprintf(file, "MOVQ %%rax, %s\n", scratch_name(e->reg));
            break;
        case EXPR_MOD:
            expr_codegen(file, e->left);
            expr_codegen(file, e->right);
            fprintf(file, "MOVQ %s, %%rax\n", scratch_name(e->left->reg));
            fprintf(file, "CQO\n");
            fprintf(file, "IDIVQ %s\n", scratch_name(e->right->reg));
            scratch_free(e->left->reg);
            scratch_free(e->right->reg);
            e->reg = scratch_alloc();
            fprintf(file, "MOVQ %%rdx, %s\n", scratch_name(e->reg));
            break;
        case EXPR_PLUS_PLUS:
            expr_codegen(file, e->left);
            fprintf(file, "INCQ %s\n", scratch_name(e->left->reg));
            if(e->left->kind == EXPR_NAME) {
                fprintf(file, "MOVQ %s, %s\n", scratch_name(e->left->reg), symbol_codegen(e->left->symbol));
            }
            e->reg = e->left->reg;
            break;
        case EXPR_MINUS_MINUS:
            expr_codegen(file, e->left);
            fprintf(file, "DECQ %s\n", scratch_name(e->left->reg));
            if(e->left->kind == EXPR_NAME) {
                fprintf(file, "MOVQ %s, %s\n", scratch_name(e->left->reg), symbol_codegen(e->left->symbol));
            }
            e->reg = e->left->reg;
            break;
        case EXPR_ASSIGN:
            expr_codegen(file, e->right);
            fprintf(file, "MOVQ %s, %s\n", scratch_name(e->right->reg), symbol_codegen(e->left->symbol));
            e->reg = e->right->reg;
            break;
        case EXPR_SUBSCRIPT:
            expr_codegen(file, e->left);
            expr_codegen(file, e->right);
            e->reg = scratch_alloc();
            fprintf(file, "MOVQ (%s, %s, 8), %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg), scratch_name(e->reg));
            scratch_free(e->left->reg);
            scratch_free(e->right->reg);
            break;
        case EXPR_CALL:
            //args
            expr_codegen(file, e->right);
            //get reg
            e->reg = scratch_alloc();
            //push stuff
            fprintf(file, "PUSHQ %%r10\n");
            fprintf(file, "PUSHQ %%r11\n");
            //call function
            fprintf(file, "CALL %s\n", e->left->symbol->name);
            //pop stuff
            fprintf(file, "POPQ %%r11\n");
            fprintf(file, "POPQ %%r10\n");
            //move result to e->reg
            fprintf(file, "MOVQ %%rax, %s\n", scratch_name(e->reg));
            break;
        case EXPR_PRINT_ARG:
            expr_codegen(file, e->left);
            e->reg = e->left->reg;
            break;
        case EXPR_EQUALS_EQUALS:
        case EXPR_NOT_EQUALS:
        case EXPR_LESS:
        case EXPR_LESS_EQUAL:
        case EXPR_GREATER:
        case EXPR_GREATER_EQUAL:
        //case EXPR_AND:
            expr_codegen(file, e->left);
            expr_codegen(file, e->right);
            fprintf(file, "CMP %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
            scratch_free(e->left->reg);
            scratch_free(e->right->reg);
            e->reg = scratch_alloc();
            int true_label = label_create();
            const char * true_label_name = label_name(true_label);
            int done_label = label_create();
            const char * done_label_name = label_name(done_label);
            if(e->kind == EXPR_EQUALS_EQUALS) {
                fprintf(file, "JE %s\n", true_label_name);
            } else if(e->kind == EXPR_NOT_EQUALS) {
                fprintf(file, "JNE %s\n", true_label_name);
            } else if(e->kind == EXPR_LESS) {
                fprintf(file, "JG %s\n", true_label_name);
            } else if(e->kind == EXPR_LESS_EQUAL) {
                fprintf(file, "JGE %s\n", true_label_name);
            } else if(e->kind == EXPR_GREATER) {
                fprintf(file, "JL %s\n", true_label_name);
            } else if(e->kind == EXPR_GREATER_EQUAL) {
                fprintf(file, "JLE %s\n", true_label_name);
            }
            fprintf(file, "MOVQ $0, %s\n", scratch_name(e->reg));
            fprintf(file, "JMP %s\n", done_label_name);
            fprintf(file, "%s:\n", true_label_name);
            fprintf(file, "MOVQ $1, %s\n", scratch_name(e->reg));
            fprintf(file, "%s:\n", done_label_name);
            free((void *)true_label_name);
            free((void *)done_label_name);
            break;
        case EXPR_NOT:
            expr_codegen(file, e->left);
            int zero = label_create();
            const char * zero_name = label_name(zero);
            int done = label_create();
            const char * done_name = label_name(done);
            fprintf(file, "CMP $0, %s\n", scratch_name(e->left->reg));
            fprintf(file, "JE %s\n", zero_name);
            fprintf(file, "MOVQ $0, %s\n", scratch_name(e->left->reg));
            fprintf(file, "JMP %s\n", done_name);
            fprintf(file, "%s:\n", zero_name);
            fprintf(file, "MOVQ $1, %s\n", scratch_name(e->left->reg));
            fprintf(file, "%s:\n", done_name);
            e->reg = e->left->reg;
            free((void *)zero_name);
            free((void *)done_name);
            break;
        case EXPR_POSITIVE:
            break;
        case EXPR_NEGATIVE:
            expr_codegen(file, e->left);
            e->reg = scratch_alloc();
            fprintf(file, "MOVQ $0, %s\n", scratch_name(e->reg));
            fprintf(file, "SUBQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->reg));
            scratch_free(e->left->reg);
            break;
        case EXPR_AND:
            expr_codegen(file, e->left);
            expr_codegen(file, e->right);
            int skip = label_create();
            const char * skip_name = label_name(skip);
            fprintf(file, "CMP $0, %s\n", scratch_name(e->left->reg));
            fprintf(file, "JNE %s\n", skip_name);
            fprintf(file, "MOVQ $0, %s\n", scratch_name(e->right->reg));
            fprintf(file, "%s:\n", skip_name);
            scratch_free(e->left->reg);
            e->reg = e->right->reg;
            free((void *)skip_name);
            break;
        case EXPR_OR:
            expr_codegen(file, e->left);
            expr_codegen(file, e->right);
            skip = label_create();
            skip_name = label_name(skip);
            fprintf(file, "CMP $1, %s\n", scratch_name(e->left->reg));
            fprintf(file, "JNE %s\n", skip_name);
            fprintf(file, "MOVQ $1, %s\n", scratch_name(e->right->reg));
            fprintf(file, "%s:\n", skip_name);
            scratch_free(e->left->reg);
            e->reg = e->right->reg;
            free((void *)skip_name);
            break;
        case EXPR_EXP:
            expr_codegen(file, e->left);
            expr_codegen(file, e->right);
            fprintf(file, "MOVQ %s, %%rdi\n", scratch_name(e->left->reg));
            fprintf(file, "MOVQ %s, %%rsi\n", scratch_name(e->right->reg));
            fprintf(file, "CALL integer_power\n");
            fprintf(file, "MOVQ %%rax, %s\n", scratch_name(e->left->reg));
            e->reg = e->left->reg;
            scratch_free(e->right->reg);
            break;
        default:
            printf("runtime error: case not handled - ");
            expr_print(e);
            printf("\n");
            exit(EXIT_FAILURE);
    }
    return;
}
