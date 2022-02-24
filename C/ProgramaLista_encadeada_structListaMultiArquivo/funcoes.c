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

typedef struct _lista{
    No *inicio;
    int tam;
}Lista;


//Funcao de criacao dos dados
void criaLista(Lista *lista){
    system("cls");
    lista->inicio = NULL;
    lista->tam = 0;
    printf("\n\nLista criada com sucesso!\n\n");
    system("pause");

}

void insere_inicio(Lista *ll, int valor){ // recebera &lista // aqui eh uma passagem por referencia e ja altero aqui e nao apenas no return
    No *novo;
    novo = (No*)malloc(sizeof(No));

    if(novo) {//verificando se alocou
        novo->dado = valor;
        novo->proximo = ll->inicio; //aponto para o conteudo apontado por ll
        ll->inicio = novo;
        ll->tam++; //incrementando o campo tamanho
    }else{
        printf("Espaco nao armazenado!\n");
    }
}

void insere_final(Lista *lista, int valor){ // recebera &lista // aqui eh uma passagem por referencia e ja altero aqui e nao apenas no return
    No *aux, *novo;

    novo = (No*)malloc(sizeof(No));
    if(novo) {//verificando se alocou
        novo->dado = valor;
        novo->proximo = NULL; //ultimo no da nossa lista

        if(lista->inicio == NULL){ //se o conteudo da posicao for nulo:lista vazia
            lista->inicio = novo; //se tiver vazia, seu conteudo sera nosso novo no
        }else{
            aux = lista->inicio;
            while(aux->proximo){ //percorro minha lista enquanto proximo for diferente de NULL
                aux = aux->proximo;
            }
        aux->proximo = novo;
        }
        lista->tam++;
    }else{
        printf("Espaco nao armazenado!\n");
    }
}

void inserir_meio(Lista *lista, int valor, int ant){
    No *aux, *novo;
    
    if(novo) {//verificando se alocou
        novo = (No*)malloc(sizeof(No));
        novo->dado = valor;
        if(lista->inicio == NULL){
            novo->proximo = NULL; //se a lista for fazia, o proximo sera o primeiro q eh nulo
            lista->inicio = novo;
        }else{
            aux = lista->inicio;
            while(aux->dado !=ant && aux->proximo){ //&& aux->proximo existir
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo; //linkei o novo no com a parte final da lista
            aux->proximo = novo;
        }
        lista->tam++;

    }else{
         printf("Espaco nao armazenado!\n");
    }
}

void imprimir(Lista lista){
    No *no = lista.inicio;

    printf("\n\tLista Tamanho %d: ", lista.tam);
    while(no){
        printf("%d->", no->dado);
        no = no->proximo;
    }
    printf("NULL\n\n");
    system("pause");
}

void insereOrdenado(Lista *lista, int valor){
    No *aux;
    No *novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->dado = valor;
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }else if(novo->dado < lista->inicio->dado){
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }else{
            aux = lista->inicio;
            while(aux->proximo && novo->dado > aux->proximo->dado){ 
                //enquanto proximo exister & valor for maior que aux guarda do proximo no, vamos caminhar na nossa lista
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;

    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

void ConsultaVazia(Lista *lista){
    if(lista->inicio == NULL){
        printf("\nLista Vazia\n");
    }else{
        printf("\nLista iniciada\n");
    }
    system("pause");
}

void limparLista(Lista *lista){
    No *no, *aux;
    no = lista->inicio;

    while (no != NULL){
        aux = no;
        no = no->proximo;
        free (aux);
    }
    lista->inicio = NULL;
    lista->tam = 0;
    printf("Lista esvaziada com sucesso");
    system("pause");
}


No *removerElem(Lista *l, int valor){ //retorna um ponteiro, pois altera
    No *aux;
    No *remover = NULL;// se nao encontrarmos o elemento, retornara nulo
    //vamos percorrer a lista procurando o elemento
    if(l->inicio){
        if(l->inicio->dado == valor){//conteudo do primeiro no da lista
            remover = l->inicio;
            l->inicio = remover->proximo;
            l->tam--;
        }else{
            aux = l->inicio;
            while(aux->proximo && aux->proximo->dado != valor){
                aux = aux->proximo;
            }
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                l->tam--;
            }
        }
    }
    return remover;
}


No *consultaValor(Lista *l, int valor){//retorna um numero inteiro
    No *no = NULL;
    No *aux;

    aux = l->inicio;
    //percorrer a lista procurando o elemento
    while(aux && aux->dado != valor){
        aux = aux->proximo; //enquanto o valor nao for encontrado, segue para o proximo
    }
    if(aux){ //aux !=NULL
        no = aux;//no recebe ponteiro para aux
    }
    return no;
}

void alteraElem(Lista *l, int valor, int new_valor){
    No *no = NULL;
    No *aux;

    aux = l->inicio;
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