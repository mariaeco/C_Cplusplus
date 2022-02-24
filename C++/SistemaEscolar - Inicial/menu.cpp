/*
PROGRAMA: GerenciamentoEscolar
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
#include <vector>
#include "menu.h"
#include "cadastroProfessores.h"


using namespace std;


int menu(int &c, vector <string> &vec){

    system("cls");
    cout << "Bem-Vindo ao Gerenciamento Escolar!\n" <<  std::endl;//criarConta();
    cout << "1 - Adicionar professor \n2 - Achar cadastro de professor \n3 - Atualizar cadastro de professor \n4 - Remove professor\n5 - Mostrar professores cadastrados\n6 - Sair" << std::endl;
    cin >> c;
    
    //c = getch(); // getch lê char, portanto no switch os case devem entrar com case '1', case '2'....
    //biblioteca conio

    system("cls");
    switch(c){
        case 1: //add
            cadastrarProfessor(vec);
            break;
        case 2: //add
            findProf(vec);
            system("pause");
            break;
        case 3: //add
            replaceProf(vec);
            break;
        case 4: //remove
            deleteProf(vec);
            break;
        case 5: //print
            printProf(vec);
            break;
        case 6: // exit
            exit(0);
            break;
        default:
            cout << "Digite uma opcao valida!" << endl;
            break;
    }
    
}
