/*==================================================================
 ====================================================================
                       C Course
        C - Structure usando vetores e passando por funcao
 ====================================================================
 ====================================================================*/
#include <stdio.h>
#include <stdlib.h>

// Variavel Global
int n = 2;
//Estruturas
typedef struct {
    char *dia_semana;
    int horas;
    int minutos;
    int segundos;
} Horarios; //vamos criar minha struct Horario

typedef struct _vector{
    int capacity; //numero maximo de elementos no vetor
    int size; // quantidade de elmentos armazenado atualmente
    Horarios *data; // nosso vetor
} Nvetor; // struct para definir a quantidade de Horarios que desejo armazenar

// @brief cria um vetor com uma dada capacidade
Nvetor *create(int capacity){
    Nvetor *vec = (Nvetor*) calloc(1, sizeof(Nvetor));
    vec -> size = 0;
    vec -> capacity = capacity;
    vec -> data = (Horarios*) calloc(capacity, sizeof(Horarios));

    return vec;
}

void destroy(Nvetor **vec_ref){
    Nvetor *vec = *vec_ref;
    free(vec->data);
    free(vec);
    *vec_ref = NULL;

}

Nvetor *receberHorarios(Nvetor *ptr){

    //Horarios *ptr;
    //ptr = &lista;
    //Livro *livro = *livro_ref;
    for(int i=0;i<n;i++){
        printf("Digite o %i horario (hh:mm:ss): ", i+1);
        scanf("%i:%i:%i",  &ptr->data.horas,
                            &ptr->data.minutos,
                            &ptr->data.segundos);
        printf("Digite o dia da semana (Domigo a Sabado): ");
        scanf("%s", ptr->data.dia_semana);
    }
    return ptr;

};

void *printHorarios(Nvetor *ptr){

    for(int i=0;i<n;i++){
        printf("O %i horario eh: ", i+1);
        printf("%i:%i:%i  - dia: %s\n", ptr->data.horas,
                             ptr->Nvetor.data.minutos,
                             ptr->data.segundos,
                             ptr->data.dia_semana);
    }
}

int main(void){

    Nvetor *ptr = create(10);

    Horarios listaHorarios; //minha estrutura do tipo horario nomeada lista Horario
   // Horarios *ptr; // ponteiro para a struct
    //ptr = listaHorarios;
    receberHorarios(ptr); //chamar funcao
    printHorarios(ptr); //chamar funcao

    destroy(&ptr);

    return 0;
}
