//
// Created by tcous on 25/06/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "buffer.h"
#include "lexer.h"
#include "ast.h"
#include "symbols.h"

const char *FUNCTION_DEFINITION = "fonction";
const char *TYPE_INTEGER_DEFINITION = "entier";
const char *TYPE_VOID_DEFINITION = "rien";


ast_type_e match_type(char *type) {
    if (strcmp(type, TYPE_INTEGER_DEFINITION) == 0) return AST_TYPE_INTEGER;
    if (strcmp(type, TYPE_VOID_DEFINITION) == 0) return AST_TYPE_VOID;
    return AST_TYPE_UNDEFINED;
}


ast_list_t *analyse_parameters(buffer_t *buffer, symbol_list_t *symbol_list, ast_list_t *params) {
    buf_skipblank(buffer);
    lexer_assert_openbrace(buffer, "ERROR: Expected '(' ");
    buf_lock(buffer);
    buf_skipblank(buffer);
    char next_char = buf_getchar(buffer);
    if (next_char != (')')) {
        buf_rollback_and_unlock(buffer, 1);
        while (1) {
            buf_skipblank(buffer);
            char *type = lexer_getalphanum(buffer);

            ast_type_e ast_type = match_type(type);
            if (ast_type == AST_TYPE_UNDEFINED) exit(EXIT_FAILURE);
            buf_skipblank(buffer);
            char *name = lexer_getalphanum(buffer);


            symbol_t *symbol = sym_search(symbol_list, name);
            if (symbol == NULL) {
                symbol = sym_new(name, ast_type, NULL);
                sym_add(symbol_list, symbol);
            }
            ast_t *new_variable = ast_new_variable(name, ast_type);
            ast_list_add(params, new_variable);

            buf_skipblank(buffer);
            char last_char = buf_getchar(buffer);

            if (last_char != ')' && last_char != ',') exit(EXIT_FAILURE);
            if (last_char == ')') break;
        }
    }
    return params;
}

ast_type_e analyse_return_type(buffer_t *buffer) {
    buf_skipblank(buffer);
    lexer_assert_semicolon(buffer, "ERROR: Expected ':' ");
    char *type = lexer_getalphanum(buffer);
    return match_type(type);

}

ast_list_t *analyse_body_function(buffer_t *buffer, symbol_list_t *symbol_list) {
    buf_skipblank(buffer);
    lexer_assert_openbracket(buffer, "ERROR: Expected '{' ");
    ast_list_t *instructions = ast_list_new();
    char *token = lexer_getalphanum(buffer);
    ast_type_e maybe_type = match_type(token);
    if (maybe_type != AST_TYPE_UNDEFINED) {
        char *name = lexer_getalphanum(buffer);
        symbol_t *symLeft = sym_search(symbol_list, name);
        if (symLeft != NULL) {
            printf("%s is already defined", name);
            exit(EXIT_FAILURE);
        }
        buf_skipblank(buffer);
        char next_char = buf_getchar(buffer);
        if (next_char != ';' && next_char != '=') exit(EXIT_FAILURE);

        if (next_char == '=') {
            char *rvalue = lexer_getalphanum(buffer);
            ast_t *attributes;

            if (isStringNumber(rvalue)) {
                char *useless;
                attributes = ast_new_integer(strtol(rvalue, &useless, 10));
            } else {
                symbol_t *symRight = sym_search(symbol_list, rvalue);
                if (symRight == NULL) {
                    printf("%s is  undefined", rvalue);
                    exit(EXIT_FAILURE);
                }
                attributes = symRight->attributes;
            }
            symbol_t *new_symbol = sym_new(name, maybe_type, attributes);
            sym_add(symbol_list, new_symbol);
            ast_list_add(instructions, ast_new_assignment(ast_new_variable(name, maybe_type), attributes));
            lexer_assert_semicolon(buffer, "ERROR: Expected ';' ");
        } else {
            symbol_t *new_symbol = sym_new(name, maybe_type, NULL);
            sym_add(symbol_list, new_symbol);
            ast_list_add(instructions, ast_new_declaration(ast_new_variable(name, maybe_type), NULL));
        }
    }
}

ast_t *analyse_function(buffer_t *buffer) {
    buf_skipblank(buffer);
    symbol_list_t *symbol_list = sym_list_new();
    ast_list_t *parameters = ast_list_new();

    char *name_function = lexer_getalphanum(buffer);
    ast_list_t *params = analyse_parameters(buffer, symbol_list, parameters);

    /* ast_type_e type = analyse_return_type(buffer);
     if (type == AST_TYPE_UNDEFINED) exit(EXIT_FAILURE);
     ast_list_t *body_function = analyse_body_function(buffer, symbol_list);
     return ast_new_function(name_function, type, params, body_function);*/
}

void parser(buffer_t *buffer) {

    char *first = lexer_getalphanum(buffer);
    if (!strcmp(first, FUNCTION_DEFINITION) == 0) exit(EXIT_FAILURE);
    analyse_function(buffer);


}
