/*==================================================================
 ====================================================================
                       C Course
                 C - Ponteiros e Arrays de Char


 ====================================================================
 ====================================================================*/
#include <stdio.h>
#include <stdlib.h>


int main(void){

    // para conseguir escrever nomes tenho qye fazer um ponteiro de chars
    // indicando a quantidade de nomes que desejo escrever
    // nao eh possivel assim: char ar[5][20]

    char *ar[5];// array com 5 posicoes
    char *p;

    p = (int *)&ar;// casting para inteiro

    printf("Endereco apontado pelo ponteiro: %i - %p\n", p, p);
    printf("Endereco do ponteiro: %i - %p\n" , &p, &p);
    printf("valor apontado pelo ponteiro %i (lixo pois ainda nao inicializei)\n" , *p);

    ar[0]= "maria";
    ar[1] = "joao";
    ar[2] = "jose";
    ar[3] = "tiago";
    ar[4] = "joana";

    printf("valor apontado de a[1] eh: %s\n" , ar[1]);  //imprime apenas o primeiro
    printf("valor apontado pelo ponteiro eh %s e seu endereco eh %p\n", p, &p[0]);
    printf("valor apontado pelo ponteiro %s e seu endereco eh %p\n" , p[1], &p[1]);
    printf("valor apontado pelo ponteiro %s e seu endereco eh %p\n" , p[2], &p[2]);
    printf("valor apontado pelo ponteiro %s e seu endereco eh %p\n" , p[3], &p[3]);
    printf("valor apontado pelo ponteiro %s e seu endereco eh %p\n" , p[4], &p[4]);

    printf("\nEndereco de ar[0]: %p\n" , &ar[0]);
    printf("Endereco de ar[1]: %p\n" , &ar[1]);
    printf("Endereco de ar[2]: %p\n" , &ar[2]);
    printf("Endereco de ar[3]: %p\n" , &ar[3]);
    printf("Endereco de ar[4]: %p\n" , &ar[4]);
}
