/*==================================================================
 ====================================================================
                       C Course 
                  C - Struct aninhadas
 ====================================================================
 ====================================================================*/
#include <stdio.h>
#include <string.h>
//#include<stdlib.h>

// Variavel Global
int n = 2;
//Estruturas
typedef struct{
    char dia_semana[10];
    int horas;
    int minutos;
    int segundos;
} Horarios;

typedef struct{
    char atividade[50];
    Horarios horario;
} Agenda;


//Fun��es
// com typedef tenho q colocar minha funcao antes e nao ha a necessidade de declarar ela antes
Agenda receberHorarios(Agenda *x){


    for(int i=0;i<n;i++){
        printf("Digite a atividade %i: ", i+1);
        scanf("%[^\n]",x[i].atividade);

        printf("Digite o %i horario (hh:mm:ss): ", i+1);
        scanf("%i:%i:%i", &x[i].horario.horas,
                            &x[i].horario.minutos,
                            &x[i].horario.segundos);    

        fflush(stdin);// para limpar o buffer 
        // eh acrescentado um \n ao final que interfere na proxima leitura, fflush limpa 
        
        printf("Digite o dia da semana (Domigo a Sabado): ");
        scanf("%[^\n]", x[i].horario.dia_semana);

        fflush(stdin);// para limpar o buffer

    }
}

void imprimeHorarios(Agenda *x){
    for(int i=0;i<n;i++){
        puts("\n-------------------------------------------------\n");
        printf("ATIVIDADE %i:\n", i+1);
        printf("%s\n",x[i].atividade);
        printf("Dia: %s\n",x[i].horario.dia_semana);
        printf("Hora: %i:%i:%i\n",x[i].horario.horas,
                                  x[i].horario.minutos,
                                  x[i].horario.segundos);
    }

    puts("\n");
}


int main(void){

    Agenda meuHorario[n];
    Agenda *ptrLista;

    ptrLista = meuHorario;

    receberHorarios(ptrLista); //chamar funcao
    imprimeHorarios(ptrLista);

    return 0;
}
