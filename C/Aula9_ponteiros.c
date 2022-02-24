/*==================================================================
 ====================================================================
                       C Course
                 C - Ponteiros Aula 1


 ====================================================================
 ====================================================================*/
#include <stdio.h>

int  main (void){

    int x, y;
    int *ponteiro;

    x = 10;
    y = 3;
    ponteiro = &x; //meu ponteiro eh igual ao endereco de memoria de meu x;


    printf("O endereco de x: %i (usando i - endereco em Inteiro)\n", &x);
    printf("O endereco de x: %p (usando p - endereco em Hexadecimal)\n", &x); //sempre que peço endereços uso %p e nao %i
    printf("O endereco de y: %i (usando i)\n", &y);
    printf("O endereco de y: %p (usando p)\n", &y);
    printf("O valor de x: %i\n\n", x);

    printf("O endereco do ponteiro: %i (usando i - endereco em Inteiro)\n", &ponteiro);
    printf("O endereco do ponteiro: %p (usando p - endereco em Hexadecimal)\n", &ponteiro);
    printf("O endereco apontado por p: %i (usando i - endereco em Inteiro)\n", ponteiro);
    printf("O endereco apontado por p: %p (usando p - endereco em Hexadecimal)\n", ponteiro);
    printf("O valor apontado por p: %i", *ponteiro);

    printf("\n\nMudando o valor de x via ponteiro (*p+1): %i\n",*ponteiro+1);



    return 0;

}
