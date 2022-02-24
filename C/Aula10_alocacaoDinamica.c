//Alocacao dinamica de es
#include <stdio.h>
#include <stdlib.h>
//* malloc retorna um void ponteiro (void *)


int main(){
    int *p;
    char *vet;
    int n = 8; // n eh o tamanho do  que quero alocar
// ponteiro para  (eu poderia fazer *vet[8]), mas assim eu nao aloco as
// posicoes na memoria stack que eh pequena. Com o malloc eu aloco na memoria Heap.

    // alocacao para int
    p = (int*)malloc(n*sizeof(int));
    //A malloc sempre retorna void, entao preciso forçar a retonar no tipo que desejo.
    //Faço isso usando um cash antes do malloc: (int*),(char*),(float*)..

    if(!(p=malloc(100))){
        printf("Sem memoria.\n");
        exit(1);
    }else{
        printf("Memoria alocada.\n");
    };


    // alocacao para char
    int  i= 0;
    for(i = 0; i <= n; ++i){
        vet=(char*)malloc(sizeof(char)); // veja que aqui  nao preciso fazer vet[i] = ....
        if(!vet){
            printf("Sem memoria.\n");
            exit(1);
        }else{
            printf("Memoria para ponteiro de chars alocada.\n");
        };

    }

    free(p);
    free(vet);
    return 0;
}
