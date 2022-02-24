#ifndef FUNCOES_H
#define FUNCOES_H


typedef struct _lista Lista;



void criaLista(Lista *L);
void insereInicio(Lista *L, int valor);
void insereFinal(Lista *L, int valor);
void removeInicio(Lista *L);
void removeFim(Lista *L);
void removeMeio(Lista *L, int posicao);
void consultaValor(Lista *L, int valor);
void alteraElem(Lista *L, int valor, int new_valor);
void removeElem(Lista *L, int valor);
void imprimeLista(Lista *L);
void limparLista(Lista *L);
void ConsultaVazia(Lista *L);



#endif // FUNCOES_H