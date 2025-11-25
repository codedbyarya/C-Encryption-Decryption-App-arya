#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "decrypt.h"
#include "encrypt.h"   // for shift_char prototype if needed

// copy of shift_char from encrypt.c, but with opposite shift use
static char shift_char(char ch, int shift) {
    if ('A' <= ch && ch <= 'Z') {
        return (char)('A' + (ch - 'A' + shift + 26) % 26);
    } else if ('a' <= ch && ch <= 'z') {
        return (char)('a' + (ch - 'a' + shift + 26) % 26);
    } else {
        return ch;
    }
}

// Algorithm 1: Caesar cipher decryption (negative shift)
void decrypt_caesar(const char *input, char *output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = shift_char(input[i], -key);
    }
    output[i] = '\0';
}

// Algorithm 2: Reverse + Shift decryption
// Step 1: unshift by -key
// Step 2: reverse again
void decrypt_reverse_shift(const char *input, char *output, int key) {
    int len = (int)strlen(input);
    int i;
    char temp[ MAX_TEXT_LENGTH ];

    // first "unshift"
    for (i = 0; i < len; i++) {
        temp[i] = shift_char(input[i], -key);
    }
    temp[len] = '\0';

    // now reverse back
    for (i = 0; i < len; i++) {
        output[i] = temp[len - 1 - i];
    }
    output[len] = '\0';
}

// Algorithm 3: Vigenere-style decryption
void decrypt_vigenere(const char *input, char *output, const char *key) {
    int text_len = (int)strlen(input);
    int key_len = (int)strlen(key);
    int i, j = 0;

    if (key_len == 0) {
        strcpy(output, input);
        return;
    }

    for (i = 0; i < text_len; i++) {
        char ch = input[i];

        if (isalpha(ch)) {
            char key_ch = key[j % key_len];
            int shift = 0;

            if ('A' <= key_ch && key_ch <= 'Z') {
                shift = key_ch - 'A';
            } else if ('a' <= key_ch && key_ch <= 'z') {
                shift = key_ch - 'a';
            }

            output[i] = shift_char(ch, -shift);
            j++;
        } else {
            output[i] = ch;
        }
    }
    output[text_len] = '\0';
}

