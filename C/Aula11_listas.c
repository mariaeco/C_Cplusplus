/***
   NAME
     Aula11_listas.c
   AUTOR:
     Maria Cardoso - Sept 02, 2021
   PURPOSE
        Listas servem para inserir dados sem a necessidade de indicar antecipadamente o numero que desejo
        Com as listas eu vou adicionando dados a medida que necessito,entao nao ocupo memoria sem necessidade.
        Nas listas, os elementos consecutivos não ficam necessariamente em posicoes consecutivas na memoria,
        mas um noh da lista aponta para o proximo.
***/
#include  <stdio.h>
#include <stdlib.h>

//Cria minha estrutura de noh,  mas nao cria o inicio da lista
typedef struct _snode{
        int val;
        struct _snode *next; // ponteiro para o proximo noh da lista.
} SNode;

//Define o inicio da lista
typedef struct _linked_list{
        SNode *begin; //Ponteiro para o primeiro noh da lista

} LinkedList;

//Funcao de criacao de lista
LinkedList *LinkedList_create(){
        LinkedList *L = (LinkedList*) calloc(1, sizeof(LinkedList));// aloca um bloco que aloque nosso inicio
}

//Funcao de criacao de noh
SNode *SNode_create(int val){
                SNode *snode = (SNode*) calloc(1, sizeof(SNode));
                snode->val = val;
                snode->next = NULL;

                return snode;
}

//Insere elemento no inicio da lista
void LinkedList_add_first(LinkedList *L, int val){
        //Primeiro testamos se a lista esta vazia.
        if(L->begin ==NULL){
                printf("\nLista Vazia\n");
        }

        SNode *p = SNode_create(val);
        p->next = L->begin;
        L->begin = p;
}

//Inserir no final da lista
void LinkedList_add_last(LinkedList *L, int val){
        SNode *q = SNode_create(val);

        if(L->begin ==NULL){
                L->begin = q;
        }else{
                SNode *p  = L->begin;
                //Enquanto p nao eh o ultimo noh
                while(p -> next !=NULL){
                        p = p->next;
                }
                // nesse momento, o ponteiro p aponta para o final da lista
                // corrige o encadeamento, faz com que o proximo elemento do atual ultimo no aponte para um novo ultimo no
                p->next = q;
        }
}

void LinkedList_print(const LinkedList *L){
        SNode *p = L->begin;

        printf("L -> ");
        while(p != NULL){
               printf("%d -> ", p->val);
                p = p->next;
        }
        printf("NULL\n");

}


int main(){
        LinkedList *L = LinkedList_create();
//
//        LinkedList_add_first(L, 5);//adiciona no inicio
//        LinkedList_print(L);
//        LinkedList_add_first(L, 4);
//        LinkedList_print(L);
//        LinkedList_add_first(L, 2);
//        LinkedList_print(L);
//        LinkedList_add_first(L, 10);
//        LinkedList_print(L);
//        LinkedList_add_first(L, 10);
//        LinkedList_print(L);

        LinkedList_add_last(L,1);// adiciona no final
        LinkedList_print(L);
        LinkedList_add_last(L,2);// adiciona no final
        LinkedList_print(L);
        LinkedList_add_first(L, 10);//adiciona no inicio
        LinkedList_print(L);
        LinkedList_add_last(L,100);// adiciona no final
        LinkedList_print(L);

        if(L->begin != NULL){
                printf("\nLista Preenchida\n");
        }

        return 0;
}



