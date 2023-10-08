%{
#include <stdio.h>
#include "expr.h"
#define YYSTYPE struct expr *
struct expr * parser_result = 0;
extern int yylineno;
extern int yylex();

int yyerror( const char *s ) {
    printf("parse error on line %d: %s\n",yylineno, s);
    return 1;
}
%}

%error-verbose

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
prog : opt_decl_list      { parser_result = $1; }
     ;

expr : expr1
     | TOKEN_LEFT_CURLY_BRACKET expr_list TOKEN_RIGHT_CURLY_BRACKET
     ;

expr1: expr2 TOKEN_EQUALS expr1
     | expr2
     ;

expr2: expr2 TOKEN_OR expr3
     | expr3
     ;

expr3: expr3 TOKEN_AND expr4
     | expr4
     ;

expr4: expr4 TOKEN_LESS expr5
     | expr4 TOKEN_LESS_EQUAL expr5
     | expr4 TOKEN_GREATER expr5
     | expr4 TOKEN_GREATER_EQUAL expr5
     | expr4 TOKEN_EQUALS_EQUALS expr5
     | expr4 TOKEN_NOT_EQUALS expr5
     | expr5
     ;

expr5: expr5 TOKEN_PLUS expr6
     | expr5 TOKEN_MINUS expr6
     | expr6
     ;

expr6: expr6 TOKEN_MULTIPLY expr7
     | expr6 TOKEN_DIVIDE expr7
     | expr6 TOKEN_MOD expr7
     | expr7
     ;

expr7: expr7 TOKEN_EXPONENT expr8
     | expr8
     ;

expr8: TOKEN_MINUS expr9
     | TOKEN_NOT expr9
     | expr9
     ;

expr9: atomic TOKEN_PLUS_PLUS
     | atomic TOKEN_MINUS_MINUS
     | atomic
     ;

atomic
     : TOKEN_IDENTIFIER
     | TOKEN_INTEGER 
     | TOKEN_FLOAT
     | TOKEN_STRING
     | TOKEN_CHAR
     | TOKEN_KW_TRUE
     | TOKEN_KW_FALSE
     | TOKEN_LEFT_PARENTHESES expr TOKEN_RIGHT_PARENTHESES
     | TOKEN_IDENTIFIER TOKEN_LEFT_BRACKET opt_expr TOKEN_RIGHT_BRACKET
     | TOKEN_IDENTIFIER TOKEN_LEFT_PARENTHESES opt_expr_list TOKEN_RIGHT_PARENTHESES
     ;

opt_expr
     : expr
     | {/* nothing */}
     ;

opt_expr_list
     : expr_list
     | {/* nothing */}
     ;

expr_list
     : expr_list TOKEN_COMMA expr
     | expr
     ;

type : TOKEN_KW_INTEGER
     | TOKEN_KW_BOOLEAN
     | TOKEN_KW_CHAR
     | TOKEN_KW_FLOAT
     | TOKEN_KW_STRING
     | TOKEN_KW_VOID
     | TOKEN_KW_ARRAY TOKEN_LEFT_BRACKET opt_expr TOKEN_RIGHT_BRACKET type
     | TOKEN_KW_FUNCTION type TOKEN_LEFT_PARENTHESES opt_param_list TOKEN_RIGHT_PARENTHESES
     ;

decl : TOKEN_IDENTIFIER TOKEN_COLON type init TOKEN_SEMICOLON
     | TOKEN_IDENTIFIER TOKEN_COLON type func_init
     ;

init : TOKEN_EQUALS expr
     | {/* nothing */}
     ;

func_init
     : TOKEN_EQUALS TOKEN_LEFT_CURLY_BRACKET stmt_list TOKEN_RIGHT_CURLY_BRACKET
     ;

decl_list
     : decl_list decl
     | decl
     ;

opt_decl_list
     : decl_list
     | {/* nothing */}
     ;

param: TOKEN_IDENTIFIER TOKEN_COLON type
     ;

param_list
     : param_list TOKEN_COMMA param
     | param
     ;

opt_param_list
     : param_list
     | {/* nothing */}
     ;

stmt : decl
     | TOKEN_KW_RETURN opt_expr TOKEN_SEMICOLON
     | TOKEN_KW_PRINT opt_expr_list TOKEN_SEMICOLON
     | expr TOKEN_SEMICOLON
     | TOKEN_LEFT_CURLY_BRACKET stmt_list TOKEN_RIGHT_CURLY_BRACKET
     | TOKEN_KW_FOR TOKEN_LEFT_PARENTHESES opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_RIGHT_PARENTHESES stmt
     | TOKEN_KW_IF TOKEN_LEFT_PARENTHESES expr TOKEN_RIGHT_PARENTHESES stmt
     | TOKEN_KW_IF TOKEN_LEFT_PARENTHESES expr TOKEN_RIGHT_PARENTHESES else_stmt TOKEN_KW_ELSE stmt
     ;

else_stmt
     : TOKEN_KW_IF TOKEN_LEFT_PARENTHESES expr TOKEN_RIGHT_PARENTHESES else_stmt TOKEN_KW_ELSE else_stmt
     | TOKEN_KW_RETURN opt_expr TOKEN_SEMICOLON
     | TOKEN_KW_PRINT opt_expr_list TOKEN_SEMICOLON
     | expr TOKEN_SEMICOLON
     | TOKEN_LEFT_CURLY_BRACKET stmt_list TOKEN_RIGHT_CURLY_BRACKET
     | TOKEN_KW_FOR TOKEN_LEFT_PARENTHESES opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_RIGHT_PARENTHESES else_stmt
     ;

stmt_list
     : stmt_list stmt
     | stmt
     ;

%%
