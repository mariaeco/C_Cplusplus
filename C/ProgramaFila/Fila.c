//IMPLEMENTANDO UMA FILA

#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int dados;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
}Fila;

void criarFila(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
    printf("\nFila Criada com Sucesso!\n");
}

void inserir(Fila *fila, int valor){
    No *aux;
    No *novo = (No*)malloc(sizeof(No));

    if(novo != NULL){
        novo->dados = valor;
        novo->proximo = NULL;
        if(fila->inicio == NULL){ //inserçao do meu primeiro no
            fila->inicio = novo;
            fila->fim = novo;
        }else{
            fila->fim->proximo = novo;
            fila->fim = novo;
        }
        fila->tam++;
    }else{
        printf("Memoria nao alocada\n\n");
    }
}

No* remover(Fila *fila){
    No *remover = NULL;

    if(fila->inicio){
        remover = fila->inicio;
        fila->inicio = remover->proximo;
        fila->tam--;
    }else{
        printf("\tFila vazia\n");
    }
    return remover;
}

void imprimir(Fila *fila){
    No *aux;

    aux = fila->inicio;
    printf("-------------- Fila ----------------\n");
    while(aux){
        printf("%d -> ", aux->dados);
        aux = aux->proximo;
    }
    printf("FIM");
    printf("\n-------------- Fim da Fila ----------------\n");
    printf("Tamanho da fila: %d\n", fila->tam);
}

int main(){
    No *rem;
    Fila fila;
    int op, valor;

    do{
        printf("\n\t0 - Sair");
        printf("\n\t1 - Criar fila");
        printf("\n\t2 - Inserir");
        printf("\n\t3 - Remover");
        printf("\n\t4 - Imprimir\n");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 1:
                system("cls");
                criarFila(&fila);
                system("pause");
                break;
            case 2:
                system("cls");
                printf("\nDigite o valor: ");
                scanf("%d", &valor);
                inserir(&fila, valor);
                system("pause");
                break;
            case 3:
                system("cls");
                rem = remover(&fila);
                if(rem != NULL){
                    printf("\nElemento removido: %d\n",rem->dados);
                    free(rem);
                }else{
                    printf("\nSem elemento a remover.\n");
                }
                system("pause");
                break;
            case 4:
                system("cls");
                imprimir(&fila);
                system("pause");                
                break;
            default:
                system("cls");
                if(op != 0){
                    printf("\nOpcao invalida!\n");
                    system("pause");
                }
        }
    }while(op != 0);

    return 0;

}

