/*==================================================================
 ====================================================================
                       C Course
                 C - Ponteiros e Funcoes Aula 2


 ====================================================================
 ====================================================================*/
#include <stdio.h>

void somar(float *var, float valor);
void iniVetor(float *v);

int main(){

    float num = 0; // vamos passar valor
    float vetor[5];// vamos passar um vetor
    int *p1, *p2;

    p1 = &num;
    p2 = vetor;

    printf("%f\n", num);

    somar(p1, 15);// passando um valor por referencia
    printf("%f\n\n", num);

    iniVetor(p2); //passando um vetor por referencia


    return 0;

}

void somar(float *var, float valor){
            *var+=valor;
}

void iniVetor(float *v){
    for(int i=0; i<5;i++){
       v[i] = i;
    }
    for(int i=0; i<5;i++){
        printf("%f\n", v[i]);
    }
}




