/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_TOKEN2_H_INCLUDED
# define YY_YY_TOKEN2_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_LEFT_PARENTHESES = 258,
    TOKEN_RIGHT_PARENTHESES = 259,
    TOKEN_LEFT_BRACKET = 260,
    TOKEN_RIGHT_BRACKET = 261,
    TOKEN_LEFT_CURLY_BRACKET = 262,
    TOKEN_RIGHT_CURLY_BRACKET = 263,
    TOKEN_COMMA = 264,
    TOKEN_SEMICOLON = 265,
    TOKEN_COLON = 266,
    TOKEN_PLUS_PLUS = 267,
    TOKEN_MINUS_MINUS = 268,
    TOKEN_EQUALS_EQUALS = 269,
    TOKEN_NOT_EQUALS = 270,
    TOKEN_NOT = 271,
    TOKEN_PLUS = 272,
    TOKEN_MINUS = 273,
    TOKEN_DIVIDE = 274,
    TOKEN_MULTIPLY = 275,
    TOKEN_MOD = 276,
    TOKEN_EXPONENT = 277,
    TOKEN_EQUALS = 278,
    TOKEN_GREATER_EQUAL = 279,
    TOKEN_LESS_EQUAL = 280,
    TOKEN_GREATER = 281,
    TOKEN_LESS = 282,
    TOKEN_AND = 283,
    TOKEN_OR = 284,
    TOKEN_KW_ARRAY = 285,
    TOKEN_KW_AUTO = 286,
    TOKEN_KW_BOOLEAN = 287,
    TOKEN_KW_CHAR = 288,
    TOKEN_KW_ELSE = 289,
    TOKEN_KW_FALSE = 290,
    TOKEN_KW_FLOAT = 291,
    TOKEN_KW_FOR = 292,
    TOKEN_KW_FUNCTION = 293,
    TOKEN_KW_IF = 294,
    TOKEN_KW_INTEGER = 295,
    TOKEN_KW_PRINT = 296,
    TOKEN_KW_RETURN = 297,
    TOKEN_KW_STRING = 298,
    TOKEN_KW_TRUE = 299,
    TOKEN_KW_VOID = 300,
    TOKEN_KW_WHILE = 301,
    TOKEN_ERROR = 302,
    TOKEN_INTEGER = 303,
    TOKEN_FLOAT = 304,
    TOKEN_CHAR = 305,
    TOKEN_STRING = 306,
    TOKEN_IDENTIFIER = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKEN2_H_INCLUDED  */
