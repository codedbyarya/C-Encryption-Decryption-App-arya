#include <stdio.h>
#include <string.h>

#include "main.h"
#include "utils.h"
#include "encrypt.h"
#include "decrypt.h"

void show_main_menu(void) {
    printf("\n===== ENCRYPTION - DECRYPTION APP =====\n");
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void show_algorithm_menu(void) {
    printf("\nSelect algorithm:\n");
    printf("1. Caesar Shift Cipher\n");
    printf("2. Reverse + Shift Cipher\n");
    printf("3. Vigenere-style Cipher (word key)\n");
    printf("Enter your choice: ");
}

int main(void) {
    int running = 1;

    char input[MAX_TEXT_LENGTH];
    char output[MAX_TEXT_LENGTH];
    char word_key[MAX_KEY_LENGTH];
    int menu_choice, algo_choice, numeric_key;

    printf("Welcome to the Encryption–Decryption Application!\n");

    while (running) {
        show_main_menu();
        menu_choice = read_int();

        switch (menu_choice) {
            case 1: // Encrypt
                show_algorithm_menu();
                algo_choice = read_int();

                printf("Enter text to encrypt (max %d characters):\n", MAX_TEXT_LENGTH - 1);
                read_line(input, MAX_TEXT_LENGTH);

                if (algo_choice == 1 || algo_choice == 2) {
                    printf("Enter numeric key (e.g., 3): ");
                    numeric_key = read_int();
                } else if (algo_choice == 3) {
                    printf("Enter word key (no spaces, max %d characters): ", MAX_KEY_LENGTH - 1);
                    read_line(word_key, MAX_KEY_LENGTH);
                }

                switch (algo_choice) {
                    case 1:
                        encrypt_caesar(input, output, numeric_key);
                        break;
                    case 2:
                        encrypt_reverse_shift(input, output, numeric_key);
                        break;
                    case 3:
                        encrypt_vigenere(input, output, word_key);
                        break;
                    default:
                        printf("Invalid algorithm choice.\n");
                        continue;
                }

                printf("\nEncrypted text:\n%s\n", output);
                break;

            case 2: // Decrypt
                show_algorithm_menu();
                algo_choice = read_int();

                printf("Enter text to decrypt (max %d characters):\n", MAX_TEXT_LENGTH - 1);
                read_line(input, MAX_TEXT_LENGTH);

                if (algo_choice == 1 || algo_choice == 2) {
                    printf("Enter numeric key used during encryption: ");
                    numeric_key = read_int();
                } else if (algo_choice == 3) {
                    printf("Enter word key used during encryption: ");
                    read_line(word_key, MAX_KEY_LENGTH);
                }

                switch (algo_choice) {
                    case 1:
                        decrypt_caesar(input, output, numeric_key);
                        break;
                    case 2:
                        decrypt_reverse_shift(input, output, numeric_key);
                        break;
                    case 3:
                        decrypt_vigenere(input, output, word_key);
                        break;
                    default:
                        printf("Invalid algorithm choice.\n");
                        continue;
                }

                printf("\nDecrypted text:\n%s\n", output);
                break;

            case 3:
                printf("Exiting... Thank you for using the app.\n");
                running = 0;
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
