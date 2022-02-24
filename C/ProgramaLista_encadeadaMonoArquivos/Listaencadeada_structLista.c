//FUNCOES
//Com estrutura lista
//Outro tipo de implemetação de lista e das funções
//Nesse formato nao preciso fazer ponteiro para ponteiro
//Rodar apenas esse arquivo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no{
    int dado;
    struct no *proximo;
}No;

typedef struct{
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
    printf("Lista esvaziada com sucess!\n");
    system("pause");
}

void ConsultaVazia(Lista *lista){
    if(lista->inicio == NULL){
        printf("\nLista Vazia\n");
    }else{
        printf("\nLista iniciada\n");
    }
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



int main(){

    int op, valor, ant, new;
    Lista lista;
    No *removido, *elemento;

    //lista = NULL;
    criaLista(&lista); //lista criada


    //MEU MENU
    do{
        printf("\n\t0 - Sair");
        printf("\n\t1 - Inserir no Inicio");
        printf("\n\t2 - Inserir no Fim");
        printf("\n\t3 - Inserir no Meio");
        printf("\n\t4 - Imprimir");
        printf("\n\t5 - Limpar Lista");
        printf("\n\t6 - Verificar se eh vazia");
        printf("\n\t7 - Remover elemento");
        printf("\n\t8 - Consulta Valor na Lista");
        printf("\n\t9 - Altera Valor na Lista\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("insira um valor: ");
            scanf("%d",&valor);
            insere_inicio(&lista, valor);
            break;
        case 2:
            printf("insira um valor: ");
            scanf("%d",&valor);
            insere_final(&lista, valor);
            break;
        case 3:
            printf("insira um valor: ");
            scanf("%d",&valor);
            printf("insira o valor anterior: ");
            scanf("%d",&ant);
            inserir_meio(&lista, valor, ant);
            break;
        case 4:
            imprimir(lista);
            break;
        case 5:
            limparLista(&lista);
            break;
        case 6:
            ConsultaVazia(&lista);
            break;
        case 7:
            printf("insira um valor a ser removido: ");
            scanf("%d",&valor);
            removido = removerElem(&lista, valor);
            if(removido){
                printf("Elemento a ser removido: %d\n", removido->dado);
                free(removido);
            }else{
                printf("Elemento inexistente.\n");
            }
            break;
        case 8: //Consultar Valor
            printf("Insira um valor para consulta: \n");
            scanf("%i", &valor);
            elemento = consultaValor(&lista, valor);
            if(elemento){
                printf("Elemento encontrado: %d\n", elemento->dado);
            }else{
                printf("Elemento inexistente.\n");    
            }
            break;
        case 9: //Altera Elemento
            printf("Insira o valor para alteracao: \n");
            scanf("%i", &valor);
            printf("Insira o novo valor: \n");
            scanf("%i", &new);
            alteraElem(&lista, valor, new);
            break;
        default:
            if(op!=0){
                printf("Opcao invalida!\n");
            }
            break;
        }

    }while(op!=0);

    return 0;
}