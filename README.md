
# Encryption–Decryption Application (MAJOR C PROJECT)

This project is a menu-based encryption and decryption program made in C.  
I created it as part of my Major Project for the subject Programming in C.  
The program supports three simple text-based algorithms and runs fully in the terminal.

## Features

- Three algorithms:
  - Caesar Shift Cipher
  - Reverse + Shift Cipher
  - Vigenere-style Cipher
- Works with both number keys and word keys
- Modular code using separate `.c` and `.h` files
- Safe input handling so the program doesn't crash
- Follows the folder structure given in the guidelines

## Folder Structure

C_Encryption_Decryption_App
|
├── src/
│ ├── main.c
│ ├── encrypt.c
│ ├── decrypt.c
│ └── utils.c
|
├── include/
│ ├── main.h
│ ├── encrypt.h
│ ├── decrypt.h
│ └── utils.h
|
├── docs/
│ └── ProjectReport.pdf
|
├── assets/
│ ├── terminal_output.png
│ ├── github_structure.png
│ └── vscode_project_structure.png
|
├── sample_input.txt
└── README.md

## How to Compile

Use GCC:
gcc src/main.c src/utils.c src/encrypt.c src/decrypt.c -Iinclude -o main

## How to Run

.\main

## Sample Input and Output

Input-
HELLO UPES
Algorithm: Caesar
Key: 3

Output-
KHOOR XSHT


## Screenshots

All screenshots  
are kept in the assets folder and also added to the report.
terminal_output.png
terminal_output2.png
github_structure.png
vscode_project_structure.png

## Tools Used
- C language  
- GCC compiler  
- VS Code  
- Git and GitHub  

## Author
K Arya
SAP ID- 590025917
B.Tech CSE, Batch 38  
UPES Dehradun
Faculty- Dr Tanu Singh