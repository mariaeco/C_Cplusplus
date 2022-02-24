/***
   NAME
     Exercicio_alocacaoDinamica.c
   AUTOR:
     Maria Cardoso - Sept 02, 2021
   PURPOSE
    Guardar 5 nomes simples em um vetor de ponteiros alocado dinamicamente.
    Regras:
    - alocar tudo dinamicamente
    � Usar uma fun��o para guardar os nomes
    � Usar uma fun��o para mostrar os nomes
    � Lembrar de liberar a mem�ria

    - Aqui aloco todos os strings de uma unica vez!
***/
#include  "stdio.h"
#include <stdlib.h>

//Variaveis Globais
int Nnome = 5; //quantidade de nomes que desejo utilizar

//Functions
void guardarNomes(char **vetNomes); //Funcao para ler nomes escritos pelo usuario: nomes = matriz de nomes, n = numero de nomes
void mostrarNomes(char **vetNomes); //Funcao para imprimir os nomes: nomes = matriz de nomes, n = numero de nomes
void limparMemoria(char **vetNomes);

//Main
int main (){
    int i;
    char **linhas; // cada nome em uma linha

    linhas  = (char**)malloc(Nnome*sizeof(char*)); // alocando as linhas
    // (char**)calloc(Nnome, sizeof(char*)); // usando calloc
    //alocando as colunas (caracteres):
    for (i=0; i<Nnome; i++){
        linhas[i]  = (char*)malloc(sizeof(char));
    }
    if (linhas == NULL){
        printf("Memoria insuficiente.\n");
    exit(1);
    }

    guardarNomes(linhas);
    mostrarNomes(linhas);
    limparMemoria(linhas);

    getchar();
    return 0;
}

void guardarNomes(char **vetNomes){ //funcao para guardar nomes

    int i;
    for (i = 0; i < Nnome; i++){
        printf("Digite o nome %i: ", i+1);
        scanf("%[^\n]%*c",vetNomes[i]);
    }

}

void mostrarNomes(char **vetNomes){

    int i;
    printf("\nNomes digitados\n");
    for (i = 0; i < Nnome; i++){
        printf("Nomes: %s\n",vetNomes[i]);
    }
    printf("\n");
}

void limparMemoria(char **vetNomes){ //funcao para limpar memoria

    int i;
    for (i = 0; i < Nnome; i++){  //    primeiro libero as colunas dentro de cada linha
        free(vetNomes[i]);  
    };

    free(*vetNomes); // agora libero as linhas
    *vetNomes =  NULL; // e faço o ponteiro apontar para NULL

}
