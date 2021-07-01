#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"
#include "lexer.h"
#include "parser.h"


int main() {

    FILE *file = NULL;
    file = fopen("text.txt", "r");
    if (file == NULL)return 1;
    buffer_t *buffer = malloc(sizeof(buffer_t));
    buf_init(buffer, file);
    parser(buffer);

    return 0;
}
