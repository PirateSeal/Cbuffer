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

    buf_print(buffer);

    printf("Hello, World!\n");
    return 0;
}
