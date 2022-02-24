/***

***/
#include  <stdio.h>
#include <stdlib.h>
struct lista {
        int valor[4] ;
        int n;
} l;

int main(){
        int i, j, aux;

      l.n=3;

//      l.valor[0]=8;
//      l.valor[1]=4;
//      l.valor[2]=7;
//      l.valor[3]=0;


        for (i=0; i<=l.n; i++) {
                //for (j=i+1; j<=l.n-1; j++) {
                        aux = l.valor[i];
                        l.valor[i] = l.valor[i];
                        l.valor[i] =aux;
                        printf("%d\n",  l.valor[i]);

        }

        printf("\n\n");
        printf("%d\n",  l.valor[0]);
        printf("%d\n",  l.valor[1]);
        printf("%d\n",  l.valor[2]);
        printf("%d\n",  l.valor[3]);

        return 0;
}

