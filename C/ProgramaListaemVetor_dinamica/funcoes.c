// aqui trabalhamos com arrays de structs
//FUNCOES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

typedef struct _lista{
    int dados;
}Lista;

typedef struct _controle{
    int tam; //tamanho total da lista
    int c; //minha variavel de controle
}Controle;

Controle *clt;
//Funcao de criacao de lista
Controle *criaControle(int tamanho){

    clt = (Controle*) malloc(tamanho*sizeof(Controle));
    clt->c = -1;
    clt->tam = tamanho;


    return clt;
}

//Funcao de criacao dos dados
Controle *criaLista(Lista *lista, int tamanho){
    clt = criaControle(tamanho);
    lista = (Lista*) malloc(tamanho*sizeof(Lista));

    printf("\n\nLista criada com sucesso!\n\n");
    system("pause");

    return clt;
}

//Inserir no inicio da lista
void insereInicio(Lista *L, int valor){
    // se a lista não tiver cheia
    // percorrer a lista até o fim
    if(clt->c == -1){
        L[0].dados = valor;
        clt->c = clt->c + 1;
        
    }else if(clt->c < clt->tam) {
        for(int i = clt->c; i>=0; i--){
             L[i+1].dados = L[i].dados;
        }
        L[0].dados = valor;
        clt->c = clt->c + 1;
    }

    printf("\n\nValor %i registrado com sucesso!\n\n", L[0].dados);
    system("pause");
}

//Insere elemento no final da lista
void insereFinal(Lista *lista, int valor){

    int arraySize = sizeof(lista->dados);
    int intSize = sizeof(lista[0].dados);
    int length = arraySize/intSize;

    if (clt->c == length-1){
        printf("size: %i\n",length);
        printf("Lista cheia\n");
    }else{
        
        lista[clt->c +1].dados = valor;
        clt->c = clt->c + 1;
    }

}

void removeInicio(Lista *L){
    if(clt->c == -1){
        printf("Lista Vazia\n");
        printf("Nao eh possivel remover\n");
    }else{
        for(int i = 0; i <= clt->c; i++){
            L[i].dados = L[i+1].dados;
        }
        clt->c = clt->c - 1;
        printf("elemento removido com sucesso\n");
    }
    system("pause");
}

void removeFim(Lista *L){
    clt->c = clt->c - 1;
    printf("elemento final removido com sucesso\n");
    system("pause");
}

void removeMeio(Lista *L, int posicao){
    
    posicao = posicao-1; //para ser a posicao visualizada pelo usuario

    if(clt->c == -1){
        printf("Lista Vazia\n");
        printf("Nao eh possivel remover\n");
    }else{
        for(int i = 0; i <= posicao; i++){
            if(i < posicao){
            }else{
                L[i].dados = L[i+1].dados;
            }
        }
        clt->c = clt->c - 1;
        printf("elemento removido com sucesso\n");
    }
    system("pause");
}

 void consultaValor(Lista *L, int valor){
    int count = 0;
    if(clt->c == -1){
        printf("Lista Vazia\n");
        printf("Nao eh possivel procurar\n");
    }else {
        for(int i = 0; i <= clt->c; i++){
                if(L[i].dados ==  valor){
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

    for(int i = 0; i <= clt->c; i++){
        if(L[i].dados ==  valor){
            printf("Registro Encontrado na posicao: %i\n",i + 1);
            L[i].dados  =  new_valor;
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

    for(int j = 0; j <= clt->c; j++){
        if(L[j].dados ==  valor){
            printf("Registro Encontrado na posicao: %i\n",j + 1);
            pos = j+1;
            for(int i = 0; i <= clt->c; i++){
                if(i < j){

                }else{
                    L[i].dados = L[i+1].dados;
                }
            }
            count += 1;
            break;
        }    
    }
    printf("Elemento removido!\n");
    clt->c = clt->c - 1;
    if(count==0){
        printf("Registro Nao Encontrado!\n");
        printf("Tente novamente!\n");
        system("pause");
    }
}


void imprimeLista(Lista *L){ //Lista *L
    if (clt->c ==-1){
        printf("Lista Vazia!\n");
    }else{
        printf("Lista->");
        for(int i=0; i <= clt->c ; i++){
            printf("%d",L[i].dados);
            printf("->");
        }
        printf("NULL\n");
    }
    system("pause");
}

void ConsultaVazia(Lista *L){
    if (clt->c ==-1){
        printf("Lista criada, mas Vazia!\n");
    }else if(clt->c == 0){
        printf("Lista NAO criada. Crie uma lista!\n");
    }else{
        printf("Lista iniciada!\n");
        printf("A lista possuem %i elementos\n",clt->c + 1);
    }
    system("pause");
}

void limparLista(Lista *lista){//Remove todos os nós da Lista
    clt->c = - 1;
    free(lista);

    printf("Lista limpa!\n");
}
