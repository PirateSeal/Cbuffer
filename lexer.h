//
// Created by Thomas Cousin on 18/06/2021.
//

#ifndef CBUFFER_LEXER_H
#define CBUFFER_LEXER_H

#include "buffer.h"

char * lexer_getalphanum (buffer_t * buffer);

//Cette fonction doit retourner une chaine de caracteres si elle trouve une suite de chiffres et/ou de
//lettres d’au moins 1 caractere.
//Si aucun caractere lu ne correspond, le curseur doit retourner a sa position initiale
//cette fonction effectue un malloc pour creer la chaine de caracteres

char * lexer_getalphanum_rollback(buffer_t * buffer);
//meme principe, mais le curseur doit revenir a sa position initiale systematiquement.

long lexer_getnumber (buffer_t * buffer);
//Cette fonction doit lire des caracteres tant que ce sont des chiffres (le nombre peut commencer par le
//symbole “-”)
//Elle retourne un long qui est la valeur numerique du nombre lu
// Appuyez-vous sur strtol()

#endif //CBUFFER_LEXER_H
