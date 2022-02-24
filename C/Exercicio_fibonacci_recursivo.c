//================================================================
// Descricao: O programa calcula e mostra o Enésimo termo
//            da sequência Fibonacci COM uso de recursividade.
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
int main() {
    int num;

    printf("\nEntre com o termo que deseja: ");
    scanf("%d", &num);
    printf("\nO %d termo de Fibonacci eh %d", num , fibonacci(num));

    return 0;
}

int fibonacci (int n) {
    if ( n==0) {
        return 0;
    }else if (n==1){
        return 1;
    } else{
        return fibonacci(n-1)+ fibonacci(n-2);
    }
}
