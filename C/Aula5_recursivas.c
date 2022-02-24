/*==================================================================
 ====================================================================
                       C Course
                 C - Funcao Recursiva
 ====================================================================
 ====================================================================*/
#include <stdio.h>


int main(){

    int fatorial(int x); // minha funcao
    int numero, resultado;

    printf("Digite um numero inteiro: ");
    scanf("%i", &numero);

    resultado = fatorial(numero);

    printf("O fatorial eh %i\n\n", resultado);

    system("pause");
    return 0;
}

int fatorial(int x){

    int resultado;

    if(x==0){
        resultado = 1;
    } else{
        resultado = x*fatorial(x-1);
    }

    return resultado;
}
