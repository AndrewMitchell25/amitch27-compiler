#include <stdio.h>
#include <stdlib.h>
#include "decl.h"
#include "expr.h"
#include "type.h"
#include "stmt.h"
#include "indent.h"
#include "symbol.h"
#include "scope.h"

struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next ) {
    struct decl * d = malloc(sizeof(*d));
    d->name = name;
    d->type = type;
    d->value = value;
    d->code = code;
    d->next = next;
    return d;
}

void decl_print( struct decl *d, int indent ) {
    if(!d) return;
    print_indent(indent);
    printf("%s: ", d->name);
    type_print(d->type);
    if(d->value) {
        printf(" = ");
        if(d->value->kind == EXPR_ARG) {
            printf("{");
            expr_print(d->value);
            printf("}");
        } else {
            expr_print(d->value);
        }
        printf(";");
    } else if(d->code) {
        printf(" = {\n");
        stmt_print(d->code, indent + 1);
        print_indent(indent);
        printf("}\n");
    } else {
        printf(";");
    }
    printf("\n");
    decl_print(d->next, indent);

}

void decl_resolve( struct decl *d ) { 
    if(!d) return;
    if(scope_level() == 0) {
        scope_enter();
    }
    symbol_t kind = scope_level() > 1 ? SYMBOL_LOCAL : SYMBOL_GLOBAL;
    d->symbol = symbol_create(kind,d->type,d->name);
    expr_resolve(d->value);
    scope_bind(d->name, d->symbol);
    if(d->code) {
        scope_enter();
        param_list_resolve(d->type->params);
        scope_enter();
        stmt_resolve(d->code);
        scope_exit();
        scope_exit();
    }
    decl_resolve(d->next);
}
