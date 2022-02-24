//================================================================
// Descricao: O programa calcula e mostra o Enésimo termo
//            da sequência Fibonacci sem uso de recursividade.
// Fibonacci: eh uma sequencia de numeros definida pela  formula:
//                   Fn = F(n-1) + F(n-2)
// Resultado em: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377...
// Cada termo subsequente corresponde a soma dos dois anteriores, e valores inicais 1,1
// Ou seja: F(2) = 1+1 = 2 = (n-1)+(n-2) = (1)+(1)= 2
//          F(3) = 2+1 = 3 = (n-1)+(n-2) = (2)+(1)= 3
//          F(4) = 3+2 = 5 = (n-1)+(n-2) = (3)+(2)= 5
//          F(5) = 5+3 = 8 = (n-1)+(n-2) = (5)+(3)= 8
//================================================================

//Library
#include <stdio.h>
#include <stdlib.h>

//Functions
int fibonacci(int n);

//Main function
int main(){

    int x;
    int resultado = fibonacci(x); //chamando a funcao

    return 0;
}

int fibonacci(int termo){ //int x serah o enesimo termo

    int i,j, aux, n1=1, n2=1, resultado = 0; //a variavel auxiliar serve par somar n1 e n2 e para guardar o valor
    printf("Digite o termo:\n");
    scanf("%i",&termo);

    if(termo==1||termo==2){
        switch (termo) //usei um switch para praticar, poderia ser um if else.
            {
            case 1 :
            printf("O valor termo 1 eh 1");
            break;

            case 2 :
            printf("O valor termo 2 eh 1");
            break;
            }

    }else{
        printf("Sequencia Fibonacci: 1|1|", resultado);
        for (i= 3; i<=termo;++i){
            aux = n1+n2;
            resultado = aux;
            n2 = n1; //n2 assume o antigo valor de n1
            n1 = aux; //n1 assume o valor de aux

            printf("%i|", resultado);
        }
        printf("\nO valor do termo %i eh %i.\n\n", termo, resultado);
    }

    return resultado;
}

