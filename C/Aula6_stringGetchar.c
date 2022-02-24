/*==================================================================
 ====================================================================
                       C Course
                 C - String GetChar

o Getchar permite a leitura de espaços e quantas palavras forem
necessarias para o usuario entrar.
Essa funcao funciona melhor com o scanf: aula stringScanfEspaco.c
 ====================================================================
 ====================================================================*/
#include <stdio.h>
//Funçoes definidas

int main(void){

    char linha[100];//
    char caractere;
    int i = 0;

    do{
        caractere = getchar();//getchar pega caractere por caractere e joga na variavel caractere
        linha[i] = caractere;
        ++i;
    }while(caractere =! '\n');//\n eh o enter que o usuario digita

    linha[i-1]='\0'; //adiciona o caractere nulo na linha, pois o getchar nao adiciona
                     //isso eh necessario para o print

    printf("%s\n", linha);

    system("pause");
    return 0;
}
