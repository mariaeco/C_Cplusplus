/*==================================================================
 ====================================================================
                       C Course
        C - Structure usando vetores e passando por funcao
 ====================================================================
 ====================================================================*/
#include <stdio.h>
// Variavel Global
int n = 3;
//Estruturas
struct horario {
    char dia_semana[20];
    int horas;
    int minutos;
    int segundos;
};

//Fun��es
void receberHorarios(struct horario x[n]); //chamando a funcao


int main(void){

    struct horario listaHorarios[n]; //minha estrutura do tipo horario com a variavel listaaHorarios
    receberHorarios(listaHorarios); //chamar funcao

    return 0;
}

void receberHorarios(struct horario x[n]){
    int i;

    for(i=0;i<n;i++){
        printf("Digite o %i horario (hh:mm:ss): ", i+1);
        scanf("%i:%i:%i", &x[i].horas,
                            &x[i].minutos,
                            &x[i].segundos);
        printf("Digite o dia da semana (Domigo a Sabado): ");
        scanf("%s",x[i].dia_semana);
    }
    for(i=0;i<n;i++){
        printf("O %i horario eh: ", i+1);
        printf("%i:%i:%i  - dia: %s\n", x[i].horas,
                             x[i].minutos,
                             x[i].segundos,
                             x[i].dia_semana);
    }
};
