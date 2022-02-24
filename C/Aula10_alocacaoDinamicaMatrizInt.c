/***
   NAME
     Exercicio_alocacaoDinamica.c
   AUTOR:
     Maria Cardoso - Sept 02, 2021
   PURPOSE
    Guardar nxn numeros simples em um vetor de ponteiros alocado dinamicamente.
    Regras:
    - alocar tudo dinamicamente
    – Usar uma função para guardar os nomes
    – Usar uma função para mostrar os nomes
    – Lembrar de liberar a memória

    - Aqui aloco todos os strings de uma unica vez!
***/
#include  "stdio.h"
#include <stdlib.h>

//Variaveis Globais
int Ncols = 3; //quantidade de nomes que desejo utilizar
int nLin = 3;

//Functions
void guardarNumeros(int **matriz); //Funcao para ler numeros escritos pelo usuario
void mostrarNumeros(int **matriz); 
void limparMemoria(int **matriz);

//Main
int main (){
    int i;
    int **matriz; // cada nome em uma lunha

    matriz  = (int**)malloc(nLin*sizeof(int*)); // alocando as linhas
    //alocando as colunas (caracteres):
    for (i=0; i<nLin; i++){
        matriz[i] = (int*)malloc(Ncols*sizeof(int));
    }
    if (matriz == NULL){
        printf("Memoria insuficiente.\n");
    exit(1);
    }

    //Aqui alocamos tudo de uma vez
    guardarNumeros(matriz);
    mostrarNumeros(matriz);
    limparMemoria(matriz);

    return 0;
}

void guardarNumeros(int **matriz){ //funcao para guardar numeros

    int i, j;
    for (i = 0; i < nLin; i++){
        for(j = 0; j < Ncols; j++){
            printf("Digite o numero [%i][%i]: ", i+1, j+1);
            scanf("%i",&matriz[i][j]);
            printf("\n");
        }
    }

}

void mostrarNumeros(int **matriz){

    int i, j;
    printf("\nNumeros digitados\n");
    for (i = 0; i < nLin; i++){
        for(j = 0; j < Ncols; j++){
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
}

void limparMemoria(int **matriz){ //funcao para limpar memoria

    // essa eh a melhor pratica de desalocacao de memoria

    int i;
    for (i = 0; i < nLin; i++){  //    primeiro libero as colunas dentro de cada linha
        free(matriz[i]);  
    };

    free(*matriz); // agora libero as linhas
    *matriz =  NULL; // e faço o ponteiro apontar para NULL
    printf("\n");
}
