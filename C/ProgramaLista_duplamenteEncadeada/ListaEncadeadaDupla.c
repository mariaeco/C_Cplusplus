//LISTA DUPLAMENTE ENCADEADA
//Rodar apenas esse arquivo
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *proximo;
    struct no *anterior; //temos agora o ponteiro anterior
}No;

No *cria_lista(No *l){
    system("cls");
    l = NULL;
    printf("\n\nLista criada com sucesso!\n\n");
    system("pause");

    return l;
}

// outro formato de insere_inicio
void insere_inicio(No **lista, int valor){ // recebera &lista // aqui eh uma passagem por referencia e ja altero aqui e nao apenas no return
    No *novo;
    novo = (No*)malloc(sizeof(No));
    if(!novo) {//verificando se alocou
        printf("Espaco nao armazenado!\n");
    }

    novo->dado = valor;
    novo->proximo = *lista; //aponto para o conteudo apontado por ll
    novo->anterior = NULL; // o primeiro no da lista nao tem ninguem antes dele
    if(*lista!=NULL){
        (*lista)->anterior = novo;
    }
    *lista = novo;
}

void insere_final(No **lista, int valor){ // recebera &lista // aqui eh uma passagem por referencia e ja altero aqui e nao apenas no return
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
        novo->anterior = NULL;//Se so existe um no, o anterior eh nulo
    }else{
        aux = *lista;
        while(aux->proximo){ //percorro minha lista enquanto proximo for diferente de NULL
            aux = aux->proximo;
        }
        aux->proximo = novo;
        novo->anterior = aux;
    }
}

void inserir_meio(No **lista, int valor, int ant){
    No *aux, *novo;
    
    if(novo) {//verificando se alocou
        novo = (No*)malloc(sizeof(No));
        novo->dado = valor;
        if(*lista==NULL){
            novo->proximo = NULL; //se a lista for fazia, o proximo sera o primeiro q eh nulo
            novo->anterior = NULL;
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->dado !=ant && aux->proximo){ //&& aux->proximo existir
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo; //linkei o novo no com a parte final da lista
            aux->proximo->anterior = novo;
            novo->anterior =  aux;
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
            novo->anterior = NULL;
            *lista = novo;
        }else if(novo->dado < (*lista)->dado){ //o conteúdo é o menor?
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista= novo;
        }else{
            aux = *lista;
            while(aux->proximo && novo->dado > aux->proximo->dado){ 
                //enquanto proximo exister & valor for maior que aux guarda do proximo no, vamos caminhar na nossa lista
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            if(aux->proximo){
                aux->proximo->anterior  = novo;
            }
            novo->anterior = aux;
            aux->proximo = novo;
        }

    }else{
        printf("Erro ao alocar memoria!\n");
    }

}

void imprimir(No *no){
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

No *removerElem(No **L, int valor){ //retorna um ponteiro, pois altera
    No *aux;
    No *remover = NULL;// se nao encontrarmos o elemento, retornara nulo
    //vamos percorrer a lista procurando o elemento
    if((*L)->dado == valor){
        remover = *L;
        *L = remover->proximo;
        if(*L){
            (*L)->anterior = NULL;

        }
    }else{
        aux = *L;
        while(aux->proximo && aux->proximo->dado != valor){
            aux = aux->proximo;
        }
        if(aux->proximo){
            remover = aux->proximo;
            aux->proximo = remover->proximo;
            if(aux->proximo){
                aux->proximo->anterior = aux;
            }
        }
    }
    return remover;
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

//Verificando se linkamos
No* ultimo(No **lista){
    No *aux = *lista;
    while(aux->proximo){
        aux = aux->proximo;
    }
    return aux;
}

void imprimirContrario(No *no){
    printf("\n\tLista: ");
    while(no){
        printf("%d->", no->dado);
        no = no->anterior;
    }
    printf("NULL\n\n");
    system("pause");
}

int main(){

    int op, valor, ant, new;
    No *lista, *remover, *elemento;

    //lista = NULL;
    lista = cria_lista(lista); //lista criada


    //MEU MENU
    do{
        printf("\n\t0 - Sair");
        printf("\n\t1 - Inserir no Inicio");
        printf("\n\t2 - Inserir no Fim");
        printf("\n\t3 - Inserir no Meio");
        printf("\n\t4 - Insere ordenado");
        printf("\n\t5 - Imprimir");
        printf("\n\t6 - Verificar se eh vazia");
        printf("\n\t7 - Limpar Lista");
        printf("\n\t8 - Remover elemento");
        printf("\n\t9 - Consulta Valor na Lista");
        printf("\n\t10 - Altera Valor na Lista");
        printf("\n\t11 - Imprimir ao Contrario\n");
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
            printf("insira um valor: ");
            scanf("%d",&valor);
            insereOrdenado(&lista, valor);
            break;
        case 5:
            imprimir(lista);
            break;
        case 6:
            ConsultaVazia(&lista);
            break;
        case 7:
            limparLista(&lista);
            break;
        case 8: //removeElemento
            printf("insira um valor a remover: ");
            scanf("%d",&valor);
            remover = removerElem(&lista, valor);
            if(remover){
                printf("Elemento a ser removido: %d\n", remover->dado);
                free(remover);
            }else{
                printf("Elemento inexistente.\n");
            }
            break;
        case 9: //Consultar Valor
            printf("Insira um valor para consulta: \n");
            scanf("%i", &valor);
            elemento = consultaValor(&lista, valor);
            if(elemento){
                printf("Elemento encontrado: %d\n", elemento->dado);
            }else{
                printf("Elemento inexistente.\n");    
            }
            break;
        case 10: //Altera Elemento
            printf("Insira o valor para alteracao: \n");
            scanf("%i", &valor);
            printf("Insira o novo valor: \n");
            scanf("%i", &new);
            alteraElem(&lista, valor, new);
            break;
        case 11:
            imprimirContrario(ultimo(&lista));
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