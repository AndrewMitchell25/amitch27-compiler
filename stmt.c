#include <stdio.h>
#include <stdlib.h>
#include "stmt.h"
#include "decl.h"
#include "expr.h"
#include "indent.h"
#include "scope.h"
#include "type.h"
#include "scratch.h"
#include "label.h"

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
    if(!s) return 0;
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
                printf("type error: cannot use type ");
                type_print(t);
                printf(" (");
                expr_print(s->expr);
                printf(") in an if statement\n");
                stmt_error = 1;
            }
            stmt_typecheck(s->body);
            stmt_typecheck(s->else_body);
            break;
        case STMT_FOR:
             t = expr_typecheck(s->init_expr);
             if(t && t->kind != TYPE_INTEGER){
                printf("type error: cannot use type ");
                type_print(t);
                printf(" (");
                expr_print(s->init_expr);
                printf(") as the first statement in a for loop\n");
                stmt_error = 1;
             }
             t = expr_typecheck(s->expr);
             if(t && t->kind != TYPE_BOOLEAN){
                printf("type error: cannot use type ");
                type_print(t);
                printf(" (");
                expr_print(s->expr);
                printf(") as the second statement in a for loop\n");
                stmt_error = 1;
             }
             t = expr_typecheck(s->next_expr);
             if(t && t->kind != TYPE_INTEGER){
                printf("type error: cannot use type ");
                type_print(t);
                printf(" (");
                expr_print(s->next_expr);
                printf(") as the third statement in a for loop\n");
                stmt_error = 1;
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

void stmt_codegen( FILE * file, struct stmt *s, const char * func_name  ) {
    if(!s) return;
    switch(s->kind) {
        case STMT_EXPR:
            expr_codegen(file, s->expr);
            scratch_free(s->expr->reg);
            break;
        case STMT_RETURN:
            expr_codegen(file, s->expr);
            fprintf(file, "MOVQ %s, %%rax\n", scratch_name(s->expr->reg));
            fprintf(file, "JMP .%s_epilogue\n", func_name);
            scratch_free(s->expr->reg);
            break;
        case STMT_DECL:
            decl_codegen(file, s->decl);
            break;
        case STMT_FOR:
            if(s->init_expr) {
                expr_codegen(file, s->init_expr);
                scratch_free(s->init_expr->reg);
            }    
            int top = label_create();
            int bottom = label_create();
            const char * top_name = label_name(top);
            const char * bottom_name = label_name(bottom);
            fprintf(file, "%s:\n", top_name);
            if(s->expr) {
                expr_codegen(file, s->expr);
                fprintf(file, "CMP $0, %s\n", scratch_name(s->expr->reg));
                fprintf(file, "JE %s\n", bottom_name);
                scratch_free(s->expr->reg);
            }
            stmt_codegen(file, s->body, func_name);
            if(s->next_expr) {
                expr_codegen(file, s->next_expr);
                scratch_free(s->next_expr->reg);
            }
            fprintf(file, "JMP %s\n", top_name);
            fprintf(file, "%s:\n", bottom_name);
            free((void *)top_name);
            free((void *)bottom_name);
            break;
        case STMT_BLOCK:
            stmt_codegen(file, s->body, func_name);
            break;
        case STMT_STANDING_BLOCK:
            stmt_codegen(file, s->body, func_name);
            break;
        case STMT_IF_ELSE:
            expr_codegen(file, s->expr);
            int else_label = label_create();
            int done_label = label_create();
            const char * else_name = label_name(else_label);
            const char * done_name = label_name(done_label);
            fprintf(file, "CMP $0, %s\n", scratch_name(s->expr->reg));
            scratch_free(s->expr->reg);
            fprintf(file, "JE %s\n", else_name);
            stmt_codegen(file, s->body, func_name);
            fprintf(file, "JMP %s\n", done_name);
            fprintf(file, "%s:\n", else_name);
            stmt_codegen(file, s->else_body, func_name);
            fprintf(file, "%s:\n", done_name);
            free((void *)else_name);
            free((void *)done_name);
            break;
        case STMT_PRINT: 
            ;
            struct expr * curr = s->expr;
            while(curr) {
                //TODO: need to fix this expr_codegen won't work
                //maybe change it to if not EXPR_ARG, so only do it
                //if it needs to evaluate something
                //or just change each kind to EXPR_PRINT_ARG before codegenning it
                if(curr->kind == EXPR_ARG) {
                    curr->kind = EXPR_PRINT_ARG;
                }
                expr_codegen(file, curr);
                struct type * t = expr_typecheck(curr);
                fprintf(file, "MOVQ %s, %%rdi\n", scratch_name(curr->reg));
                scratch_free(curr->reg);
                switch(t->kind){
                    case TYPE_INTEGER:
                        fprintf(file, "CALL print_integer\n");
                        break;
                    case TYPE_STRING:
                        fprintf(file, "CALL print_string\n");
                        break;
                    case TYPE_BOOLEAN:
                        fprintf(file, "CALL print_boolean\n");
                        break;
                    case TYPE_CHARACTER:
                        fprintf(file, "CALL print_character\n");
                        break;
                    default:
                        break;
                }
                curr = curr->right;
            }
            break;
    }
    stmt_codegen(file, s->next, func_name);
}
