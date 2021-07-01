#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Element {
    char value;
    struct Element *next;
} Element;

typedef struct Stack {
    struct Element *head;
} Stack;


typedef struct Node {
    char value;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Tree {
    struct Node *root;
} Tree;


Node *create_node(char value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void free_node(Node *node) {
    if (node != NULL) {
        free_node(node->left);
        free_node(node->right);
        free(node);
    }
}

void free_tree(Tree *t) {
    if (t != NULL) {
        free_node(t->root);
        free(t);
    }
}

Tree *create_tree() {
    Tree *new_tree = (Tree *) malloc(sizeof(Tree));
    new_tree->root = NULL;
    return new_tree;
}

Element *create_element(char value, Element *next) {
    Element *new_element = (Element *) malloc(sizeof(Element));
    new_element->value = value;
    new_element->next = next;
    return new_element;
}

Stack *create_stack_value(char value) {
    Stack *new_stack = (Stack *) malloc(sizeof(Stack));
    new_stack->head = create_element(value, NULL);
    return new_stack;
}

Stack *create_stack() {
    Stack *new_stack = (Stack *) malloc(sizeof(Stack));
    new_stack->head = NULL;
    return new_stack;
}

void push(Stack *s, char value) {
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
    if(stack != NULL){
        while (stack->head != NULL) {
            Element *popped = pop(stack);
            free(popped);
        }
    }
    free(stack);
}

void print_stack(Stack *s) {
    if (s != NULL) {
        Element *temp = s->head;
        while (temp != NULL) {
            printf("%c \n", temp->value);
            temp = temp->next;
        }
    }
}

int is_prioritised(char c1, char c2) {

    if (c1 >= '0' && c1 <= '9' && c2 >= '0' && c2 <= '9' || (c1 == '\0' && c2 == '\0')) {
        printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
        return 0;
    }

    if (c1 == '\0' || (c1 == '+' && c2 == '*') || c2 >= '0' && c2 <= '9') {
        return -1;
    }

    return 1;
}


Stack *algo_linear_tree(const char *chaine) {
    Stack *pile = create_stack_value('\0');
    Stack *sortie = create_stack();
    int i = 0;
    while (1) {
        if (chaine[i] == '\0' && pile->head->value == '\0') {
            free_stack(pile);
            return sortie;
        }
        char a = pile->head->value;
        char b = chaine[i];
        if (is_prioritised(a, b) == -1) {
            push(pile, b);
            i++;
        } else {
            Element *popped;
            do {
                popped = pop(pile);
                push_element(sortie, popped);
            } while (is_prioritised(pile->head->value, popped->value) == 1);
        }
    }

}

Node *stack_to_node(Stack *pile) {
    if (pile != NULL && pile->head != NULL) {
        Element *popped = pop(pile);
        Node *new_node = create_node(popped->value);

        if (popped->value < '0') {
            new_node->left = stack_to_node(pile);
            new_node->right = stack_to_node(pile);
        }
        free(popped);
        return new_node;
    }
    return NULL;
}

Tree *algo_stack_to_tree(Stack *pile) {
    if (pile != NULL && pile->head != NULL) {
        Tree *tree = create_tree();
        tree->root = stack_to_node(pile);
        return tree;
    }
    return NULL;
}
void print_node_solo(Node* root){
    printf("<%c>", root->value);
    if(root->left != NULL){
        printf(" left:(<%c>)", root->left->value);

    }
     if(root->right != NULL){
        printf(" right:(<%c>)\n", root->right->value);
    }
}

int calcul_node(Node* root){
    if(root != NULL){
        switch(root->value){
            case('*'):
                return calcul_node(root->right)*calcul_node(root->left);
            case('+'):
                return calcul_node(root->right)+calcul_node(root->left);
            case('-'):
                return calcul_node(root->right)-calcul_node(root->left);
            default:
                return root->value - '0';
        }
    }
    return 0;
}

int algo_calcul(Tree* t){
    int result = 0;
    if(t != NULL){
        result = calcul_node(t->root);
    }
    printf("Résultat du calcul : %d", result);
    return result;
}

void print_node_mode(Node *root, char how) {
    if(root != NULL){
        if(how == 'P')printf("%c ", root->value);
        print_node_mode(root->left, how);
        if(how == 'I')printf("%c ", root->value);
        print_node_mode(root->right, how);
        if(how == 'S')printf("%c ", root->value);
    }
}


void print_tree(Tree *t) {
    if (t != NULL) {
        printf("___________________PREFIX_______________________ \n");
        print_node_mode(t->root, 'P');
        printf("\n");
        printf("___________________INFIX________________________ \n");
        print_node_mode(t->root, 'I');
        printf("\n");
        printf("___________________SUFFIX_______________________ \n");
        print_node_mode(t->root, 'S');
        printf("\n");
    }
}

int equation_solver(const char* equation){
    Stack *stack = algo_linear_tree(equation);
    print_stack(stack);

    Tree *tree = algo_stack_to_tree(stack);
    print_tree(tree);

    int result = algo_calcul(tree);
    free_stack(stack);
    free_tree(tree);

    return result;
} 

int main() {
    const char *equation = "1+2*3-4+5+9";
    equation_solver(equation);
    return 0;
}
