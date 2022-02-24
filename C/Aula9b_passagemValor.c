/*==================================================================
 ====================================================================
                       C Course
                 C - Funcao: Passagem por Valor

Observe que ao imprimir, quando passamos por Valor,
a funcao cria uma copia dos valores em outro endereco de memoria
ao terminar a funcao ele descatarda essa copia
 ====================================================================
 ====================================================================*/
#include <stdio.h>

int soma(int x, int y);

int main(){

    int a = 10;
    int b = 20;
    int c;

    puts("###  ANTES DA FUNCAO");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);

    c = soma(a,b);

    puts("\n###  DEPOIS DA FUNCAO");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);

    return 0;
}

int soma(int x, int y){

    int z = x+y;

    puts("\n==> FUNCAO");
    printf("&x = %p, x = %d\n", &x, x);
    printf("&y = %p, y = %d\n", &y, y);
    printf("&z = %p, z = %d\n", &z, z);

    return z;
}

