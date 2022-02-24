/*==================================================================
 ====================================================================
                       C Course
                 C - Comparando Strings
 ====================================================================
 ====================================================================*/
#include <stdio.h>
//Funçoes definidas
_Bool stringsIguais(char s1[], char s2[]); //_Bool = booleana

int main(void){


    char string1[10],string2[10];

    printf("Digite a primeira palavra:\n");
    scanf("%s", &string1);
    printf("Digite a segunda palavra:\n");
    scanf("%s", &string2);

    if(stringsIguais(string1,string2)){
       printf("Sao iguais :)\n");
    }else {
       printf("Nao sao iguais :(\n");
    };

    system("pause");
    return 0;
}

_Bool stringsIguais(char s1[], char s2[]){

    int i=0;

    while(s1[i]==s2[i] && s1[i]!='\0' && s2[i]!='\0'){
        ++i;
    }

    if(s1[i]== '\0' && s2[i]=='\0'){
        return 1;
    }else{
        return 0;
    }

}
