//
// Created by tcous on 25/06/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

void enqueueAst(ast_t *ast, ast_list_t *list) {
    if (ast != NULL) {
        ast_list_t *newAst = malloc(sizeof(ast_list_t));
        newAst->next = NULL;
        newAst->ast = ast;
        if (list == NULL) list = newAst;
        else {
            ast_list_t *temp = list->next;
            while (temp != NULL) {
                temp = temp->next;
            }
            temp = newAst;
        }
    }
}
