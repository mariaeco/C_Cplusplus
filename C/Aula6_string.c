/*==================================================================
 ====================================================================
                       C Course
                  C - Basic String
 ====================================================================
 ====================================================================*/
#include <stdio.h>

int main(void){

    void concatenarStrings(char string1[], int t1, //t1 eh o tamanho da palavra 1
                           char string2[], int t2,
                           char string3[]);
    char palavra1[]={'B','r','a','s','i','l'};
    char palavra2[]={'-','P','a','i','s'};
    char novaPalavra[11];
    int i;

    /*--------------------------------------------------------
    Outros formatos para definir string:
    char palavra[6]={'B','r','a','s','i','l'};
    char palavra[] = {'B','r','a','s','i','l'};
    char palavra[7] = {"Brasil"}; //o compilador vê: "Brasil\0"
    char palavra[] = {"Brasil"};  //o compilador vê: "Brasil\0"
    char palavra[] = "Brasil";    //o compilador vê: "Brasil\0"
    //Observe que as duas primeiras nao funcionam bem no printf %s, pq ele inclui o caracter nulo (\0) no final.

    printf("%s\n", palavra) //tem que ser %s
    ----------------------------------------------------------*/

    concatenarStrings(palavra1, 6, palavra2,5,novaPalavra);

    for(i=0; i<11;i++){
        printf("%c",novaPalavra[i]);
    }

    printf("\n");
    //scanf("%[^\n]", frase); //lê espaços
    return 0;
}

void concatenarStrings(char string1[], int t1, //t1 eh o tamanho da palavra 1
                       char string2[], int t2,
                       char string3[]){
    int i, j;

    for(i=0; i<t1;i++){
        string3[i]=string1[i];
    }
    for(j=0;j<t2;j++){
        string3[t1+j]=string2[j];
    }

}
