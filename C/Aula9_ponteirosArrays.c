/*==================================================================
 ====================================================================
                       C Course
                 C - Ponteiros e Arrays


 ====================================================================
 ====================================================================*/
#include <stdio.h>

int main(void){

    int ar[5];// array com 5 posicoes
    int *p;
    p = ar;// eh o mesmo que p = ar[0] // aponta para o inicio do array

    printf("Endereco apontado pelo ponteiro: %i - %p\n" , p, p);
    printf("Endereco do ponteiro: %i - %p\n" , &p, &p);
    printf("valor apontado pelo ponteiro %i (lixo pois ainda nao inicializei)\n" , *p);

    ar[0] = 10;
    ar[1] = 20;
    ar[2] = 30;
    ar[3] = 40;
    ar[4] = 50;

    printf("valor apontado pelo ponteiro %i\n" , *p); // imprime apenas o primeiro
    printf("valor apontado pelo ponteiro %i e seu endereco eh %p\n" , p[0], &p[0]);
    printf("valor apontado pelo ponteiro %i e seu endereco eh %p\n" , p[1], &p[1]);
    printf("valor apontado pelo ponteiro %i e seu endereco eh %p\n" , p[2], &p[2]);
    printf("valor apontado pelo ponteiro %i e seu endereco eh %p\n" , p[3], &p[3]);
    printf("valor apontado pelo ponteiro %i e seu endereco eh %p\n" , p[4], &p[4]);

    printf("\nEndereco de ar[0]: %p\n" , &ar[0]);
    printf("Endereco de ar[1]: %p\n" , &ar[1]);
    printf("Endereco de ar[2]: %p\n" , &ar[2]);
    printf("Endereco de ar[3]: %p\n" , &ar[3]);
    printf("Endereco de ar[4]: %p\n" , &ar[4]);
}
