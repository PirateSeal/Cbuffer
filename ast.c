//
// Created by tcous on 25/06/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

ast_list_t *ast_list_new_node(ast_t *elem) {
    ast_list_t *newAst = malloc(sizeof(ast_list_t));
    newAst->next = NULL;
    newAst->ast = elem;
    return newAst;
};
ast_list_t * ast_list_new(){
    ast_list_t * new_list = malloc(sizeof(ast_list_t));
    new_list->ast = NULL;
    new_list->next = NULL;
};

ast_list_t *ast_list_add(ast_list_t *list, ast_t *elem) {
    if ( elem == NULL) exit(EXIT_FAILURE);
    ast_list_t *newAst = ast_list_new_node(elem);

    if (list == NULL || list->ast == NULL) list = newAst;
    else {
        ast_list_t *temp = list->next;
        while (temp != NULL) {
            temp = temp->next;
        }
        temp = newAst;
    }
    return newAst;
};

void free_ast_list(ast_list_t *list) {
    if (list != NULL) {
        free_ast(list->ast);
        free_ast_list(list);
        free(list);
    }
}

void free_ast(ast_t *ast) {
    if (ast != NULL) {
        switch (ast->type) {
            case (AST_BINARY):
                free_ast(ast->binary.left);
                free_ast(ast->binary.right);
                break;
            case (AST_UNARY):
                free_ast(ast->unary.operand);
                break;
            case (AST_FUNCTION):
                free_ast_list(ast->function.params);
                free_ast_list(ast->function.stmts);
                break;
            case (AST_FNCALL):
                free(ast->call.name);
                free_ast_list(ast->call.args);
                break;
            case (AST_CONDITION):
                free_ast(ast->branch.condition);
                free_ast(ast->branch.valid);
                free_ast(ast->branch.invalid);
                break;
            case (AST_LOOP):
                free_ast(ast->loop.condition);
                free_ast(ast->loop.stmt);
                break;
            case (AST_DECLARATION):
                free_ast(ast->declaration.lvalue);
                free_ast(ast->declaration.rvalue);
                break;
            case (AST_ASSIGNMENT):
                free_ast(ast->assignment.lvalue);
                free_ast(ast->assignment.rvalue);
                break;
            case (AST_COMPOUND_STATEMENT):
                free_ast_list(ast->compound_stmt.stmts);
                break;
            case (AST_RETURN):
                free_ast(ast->ret.expr);
                break;
            case (AST_VARIABLE):
                free(ast->var.name);
                break;
        }
        free(ast);
    }
}

ast_t *ast_new_integer(long val) {
    ast_t *newAst = malloc(sizeof(ast_t));
    newAst->type = AST_INTEGER;
    newAst->integer = val;
    return newAst;
}

ast_t *ast_new_variable(char *name, ast_type_e type) {
    ast_t *newAst = malloc(sizeof(ast_t));
    newAst->type = AST_VARIABLE;
    newAst->var.type = type;
    newAst->var.name = name;
    return newAst;
}


ast_t *ast_new_binary(ast_binary_e op, ast_t *left, ast_t *right) {
    ast_t *newAst = malloc(sizeof(ast_t));
    newAst->type = AST_BINARY;
    newAst->binary.op = op;
    newAst->binary.right = right;
    newAst->binary.left = left;
    return newAst;
}

ast_t *ast_new_function(char *name, ast_type_e return_type, ast_list_t *params, ast_list_t *stmts) {
    ast_t *newAst = malloc(sizeof(ast_t));
    newAst->type = AST_FUNCTION;
    newAst->function.name = name;
    newAst->function.return_type = return_type;
    newAst->function.params = params;
    newAst->function.stmts = stmts;
    return newAst;
}

ast_t *ast_new_fncall(char *name, ast_list_t *args) {
    ast_t *newAst = malloc(sizeof(ast_t));
    newAst->type = AST_FNCALL;
    newAst->call.name = name;
    newAst->call.args = args;
    return newAst;
}

ast_t *ast_new_comp_stmt(ast_list_t *stmts) {
    ast_t *newAst = malloc(sizeof(ast_t));
    newAst->type = AST_COMPOUND_STATEMENT;
    newAst->compound_stmt.stmts = stmts;
    return newAst;
}

ast_t *ast_new_assignment(ast_t *lvalue, ast_t *rvalue) {
    ast_t *newAst = malloc(sizeof(ast_t));
    newAst->type = AST_ASSIGNMENT;
    newAst->assignment.lvalue = lvalue;
    newAst->assignment.rvalue = rvalue;
    return newAst;
}

ast_t *ast_new_declaration(ast_t *lvalue, ast_t *rvalue) {
    ast_t *newAst = malloc(sizeof(ast_t));
    newAst->type = AST_DECLARATION;
    newAst->declaration.lvalue = lvalue;
    newAst->declaration.rvalue = rvalue;
    return newAst;
}

ast_t *ast_new_condition(ast_t *condition, ast_t *valid, ast_t *invalid) {
    ast_t *newAst = malloc(sizeof(ast_t));
    newAst->type = AST_CONDITION;
    newAst->branch.condition = condition;
    newAst->branch.valid = valid;
    newAst->branch.invalid = invalid;
    return newAst;
};

ast_t *ast_new_loop(ast_t *condition, ast_t *stmt) {
    ast_t *newAst = malloc(sizeof(ast_t));
    newAst->type = AST_LOOP;
    newAst->loop.condition = condition;
    newAst->loop.stmt = stmt;
    return newAst;
}

ast_t *ast_new_return(ast_t *expr){
    ast_t *newAst = malloc(sizeof(ast_t));
    newAst->type = AST_RETURN;
    newAst->ret.expr = expr;
    return newAst;
}
