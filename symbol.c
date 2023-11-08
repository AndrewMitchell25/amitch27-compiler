#include "symbol.h"
#include <stdlib.h>
#include <stdio.h>
#include "expr.h"

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name ) {
    struct symbol *s = malloc(sizeof(*s));
    s->kind = kind;
    s->type = type;
    s->name = name;
    s->which = 0;
    return s;
}

void symbol_print(struct symbol *s){
    if(s->kind == SYMBOL_GLOBAL) {
        printf("global %s", s->name);
    } else if(s->kind == SYMBOL_LOCAL) {
        printf("local %d", s->which);
    } else {
        printf("param %d", s->which);
    }
}