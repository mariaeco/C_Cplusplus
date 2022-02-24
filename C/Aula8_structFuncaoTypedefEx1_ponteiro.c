/*==================================================================
 ====================================================================
                       C Course
        C - Structure usando typedef // O FORMATO MAIS INDICADO
                Passando separando a função de impressão
Usando Ponteiros (ATENÇÃO - VER OS EXERCÍDIOS DE PONTEIROS ANTES DESSE)
// vetor de struct

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
Horarios receberHorarios(Horarios *x){

    for(int i=0;i<n;i++){
        printf("Digite o %i horario (hh:mm:ss): ", i+1);
        scanf("%i:%i:%i", &x[i].horas,
                            &x[i].minutos,
                            &x[i].segundos);

        fflush(stdin);// para limpar o buffer

        printf("Digite o dia da semana (Domigo a Sabado): ");
        scanf("%[^\n]",x[i].dia_semana);
    }
}

void imprimeHorarios(Horarios *x){
    for(int i=0;i<n;i++){
        printf("O %i horario eh: ", i+1);
        printf("%i:%i:%i  - dia: %s\n", x[i].horas,
                             x[i].minutos,
                             x[i].segundos,
                             x[i].dia_semana);
    }

}


int main(void){

    Horarios listaHorarios[n]; //minha estrutura do tipo horario nomeada lista Horario COM A VARIAVEL ListaHorarios
    Horarios *ptrLista;

    ptrLista = listaHorarios;

    receberHorarios(ptrLista); //chamar funcao
    imprimeHorarios(ptrLista);

    return 0;
}
