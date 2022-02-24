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

    - Aqui eu faco a alocacao de cada string individualmente, nao eh legal,
    pois nao garante que sejam alocados todos sequencialmente
***/
#include  "stdio.h"
#include <stdlib.h>

//Variaveis Globais
int Nnome = 10; //quantidade de nomes que desejo utilizar

//Functions
void guardarNomes(char *nome[Nnome][20]); //Funcao para ler nomes escritos pelo usuario
void mostrarNomes(char *nome[Nnome][20]); //Funcao para imprimir os nomes

//Main
void main (){
    int i;
    char **nomes;

    nomes = malloc(sizeof(char*)*Nnome);//alocando dinamicamente tamanho para 10 strings
    for(i=0;i<10;i++){ //alocando dinamicamente cada string
        nomes[i]=malloc(sizeof(char)*20);
    } //alocando dinamicamente cada string nao eh legal, pois nao garante que estarao sequenciadas na memoria

    //Chamo aqui so a funcao mostra nomes. Dentro dela ela chama a guardarNomes.
    mostrarNomes(nomes);

    // Liberando cada string usado
    for(i=0;i<10;i++) //Percorre o "Vetor"
        free(nomes[i]); //Libera a String
    free(nomes);
    return 0;
}

void guardarNomes(char *nome[][20]){ //funcao para guardar nomes

    int i;
    for (i = 0; i < Nnome; i++){
        printf("Digite o nome %i: ", i+1);
        scanf("%[^\n]%*c",nome[i]);
    }

    printf("\n");
}

void mostrarNomes(char *nome[][20]){
    int i;
    guardarNomes(nome);
    for (i = 0; i < Nnome; i++){
        printf("Nomes: %s\n",nome[i]);
    }
    printf("\n");
}
