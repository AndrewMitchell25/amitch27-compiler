#ifndef SCOP_H
#define SCOP_H

#include "symbol.h"
#include "hash_table.h"

struct scope {
    struct hash_table *h;
    struct scope *next;
    struct scope *prev;
    int local;
    int param;
    const char * func_name;
};

void scope_enter();
void scope_exit();
int scope_level();
void scope_bind( const char *name, struct symbol *sym );
struct symbol *scope_lookup( const char *name );
struct symbol *scope_lookup_current( const char *name );
int scope_get_error();
int scope_get_params();
int scope_get_locals();

#endif