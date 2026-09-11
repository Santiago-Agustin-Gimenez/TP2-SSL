#include "scanner.h"

int main(){

    char entrada[100];

    while(1){

        printf(">");

        char* lexema = fgets(entrada, sizeof(entrada), stdin);

        if(lexema == NULL){
            break;
        }
        

        
        printf("%s", entrada);

    }

    printf("Power off");

return 0;
}
