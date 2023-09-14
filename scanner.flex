%{
    #include "token.h"
    #include "encoder.h"
    #include <stdlib.h>
    int line_count = 1;
    #define YYLMAX 255
    
%}

%array

%%

\(                                    {return LEFT_PARENTHESES;}
\)                                    {return RIGHT_PARENTHESES;}
\[                                    {return LEFT_BRACKET;}
\]                                    {return RIGHT_BRACKET;}
\{                                    {return LEFT_CURLY_BRACKET;}
\}                                    {return RIGHT_CURLY_BRACKET;}
,                                     {return COMMA;}
;                                     {return SEMICOLON;}
:                                     {return COLON;}

\+\+                                  {return PLUS_PLUS;}
--                                    {return MINUS_MINUS;}
==                                    {return EQUALS_EQUALS;}
!=                                    {return NOT_EQUALS;} 
!                                     {return NOT;}

\+                                    {return PLUS;}
-                                     {return MINUS;}
\/                                    {return DIVIDE;}
\*                                    {return MULTIPLY;}
%                                     {return MOD;}
\^                                    {return EXPONENT;}
=                                     {return EQUALS;}

>=                                    {return GREATER_EQUAL;}
\<=                                   {return LESS_EQUAL;}
>                                     {return GREATER;}
\<                                    {return LESS;}

&&                                    {return AND;}
\|\|                                  {return OR;}

array                                 {return KW_ARRAY;}
auto                                  {return KW_AUTO;}
boolean                               {return KW_BOOLEAN;}
char                                  {return KW_CHAR;}
else                                  {return KW_ELSE;}
false                                 {return KW_FALSE;}
float                                 {return KW_FLOAT;}
for                                   {return KW_FOR;}
function                              {return KW_FUNCTION;}
if                                    {return KW_IF;}
integer                               {return KW_INTEGER;}
print                                 {return KW_PRINT;}
return                                {return KW_RETURN;}
string                                {return KW_STRING;}
true                                  {return KW_TRUE;}
void                                  {return KW_VOID;}
while                                 {return KW_WHILE;}

(\+|-)?[0-9]*                         {
                                        //check if the integer is too long
                                        long int l = strtol(yytext, 0, 10);
                                        if(l >= 9223372036854775807 || l < -9223372036854775807) {
                                            fprintf(stderr, "Integer exceeds 64 bits\n");
                                            return ERROR;
                                        }
                                        return INTEGER;
                                      }
([0-9]*\.[0-9]+)|([0-9]*(\.[0-9]+)?(e|E)[+-]?[0-9]+) {return FLOAT;}
'(.|\\.|\\0x..?)'                     {char c = '0'; 
                                        int res = char_decode(yytext, &c); 
                                        if(res){
                                            sprintf(yytext, "%c", c); 
                                            return CHAR;
                                        } else {
                                            fprintf(stderr, "Scan Error: %s is not a valid character\n", yytext);
                                            return ERROR;
                                        }
                                      }  

(\"((\\\")|[^\"])*\")                 {char s[255]; 
                                        int res = string_decode(yytext, s); 
                                        if(res){
                                            sprintf(yytext, "%s", s);
                                            return STRING;
                                        } else {
                                            fprintf(stderr, "Scan Error: %s is not a valid string\n", yytext);
                                            return ERROR;
                                        }
                                      }
\"                                    {fprintf(stderr, "Invalid String\n"); return ERROR;}
[a-zA-Z_][a-zA-Z0-9_]*                {return IDENTIFIER;}
(\/\*([^*]|(\*+([^*\/])))*\*+\/)|(\/\/[^\n]*) {/*Eat up comments*/}
\/\*                                  {fprintf(stderr, "Invalid Comment\n"); return ERROR;}

(\ |\t|\r)                            {/*white space*/}
\n                                    {line_count += 1;}

.                                     {fprintf(stderr, "Scan Error: %s is not valid.\n", yytext); return ERROR;}

<<EOF>>                               {return EOF;}

%%

int yywrap() {return 1;}

