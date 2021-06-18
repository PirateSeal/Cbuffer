#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"
#include "lexer.h"


int main() {

    FILE *file = NULL;
    file = fopen("text.txt", "r");
    if (file == NULL)printf("Oups \n");
    buffer_t *buffer = malloc(sizeof(buffer_t));

    buf_init(buffer, file);
    long l =  lexer_getnumber(buffer);
    printf("%d", l);

    return 0;
}
