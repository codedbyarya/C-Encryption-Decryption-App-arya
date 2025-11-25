#ifndef ENCRYPT_H
#define ENCRYPT_H

#include "main.h"

// Algorithm 1: Caesar Shift
void encrypt_caesar(const char *input, char *output, int key);

// Algorithm 2: Reverse + Shift
void encrypt_reverse_shift(const char *input, char *output, int key);

// Algorithm 3: Vigenere-style using word key
void encrypt_vigenere(const char *input, char *output, const char *key);

#endif
