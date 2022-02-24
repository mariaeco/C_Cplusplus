/***
   NAME
     Aula10_alocacaoDinamicaStructureEx2.c
   AUTOR:
     Maria Cardoso - Sept 08, 2021
   PURPOSE
    Usar alocacao dinamica com structures
    Exemplo 2
***/

/// AINDA NAO TERMINEI ESSE
#include <stdio.h>
#include <stdlib.h>

#define MAXIMO_DE_PASSAGEIROS 200

struct cadastroPassageiros{
    char nome[30];
    char identidade[12];
    char numeroDoBilhete[10];
};


int main(void){

    struct cadastroPassageiros *listaDeEspera,*ptrPassageiro;
    unsigned int numeroDePassageiros;struct cadastroPassageiros

    printf("Digite o numero maximo de passageiros na lista de espera:\n");
    scanf("%i", &numeroDePassageiros);

    listaDeEspera = malloc(numeroDePassageiros*sizeof(tPassageiro));

    if (listaDeEspera == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }

     /* Um string (vetor de caracteres) é um ponteiro, por isto a ausência do & no uso da função scanf */
    printf("\nEntre com o nome ->");


    int i;
    for (i = 0; i < numeroDePassageiros; i++){
        printf("Digite o nome %i: ", i+1);
        scanf("%s",listaDeEspera[i].nome);
    }

   // printf("Entre com o salario ->");
   // scanf("%f", &p->salario);

}
