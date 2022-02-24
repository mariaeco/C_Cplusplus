/***
   NAME
     Exercicio_alocacaoDinamica.c
   AUTOR:
     Maria Cardoso - Sept 02, 2021
   PURPOSE
    Guardar 10 nomes simples sem alocacao dinamica.
    Regras:

***/
#include  "stdio.h"
#include <stdlib.h>

//Variaveis Globais
int Nnome = 3; //quantidade de nomes que desejo utilizar

//Functions
void guardarNomes(char *nome[Nnome][20]);
void mostrarNomes(char *nome[Nnome][20]);

//Main
void main (){
    int i;
    char nome[Nnome];
    int *p;

    //p = (int *)&nome;

    p = (int *)&nome;

    mostrarNomes(nome);

    printf("\n");


    return 0;
}

void guardarNomes(char *nome[][20]){
    int i;
    for (i = 0; i < Nnome; i++){
        printf("Digite o nome %i: ", i+1);
        scanf("%s[^\n]",nome[i]);
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
