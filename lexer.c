//
// Created by Thomas Cousin on 18/06/2021.
//
#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "lexer.h"
#include "ctype.h"

char *lexer_getop(buffer_t *buffer) {
    char c = buf_getchar(buffer);
    if(!isop(c)) return NULL;
    buf_lock(buffer);
    char c2 = buf_getchar(buffer);
    char *op = malloc(sizeof(char) * 3);
    op[0] = c;
    if (isop(c2)) {
        op[1] = c2;
        op[2] = '\0';
    } else {
        buf_rollback(buffer, 1);
        op[1] = '\0';
    }
    buf_unlock(buffer);
    printf("[%s]\n", op);
    return op;
}

void lexer_assert(buffer_t* buffer, char chr, char *msg){
    buf_skipblank(buffer);
    char c = buf_getchar(buffer);
    if (c != chr) {
        printf("%s -> got %s instead", msg, c);
        exit(EXIT_FAILURE);
    }
}
void lexer_assert_simplechar(buffer_t *buffer, char chr, char *msg) {
    lexer_assert(buffer, chr, msg);
}

void lexer_assert_twopoints(buffer_t *buffer, char *msg) {
    lexer_assert(buffer, ':', msg);

}

void lexer_assert_newline(buffer_t *buffer, char *msg) {
    lexer_assert(buffer, '\n', msg);

}

void lexer_assert_semicolon(buffer_t *buffer, char *msg) {
    lexer_assert(buffer, ';', msg);

}

void lexer_assert_openbrace(buffer_t *buffer, char *msg) {
    lexer_assert(buffer, '(', msg);

}

void lexer_assert_closebrace(buffer_t *buffer, char *msg) {
    lexer_assert(buffer, ')', msg);

}

void lexer_assert_openbracket(buffer_t *buffer, char *msg) {
    lexer_assert(buffer, '{', msg);
};

void lexer_assert_closebracket(buffer_t *buffer, char *msg) {
    lexer_assert(buffer, '}', msg);
};

void lexer_assert_equalsign(buffer_t *buffer, char *msg) {
    lexer_assert(buffer, '=', msg);
};

void lexer_assert_blank(buffer_t *buffer, char *msg) {
    char c = buf_getchar(buffer);
    if (!ISBLANK(c)) {
        printf("%s", msg);
        exit(EXIT_FAILURE);
    }
};

char *lexer_getalphanum(buffer_t *buffer) {
//Cette fonction doit retourner une chaine de caracteres si elle trouve une suite de chiffres et/ou de
//lettres d’au moins 1 caractere.
//Si aucun caractere lu ne correspond, le curseur doit retourner a sa position initiale
//cette fonction effectue un malloc pour creer la chaine de caracteres
    size_t count = 0;
    char c;
    buf_lock(buffer);
    do {
        c = buf_getchar(buffer);
        count++;
    } while (isalnum(c) && !ISBLANK(c));
    char *chaine = NULL;
    if (count > 1 || isalnum(c)) {
        chaine = malloc(sizeof(char) * count);
        buf_rollback_and_unlock(buffer, count);
        buf_getnchar(buffer, chaine, count-1);
        chaine[count - 1] = '\0';
    } else {
        buf_rollback_and_unlock(buffer, 1);
    }
    return chaine;
};

char *lexer_getalphanum_rollback(buffer_t *buffer) {
//meme principe, mais le curseur doit revenir a sa position initiale systematiquement.

    size_t count = 0;
    char c;
    buf_lock(buffer);
    do {
        c = buf_getchar(buffer);
        count++;
    } while (isalnum(c) && !ISBLANK(c));
    char *chaine = NULL;
    if (count > 1 || isalnum(c)) {
        chaine = malloc(sizeof(char) * count);
        buf_rollback(buffer, count);
        buf_getnchar(buffer, chaine, count);
        chaine[count - 1] = '\0';
    }
    buf_rollback_and_unlock(buffer, count);
    return chaine;
}

long lexer_getnumber(buffer_t *buffer) {
//Cette fonction doit lire des caracteres tant que ce sont des chiffres (le nombre peut commencer par le
//symbole “-”)
//Elle retourne un long qui est la valeur numerique du nombre lu
// Appuyez-vous sur strtol()
    char *osef;
    char first = buf_getchar(buffer);
    int isPositive = first == '-' ? -1 : 1;
    char c[10];
    int size = 0;
    char c2 = buf_getchar(buffer);
    if (isPositive == 1) {
        c[size] = first;
        size++;
    }
    while (isdigit(c2)) {
        c[size] = c2;
        c2 = buf_getchar(buffer);
        size++;
    }
    long number = strtol(c, &osef, 10);
    return number * isPositive;
}


bool isalphanum(char chr) {
    return isalnum(chr);
};

bool isnumber(char chr) {
    return isdigit(chr);
};

bool isStringNumber(char* chr) {
    bool isCorrect = true;
    size_t length = strlen( chr );
    for( int i=0; i<length; i++ ) {
        if ( ! isdigit( chr[i] ) ) {
            isCorrect = false;
        }
    }
    return isCorrect;
}

bool isop(char chr) {
    return chr == '!' ||
           chr == 'E' || chr == 'T' ||
           chr == 'O' || chr == 'U' ||
           chr == '+' || chr == '-' ||
           chr == '%' || chr == '/' ||
           chr == '*' || chr == '<' ||
           chr == '>' || chr == '=';
};
