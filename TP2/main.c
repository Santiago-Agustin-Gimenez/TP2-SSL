#include "scanner.h"

int main(){

    char entrada[100];

    while(1){

        printf(">");

        char* ingreasado = fgets(entrada, sizeof(entrada), stdin);
        //el main captura toda la frase ingresada

        if(ingreasado == NULL){
            break;
        }
        
        //el main le entrega al scanner un puntero a la frase ingresada
        scanner(entrada);

        Token t;

        while(t != TOKEN_FDT){//

            printf("Token: %d, Lexema: %s\n", t, get_lexema());

        };
        
        printf("%s", entrada);

    }

    printf("Power off");

return 0;
}
