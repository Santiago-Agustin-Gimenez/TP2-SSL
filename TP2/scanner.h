#ifndef SCANNER_H
#define SCANNER_H
#include <stdio.h>
#include <ctype.h>

typedef enum{
    TOKEN_SUMA= 101,        // +
    TOKEN_RESTA= 102,       // -
    TOKEN_MULT= 103,        // *
    TOKEN_DIV= 104,         // /
    TOKEN_EXP= 105,         // ^
    TOKEN_ASIG= 106,        // =
    TOKEN_ASIG_SUMA= 107,   // +=
    TOKEN_ASIG_RESTA= 108,  // -=
    TOKEN_ASIG_MULT= 109,   // *=
    TOKEN_ASIG_DIV= 110,    // /=
    TOKEN_FDT= 111,         // Fin del lexema
    TOKEN_VAR= 112,         // Variable
    TOKEN_CONST= 100,       // Constante

    ERROR= 401
} Token;

void scanner(char* entrada);
Token get_token();
const char* get_lexema();

#endif