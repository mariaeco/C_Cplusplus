# include <stdio.h>
# include <stdlib.h>
# define TAM  10


char guardar_nome( char* v){
    int i;
    for (i=0; i<TAM; i++){
        printf("\n digite um nome: ");
        scanf("%s", &v[i]);

    }
}
void imprimir( char* v){
int i;
        for (i=0; i<TAM; i++){
        printf("%s \n ", &v[i]);
    }
}
faltou & no imprimir

// alocando dinamicamente a quantidade o tamanho de cada nome digitado
char phrase[30];
scanf("%[^\n]%*c",phrase);
v[posicao] = (char *) malloc(strlen(phrase)*sizeof(char));
