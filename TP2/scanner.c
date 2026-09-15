
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

    while(1){

        char c = *caracter_apuntado;

        switch (estado){ 
            case 0:
                /* code */
                break;
            case 1:
                /* code */
                break;
            case 2:
                /* code */
                break;
            case 3:
                /* code */
                break;
            case 4:
                /* code */
                break;
            case 5:
                /* code */
                break;
            case 6:
                /* code */
                break;
            case 7:
                /* code */
                break;
            case 8:
                /* code */
                break;
            default:
                break;
        }
    }

}