
#include "scanner.h"

static char* caracter_apuntado = NULL;

static char buffer[256];

void scanner(char* caracter){
    caracter_apuntado = caracter;
}

const char* get_lexema(){
    return buffer;
}
Token get_token(){

    int estado=0; //estado inicial
    int i=0;
    buffer[0] = '\0';

    // saltear espacios en blanco previos al próximo token
    while (*caracter_apuntado != '\0' && isspace((unsigned char)*caracter_apuntado)) {
        caracter_apuntado++;
    }

    while(1){

        char c = *caracter_apuntado;

        int proximo_estado = estado;   /* si no cambia, seguimos en el mismo estado */
        int token_final = -1;          /* -1 = todavía no hay token final            */
        int consumir = 0;              /* si hay que avanzar caracter_apuntado       */

        switch (estado) {

            case 0: /* estado inicial */
                if (isalpha((unsigned char)c))        { proximo_estado = 1; consumir = 1; }
                else if (isdigit((unsigned char)c))   { proximo_estado = 2; consumir = 1; }
                else if (c == '.')                    { proximo_estado = 4; consumir = 1; }
                else if (c == '+')                    { proximo_estado = 5; consumir = 1; }
                else if (c == '-')                    { proximo_estado = 6; consumir = 1; }
                else if (c == '*')                    { proximo_estado = 7; consumir = 1; }
                else if (c == '/')                    { proximo_estado = 8; consumir = 1; }
                else if (c == '^')                    { token_final = TOKEN_EXP;  consumir = 1; }
                else if (c == '=')                    { token_final = TOKEN_ASIG; consumir = 1; }
                else if (c == '\0')                   { token_final = TOKEN_FDT;  consumir = 1; }
                else                                   { token_final = ERROR;      consumir = 1; }
                break;

            case 1: /* letra detectada: armando identificador */
                if (isalpha((unsigned char)c) || isdigit((unsigned char)c)) {
                    proximo_estado = 1; consumir = 1;
                } else {
                    token_final = TOKEN_VAR; consumir = 0;
                }
                break;

            case 2: /* dígito detectado: armando parte entera */
                if (isdigit((unsigned char)c))      { proximo_estado = 2; consumir = 1; }
                else if (c == '.')                  { proximo_estado = 3; consumir = 1; }
                else                                 { token_final = TOKEN_CONST; consumir = 0; }
                break;

            case 3: /* ya hay al menos un dígito y se vio el punto: parte fraccionaria */
                if (isdigit((unsigned char)c))      { proximo_estado = 3; consumir = 1; }
                else if (c == '.')                  { token_final = ERROR; consumir = 1; } /* segundo punto */
                else                                 { token_final = TOKEN_CONST; consumir = 0; }
                break;

            case 4: /* punto sin dígitos previos: falta al menos un dígito */
                if (isdigit((unsigned char)c))      { proximo_estado = 3; consumir = 1; }
                else                                 { token_final = ERROR; consumir = 1; } /* punto aislado */
                break;

            case 5: /* se vio '+': suma o += */
                if (c == '=')                       { token_final = TOKEN_ASIG_SUMA; consumir = 1; }
                else                                 { token_final = TOKEN_SUMA; consumir = 0; }
                break;

            case 6: /* se vio '-': resta o -= */
                if (c == '=')                       { token_final = TOKEN_ASIG_RESTA; consumir = 1; }
                else                                 { token_final = TOKEN_RESTA; consumir = 0; }
                break;

            case 7: /* se vio '*': mult o *= */
                if (c == '=')                       { token_final = TOKEN_ASIG_MULT; consumir = 1; }
                else                                 { token_final = TOKEN_MULT; consumir = 0; }
                break;

            case 8: /* se vio '/': div o /= */
                if (c == '=')                       { token_final = TOKEN_ASIG_DIV; consumir = 1; }
                else                                 { token_final = TOKEN_DIV; consumir = 0; }
                break;

            default:
                token_final = ERROR; consumir = 1;
                break;
        }

        if (consumir && c != '\0') {
            if (i < (int)sizeof(buffer) - 1) {
                buffer[i++] = c;
                buffer[i] = '\0';
            }
            caracter_apuntado++;
        }

        if (token_final != -1) {
            return (Token) token_final;
        }

        estado = proximo_estado;
    }
}