/***
   NAME
     Exercicio_alocacaoDinamica.c
   AUTOR:
     Maria Cardoso - Sept 02, 2021
   PURPOSE
    Guardar 10 nomes simples em um vetor de ponteiros alocado dinamicamente.
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
int Nnome = 3; //quantidade de nomes que desejo utilizar

//Functions
void guardarNomes(char *nome[Nnome][20]); //Funcao para ler nomes escritos pelo usuario
void mostrarNomes(char *nome[Nnome][20]); //Funcao para imprimir os nomes

//Main
void main (){
    int i;
    char *nomes;

    nomes  = (char*)malloc(Nnome*sizeof(char));


    //Aqui alocamos tudo de uma vez
    //Chamo aqui so a funcao mostra nomes. Dentro dela ela chama a guardarNomes.
    guardarNomes(nomes);
    mostrarNomes(nomes);

    free(nomes);
    return 0;
}

void guardarNomes(char *nome[Nnome][20]){ //funcao para guardar nomes

    int i;
    for (i = 0; i < Nnome; i++){
        printf("Digite o nome %i: ", i+1);
        scanf("%[^\n]%*c",nome[i]);
    }
    getchar();
}

void mostrarNomes(char *nome[Nnome][20]){

    int i;
    for (i = 0; i < Nnome; i++){
        printf("Nomes: %s\n",nome[i]);
    }
    printf("\n");
}
