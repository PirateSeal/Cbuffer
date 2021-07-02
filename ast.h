//
// Created by tcous on 25/06/2021.
//

#ifndef CBUFFER_AST_H
#define CBUFFER_AST_H

#include <stdbool.h>

typedef enum {
    AST_VOID, AST_INTEGER, AST_BINARY, AST_UNARY, AST_FUNCTION, AST_FNCALL, AST_VARIABLE,
    AST_CONDITION, AST_LOOP, AST_DECLARATION, AST_ASSIGNMENT, AST_COMPOUND_STATEMENT, AST_RETURN
} ast_node_type_e;

typedef enum {
    AST_BINARY_PLUS,
    AST_BINARY_EQUAL,
    AST_BINARY_MINUS,
    AST_BINARY_MODULO,
    AST_BINARY_OR,
    AST_BINARY_AND,
    AST_BINARY_TIMES,
    AST_BINARY_DIVIDE,
    AST_BINARY_NOT,
    AST_BINARY_LOWER,
    AST_BINARY_LOWER_STRICT,
    AST_BINARY_HIGHER_STRICT,
    AST_BINARY_HIGHER
} ast_binary_e;

typedef enum {
    AST_UNARY_PARENTHESIS,
    AST_UNARY_NEGATION,
    AST_UNARY_INCREMENTATION,
    AST_UNARY_DECREMENTATION,
} ast_unary_e;

typedef enum {
    AST_TYPE_INTEGER,
    AST_TYPE_VOID,
    AST_TYPE_UNDEFINED,
} ast_type_e;


typedef struct ast_list {
    struct ast_t *ast;
    struct ast_list *next;
} ast_list_t;

typedef struct ast_t {
    ast_node_type_e type;
    union {
        long integer;
        struct {
            char *name;
            ast_type_e type;
        } var;
        struct {
            ast_binary_e op;
            struct ast_t *left;
            struct ast_t *right;
        } binary;
        struct {
            ast_unary_e op;
            struct ast_t *operand;
        } unary;
        struct {
            char *name;
            ast_list_t *args;
        } call;
        struct {
            char *name;
            ast_type_e return_type;
            ast_list_t *params;
            ast_list_t *stmts;
        } function;
        struct {
            ast_list_t *stmts;
        } compound_stmt;
        struct {
            struct ast_t *lvalue;
            struct ast_t *rvalue;
        } assignment;
        struct {
            struct ast_t *lvalue;
            struct ast_t *rvalue;
        } declaration;
        struct {
            struct ast_t *condition;
            struct ast_t *valid;
            struct ast_t *invalid;
        } branch;
        struct {
            struct ast_t *condition;
            struct ast_t *stmt;
        } loop;
        struct {
            struct ast_t *expr;
        } ret;
    };
} ast_t;


ast_t *ast_new_integer(long val);

ast_t *ast_new_variable(char *name, ast_type_e type);

ast_t *ast_new_binary(ast_binary_e op, ast_t *left, ast_t *right);

ast_t *ast_new_function(char *name, ast_type_e return_type, ast_list_t *params, ast_list_t *stmts);

ast_t *ast_new_fncall(char *name, ast_list_t *args);

ast_t *ast_new_comp_stmt(ast_list_t *stmts);

ast_t *ast_new_assignment(ast_t *lvalue, ast_t *rvalue);

ast_t *ast_new_declaration(ast_t *lvalue, ast_t *rvalue);

ast_t *ast_new_condition(ast_t *condition, ast_t *valid, ast_t *invalid);

ast_t *ast_new_loop(ast_t *condition, ast_t *stmt);

ast_t *ast_new_return(ast_t *expr);

ast_list_t *ast_list_new_node(ast_t *elem);

ast_list_t *ast_list_add(ast_list_t **list, ast_t *elem);

ast_list_t * ast_list_new();

void free_ast(ast_t *ast);

#endif //CBUFFER_AST_H
