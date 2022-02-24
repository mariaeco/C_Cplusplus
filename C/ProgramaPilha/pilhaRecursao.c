/* RECURSAO EM PILHA
    Como simular a recursao do fatorial  com uma pilha?
    3! = 3 * 2 * 1 = 6 

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

No* empilhar(No *pilha, int num){
    No *novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = pilha;
        return novo;
    }else{
        printf("\nErro ao alocar memoria...\n");
    }
    return NULL;
}

No *desempilhar(No **pilha){//quero alterar o conteudo do topo, entao faco ponteiro de ponteiro
    No *remover = NULL;
    if(*pilha != NULL){
        remover = *pilha;
        *pilha = remover->proximo;
        return remover;
    }else{
        printf("\nPilha Vazia.\n");
    }
    return NULL;
}

void imprimir(No *pilha){
    printf("\n------------- PILHA --------------\n");
    printf("\t1\n");
    while(pilha){
        printf("\t%d\n",pilha->valor);
        pilha = pilha->proximo; //caminha na pilha para naoficar um loop infinito
    }
    printf("\n-------------  FIM  ---------------\n");
}

int fatorial(int num){
    No *remover;
    No *pilha = NULL;

    while(num > 1){ //enquanto maior q um, pq fatorial de 1 eh 1
        pilha = empilhar(pilha, num);// vamos empilhar
        num--;
    }
   
    imprimir(pilha);

    while(pilha != NULL){
        remover = desempilhar(&pilha);
        num = num * remover->valor;
        free(remover);
    }
    return num; 
}


int main(){
    int valor;

    printf("Digite um valor maior que ZERO para o fatorial:\n");
    scanf("%d", &valor);
    printf("Fatorial de %d: %d\n", valor, fatorial(valor));

    return 0;
}
