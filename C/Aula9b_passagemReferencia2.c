/*==================================================================
 ====================================================================
                       C Course
                 C - Funcao: Passagem por Referencia

z sera nosso ponteiro
 ====================================================================
 ====================================================================*/
#include <stdio.h>

void soma(int x, int y, int *z);

int main(){

    int a = 10;
    int b = 20;
    int c, *p;

    p = &c;

    puts("###  ANTES DA FUNCAO");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);
    printf("&p = %p, p = %d\n", &p, *p);

    soma(a,b,p);

    puts("\n###  DEPOIS DA FUNCAO");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);
    printf("&p = %p, p = %d\n", &p, *p);

    return 0;
}

void soma(int x, int y, int *z){

    *z = x+y;

    puts("\n==> FUNCAO");
    printf("&x = %p, x = %d\n", &x, x);
    printf("&y = %p, y = %d\n", &y, y);
    printf("&z = %p, z = %d\n", &z, *z);
    printf("&p = %p, p = %d\n", &z, *z);

    return z;
}
