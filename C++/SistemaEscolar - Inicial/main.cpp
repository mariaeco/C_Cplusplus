/*
PROGRAMA: GerenciamentoEscolar
AUTOR: MARIA MARCOLINA CARDOSO
Objetivos: MEUS MENUS
    Menu Inicial:
    - Cadastro (Gestão);
    - Registro (Professores);

    Menu de Cadastramento
    - Cadastrar escola
    - Cadastrar turmas  (Cria, Lê, Atualiza e Deleta dados)
    - Cadastrar professores
    - Cadastrar alunos

    Menu de Registros
    - Registro de aulas
    - Registro de notas
    - Resumo das notas

*/
#include <iostream>
#include <string>
#include<vector>
#include "menu.h"
#include "cadastroProfessores.h"


using namespace std;


int main(){

    int choice = 0;
    vector <string> names;

    menu(choice, names);

    while(choice>0){
        menu(choice, names);
    }

    system("PAUSE");
    return 0;
}
