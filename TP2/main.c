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
        scanner(entrada);

        Token t = 0;

        while(t != TOKEN_FDT){
            t = get_token();
            printf("Token: %d, Lexema: %s\n", t, get_lexema());
        };
        
        printf("%s", entrada);


    }

    printf("Power off");

return 0;
}
