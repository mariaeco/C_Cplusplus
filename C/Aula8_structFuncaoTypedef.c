/*==================================================================
 ====================================================================
                       C Course
        C - Structure usando typedef // O FORMATO MAIS INDICADO
                        Passagem por valor
 ====================================================================
 ====================================================================*/
#include <stdio.h>
// Variavel Global
int n = 3;
//Estruturas
typedef struct {
    char dia_semana[20];
    int horas;
    int minutos;
    int segundos;
} Horarios;

//Fun��es
// com typedef tenho q colocar minha funcao antes e nao ha a necessidade de declarar ela antes
void receberHorarios(Horarios x[n]){
    int i;

    for(i=0;i<n;i++){
        printf("Digite o %i horario (hh:mm:ss): ", i+1);
        scanf("%i:%i:%i", &x[i].horas,
                            &x[i].minutos,
                            &x[i].segundos);
        
        fflush(stdin);// para limpar o buffer
        
        printf("Digite o dia da semana (Domigo a Sabado): ");
        scanf("%[^\n]",x[i].dia_semana);
    }
    for(i=0;i<n;i++){
        printf("O %i horario eh: ", i+1);
        printf("%i:%i:%i  - dia: %s\n", x[i].horas,
                             x[i].minutos,
                             x[i].segundos,
                             x[i].dia_semana);
    }
};


int main(void){

    Horarios listaHorarios[n]; //minha estrutura do tipo horario nomeada lista Horario COM A VARIAVEL ListaHorarios
    receberHorarios(listaHorarios); //chamar funcao

    return 0;
}
