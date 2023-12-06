
#ifndef DECL_H
#define DECL_H

#include "type.h"
#include "stmt.h"
#include "expr.h"
#include <stdio.h>

struct decl {
	char *name;
	struct type *type;
	struct expr *value;
	struct stmt *code;
	struct symbol *symbol;
	struct decl *next;
	int func_params;
	int func_locals;
};

struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next );
void decl_print( struct decl *d, int indent );
void decl_resolve( struct decl *d );
void decl_typecheck(struct decl *d);
int decl_type_error();
void decl_codegen( FILE * file, struct decl *d );
void decl_array_init_print(FILE * file, struct expr * e);
#endif


