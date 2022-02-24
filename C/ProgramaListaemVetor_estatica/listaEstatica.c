/*
PROGRAMA: LISTA ESTATICA - SEM ALOCACAO DINAMICA
AUTOR: MARIA MARCOLINA CARDOSO
Objetivos: 
    Menu Inicial:
    - Cria Lista
    - Limpa Lista
    - Insere no Inicio da Lista
    - Insere no Fim da Lista
    - Remove do Inicio da Lista
    - Remove do Fim da Lista
    - Mostra Lista
    - Ver se esta vazia a Lista
    - Ver se esta cheia a Lista
    - Consulta Valor na Lista
    - Altera Elemento da Lista

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

typedef struct _lista{
    int vetor[10];
    int c; //minha variavel de controle
}Lista;


int main(){

    int choice = 0;
    int num, pos, new;
    Lista lista;   


    // MEU MENU -------------------------------------------------
    do{
        printf ("MEU MENU\n");
        printf("1 - Cria Lista\n");
        printf("2 - Insere no Inicio da Lista\n");
        printf("3 - Insere no Fim da Lista\n");
        printf("4 - Remove do Inicio da Lista\n");
        printf("5 - Remove do Fim da Lista\n");
        printf("6 - Remove do Meio Lista\n");
        printf("7 - Consulta Valor na Lista\n");
        printf("8 - Altera Valor na Lista\n");
        printf("9 - Remove Elemento\n");
        printf("10 - Mostrar Lista\n");
        printf("11 - Ver se eh vazia a Lista\n");
        printf("12 - Limpa Lista\n");
        printf("0 - Sair\n");

            
        scanf("%d", &choice);
        system("cls||clear");

        switch(choice){
            case 1: //Cria lista
                criaLista(&lista);
                break;
            case 2: //addINICIO
                printf("Insira um numero: \n");
                scanf("%i", &num);
                insereInicio(&lista,num);
                break;
            case 3: //addFIM
                printf("Insira um numero: \n");
                scanf("%i", &num);
                insereFinal(&lista,num);
                break;
            case 4: //removeInicio
                removeInicio(&lista);
                break;
            case 5: //removeFim
                removeFim(&lista);
                break;
            case 6: //Remove meio
                printf("Insira a posicao para remocao: \n");
                scanf("%i", &pos);
                removeMeio(&lista, pos);
                break;
            case 7: //Consultar Valor
                printf("Insira um valor para consulta: \n");
                scanf("%i", &num);
                consultaValor(&lista, num);
                break;
            case 8: //Altera Elemento
                printf("Insira o valor para alteracao: \n");
                scanf("%i", &num);
                printf("Insira o novo valor: \n");
                scanf("%i", &new);
                alteraElem(&lista, num, new);
                break;
            case 9: //Remove elemento // como nao tenho outro classificador, estou removendo todos os elementos iguais
                printf("Insira o elemento para remocao: \n");
                scanf("%i", &num);
                removeElem(&lista, num);
                break;
            case 10: //printLista
                printf("\nMINHA LISTA\n");
                imprimeLista(&lista);
                break;
            case 11: //VER SE A LISTA EH VAZIA
                ConsultaVazia(&lista);
                break;
            case 12: //LIMPA LISTA
                limparLista(&lista);
                break;
            default:
                if(choice==0){
                exit(0);
                }
                printf("Digite uma opcao valida!\n");
                break;
            }
    }while(choice!= 0);

    
    return 0;
}
