#include <stdio.h>
#include <string.h>
#include "utils.h"

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* discard extra characters */
    }
}

int read_int(void) {
    int value;
    int result;

    while (1) {
        result = scanf("%d", &value);
        if (result == 1) {
            clear_input_buffer();
            return value;
        } else {
            printf("Invalid number. Please try again: ");
            clear_input_buffer();
        }
    }
}

void read_line(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}
