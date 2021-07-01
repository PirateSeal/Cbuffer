#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ast.h"

typedef struct Element {
    ast_t *value;
    struct Element *next;
} Element;

typedef struct Stack {
    struct Element *head;
} Stack;

Element *create_element(ast_t *value, Element *next) {
    Element *newElement = malloc(sizeof(Element));
    newElement->value = value;
    newElement->next = NULL;
    return newElement;
}

Stack *create_stack() {
    Stack *new_stack = (Stack *) malloc(sizeof(Stack));
    new_stack->head = NULL;
    return new_stack;
}

void push(Stack *s, ast_t *value) {
    if (s != NULL) {
        Element *new_value = create_element(value, s->head);
        s->head = new_value;
    }
}

void push_element(Stack *s, Element *element) {
    if (s != NULL) {
        element->next = s->head;
        s->head = element;
    }
}

Element *pop(Stack *s) {
    if (s != NULL) {
        Element *tempElement = s->head;
        if (s->head != NULL) {
            Element *tempNext = tempElement->next;
            s->head = tempNext;
            return tempElement;
        }
    }
    return NULL;
}

void free_stack(Stack *stack) {
    if (stack != NULL) {
        while (stack->head != NULL) {
            Element *popped = pop(stack);
            free_ast(popped->value);
            free(popped);
        }
    }
    free(stack);
}

int is_prioritised(ast_t *ast1, ast_t *ast2) {
    if (ast1->type == AST_VOID || ast2->type == AST_INTEGER ||
        (ast1->binary.op == AST_BINARY_PLUS && ast2->binary.op == AST_BINARY_TIMES)) {
        return -1;
    }

    return 1;
}

Stack *algo_linear_tree(ast_list_t *list) {
    Stack *pile = create_stack();
    Stack *sortie = create_stack();

    ast_list_t *temp = list;

    while (1) {
        if (temp == NULL && pile->head == NULL) {
            free_stack(pile);
            return sortie;
        }
        ast_t *a = pile->head->value;
        ast_t *b = temp->ast;
        if (is_prioritised(a, b) == -1) {
            push(pile, b);
            temp = temp->next;
        } else {
            Element *popped;
            do {
                popped = pop(pile);
                push_element(sortie, popped);
            } while (is_prioritised(pile->head->value, popped->value) == 1);
        }
    }

}

ast_t *stack_to_node(Stack *pile) {
    if (pile != NULL && pile->head != NULL) {
        Element *popped = pop(pile);
        ast_t *temp = NULL;
        ast_t *curr = popped->value;
        if (curr->type == AST_UNARY && curr->unary.op == AST_UNARY_PARENTHESIS) {
            temp = curr->unary.operand;
            free(curr);
            curr = temp;
        }
        if (curr->type == AST_BINARY) {
            if (curr->binary.right == NULL) {
                curr->binary.right = stack_to_node(pile);
            }
            if (curr->binary.left == NULL) {
                curr->binary.left = stack_to_node(pile);
            }
        }
        free(popped);
        return curr;
    }
    return NULL;
}
