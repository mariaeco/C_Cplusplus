 /*==================================================================
 ====================================================================
                C Course
        C - Types of Variables
        Para rodar basta remober os comentarios
 ====================================================================
 ====================================================================*/
#include <stdio.h>
#include <stdbool.h> // para interpretar booleanas

int main(){

/*     // tratando caracteres e palavras -------------------------
      //Recebe apenas uma letra
      printf("---------------- CHAR -------------------\n");
      char variableChar;
      printf("Char sao caracteres (letras, numeros tambem podem ser caracters):\n");
      printf("Digite uma letra: ");
      scanf("%c", &variableChar);
      printf("%c\n", variableChar); // observe que com essa funcao se voce digitar um nome, ela captura apenas a primeira letra

      //Recebe palavras
      char nomeChar[10];
      printf("Digite uma palavra: ");
      scanf("%s", &nomeChar);// observe que nesse caso para imprimir a palavra eu utilizo %s (de string)
      printf("%s\n", nomeChar);
*/

      //Booleanos -----------------------------------------------
/*
      printf("---------------BOOLEANAS--------------------\n");

      bool varBool = 'true';
      printf("Observe que voce escreve 'true' e aparece um inteiro:\n");
      printf("%i\n", varBool); */

    // observe abaixo q o scanf nao recebe booleana
/*
    bool varTest;
    printf("\nDigite que qualquer valor que digitar resultara em lixo:\n");
    scanf("\n%s", &varTest);
    printf("%i\n", varTest); // se cololocar %s dah erro
    // como resolver isso? Pensar mais na frente.
*/
    //LONG INT -----------------------------------------------
/*    printf("--------------- LONG INT --------------------\n");

    long int Area_Lake;
    printf("\nDigite numero inteiro muito grande (ex.:2187341) :\n");
    scanf("\n%i", &Area_Lake);
    printf("%i\n", Area_Lake);
    printf("\nVeja que agora foi ok!!\n");*/

    //FLOAT AND DOUBLE
    float varFloat = 10.02;
    double varDouble = 10.11234;
    printf("\n float: %f\ndouble: %f",varFloat,varDouble);

    printf("\nDigite um float com muitas casas decimais para float:");
    scanf("\n%f", &varFloat);
    printf("\nDigite um float com muitas casas decimais para double:");
    scanf("\n%lf", &varDouble);
    printf("Veja a diferenca:\nFloat:%f\nDouble: %f\n", varFloat,varDouble);
    return 0;
}
