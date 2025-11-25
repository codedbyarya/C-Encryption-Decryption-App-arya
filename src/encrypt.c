#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "encrypt.h"

// helper: shift a single character for Caesar / Vigenere
static char shift_char(char ch, int shift) {
    if ('A' <= ch && ch <= 'Z') {
        return (char)('A' + (ch - 'A' + shift + 26) % 26);
    } else if ('a' <= ch && ch <= 'z') {
        return (char)('a' + (ch - 'a' + shift + 26) % 26);
    } else {
        // leave non-letters unchanged
        return ch;
    }
}

// Algorithm 1: Caesar cipher
void encrypt_caesar(const char *input, char *output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = shift_char(input[i], key);
    }
    output[i] = '\0';
}

// Algorithm 2: Reverse + Shift
// Step 1: reverse the string
// Step 2: shift each letter by key
void encrypt_reverse_shift(const char *input, char *output, int key) {
    int len = (int)strlen(input);
    int i;

    for (i = 0; i < len; i++) {
        char ch = input[len - 1 - i];   // reversed position
        output[i] = shift_char(ch, key);
    }
    output[len] = '\0';
}

// Algorithm 3: Vigenere-style cipher using a word key
void encrypt_vigenere(const char *input, char *output, const char *key) {
    int text_len = (int)strlen(input);
    int key_len = (int)strlen(key);
    int i, j = 0;

    if (key_len == 0) {
        // nothing to do
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

            output[i] = shift_char(ch, shift);
            j++; // only advance key index for letters
        } else {
            output[i] = ch;
        }
    }
    output[text_len] = '\0';
}
