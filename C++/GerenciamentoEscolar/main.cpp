/*
PROGRAMA: GerenciamentoEscolar
Objetivos:
    Menu Inicial:
    - Cadastro (Gestão);
    - Registro (Professores);

    Menu de Cadastramento
    - Cadastrar turmas  (Cria, Lê, Atualiza e Deleta dados)
    - Cadastrar professores
    - Cadastrar alunos

    Menu de Registros
    - Registro de aulas
    - Registro de frequencia
    - Registro de notas
    - Resumo das notas

*/
#include <iostream>
#include <string>
#include <conio.h>
#include "menu.h"
#include "cadastroTurma.h"

#define TRUE 1
#define FALSE 0

void menu();

int main(){


    //using namespace std;
    menu();

    return 0;
}


void menu(){

    int var, var_gestor, var_turmas, var_prof;
    
    while (TRUE){
        var = menu_principal ();
        if (var == 1){
            var_gestor = menu_gestor();
            if (var_gestor == 1){ // acesso as turmas
                var_turmas = menu_turmas();
                    if (var_turmas == 1){
                        criarTurma(); //crio turmas
                        printTurmas(); // imprimindo turmas cadastradas
                    }else if (var_turmas == 2){
                        alteraTurma();
                    }else if (var_turmas == 3){
                        deletaTurma();                             
                    }else{
                        menu_gestor();
                    }
            } else{
                printf("campo ainda nao inserido");
            }
        } else if (var == 2){   
            printf("campo ainda nao inserido");
            var_prof = menu_professor(); 
        }
        else if (var == 3){
            exit (0);
        }
    }


}