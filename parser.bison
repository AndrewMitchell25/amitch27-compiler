%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.h"
#include "decl.h"
#include "stmt.h"
#include "param_list.h"
#include "type.h"
#include "encoder.h"
struct decl * parser_result = 0;
extern int yylineno;
extern int yylex();
extern char yytext[];

int yyerror( const char *s ) {
    printf("parse error on line %d: %s\n",yylineno, s);
    return 1;
}
%}

%error-verbose

%union {
     struct decl *decl;
     struct stmt *stmt;
     struct expr *expr;
     struct type *type;
     struct param_list *param_list;
     char *name;
};

%type <decl> prog decl decl_list opt_decl_list
%type <stmt> stmt stmt_list else_stmt opt_stmt_list
%type <expr> atomic expr expr1 expr2 expr3 expr4 expr5 expr6 expr7 expr8 expr9 expr_list opt_expr_list opt_expr array_subscript
%type <type> type
%type <param_list> opt_param_list param_list param
%type <name> name


%token TOKEN_LEFT_PARENTHESES
%token TOKEN_RIGHT_PARENTHESES
%token TOKEN_LEFT_BRACKET
%token TOKEN_RIGHT_BRACKET
%token TOKEN_LEFT_CURLY_BRACKET
%token TOKEN_RIGHT_CURLY_BRACKET
%token TOKEN_COMMA
%token TOKEN_SEMICOLON
%token TOKEN_COLON
%token TOKEN_PLUS_PLUS
%token TOKEN_MINUS_MINUS
%token TOKEN_EQUALS_EQUALS
%token TOKEN_NOT_EQUALS
%token TOKEN_NOT
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_DIVIDE
%token TOKEN_MULTIPLY
%token TOKEN_MOD
%token TOKEN_EXPONENT
%token TOKEN_EQUALS
%token TOKEN_GREATER_EQUAL
%token TOKEN_LESS_EQUAL
%token TOKEN_GREATER
%token TOKEN_LESS
%token TOKEN_AND
%token TOKEN_OR
%token TOKEN_KW_ARRAY
%token TOKEN_KW_AUTO
%token TOKEN_KW_BOOLEAN
%token TOKEN_KW_CHAR
%token TOKEN_KW_ELSE
%token TOKEN_KW_FALSE
%token TOKEN_KW_FLOAT
%token TOKEN_KW_FOR
%token TOKEN_KW_FUNCTION
%token TOKEN_KW_IF
%token TOKEN_KW_INTEGER
%token TOKEN_KW_PRINT
%token TOKEN_KW_RETURN
%token TOKEN_KW_STRING
%token TOKEN_KW_TRUE
%token TOKEN_KW_VOID
%token TOKEN_KW_WHILE
%token TOKEN_ERROR
%token TOKEN_INTEGER
%token TOKEN_FLOAT
%token TOKEN_CHAR
%token TOKEN_STRING
%token TOKEN_IDENTIFIER


%%
prog : opt_decl_list      
          { parser_result = $1; }
     ;

expr : expr1
          {$$ = $1;}
     | TOKEN_LEFT_CURLY_BRACKET expr_list TOKEN_RIGHT_CURLY_BRACKET
          {$$ = $2; $2->kind = EXPR_ARRAY_INIT;}
     ;

expr1: expr2 TOKEN_EQUALS expr1
          {$$ = expr_create(EXPR_ASSIGN, $1, $3);}
     | expr2
          {$$ = $1;}
     ;

expr2: expr2 TOKEN_OR expr3
          {$$ = expr_create(EXPR_OR, $1, $3);}
     | expr3
          {$$ = $1;}
     ;

expr3: expr3 TOKEN_AND expr4
          {$$ = expr_create(EXPR_AND, $1, $3);}
     | expr4
          {$$ = $1;}
     ;

expr4: expr4 TOKEN_LESS expr5
          {$$ = expr_create(EXPR_LESS, $1, $3);}
     | expr4 TOKEN_LESS_EQUAL expr5
          {$$ = expr_create(EXPR_LESS_EQUAL, $1, $3);}
     | expr4 TOKEN_GREATER expr5
          {$$ = expr_create(EXPR_GREATER, $1, $3);}
     | expr4 TOKEN_GREATER_EQUAL expr5
          {$$ = expr_create(EXPR_GREATER_EQUAL, $1, $3);}
     | expr4 TOKEN_EQUALS_EQUALS expr5
          {$$ = expr_create(EXPR_EQUALS_EQUALS, $1, $3);}
     | expr4 TOKEN_NOT_EQUALS expr5
          {$$ = expr_create(EXPR_NOT_EQUALS, $1, $3);}
     | expr5
          {$$ = $1;}
     ;

expr5: expr5 TOKEN_PLUS expr6
          {$$ = expr_create(EXPR_ADD, $1, $3);}
     | expr5 TOKEN_MINUS expr6
          {$$ = expr_create(EXPR_SUB, $1, $3);}
     | expr6
          {$$ = $1;}
     ;

expr6: expr6 TOKEN_MULTIPLY expr7
          {$$ = expr_create(EXPR_MUL, $1, $3);}
     | expr6 TOKEN_DIVIDE expr7
          {$$ = expr_create(EXPR_DIV, $1, $3);}
     | expr6 TOKEN_MOD expr7
          {$$ = expr_create(EXPR_MOD, $1, $3);}
     | expr7
          {$$ = $1;}
     ;

expr7: expr7 TOKEN_EXPONENT expr8
          {$$ = expr_create(EXPR_EXP, $1, $3);}
     | expr8
          {$$ = $1;}
     ;

expr8: TOKEN_MINUS expr9
          {$$ = expr_create(EXPR_NEGATIVE, $2, 0);}
     | TOKEN_PLUS expr9
          {$$ = expr_create(EXPR_POSITIVE, $2, 0);}
     | TOKEN_NOT expr9
          {$$ = expr_create(EXPR_NOT, $2, 0);}
     | expr9
          {$$ = $1;}
     ;

expr9: atomic TOKEN_PLUS_PLUS
          {$$ = expr_create(EXPR_PLUS_PLUS, $1, 0);}
     | atomic TOKEN_MINUS_MINUS
          {$$ = expr_create(EXPR_MINUS_MINUS, $1, 0);}
     | atomic
          {$$ = $1;}
     ;

atomic
     : name
          {$$ = expr_create_name($1);}
     | TOKEN_INTEGER 
          {$$ = expr_create_integer_literal(atoi(yytext));}
     | TOKEN_FLOAT
          {$$ = expr_create_float_literal(atof(yytext));}
     | TOKEN_STRING
          {char *str = strdup(yytext);
               char *estr = malloc(strlen(str)); 
               string_encode(str, estr);
               $$ = expr_create_string_literal(estr);
          }
     | TOKEN_CHAR
          {$$ = expr_create_char_literal(yytext[0]);}
     | TOKEN_KW_TRUE
          {$$ = expr_create_boolean_literal(1);}
     | TOKEN_KW_FALSE
          {$$ = expr_create_boolean_literal(0);}
     | TOKEN_LEFT_PARENTHESES expr TOKEN_RIGHT_PARENTHESES 
          {$$ = $2; /*TODO GET PARENTHESES*/}
     | name TOKEN_LEFT_BRACKET opt_expr TOKEN_RIGHT_BRACKET array_subscript
          {if(!$5) {
               $$ = expr_create(EXPR_SUBSCRIPT, expr_create_name($1), $3);
          } else {
               struct expr * curr = $5;
               while(curr->left) {
                    curr = curr->left;
               }
               curr->left = expr_create(EXPR_SUBSCRIPT, expr_create_name($1), $3);
               $$ = $5;
          }}
     | name TOKEN_LEFT_PARENTHESES opt_expr_list TOKEN_RIGHT_PARENTHESES
          {$$ = expr_create(EXPR_CALL, expr_create_name($1), $3);}
     ;

name : TOKEN_IDENTIFIER
          {$$ = strdup(yytext);}
     ;

array_subscript
     : TOKEN_LEFT_BRACKET expr TOKEN_RIGHT_BRACKET array_subscript
          {if(!$4) {
               $$ = expr_create(EXPR_SUBSCRIPT, 0, $2);
          } else {
               struct expr * curr = $4;
               while(curr->left) {
                    curr = curr->left;
               }
               curr->left = expr_create(EXPR_SUBSCRIPT, 0, $2);
               $$ = $4;
          }}
     | {/* nothing */}
          {$$ = 0;}
     ;

opt_expr
     : expr
          {$$ = $1;}
     | {/* nothing */}
          {$$ = 0;}
     ;

opt_expr_list
     : expr_list
          {$$ = $1;}
     | {/* nothing */}
          {$$ = 0;}
     ;

expr_list
     : expr
          {$$ = expr_create(EXPR_ARG, $1, 0);}
     | expr TOKEN_COMMA expr_list
          {$$ = expr_create(EXPR_ARG, $1, $3);}
     ;

type : TOKEN_KW_INTEGER
          {$$ = type_create(TYPE_INTEGER, 0, 0, 0);}
     | TOKEN_KW_BOOLEAN
          {$$ = type_create(TYPE_BOOLEAN, 0, 0, 0);}
     | TOKEN_KW_CHAR
          {$$ = type_create(TYPE_CHARACTER, 0, 0, 0);}
     | TOKEN_KW_FLOAT
          {$$ = type_create(TYPE_FLOAT, 0, 0, 0);}
     | TOKEN_KW_STRING
          {$$ = type_create(TYPE_STRING, 0, 0, 0);}
     | TOKEN_KW_VOID
          {$$ = type_create(TYPE_VOID, 0, 0, 0);}
     | TOKEN_KW_ARRAY TOKEN_LEFT_BRACKET opt_expr TOKEN_RIGHT_BRACKET type
          {$$ = type_create(TYPE_ARRAY, $5, 0, $3);}
     | TOKEN_KW_FUNCTION type TOKEN_LEFT_PARENTHESES opt_param_list TOKEN_RIGHT_PARENTHESES
          {$$ = type_create(TYPE_FUNCTION, $2, $4, 0);}
     ;

decl : name TOKEN_COLON type TOKEN_SEMICOLON    
          {$$ = decl_create($1, $3, 0, 0, 0);}
     | name TOKEN_COLON type TOKEN_EQUALS expr TOKEN_SEMICOLON
          {$$ = decl_create($1, $3, $5, 0, 0);}
     | name TOKEN_COLON type TOKEN_EQUALS TOKEN_LEFT_CURLY_BRACKET opt_stmt_list TOKEN_RIGHT_CURLY_BRACKET
          {$$ = decl_create($1, $3, 0, $6, 0);}
     ;

decl_list
     : decl
          {$$ = $1;}
     | decl decl_list
          {$1->next = $2; $$ = $1;}
     ;

opt_decl_list
     : decl_list
          {$$ = $1;}
     | {/* nothing */}
          {$$ = 0;}
     ;

param: name TOKEN_COLON type
          {$$ = param_list_create($1, $3, 0);}
     ;

param_list
     : param
          {$$ = $1;}
     | param TOKEN_COMMA param_list
          {$$ = $1; $1->next = $3;}
     ;

opt_param_list
     : param_list
          {$$ = $1;}
     | {/* nothing */}
          {$$ = 0;}
     ;

stmt : decl
          {$$ = stmt_create(STMT_DECL, $1, 0, 0, 0, 0, 0, 0);}
     | TOKEN_KW_RETURN opt_expr TOKEN_SEMICOLON
          {$$ = stmt_create(STMT_RETURN, 0, 0, $2, 0, 0, 0, 0);}
     | TOKEN_KW_PRINT opt_expr_list TOKEN_SEMICOLON
          {$$ = stmt_create(STMT_PRINT, 0, 0, $2, 0, 0, 0, 0);}
     | expr TOKEN_SEMICOLON
          {$$ = stmt_create(STMT_EXPR, 0, 0, $1, 0, 0, 0, 0);}
     | TOKEN_LEFT_CURLY_BRACKET stmt_list TOKEN_RIGHT_CURLY_BRACKET
          {$$ = stmt_create(STMT_BLOCK, 0, 0, 0, 0, $2, 0, 0);}
     | TOKEN_KW_FOR TOKEN_LEFT_PARENTHESES opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_RIGHT_PARENTHESES stmt
          {$$ = stmt_create(STMT_FOR, 0, $3, $5, $7, $9, 0, 0);}
     | TOKEN_KW_IF TOKEN_LEFT_PARENTHESES expr TOKEN_RIGHT_PARENTHESES stmt
          {$$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, 0, 0);}
     | TOKEN_KW_IF TOKEN_LEFT_PARENTHESES expr TOKEN_RIGHT_PARENTHESES else_stmt TOKEN_KW_ELSE stmt
          {$$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, $7, 0);}
     ;

else_stmt
     : TOKEN_KW_IF TOKEN_LEFT_PARENTHESES expr TOKEN_RIGHT_PARENTHESES else_stmt TOKEN_KW_ELSE else_stmt
          {$$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, $7, 0);}
     | TOKEN_KW_RETURN opt_expr TOKEN_SEMICOLON
          {$$ = stmt_create(STMT_RETURN, 0, 0, $2, 0, 0, 0, 0);}
     | TOKEN_KW_PRINT opt_expr_list TOKEN_SEMICOLON
          {$$ = stmt_create(STMT_PRINT, 0, 0, $2, 0, 0, 0, 0);}
     | expr TOKEN_SEMICOLON
          {$$ = stmt_create(STMT_EXPR, 0, 0, $1, 0, 0, 0, 0);}
     | TOKEN_LEFT_CURLY_BRACKET stmt_list TOKEN_RIGHT_CURLY_BRACKET
          {$$ = stmt_create(STMT_BLOCK, 0, 0, 0, 0, $2, 0, 0);}
     | TOKEN_KW_FOR TOKEN_LEFT_PARENTHESES opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_RIGHT_PARENTHESES else_stmt
          {$$ = stmt_create(STMT_FOR, 0, $3, $5, $7, $9, 0, 0);}
     ;

opt_stmt_list
     : stmt_list
          {$$ = $1;}
     | {/* nothing */}
          {$$ = 0;}
     ;

stmt_list
     : stmt
          {$$ = $1;}
     | stmt stmt_list
          {$1->next = $2; $$ = $1;}
     ;

%%
