/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.bison" /* yacc.c:339  */

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

#line 87 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "token2.h".  */
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

union YYSTYPE
{
#line 24 "parser.bison" /* yacc.c:355  */

     struct decl *decl;
     struct stmt *stmt;
     struct expr *expr;
     struct type *type;
     struct param_list *param_list;
     char *name;

#line 189 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKEN2_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 206 "parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    98,   100,   104,   106,   110,   112,   116,
     118,   122,   124,   126,   128,   130,   132,   134,   138,   140,
     142,   146,   148,   150,   152,   156,   158,   162,   164,   166,
     168,   172,   174,   176,   181,   183,   185,   187,   193,   195,
     197,   199,   201,   212,   216,   221,   232,   232,   237,   239,
     239,   244,   246,   246,   251,   253,   257,   259,   261,   263,
     265,   267,   269,   271,   275,   277,   279,   284,   286,   291,
     293,   293,   297,   302,   304,   309,   311,   311,   315,   317,
     319,   321,   323,   325,   327,   329,   334,   336,   338,   340,
     342,   344,   349,   351,   351,   356,   358
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_LEFT_PARENTHESES",
  "TOKEN_RIGHT_PARENTHESES", "TOKEN_LEFT_BRACKET", "TOKEN_RIGHT_BRACKET",
  "TOKEN_LEFT_CURLY_BRACKET", "TOKEN_RIGHT_CURLY_BRACKET", "TOKEN_COMMA",
  "TOKEN_SEMICOLON", "TOKEN_COLON", "TOKEN_PLUS_PLUS", "TOKEN_MINUS_MINUS",
  "TOKEN_EQUALS_EQUALS", "TOKEN_NOT_EQUALS", "TOKEN_NOT", "TOKEN_PLUS",
  "TOKEN_MINUS", "TOKEN_DIVIDE", "TOKEN_MULTIPLY", "TOKEN_MOD",
  "TOKEN_EXPONENT", "TOKEN_EQUALS", "TOKEN_GREATER_EQUAL",
  "TOKEN_LESS_EQUAL", "TOKEN_GREATER", "TOKEN_LESS", "TOKEN_AND",
  "TOKEN_OR", "TOKEN_KW_ARRAY", "TOKEN_KW_AUTO", "TOKEN_KW_BOOLEAN",
  "TOKEN_KW_CHAR", "TOKEN_KW_ELSE", "TOKEN_KW_FALSE", "TOKEN_KW_FLOAT",
  "TOKEN_KW_FOR", "TOKEN_KW_FUNCTION", "TOKEN_KW_IF", "TOKEN_KW_INTEGER",
  "TOKEN_KW_PRINT", "TOKEN_KW_RETURN", "TOKEN_KW_STRING", "TOKEN_KW_TRUE",
  "TOKEN_KW_VOID", "TOKEN_KW_WHILE", "TOKEN_ERROR", "TOKEN_INTEGER",
  "TOKEN_FLOAT", "TOKEN_CHAR", "TOKEN_STRING", "TOKEN_IDENTIFIER",
  "$accept", "prog", "expr", "expr1", "expr2", "expr3", "expr4", "expr5",
  "expr6", "expr7", "expr8", "expr9", "atomic", "name", "array_subscript",
  "$@1", "opt_expr", "$@2", "opt_expr_list", "$@3", "expr_list", "type",
  "decl", "decl_list", "opt_decl_list", "$@4", "param", "param_list",
  "opt_param_list", "$@5", "stmt", "else_stmt", "opt_stmt_list", "$@6",
  "stmt_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -142

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-142)))

#define YYTABLE_NINF -91

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -44,  -142,    27,    24,   -44,  -142,  -142,  -142,  -142,   -14,
    -142,    36,  -142,  -142,  -142,   -14,  -142,  -142,  -142,     2,
      30,    42,  -142,   207,    30,    30,    49,    49,    49,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,     7,    15,    89,
      37,    39,    29,  -142,  -142,    50,     8,    64,  -142,   -44,
     149,    98,   113,   109,   114,  -142,  -142,  -142,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,  -142,  -142,    30,    30,   -14,   110,   115,
    -142,   121,  -142,   149,   124,   125,    30,    30,    96,    12,
    -142,   149,   128,  -142,  -142,  -142,  -142,    30,  -142,  -142,
      15,    89,    37,    37,    37,    37,    37,    37,    39,    39,
      29,    29,    29,  -142,   133,  -142,  -142,   134,  -142,   -14,
     -44,  -142,   131,    30,    30,   136,   137,  -142,   139,  -142,
    -142,  -142,  -142,   138,  -142,  -142,  -142,   140,   150,  -142,
    -142,    30,  -142,  -142,    30,   178,   135,   145,   149,   141,
     154,    30,    30,   152,  -142,   126,   138,    30,   151,    30,
      30,   153,   158,   142,   149,  -142,   165,   143,   160,   167,
     144,   148,  -142,   149,    30,   178,  -142,   162,   155,    30,
     178,   170,  -142,   178,  -142
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      70,    44,     0,     0,    67,    69,     2,    71,     1,     0,
      68,     0,    57,    58,    59,     0,    56,    60,    61,     0,
      49,     0,    64,     0,     0,     0,     0,     0,     0,    40,
      39,    35,    36,    38,    37,    48,     3,     6,     8,    10,
      17,    20,    24,    26,    30,    33,    34,     0,    50,    76,
      93,     0,     0,    54,     0,    29,    28,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,    52,    49,     0,     0,    73,
      75,     0,    77,     0,     0,     0,    52,    49,    54,    34,
      78,    95,     0,    94,    92,    65,    41,     0,     4,     5,
       7,     9,    15,    16,    14,    12,    13,    11,    18,    19,
      22,    21,    23,    25,     0,    53,    51,     0,    62,     0,
       0,    63,     0,    49,     0,     0,     0,    81,     0,    96,
      66,    55,    43,    46,    72,    74,    82,     0,     0,    80,
      79,     0,    42,    47,    49,     0,     0,     0,     0,     0,
       0,    52,    49,     0,    84,     0,    46,    49,     0,    49,
       0,     0,     0,    81,     0,    45,     0,    82,     0,     0,
      80,    79,    85,     0,    49,     0,    83,     0,     0,    49,
       0,     0,    86,     0,    91
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,   -22,   129,  -142,   120,   132,    69,    43,    18,
     130,    68,  -142,     0,    47,  -142,   -67,  -142,   -79,  -142,
     -65,   -10,    40,   200,  -142,  -142,  -142,    85,  -142,  -142,
    -107,  -141,  -142,  -142,   -77
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   142,   143,    47,    48,   114,   115,
      54,    19,    90,     5,     6,     7,    79,    80,    81,    82,
      91,   155,    92,    93,    94
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       3,    51,    52,    53,     3,    21,   122,   125,     1,   117,
     116,    75,    22,    76,   129,    75,    11,    76,    12,    13,
     126,   116,    14,     9,    15,    23,    16,     8,    88,    17,
      58,    18,   131,    24,   178,     9,    59,    25,   154,   182,
       4,    20,   184,    60,     4,    49,    26,    27,    28,    78,
      89,    72,    24,    53,    67,    68,   137,   172,    69,    70,
      71,    88,    73,    74,    53,    29,   176,   118,   154,   128,
      77,   158,   161,   172,    30,    53,   176,   147,    31,    32,
      33,    34,     1,    89,    29,   162,   116,   110,   111,   112,
     166,    89,   168,    30,    55,    56,    57,    31,    32,    33,
      34,     1,   138,    61,    62,    97,   127,   177,    95,   134,
     108,   109,   181,    63,    64,    65,    66,    96,    97,   146,
      78,   119,    98,   153,   120,   121,    88,   123,   124,    53,
     102,   103,   104,   105,   106,   107,   130,   132,   169,   136,
     133,   156,   128,   141,   159,    89,   139,   140,    89,   127,
     144,   128,    24,   153,   145,   157,    83,   160,   153,   167,
     164,   153,   163,   170,    89,    26,    27,    28,   171,   173,
     174,   175,   179,    89,   183,    89,   -89,   -90,   -88,   100,
      89,    24,   -87,    89,    29,   148,    84,    99,    85,   180,
      86,    87,   101,    30,    26,    27,    28,    31,    32,    33,
      34,     1,   113,   165,    10,   135,     0,     0,     0,     0,
      24,     0,     0,    29,    50,   149,     0,   150,     0,   151,
     152,    24,    30,    26,    27,    28,    31,    32,    33,    34,
       1,     0,     0,     0,    26,    27,    28,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     0,    29,     0,    31,    32,    33,    34,     1,
       0,     0,    30,     0,     0,     0,    31,    32,    33,    34,
       1
};

static const yytype_int16 yycheck[] =
{
       0,    23,    24,    25,     4,    15,    83,    86,    52,    76,
      75,     3,    10,     5,    91,     3,    30,     5,    32,    33,
      87,    86,    36,    11,    38,    23,    40,     0,    50,    43,
      23,    45,    97,     3,   175,    11,    29,     7,   145,   180,
       0,     5,   183,    28,     4,     3,    16,    17,    18,    49,
      50,    22,     3,    75,    17,    18,   123,   164,    19,    20,
      21,    83,    12,    13,    86,    35,   173,    77,   175,    91,
       6,   148,   151,   180,    44,    97,   183,   144,    48,    49,
      50,    51,    52,    83,    35,   152,   151,    69,    70,    71,
     157,    91,   159,    44,    26,    27,    28,    48,    49,    50,
      51,    52,   124,    14,    15,     9,    10,   174,    10,   119,
      67,    68,   179,    24,    25,    26,    27,     4,     9,   141,
     120,    11,     8,   145,     9,     4,   148,     3,     3,   151,
      61,    62,    63,    64,    65,    66,     8,     4,   160,     8,
       6,     6,   164,     5,     3,   145,    10,    10,   148,    10,
      10,   173,     3,   175,     4,    10,     7,     3,   180,     8,
      34,   183,    10,    10,   164,    16,    17,    18,    10,     4,
      10,     4,    10,   173,     4,   175,    34,    34,    34,    59,
     180,     3,    34,   183,    35,     7,    37,    58,    39,    34,
      41,    42,    60,    44,    16,    17,    18,    48,    49,    50,
      51,    52,    72,   156,     4,   120,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    35,     7,    37,    -1,    39,    -1,    41,
      42,     3,    44,    16,    17,    18,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    35,    -1,    48,    49,    50,    51,    52,
      -1,    -1,    44,    -1,    -1,    -1,    48,    49,    50,    51,
      52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    52,    54,    66,    75,    76,    77,    78,     0,    11,
      76,    30,    32,    33,    36,    38,    40,    43,    45,    74,
       5,    74,    10,    23,     3,     7,    16,    17,    18,    35,
      44,    48,    49,    50,    51,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    69,    70,     3,
       7,    55,    55,    55,    73,    64,    64,    64,    23,    29,
      28,    14,    15,    24,    25,    26,    27,    17,    18,    19,
      20,    21,    22,    12,    13,     3,     5,     6,    66,    79,
      80,    81,    82,     7,    37,    39,    41,    42,    55,    66,
      75,    83,    85,    86,    87,    10,     4,     9,     8,    56,
      58,    59,    60,    60,    60,    60,    60,    60,    61,    61,
      62,    62,    62,    63,    71,    72,    73,    69,    74,    11,
       9,     4,    87,     3,     3,    71,    69,    10,    55,    87,
       8,    73,     4,     6,    74,    80,     8,    69,    55,    10,
      10,     5,    67,    68,    10,     4,    55,    69,     7,    37,
      39,    41,    42,    55,    83,    84,     6,    10,    87,     3,
       3,    71,    69,    10,    34,    67,    69,     8,    69,    55,
      10,    10,    83,     4,    10,     4,    83,    69,    84,    10,
      34,    69,    84,     4,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      60,    61,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    64,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    66,    67,    68,    67,    69,    70,
      69,    71,    72,    71,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    75,    76,    76,    77,
      78,    77,    79,    80,    80,    81,    82,    81,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    84,    84,    84,
      84,    84,    85,    86,    85,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     1,     2,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     5,     4,     1,     4,     0,     1,     1,     0,
       1,     1,     0,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     5,     5,     4,     6,     7,     1,     2,     1,
       0,     1,     3,     1,     3,     1,     0,     1,     1,     3,
       3,     2,     3,     9,     5,     7,     7,     3,     3,     2,
       3,     9,     1,     0,     1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 95 "parser.bison" /* yacc.c:1646  */
    { parser_result = (yyvsp[0].decl); }
#line 1440 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 99 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1446 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 101 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[-1].expr); (yyvsp[-1].expr)->kind = EXPR_ARRAY_INIT;}
#line 1452 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 105 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr), 1);}
#line 1458 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 107 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1464 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 111 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr), 2);}
#line 1470 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 113 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1476 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr), 3);}
#line 1482 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 119 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1488 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 123 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr), 4);}
#line 1494 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 125 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_LESS_EQUAL, (yyvsp[-2].expr), (yyvsp[0].expr), 4);}
#line 1500 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 127 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_GREATER, (yyvsp[-2].expr), (yyvsp[0].expr), 4);}
#line 1506 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 129 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_GREATER_EQUAL, (yyvsp[-2].expr), (yyvsp[0].expr), 4);}
#line 1512 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 131 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_EQUALS_EQUALS, (yyvsp[-2].expr), (yyvsp[0].expr), 4);}
#line 1518 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 133 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_NOT_EQUALS, (yyvsp[-2].expr), (yyvsp[0].expr), 4);}
#line 1524 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 135 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1530 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 139 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr), 5);}
#line 1536 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 141 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr), 5);}
#line 1542 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 143 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1548 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 147 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr), 6);}
#line 1554 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 149 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr), 6);}
#line 1560 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 151 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr), 6);}
#line 1566 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 153 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1572 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 157 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_EXP, (yyvsp[-2].expr), (yyvsp[0].expr), 7);}
#line 1578 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 159 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1584 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 163 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_NEGATIVE, (yyvsp[0].expr), 0, 8);}
#line 1590 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 165 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_POSITIVE, (yyvsp[0].expr), 0, 8);}
#line 1596 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 167 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_NOT, (yyvsp[0].expr), 0, 8);}
#line 1602 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 169 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1608 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 173 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_PLUS_PLUS, (yyvsp[-1].expr), 0, 9);}
#line 1614 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 175 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_MINUS_MINUS, (yyvsp[-1].expr), 0, 9);}
#line 1620 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 177 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1626 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 182 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create_name((yyvsp[0].name));}
#line 1632 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 184 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create_integer_literal(atoi(yytext));}
#line 1638 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 186 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create_float_literal(atof(yytext));}
#line 1644 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 188 "parser.bison" /* yacc.c:1646  */
    {char *str = strdup(yytext);
               char *estr = malloc(strlen(str)); 
               string_encode(str, estr);
               (yyval.expr) = expr_create_string_literal(estr);
          }
#line 1654 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 194 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create_char_literal(yytext[0]);}
#line 1660 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 196 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create_boolean_literal(1);}
#line 1666 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 198 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create_boolean_literal(0);}
#line 1672 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 200 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[-1].expr); (yyvsp[-1].expr)->has_parens = 1;}
#line 1678 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 202 "parser.bison" /* yacc.c:1646  */
    {if(!(yyvsp[0].expr)) {
               (yyval.expr) = expr_create(EXPR_SUBSCRIPT, expr_create_name((yyvsp[-4].name)), (yyvsp[-2].expr), 10);
          } else {
               struct expr * curr = (yyvsp[0].expr);
               while(curr->left) {
                    curr = curr->left;
               }
               curr->left = expr_create(EXPR_SUBSCRIPT, expr_create_name((yyvsp[-4].name)), (yyvsp[-2].expr), 10);
               (yyval.expr) = (yyvsp[0].expr);
          }}
#line 1693 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 213 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_CALL, expr_create_name((yyvsp[-3].name)), (yyvsp[-1].expr), 10);}
#line 1699 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 217 "parser.bison" /* yacc.c:1646  */
    {(yyval.name) = strdup(yytext);}
#line 1705 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 222 "parser.bison" /* yacc.c:1646  */
    {if(!(yyvsp[0].expr)) {
               (yyval.expr) = expr_create(EXPR_SUBSCRIPT, 0, (yyvsp[-2].expr), 10);
          } else {
               struct expr * curr = (yyvsp[0].expr);
               while(curr->left) {
                    curr = curr->left;
               }
               curr->left = expr_create(EXPR_SUBSCRIPT, 0, (yyvsp[-2].expr), 10);
               (yyval.expr) = (yyvsp[0].expr);
          }}
#line 1720 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 232 "parser.bison" /* yacc.c:1646  */
    {/* nothing */}
#line 1726 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 233 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = 0;}
#line 1732 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 238 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1738 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 239 "parser.bison" /* yacc.c:1646  */
    {/* nothing */}
#line 1744 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 240 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = 0;}
#line 1750 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 245 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1756 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 246 "parser.bison" /* yacc.c:1646  */
    {/* nothing */}
#line 1762 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 247 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = 0;}
#line 1768 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 252 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_ARG, (yyvsp[0].expr), 0, 10);}
#line 1774 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 254 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_ARG, (yyvsp[-2].expr), (yyvsp[0].expr), 10);}
#line 1780 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 258 "parser.bison" /* yacc.c:1646  */
    {(yyval.type) = type_create(TYPE_INTEGER, 0, 0, 0);}
#line 1786 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 260 "parser.bison" /* yacc.c:1646  */
    {(yyval.type) = type_create(TYPE_BOOLEAN, 0, 0, 0);}
#line 1792 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 262 "parser.bison" /* yacc.c:1646  */
    {(yyval.type) = type_create(TYPE_CHARACTER, 0, 0, 0);}
#line 1798 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 264 "parser.bison" /* yacc.c:1646  */
    {(yyval.type) = type_create(TYPE_FLOAT, 0, 0, 0);}
#line 1804 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 266 "parser.bison" /* yacc.c:1646  */
    {(yyval.type) = type_create(TYPE_STRING, 0, 0, 0);}
#line 1810 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 268 "parser.bison" /* yacc.c:1646  */
    {(yyval.type) = type_create(TYPE_VOID, 0, 0, 0);}
#line 1816 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 270 "parser.bison" /* yacc.c:1646  */
    {(yyval.type) = type_create(TYPE_ARRAY, (yyvsp[0].type), 0, (yyvsp[-2].expr));}
#line 1822 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 272 "parser.bison" /* yacc.c:1646  */
    {(yyval.type) = type_create(TYPE_FUNCTION, (yyvsp[-3].type), (yyvsp[-1].param_list), 0);}
#line 1828 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 276 "parser.bison" /* yacc.c:1646  */
    {(yyval.decl) = decl_create((yyvsp[-3].name), (yyvsp[-1].type), 0, 0, 0);}
#line 1834 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 278 "parser.bison" /* yacc.c:1646  */
    {(yyval.decl) = decl_create((yyvsp[-5].name), (yyvsp[-3].type), (yyvsp[-1].expr), 0, 0);}
#line 1840 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 280 "parser.bison" /* yacc.c:1646  */
    {(yyval.decl) = decl_create((yyvsp[-6].name), (yyvsp[-4].type), 0, (yyvsp[-1].stmt), 0);}
#line 1846 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 285 "parser.bison" /* yacc.c:1646  */
    {(yyval.decl) = (yyvsp[0].decl);}
#line 1852 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 287 "parser.bison" /* yacc.c:1646  */
    {(yyvsp[-1].decl)->next = (yyvsp[0].decl); (yyval.decl) = (yyvsp[-1].decl);}
#line 1858 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 292 "parser.bison" /* yacc.c:1646  */
    {(yyval.decl) = (yyvsp[0].decl);}
#line 1864 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 293 "parser.bison" /* yacc.c:1646  */
    {/* nothing */}
#line 1870 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 294 "parser.bison" /* yacc.c:1646  */
    {(yyval.decl) = 0;}
#line 1876 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 298 "parser.bison" /* yacc.c:1646  */
    {(yyval.param_list) = param_list_create((yyvsp[-2].name), (yyvsp[0].type), 0);}
#line 1882 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 303 "parser.bison" /* yacc.c:1646  */
    {(yyval.param_list) = (yyvsp[0].param_list);}
#line 1888 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 305 "parser.bison" /* yacc.c:1646  */
    {(yyval.param_list) = (yyvsp[-2].param_list); (yyvsp[-2].param_list)->next = (yyvsp[0].param_list);}
#line 1894 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 310 "parser.bison" /* yacc.c:1646  */
    {(yyval.param_list) = (yyvsp[0].param_list);}
#line 1900 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 311 "parser.bison" /* yacc.c:1646  */
    {/* nothing */}
#line 1906 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 312 "parser.bison" /* yacc.c:1646  */
    {(yyval.param_list) = 0;}
#line 1912 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 316 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), 0, 0, 0, 0, 0, 0);}
#line 1918 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 318 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_RETURN, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0);}
#line 1924 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 320 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0);}
#line 1930 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 322 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0);}
#line 1936 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 324 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_STANDING_BLOCK, 0, 0, 0, 0, (yyvsp[-1].stmt), 0, 0);}
#line 1942 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 326 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), 0, 0);}
#line 1948 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 328 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-2].expr), 0, (yyvsp[0].stmt), 0, 0);}
#line 1954 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 330 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-4].expr), 0, (yyvsp[-2].stmt), (yyvsp[0].stmt), 0);}
#line 1960 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 335 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-4].expr), 0, (yyvsp[-2].stmt), (yyvsp[0].stmt), 0);}
#line 1966 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 337 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_RETURN, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0);}
#line 1972 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 339 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0);}
#line 1978 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 341 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0);}
#line 1984 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 343 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_BLOCK, 0, 0, 0, 0, (yyvsp[-1].stmt), 0, 0);}
#line 1990 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 345 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), 0, 0);}
#line 1996 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 350 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 2002 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 351 "parser.bison" /* yacc.c:1646  */
    {/* nothing */}
#line 2008 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 352 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = 0;}
#line 2014 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 357 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 2020 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 359 "parser.bison" /* yacc.c:1646  */
    {(yyvsp[-1].stmt)->next = (yyvsp[0].stmt); (yyval.stmt) = (yyvsp[-1].stmt);}
#line 2026 "parser.c" /* yacc.c:1646  */
    break;


#line 2030 "parser.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 362 "parser.bison" /* yacc.c:1906  */

