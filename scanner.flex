%{
    #include "token2.h"
    #include "encoder.h"
    #include <stdlib.h>
    #define YYLMAX 255
    
%}

%array
%option nounput
%option noinput
%option yylineno

%%

\(                                    {return TOKEN_LEFT_PARENTHESES;}
\)                                    {return TOKEN_RIGHT_PARENTHESES;}
\[                                    {return TOKEN_LEFT_BRACKET;}
\]                                    {return TOKEN_RIGHT_BRACKET;}
\{                                    {return TOKEN_LEFT_CURLY_BRACKET;}
\}                                    {return TOKEN_RIGHT_CURLY_BRACKET;}
,                                     {return TOKEN_COMMA;}
;                                     {return TOKEN_SEMICOLON;}
:                                     {return TOKEN_COLON;}

\+\+                                  {return TOKEN_PLUS_PLUS;}
--                                    {return TOKEN_MINUS_MINUS;}
==                                    {return TOKEN_EQUALS_EQUALS;}
!=                                    {return TOKEN_NOT_EQUALS;} 
!                                     {return TOKEN_NOT;}

\+                                    {return TOKEN_PLUS;}
-                                     {return TOKEN_MINUS;}
\/                                    {return TOKEN_DIVIDE;}
\*                                    {return TOKEN_MULTIPLY;}
%                                     {return TOKEN_MOD;}
\^                                    {return TOKEN_EXPONENT;}
=                                     {return TOKEN_EQUALS;}

>=                                    {return TOKEN_GREATER_EQUAL;}
\<=                                   {return TOKEN_LESS_EQUAL;}
>                                     {return TOKEN_GREATER;}
\<                                    {return TOKEN_LESS;}

&&                                    {return TOKEN_AND;}
\|\|                                  {return TOKEN_OR;}

array                                 {return TOKEN_KW_ARRAY;}
auto                                  {return TOKEN_KW_AUTO;}
boolean                               {return TOKEN_KW_BOOLEAN;}
char                                  {return TOKEN_KW_CHAR;}
else                                  {return TOKEN_KW_ELSE;}
false                                 {return TOKEN_KW_FALSE;}
float                                 {return TOKEN_KW_FLOAT;}
for                                   {return TOKEN_KW_FOR;}
function                              {return TOKEN_KW_FUNCTION;}
if                                    {return TOKEN_KW_IF;}
integer                               {return TOKEN_KW_INTEGER;}
print                                 {return TOKEN_KW_PRINT;}
return                                {return TOKEN_KW_RETURN;}
string                                {return TOKEN_KW_STRING;}
true                                  {return TOKEN_KW_TRUE;}
void                                  {return TOKEN_KW_VOID;}
while                                 {return TOKEN_KW_WHILE;}

[0-9]*                         {
                                        //check if the integer is too long
                                        long int l = strtol(yytext, 0, 10);
                                        if(l >= 9223372036854775807 || l < -9223372036854775807) {
                                            fprintf(stderr, "Integer exceeds 64 bits\n");
                                            return TOKEN_ERROR;
                                        }
                                        return TOKEN_INTEGER;
                                      }
([0-9]*\.[0-9]+)|([0-9]*(\.[0-9]+)?(e|E)[+-]?[0-9]+) {return TOKEN_FLOAT;}
'(.|\\.|\\0x..?)'                     {char c = '0'; 
                                        int res = char_decode(yytext, &c); 
                                        if(res){
                                            sprintf(yytext, "%c", c); 
                                            return TOKEN_CHAR;
                                        } else {
                                            fprintf(stderr, "Scan Error: %s is not a valid character\n", yytext);
                                            return TOKEN_ERROR;
                                        }
                                      }  

(\"((\\\")|[^\"])*\")                 {char s[255]; 
                                        int res = string_decode(yytext, s); 
                                        if(res){
                                            sprintf(yytext, "%s", s);
                                            return TOKEN_STRING;
                                        } else {
                                            fprintf(stderr, "Scan Error: %s is not a valid string\n", yytext);
                                            return TOKEN_ERROR;
                                        }
                                      }
\"                                    {fprintf(stderr, "Invalid String\n"); return TOKEN_ERROR;}
[a-zA-Z_][a-zA-Z0-9_]*                {return TOKEN_IDENTIFIER;}
(\/\*([^*]|(\*+([^*\/])))*\*+\/)|(\/\/[^\n]*) {/*Eat up comments*/}
\/\*                                  {fprintf(stderr, "Invalid Comment\n"); return TOKEN_ERROR;}

(\ |\t|\r|\n)                         {/*white space*/}

.                                     {fprintf(stderr, "Scan Error: %s is not valid.\n", yytext); return TOKEN_ERROR;}


%%

int yywrap() {return 1;}

