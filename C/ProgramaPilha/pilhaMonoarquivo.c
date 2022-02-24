//IMPLEMENTANDO UMA PILHA EM UM ÚNICO ARQUIVO

#include <stdio.h>
#include <stdlib.h>

typedef struct _data{
    int dia, mes, ano;
}Data;

typedef struct _pessoa{
    char nome[20];
    Data data;
}Pessoa;

typedef struct _no{
    Pessoa p;
    struct _no *proximo;
}No;


Pessoa ler_pessoa(){
    Pessoa p;

    printf("\nDigite o nome e data:\n");
    scanf("%[^\n]%*c", p.nome);
    printf("\nDigite a data de nascimento (dd/mm/aaaa):\n");
    scanf("%d/%d/%d", &p.data.dia,&p.data.mes,&p.data.ano);

    return p;
}

void imprimir_pessoa(Pessoa p){
    printf("\n\tNome: %s", p.nome);
    printf("\n\tData: %2d/%2d/%4d\n", p.data.dia, p.data.mes, p.data.ano);
}

//FUNÇAO PARA A OPERAÇAO PUSH(EMPILHAR)
No *empilhar(No *topo){ //retorna um ponteiro par um noh.
    No *novo = (No *)malloc(sizeof(No));

    if(novo){
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return novo;
    }else{
        printf("\nErro ao alocar memoria...\n");
    }
    return NULL;
}

No *desempilhar(No **topo){//quero alterar o conteudo do topo, entao faco ponteiro de ponteiro
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }else{
        printf("\nPilha Vazia.\n");
    }
    return NULL;
}


void imprimir_pilha(No *topo){
    printf("\n------------- PILHA --------------\n");
    while(topo){
        imprimir_pessoa(topo->p);
        topo = topo->proximo; //caminha na pilha para naoficar um loop infinito
    }
    printf("\n-------------  FIM  ---------------\n");
}


int main(){
    No *topo = NULL; //inserir e remover do topo
    No *remover;
    int op;

    do{
        printf("\n\t0 - Sair");
        printf("\n\t1 - Empilhar");
        printf("\n\t2 - Desempilhar");
        printf("\n\t3 - Imprimir\n");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 1:
                topo = empilhar(topo);
                break;
            case 2:
                remover = desempilhar(&topo);
                if(remover != NULL){
                    printf("\nElemento removido:\n");
                    imprimir_pessoa(remover->p);
                    free(remover);
                }else{
                    printf("\nSem no a remover.\n");
                }
                break;
            case 3:
                imprimir_pilha(topo);
                break;
            default:
            if(op != 0){
                printf("\nOpcao invalida!\n");
            }
        }
    }while(op != 0);

    return 0;

}

