//
// Created by tcous on 25/06/2021.
//
#include "ast.h"

#ifndef CBUFFER_SYMBOLS_H
#define CBUFFER_SYMBOLS_H

typedef struct symbol {
    char *name;
    int type;
    ast_t *attributes;
} symbol_t;

typedef struct symbol_list {
    struct symbol_t *sym;
    struct symbol_list *next;
} symbol_list_t;

symbol_t *sym_new(char *name, int type, ast_t *attributes);

void sym_delete(symbol_t *sym);

void sym_remove(symbol_list_t **list, symbol_t *sym);

void sym_add(symbol_list_t **list, symbol_t *sym);

symbol_t *sym_search(symbol_list_t *list, char *name);

#endif //CBUFFER_SYMBOLS_H
