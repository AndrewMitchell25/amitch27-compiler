#include <stdio.h>
#include <stdlib.h>
#include "stmt.h"
#include "decl.h"
#include "expr.h"
#include "indent.h"

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
            printf("; ");
            expr_print(s->expr);
            printf("; ");
            expr_print(s->next_expr);
            printf(") ");
            if(s->body->kind != STMT_BLOCK) {
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
            if(s->body->kind != STMT_BLOCK) {
                struct stmt *new = stmt_create(STMT_BLOCK, 0, 0, 0, 0, s->body, 0, 0);
                s->body = new;
            }
            stmt_print(s->body, indent);
            if(s->else_body) {
                printf(" else ");
                if(s->else_body->kind == STMT_IF_ELSE) {
                    s->else_body->prev = STMT_IF_ELSE;
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