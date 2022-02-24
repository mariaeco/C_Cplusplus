#ifndef FUNCOES_H
#define FUNCOES_H


typedef struct no No;
typedef struct _lista Lista;


void criaLista(Lista *lista);
void insere_inicio(Lista *ll, int valor);
void insere_final(Lista *lista, int valor);
void inserir_meio(Lista *lista, int valor, int ant);
void insereOrdenado(Lista *lista, int valor);
No *consultaValor(Lista *l, int valor);
void alteraElem(Lista *l, int valor, int new_valor);
No *removerElem(Lista *l, int valor);
void imprimir(Lista lista);
void limparLista(Lista *lista);
void ConsultaVazia(Lista *lista);



#endif // FUNCOES_H