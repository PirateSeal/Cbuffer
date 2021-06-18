#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "buffer.h"

int main() {
    print_backtrace();

    FILE* file;
    file = fopen("text.txt", "r");

    buffer_t* buffer = malloc(sizeof(buffer_t));

    buf_init(buffer, file);
    char c = buf_getchar(buffer);


    return 0;
}
