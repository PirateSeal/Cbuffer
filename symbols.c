//
// Created by tcous on 25/06/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbols.h"

symbol_t *sym_new(char *name, int type, ast_t *attributes) {
    symbol_t *new_symbol = malloc(sizeof(symbol_t));
    if (new_symbol == NULL) exit(EXIT_FAILURE);
    new_symbol->name = name;
    new_symbol->type = type;
    new_symbol->attributes = attributes;
    return new_symbol;
};

symbol_list_t *symbol_list_new_node(symbol_t *sym) {
    symbol_list_t *newSymList = malloc(sizeof(symbol_list_t));
    newSymList->next = NULL;
    newSymList->sym = sym;
    return newSymList;
};

void sym_delete(symbol_t *sym) {
    if (sym != NULL) {
        free_ast(sym->attributes);
        free(sym);
    }
};

void sym_add(symbol_list_t **list, symbol_t *sym) {
    if (list == NULL || sym == NULL) exit(EXIT_FAILURE);
    symbol_list_t *newSymList = symbol_list_new_node(sym);
    if ((*list)->sym == NULL) *list = newSymList;
    else {
        symbol_list_t *temp = (*list)->next;
        while (temp != NULL) {
            temp = temp->next;
        }
        temp = newSymList;
    }
};


void sym_remove(symbol_list_t **list, symbol_t *sym) {
    if (list == NULL || sym == NULL) exit(EXIT_FAILURE);
    symbol_list_t *temp = (*list);

    if (temp == NULL)return;

    if (temp->sym == sym) {
        sym_delete(sym);
        symbol_list_t *temp2 = temp->next;
        (*list) = temp2;
        free(temp);
    } else {
        while (temp->next != NULL || temp->next->sym == sym) {
            temp = temp->next;
        }
        if (temp->next != NULL) {
            sym_delete(temp->next->sym);
            symbol_list_t *saveNext = temp->next->next;
            free(temp->next);
            temp->next = saveNext;
        }
    }
};

symbol_t *sym_search(symbol_list_t *list, char *name) {
    if (list == NULL || name == NULL)return NULL;
    symbol_t *sym = list->sym;
    if (strcmp(sym->name, name) == 0) return sym;
    return sym_search(list->next, name);
};
