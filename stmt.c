#include <stdio.h>
#include <stdlib.h>
#include "stmt.h"
#include "decl.h"
#include "expr.h"
#include "indent.h"
#include "scope.h"
#include "type.h"

int stmt_error = 0;

struct stmt * stmt_create( stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next ){
    struct stmt * s = malloc(sizeof(*s));
    s->kind = kind;
    s->decl = decl;
    s->init_expr = init_expr;
    s->expr = expr;
    s->next_expr = next_expr;
    s->body = body;
    s->else_body = else_body;
    s->next = next;
    return s;
}

void stmt_print( struct stmt *s, int indent ){
    if(!s) return;
    int semi = 1;
    
    switch(s->kind) {
        case STMT_DECL: decl_print(s->decl, indent); semi = 0; break;
        case STMT_EXPR: 
            print_indent(indent); 
            expr_print(s->expr); 
            break;
        case STMT_RETURN: 
            print_indent(indent); 
            printf("return"); 
            if(s->expr){
                printf(" ");
                expr_print(s->expr); 
            }
            break;
        case STMT_PRINT: 
            print_indent(indent);
            printf("print");
            if(s->expr) {
                printf(" ");
                expr_print(s->expr);
            }
            break;
        case STMT_STANDING_BLOCK:
            print_indent(indent);
            printf("{\n");
            stmt_print(s->body, indent+1);
            print_indent(indent);
            printf("}\n");
            semi = 0;
            break;
        case STMT_BLOCK:
            printf("{\n");
            stmt_print(s->body, indent+1);
            print_indent(indent);
            printf("}");
            semi = 0;
            break;
        case STMT_FOR: 
            print_indent(indent);
            printf("for ("); 
            expr_print(s->init_expr);
            printf(";");
            expr_print(s->expr);
            printf(";");
            expr_print(s->next_expr);
            printf(") ");
            if(s->body->kind == STMT_STANDING_BLOCK) {
                s->body->kind = STMT_BLOCK;
            } else if(s->body->kind != STMT_BLOCK) {
                struct stmt *new = stmt_create(STMT_BLOCK, 0, 0, 0, 0, s->body, 0, 0);
                s->body = new;
            }
            stmt_print(s->body, indent);
            printf("\n");
            semi = 0;
            break;
        case STMT_IF_ELSE:
            if(s->prev != STMT_IF_ELSE) {
                print_indent(indent);
            }
            printf("if(");
            expr_print(s->expr);
            printf(") ");
            if(s->body->kind == STMT_STANDING_BLOCK) {
                s->body->kind = STMT_BLOCK;
            } else if(s->body->kind != STMT_BLOCK) {
                struct stmt *new = stmt_create(STMT_BLOCK, 0, 0, 0, 0, s->body, 0, 0);
                s->body = new;
            }
            stmt_print(s->body, indent);
            if(s->else_body) {
                printf(" else ");
                if(s->else_body->kind == STMT_IF_ELSE) {
                    s->else_body->prev = STMT_IF_ELSE;
                } else if (s->else_body->kind == STMT_STANDING_BLOCK) {
                    s->else_body->kind = STMT_BLOCK;
                } else if(s->else_body->kind != STMT_BLOCK) {
                    struct stmt *new = stmt_create(STMT_BLOCK, 0, 0, 0, 0, s->else_body, 0, 0);
                    s->else_body = new;
                }
                stmt_print(s->else_body, indent);
            }
            if(s->prev != STMT_IF_ELSE){
                printf("\n");
            }
            semi = 0;
            break;
        default: break;
    }
    if(semi) {
        printf(";\n");
    }
    stmt_print(s->next, indent);
}

void stmt_resolve( struct stmt *s ) {
    if(!s) return;
    if(s->kind == STMT_BLOCK || s->kind == STMT_STANDING_BLOCK) {
        scope_enter();
        stmt_resolve(s->body);
        scope_exit();
    } else {
        decl_resolve(s->decl);
        expr_resolve(s->init_expr);
        expr_resolve(s->expr);
        expr_resolve(s->next_expr);
        stmt_resolve(s->body);
        stmt_resolve(s->else_body);
    }
    stmt_resolve(s->next);
}

struct type * stmt_typecheck(struct stmt *s){
    struct type *t;
    switch(s->kind){
        case STMT_DECL:
            decl_typecheck(s->decl);
            break;
        case STMT_EXPR:
            t = expr_typecheck(s->expr);
            break;
        case STMT_IF_ELSE:
            t = expr_typecheck(s->expr);
            if(t->kind != TYPE_BOOLEAN){
                printf("ERROR\n");
                //print error
            }
            stmt_typecheck(s->body);
            stmt_typecheck(s->else_body);
            break;
        case STMT_FOR:
             t = expr_typecheck(s->init_expr);
             if(t && t->kind != TYPE_INTEGER){
                printf("ERROR\n");
                //error
             }
             t = expr_typecheck(s->expr);
             if(t && t->kind != TYPE_BOOLEAN){
                printf("ERROR\n");
                //error
             }
             t = expr_typecheck(s->next_expr);
             if(t && t->kind != TYPE_INTEGER){
                printf("ERROR\n");
                //error
             }
             stmt_typecheck(s->body);
             break;
        case STMT_PRINT:
            t = expr_typecheck(s->expr);
            break;
        case STMT_RETURN:
            t = expr_typecheck(s->expr);
            if(!t){
                t = type_create(TYPE_VOID, 0, 0, 0);
            }
            return(t);
        case STMT_BLOCK:
            stmt_typecheck(s->body);
            break;
        case STMT_STANDING_BLOCK:
            stmt_typecheck(s->body);
            break;
    }
    type_delete(t);
    return 0;
}

int stmt_type_error() {
    return stmt_error;
}