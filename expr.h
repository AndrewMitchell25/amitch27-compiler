#ifndef EXPR_H
#define EXPR_H

#include "symbol.h"
#include "type.h"

typedef enum {
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_DIV,
	EXPR_MOD,
	EXPR_EXP,
	EXPR_OR,
	EXPR_AND,
	EXPR_VALUE,
	EXPR_NAME,
	EXPR_ASSIGN,
	EXPR_INTEGER_LITERAL,
	EXPR_STRING_LITERAL,
	EXPR_BOOLEAN_LITERAL,
	EXPR_CHAR_LITERAL,
	EXPR_FLOAT_LITERAL,
	EXPR_CALL,
	EXPR_ARG,
	EXPR_LESS,
	EXPR_LESS_EQUAL,
	EXPR_GREATER,
	EXPR_GREATER_EQUAL,
	EXPR_EQUALS_EQUALS,
	EXPR_NOT_EQUALS,
	EXPR_PLUS_PLUS,
	EXPR_MINUS_MINUS,
	EXPR_NEGATIVE,
	EXPR_POSITIVE,
	EXPR_NOT,
	EXPR_SUBSCRIPT,
	EXPR_ARRAY_INIT
	/* many more kinds of exprs to add here */
} expr_t;

struct expr {
	/* used by all kinds of exprs */
	expr_t kind;
	struct expr *left;
	struct expr *right;

	/* used by various leaf exprs */
	const char *name;
	int literal_value;
	float float_literal;
	const char * string_literal;
	struct symbol *symbol;
	int has_parens;
	int level;
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right, int level );

struct expr * expr_create_name( const char *n );
struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_float_literal( float c );
struct expr * expr_create_boolean_literal( int c );
struct expr * expr_create_char_literal( char c );
struct expr * expr_create_string_literal( const char *str );

int expr_evaluate( struct expr *e );
void expr_print( struct expr *e );
void expr_resolve( struct expr *e );
struct type * expr_typecheck(struct expr *e);
struct type *expr_array_init_type(struct expr *e);
int expr_type_error();

#endif
