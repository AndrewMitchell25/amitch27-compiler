#include <stdio.h>
#include <stdlib.h>
#include "param_list.h"
#include "type.h"
#include "scope.h"
#include "symbol.h"

struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ){
    struct param_list * p = malloc(sizeof(*p));
    p->name = name;
    p->type = type;
    p->next = next;
    return p;
}

void param_list_print( struct param_list *a ){
    if(!a) return;
    printf("%s: ", a->name);
    type_print(a->type);
    if(a->next) {
        printf(", ");
        param_list_print(a->next);
    }
}

void param_list_resolve(struct param_list *a ){
    if(!a) return;
    a->symbol = symbol_create(SYMBOL_PARAM, a->type, a->name);
    scope_bind(a->name, a->symbol);
    param_list_resolve(a->next);
}