/*FUNCOES
PROGRAMA MULTIARQUIVOS: LISTA ENCADEADA
AUTOR: MARIA MARCOLINA CARDOSO
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

typedef struct no{
    int dado;
    struct no *proximo;
}No;


//Funcao de criacao dos dados
No *criaLista(No *lista){
    system("cls");
    lista = NULL;
    printf("\n\nLista criada com sucesso!\n\n");
    system("pause");

    return lista;
}

//Inserir no inicio da lista
void insereInicio(No **ll, int valor){ // recebera &lista // aqui eh uma passagem por referencia e ja altero aqui e nao apenas no return
    No *novo;
    novo = (No*)malloc(sizeof(No));
    if(!novo) {//verificando se alocou
        printf("Espaco nao armazenado!\n");
    }

    novo->dado = valor;
    novo->proximo = *ll; //aponto para o conteudo apontado por ll
    *ll = novo;
}

//Insere elemento no final da lista
void insereFinal(No **lista, int valor){ // recebera &lista // aqui eh uma passagem por referencia e ja altero aqui e nao apenas no return
    No *aux, *novo;

    novo = (No*)malloc(sizeof(No));
    if(!novo) {//verificando se alocou
        printf("Espaco nao armazenado!\n");
        return;
    }

    novo->dado = valor;
    novo->proximo = NULL; //ultimo no da nossa lista

    if(*lista == NULL){ //se o conteudo da posicao for nulo:lista vazia
        *lista = novo; //se tiver vazia, seu conteudo sera nosso novo no
    }else{
        aux = *lista;
        while(aux->proximo){ //percorro minha lista enquanto proximo for diferente de NULL
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}


void insereMeio(No **lista, int valor, int ant){
    No *aux, *novo;
    
    if(novo) {//verificando se alocou
        novo = (No*)malloc(sizeof(No));
        novo->dado = valor;
        if(*lista==NULL){
            novo->proximo = NULL; //se a lista for fazia, o proximo sera o primeiro q eh nulo
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->dado !=ant && aux->proximo){ //&& aux->proximo existir
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo; //linkei o novo no com a parte final da lista
            aux->proximo = novo;
        }

    }else{
         printf("Espaco nao armazenado!\n");
    }
}


void insereOrdenado(No **lista, int valor){
    No *aux;
    No *novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->dado = valor;
        //a lista esta vazia?
        if(*lista ==  NULL){
            novo->proximo = NULL;
            *lista = novo;
        }else if(novo->dado < (*lista)->dado){ //o conteúdo é o menor?
            novo->proximo = *lista;
            *lista= novo; 
        }else{
            aux = *lista;
            while(aux->proximo && novo->dado > aux->proximo->dado){ 
                //enquanto proximo exister & valor for maior que aux guarda do proximo no, vamos caminhar na nossa lista
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }

    }else{
        printf("Erro ao alocar memoria!\n");
    }

}


No *consultaValor(No **l, int valor){//retorna um numero inteiro
    No *no = NULL;
    No *aux;

    aux = *l;
    //percorrer a lista procurando o elemento
    while(aux && aux->dado != valor){
        aux = aux->proximo; //enquanto o valor nao for encontrado, segue para o proximo
    }
    if(aux){ //aux !=NULL
        no = aux;//no recebe ponteiro para aux
    }
    return no;
}

void alteraElem(No **l, int valor, int new_valor){
    No *no = NULL;
    No *aux;

    aux = *l;
    //percorrer a lista procurando o elemento
    while(aux && aux->dado != valor){
        aux = aux->proximo; //enquanto o valor nao for encontrado, segue para o proximo
    }
    if(aux){ //aux !=NULL
        no = aux;//no recebe ponteiro para aux
        no->dado = new_valor;
        printf("Elemento alterado com sucesso: %d->%d\n\n", valor, no->dado);
    }
}


No *removerElem(No **L, int valor){ //retorna um ponteiro, pois altera
    No *aux;
    No *remover = NULL;// se nao encontrarmos o elemento, retornara nulo
    //vamos percorrer a lista procurando o elemento
    if((*L)->dado == valor){
        remover = *L;
        *L = remover->proximo;
    }else{
        aux = *L;
        while(aux->proximo && aux->proximo->dado != valor){
            aux = aux->proximo;
        }
        if(aux->proximo){
            remover = aux->proximo;
            aux->proximo = remover->proximo;
        }
    }
    return remover;
}



void imprimeLista(No *no){
    printf("\n\tLista: ");
    while(no){
        printf("%d->", no->dado);
        no = no->proximo;
    }
    printf("NULL\n\n");
    system("pause");
}


void limparLista(No **lista){
    No *no, *aux;
    no = *lista;

    while (no != NULL){
        aux = no;
        no = no->proximo;
        free (aux);
    }
    *lista = NULL;
    printf("Lista esvaziada com sucesso\n\n");
    system("pause");
}

void ConsultaVazia(No **lista){
    if(*lista == NULL){
        printf("\nLista Vazia\n");
    }else{
        printf("\nLista iniciada\n");
    }
    system("pause");
}