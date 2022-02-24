//IMPLEMENTANDO UMA PILHA SEGUNDA FORMA

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

//Agora temos explicitamente uma variavel, um tipo PILHA
typedef struct _pilha{
    No *topo;
    int tam;
}Pilha;

void criaPilha(Pilha *p){ //inicializando a pilha
    p->topo = NULL;
    p->tam = 0;
}

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
void *empilhar(Pilha *p){ //retorna um ponteiro par um noh.
    No *novo = (No *)malloc(sizeof(No));

    if(novo){
        novo->p = ler_pessoa();
        novo->proximo = p->topo;
        p->topo = novo;
        p->tam++;
    }else{
        printf("\nErro ao alocar memoria...\n");
    }
}

No *desempilhar(Pilha *p){//quero alterar o conteudo do topo, entao faco ponteiro de ponteiro
    if(p->topo != NULL){
        No *remover = p->topo;
        p->topo = remover->proximo;
        p->tam--;
        return remover;
    }else{
        printf("\nPilha Vazia.\n");
    }
    return NULL;
}


void imprimir_pilha(Pilha *p){
    No *aux = p->topo; 
    //utilizo um ponteiro auxiliar para receber minha pilha, senao vou perder minha pilha
    printf("\n------------- PILHA Tam: %d --------------\n", p->tam);
    while(aux){
        imprimir_pessoa(aux->p);
        aux = aux->proximo; //caminha na pilha para naoficar um loop infinito
    }
    printf("\n-------------  FIM  ---------------\n");


}


int main(){
    
    Pilha p;
    No *remover;
    int op;

    criaPilha(&p);

    do{
        printf("\n\t0 - Sair");
        printf("\n\t1 - Empilhar");
        printf("\n\t2 - Desempilhar");
        printf("\n\t3 - Imprimir\n");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 1:
                empilhar(&p);
                break;
            case 2:
                remover = desempilhar(&p);
                if(remover != NULL){
                    printf("\nElemento removido:\n");
                    imprimir_pessoa(remover->p);
                    free(remover);
                }else{
                    printf("\nSem no a remover.\n");
                }
                break;
            case 3:
                imprimir_pilha(&p);
                break;
            default:
            if(op != 0){
                printf("\nOpcao invalida!\n");
            }
        }
    }while(op != 0);

    return 0;

}

