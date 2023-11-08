#include "scope.h"
#include "hash_table.h"
#include <stdlib.h>

struct scope *scope;
int level = 0;
int error = 0;

void scope_enter(){
    struct hash_table *h = hash_table_create(0, 0);
    if(scope) {
        struct scope *new_scope = malloc(sizeof(struct scope));
        new_scope->h = h;
        new_scope->prev = scope;
        new_scope->local = 0;
        new_scope->param = 0;
        scope->next = new_scope;
        scope = new_scope;
        level++;
    } else {
        scope = malloc(sizeof(struct scope));
        scope->h = h;
        scope->next = NULL;
        scope->prev = NULL;
        level = 1;
        scope->local = 0;
        scope->param = 0;
    }

}
void scope_exit(){
    struct scope* old_scope = scope;
    scope = old_scope->prev;
    hash_table_delete(old_scope->h);
    free(old_scope);
}

int scope_level(){
    return level;
}

void scope_bind( const char *name, struct symbol *sym ){
    if(sym->kind == SYMBOL_LOCAL) {
        scope->local++;
        sym->which = scope->local;
    } else if(sym->kind == SYMBOL_PARAM) {
        scope->param++;
        sym->which = scope->param;
    }
    if(!hash_table_insert(scope->h, name, sym)) {
        error = 1;
        printf("resolve error: %s already defined\n", name);
    }
}

struct symbol *scope_lookup( const char *name ){
    struct scope *curr = scope;
    while(curr){
        struct symbol *sym = hash_table_lookup(curr->h, name);
        if(sym) {
            printf("%s resolves to ", name);
            symbol_print(sym);
            printf("\n");
            return sym;
        }
        curr = curr->prev;
    }
    error = 1;
    printf("resolve error: %s is not defined\n", name);
    return NULL;
}

struct symbol *scope_lookup_current( const char *name ){
    return hash_table_lookup(scope->h, name);
}

int scope_error() {
    return error;
}