/*==================================================================
 ====================================================================
                       C Course
                 C - OrdenacaoVetor
 ====================================================================
 ====================================================================*/
#include <stdio.h>
//Funções
void ordemCrescente(int vetor[],int n);

int main(void){


    int n;

    printf("Digite a quantidade de numeros que precisa ordenar: ");
    scanf("%i", &n);

    int vetor[n];
    int i;


    for (i=0; i<=n-1; ++i){
        printf("Digite o termo %i: ",i+1);
        scanf("%i", &vetor[i]);
    }
    printf("\nValores digitados:\n");
    for (i=0; i<=n-1; ++i){
        printf("%i ", vetor[i]);
    }

    ordemCrescente(vetor, n);
    return 0;
}

void ordemCrescente(int vetor[], int n){ // esse nao eh o formato mais eficiente, mas eh mais didatico

    int i, j, temporaria;

    for(i=0; i<n; ++i){ //comparando todos os numeros par-a-par.
        for(j=i+1; j<n;++j){
            if(vetor[i]>vetor[j]){
                temporaria = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temporaria;
            }
        }
    }
    printf("\n\nValores ordenados:\n");
    for (i=0; i<=n-1; ++i){
        printf("%i ", vetor[i]);
    }
}
