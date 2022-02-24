/*
PROGRAMA MULTIARQUIVOS: LISTA ENCADEADA
AUTOR: MARIA MARCOLINA CARDOSO
Objetivos: 
    Menu Inicial:
        printf("1 - Cria Lista\n");
        printf("2 - Insere no Inicio da Lista\n");
        printf("3 - Insere no Fim da Lista\n");
        printf("4 - Insere no Meio da Lista\n");
        printf("5 - Insere Ordenado\n");
        printf("6 - Remove Elemento\n");
        printf("7 - Consulta Valor na Lista\n");
        printf("8 - Altera Valor na Lista\n");
        printf("9 - Ver se eh vazia a Lista\n");
        printf("10 - Imprimir Lista\n");
        printf("11 - Limpa Lista\n");
        printf("0 - Sair\n");
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

typedef struct no{
    int dado;
    struct no *proximo;
}No;

typedef struct _lista{
    No *inicio;
    int tam;
}Lista;


int main(){

    int choice = 0;
    int tamanho, num, pos, new;
    Lista lista;
    No *remover, *elemento;
    

    // MEU MENU -------------------------------------------------
    do{
        printf ("MEU MENU\n");
        printf("1 - Cria Lista\n");
        printf("2 - Insere no Inicio da Lista\n");
        printf("3 - Insere no Fim da Lista\n");
        printf("4 - Insere no Meio da Lista\n");
        printf("5 - Insere Ordenado\n");
        printf("6 - Remove Elemento\n");
        printf("7 - Consulta Valor na Lista\n");
        printf("8 - Altera Valor na Lista\n");
        printf("9 - Ver se eh vazia a Lista\n");
        printf("10 - Imprimir Lista\n");
        printf("11 - Limpa Lista\n");
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
                insere_inicio(&lista,num);
                break;
            case 3: //addFIM
                printf("Insira um numero: \n");
                scanf("%i", &num);
                insere_final(&lista,num);
                break;
            case 4://add mo meio
                printf("insira um valor: ");
                scanf("%d",&num);
                printf("insira o valor anterior: ");
                scanf("%d",&pos);//adicionar após
                inserir_meio(&lista, num, pos);
            case 5: //insere ordenado
                printf("insira um valor: ");
                scanf("%d",&num);
                insereOrdenado(&lista, num);
                break;
            case 6: //removeElemento
                printf("insira um valor a remover: ");
                scanf("%d",&num);
                remover = removerElem(&lista, num);
                if(remover){
                    printf("Elemento a ser removido: %d\n", remover->dado);
                    free(remover);
                }else{
                    printf("Elemento inexistente.\n");
                }
                break;
            case 7: //Consultar Valor
                printf("Insira um valor para consulta: \n");
                scanf("%i", &num);
                elemento = consultaValor(&lista, num);
                if(elemento){
                    printf("Elemento encontrado: %d\n", elemento->dado);
                }else{
                    printf("Elemento inexistente.\n");    
                }
                break;
            case 8: //Altera Elemento
                printf("Insira o valor para alteracao: \n");
                scanf("%i", &num);
                printf("Insira o novo valor: \n");
                scanf("%i", &new);
                alteraElem(&lista, num, new);
                break;
            case 9: //VER SE A LISTA EH VAZIA
                ConsultaVazia(&lista);
                break;
            case 10: //printLista
                printf("\nMINHA LISTA\n");
                imprimir(lista);
                break;
            case 11: //LIMPA LISTA
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
