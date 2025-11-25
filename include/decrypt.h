#ifndef DECRYPT_H
#define DECRYPT_H

#include "main.h"

// Algorithm 1: Caesar Shift
void decrypt_caesar(const char *input, char *output, int key);

// Algorithm 2: Reverse + Shift
void decrypt_reverse_shift(const char *input, char *output, int key);

// Algorithm 3: Vigenere-style using word key
void decrypt_vigenere(const char *input, char *output, const char *key);

#endif
