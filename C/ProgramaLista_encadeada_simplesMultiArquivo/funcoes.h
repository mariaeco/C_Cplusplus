#ifndef FUNCOES_H
#define FUNCOES_H


typedef struct no No;


No *criaLista(No *L);
void insereInicio(No **ll, int valor);
void insereFinal(No **lista, int valor);
void insereMeio(No **lista, int valor, int ant);
void insereOrdenado(No **lista, int valor);
void removeInicio(No *L);
void removeFim(No *L);
void removeMeio(No *L, int posicao);
No *consultaValor(No **L, int valor);
void alteraElem(No **L, int valor, int new_valor);
No *removerElem(No **L, int valor);
void imprimeLista(No *no);
void limparLista(No **L);
void ConsultaVazia(No **L);



#endif // FUNCOES_H