/***
   NAME
     Aula11_listas_end.c
   AUTOR:
     Maria Cardoso - Sept 02, 2021
   PURPOSE
        Crio um ponteiro que guarda o fim da lista, fica mais eficiente
        pois nao preciso percorrer toda a lista na funcao add Last para adicionar no final
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
        SNode *end; //Ponteiro para o ultimo noh da lista, assim nao preciso percorrer toda a lista para achar o final dela
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
                L->end = q;
        }else{
                L->end ->next = q;
                L->end = L->end ->next;
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

