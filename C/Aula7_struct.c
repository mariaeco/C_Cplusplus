/*==================================================================
 ====================================================================
                       C Course
                    C - Structure
 ====================================================================
 ====================================================================*/
#include <stdio.h>
//Funções

struct horario {
    int horas;
    int minutos;
    int segundos;
};

//Podemos definir ja a variavel agora assim, ou podemos definir varias, como agora, depois, antes
//mas eh melhor definir separadamente por organizacao
/*struct horario {
    int horas;
    int minutos;
    int segundos;
}; agora, depois, antes;*/


int main(void){

    struct horario agora; //minha estrutura do tipo horario nomeada de agora

    agora.horas = 13;  //definindo os valores
    agora.minutos = 35;
    agora.segundos = 24;

    printf("%i:%i:%i\n", agora.horas, agora.minutos,agora.segundos);

    return 0;
}
