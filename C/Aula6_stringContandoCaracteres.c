/*==================================================================
 ====================================================================
                       C Course
                 C - String contando Caracteres

Lembre que o ultimo caracter em uma string eh o caracter nulo \0
 ====================================================================
 ====================================================================*/
#include <stdio.h>
//Funçoes definidas
int tamanhoString(char string[]);

int main(void){

    char stringUsuario[20];

    printf("Digite uma palavra:\n");
    scanf("%s", stringUsuario);

    tamanhoString(stringUsuario);

    return 0;
}

int tamanhoString(char string[]){

    int numCaracteres = 0;

    while(string[numCaracteres]!='\0'){
        ++numCaracteres;
    }

    printf("O numero de caracteres eh: %i\n", numCaracteres);
}
