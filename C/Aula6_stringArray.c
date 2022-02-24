/*==================================================================
 ====================================================================
                       C Course
                 C - Arrays de String


 ====================================================================
 ====================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    int i, j;
    char caractere;
    char nomes[5][20];// array com 5 posicoes


    for(i=0; i<5; i++){
        printf("Digite o nome %i: ", i+1);  // nao leh espacos
        scanf("%s[^\n]",nomes[i]);
    }

    for(i=0; i<5; i++){
       printf("Nome %i: %s\n", i+1, nomes[i]);
    }

    return 0;
}
