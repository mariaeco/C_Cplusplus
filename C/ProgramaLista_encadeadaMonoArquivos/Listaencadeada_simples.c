// Lista encadeada simples
// conceitos iniciais
// cada entrada deve ser alocada individualmente, alocamos espaço de acordo com nossa necessidade.
// mostra duas formas de inserir os valores na lista (para saber as diferentes formas)
// o ultimo elemento da lista deve apontar para zero!
//Rodar apenas esse arquivo
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *proximo;
}No;

No *cria_lista(No *l){
    system("cls");
    l = NULL;
    printf("\n\nLista criada com sucesso!\n\n");
    system("pause");

    return l;
}

No* insere_inicio2(No *lista, int valor){ // NESSE FORMATO A ENTREDA EH insere_inicio2(lista, valor);
    
    // 1)crio o no
    // 2)preencho o no
    // 3)coloco o no na lista
    No *novo; //minha auxiliar
    novo = (No*)malloc(sizeof(No));
    //lembrar de verificar se alocou
    if(!novo) {//verificando se alocou
        printf("Espaco nao armazenado!\n");
    }
    novo->dado = valor;
    novo->proximo = lista;
    lista = novo;
    
    return lista; //aqui implemento a mudança
}
// outro formato de insere_inicio
void insere_inicio(No **ll, int valor){ // recebera &lista // aqui eh uma passagem por referencia e ja altero aqui e nao apenas no return
    No *novo;
    novo = (No*)malloc(sizeof(No));
    if(!novo) {//verificando se alocou
        printf("Espaco nao armazenado!\n");
    }

    novo->dado = valor;
    novo->proximo = *ll; //aponto para o conteudo apontado por ll
    *ll = novo;
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
    }else{
        aux = *lista;
        while(aux->proximo){ //percorro minha lista enquanto proximo for diferente de NULL
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

void inserir_meio(No **lista, int valor, int ant){
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




int main(){

    //na lista dinamica, nosso marco inicial eh uma variavel ponteiro estatica (*estatica)
    // os elementos serao alocados um a um
    // nunca perder a marcacao inicial --> o *lista ira marcar o primeiro elemento;
    // na lista encadeada nao preciso do controle, pois nao tenho memoria limitada, nao precisa saber se atingiu a memoria
    //No *lista; // inicio da minha lista // lista sera minha unica variavel estatica
 
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
        printf("\n\t4 - Imprimir");
        printf("\n\t5 - Verificar se eh vazia");
        printf("\n\t6 - Limpar Lista");
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
            ConsultaVazia(&lista);
            break;
        case 6:
            limparLista(&lista);
            break;
        case 7: //removeElemento
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