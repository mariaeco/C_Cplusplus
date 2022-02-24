//FUNCOES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

typedef struct _lista{
    int vetor[10];
    int c; //minha variavel de controle
}Lista;


//Funcao de criacao de lista
void criaLista(Lista *lista){

    lista->c = -1;
    printf("\n\nLista criada com sucesso!\n\n");
    system("pause");

}


//Inserir no inicio da lista
void insereInicio(Lista *L, int valor){
    // se a lista não tiver cheia
    // percorrer a lista até o fim
    if(L->c == -1){
        L->vetor[0] = valor;
        L->c = L->c + 1;
    }else if(L->c < 9) {
        for(int i = L->c; i>=0; i--){
            L->vetor[i+1] = L->vetor[i];
        }
        L->vetor[0] = valor;
        L->c = L->c + 1;
    }
}

//Insere elemento no final da lista
void insereFinal(Lista *lista, int valor){

    int arraySize = sizeof(lista->vetor);
    int intSize = sizeof(lista->vetor[0]);
    int length = arraySize/intSize;

    if (lista->c == length-1){
        printf("size: %i\n",length);
        printf("Lista cheia\n");
    }else{
        
        lista->vetor[lista->c +1] = valor;
        lista->c = lista->c + 1;
    }
}

void removeInicio(Lista *L){
    if(L->c == -1){
        printf("Lista Vazia\n");
        printf("Nao eh possivel remover\n");
    }else{
        for(int i = 0; i <= L->c; i++){
            L->vetor[i] = L->vetor[i+1];
        }
        L->c = L->c - 1;
        printf("elemento removido com sucesso\n");
    }
    system("pause");
}

void removeFim(Lista *L){
    L->c = L->c - 1;
    printf("elemento final removido com sucesso\n");
    system("pause");
}

void removeMeio(Lista *L, int posicao){
    
    posicao = posicao-1; //para ser a posicao visualizada pelo usuario

    if(L->c == -1){
        printf("Lista Vazia\n");
        printf("Nao eh possivel remover\n");
    }else{
        for(int i = 0; i <= posicao; i++){
            if(i < posicao){
            }else{
                L->vetor[i] = L->vetor[i+1];
            }
        }
        L->c = L->c - 1;
        printf("elemento removido com sucesso\n");
    }
    system("pause");
}

 void consultaValor(Lista *L, int valor){
    int count = 0;
    if(L->c == -1){
        printf("Lista Vazia\n");
        printf("Nao eh possivel procurar\n");
    }else {
        for(int i = 0; i <= L->c; i++){
                if(L->vetor[i] ==  valor){
                    printf("Registro Encontrado na posicao: %i\n",i + 1);
                    count += 1;
                }
        }
    }
    if(count==0){
        printf("Registro Nao Encontrado!\n");
        printf("Tente novamente!\n");
    }
    system("pause");
 }

void alteraElem(Lista *L, int valor, int new_valor){
    int count = 0;

    for(int i = 0; i <= L->c; i++){
        if(L->vetor[i] ==  valor){
            printf("Registro Encontrado na posicao: %i\n",i + 1);
            L->vetor[i] =  new_valor;
            count += 1;
        }
    }
    if(count==0){
        printf("Registro Nao Encontrado!\n");
        printf("Tente novamente!\n");
        system("pause");
    }
}


void removeElem(Lista *L, int valor){
    int count = 0;
    int pos;

    for(int j = 0; j <= L->c; j++){
        if(L->vetor[j] ==  valor){
            printf("Registro Encontrado na posicao: %i\n",j + 1);
            pos = j+1;
            for(int i = 0; i <= L->c; i++){
                if(i < j){

                }else{
                    L->vetor[i] = L->vetor[i+1];
                }
            }
            count += 1;
            break;
        }    
    }
    L->c = L->c - 1;
    if(count==0){
        printf("Registro Nao Encontrado!\n");
        printf("Tente novamente!\n");
        system("pause");
    }
}


void imprimeLista(Lista *L){ //Lista *L

    if (L->c ==-1){
        printf("Lista Vazia!\n");
    }else{
        printf("Lista->");
        for(int i=0; i <= L->c ; i++){
            printf("%d",L->vetor[i]);
            printf("->");
        }
        printf("NULL\n");
    }
    system("pause");
}

void ConsultaVazia(Lista *L){
    if (L->c ==-1){
        printf("Lista criada, mas Vazia!\n");
    }else if(L->c == 0){
        printf("Lista NAO criada. Crie uma lista!\n");
    }else{
        printf("Lista iniciada!\n");
        printf("A lista possuem %i elementos\n",L->c + 1);
    }
    system("pause");
}

void limparLista(Lista *lista){//Remove todos os nós da Lista
    lista->c = - 1;
    printf("Lista limpa!\n");
}
