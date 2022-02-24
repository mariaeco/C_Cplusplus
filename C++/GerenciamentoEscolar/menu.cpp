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
#include <string> //biblioteca para strings
#include <conio.h>
#include "menu.h"
#include "cadastroTurma.h"


int menu_principal(){

    int opcao;

    inicio:
    system("cls");
    //system("color 0F");
    std::cout << "Bem-Vindo ao Gerenciamento Escolar!\n" <<  std::endl;//criarConta();
    std::cout << "1 - Plataforma do Gestor \n2 - Plataforma do Professor \n3 - Sair" << std::endl;
    opcao = getch();
    switch (opcao) {
        case '1':
            system("cls");
            return 1; //chamar funcao 
            break;
        case '2':
            system("cls");
            return 2;
            break;
        case '3':
            system("cls");  
            return 3;
            break;
       default:
            printf("voce deve escolher uma opcao valida\n");
            printf("Precione qualquer tecla para voltar ao menu\n");
            system("pause");
            goto inicio;
    }
    setbuf (stdin, NULL);
    getchar ();
}

int menu_gestor(){

    int opcao;

    inicio:
    system("cls");
    
    std::cout << "Bem-Vindo a plataforma do Gestor!\n" <<  std::endl;//criarConta();
    std::cout << "1 - Cadastrar Turmas \n2 - Cadastrar alunos \n3 - Cadastrar Professor\n4 - Voltar ao Menu Principal" << std::endl;
    opcao = getch();
    switch (opcao) {
        case '1':
            system("cls");
            return 1; //chamar funcao 
            break;
        case '2':
            system("cls");
            return 2;
            break;
        case '3':
            system("cls");  
            return 3;
            break;
        case '4':
            system("cls");  
            return 0;
        default:
            printf("voce deve escolher uma opcao valida\n");
            printf("Precione qualquer tecla para voltar ao menu\n");
            system("pause");
            goto inicio;
    }
    setbuf (stdin, NULL);
    getchar ();
}

int menu_turmas(){

    int opcao;

    inicio:
    system("cls");
    //system("color 0F");
    std::cout << "1 - Criar Turma \n2 - Alterar Turma \n3 - Deletar Turma\n4 - Voltar ao Menu Gestor" << std::endl;
    opcao = getch();
    switch (opcao) {
        case '1':
            system("cls");
            return 1; //chamar funcao 
            break;
        case '2':
            system("cls");
            return 2;
            break;
        case '3':
            system("cls");  
            return 3;
            break;
        case '4':
            system("cls");  
            return 0;
        default:
            printf("voce deve escolher uma opcao valida\n");
            printf("Precione qualquer tecla para voltar ao menu\n");
            system("pause");
            goto inicio;
    }
    setbuf (stdin, NULL);
    getchar ();
}

int menu_professor(){

    int opcao;

    inicio:
    system("cls");
    //system("color 0F");
    
    std::cout << "1 - Registrar aula \n2 - Registrar Frequencia \n3 - Registrar Notas\n4 - Voltar ao Menu Principal" << std::endl;
    opcao = getch();
    switch (opcao) {
        case '1':
            system("cls");
            return 1;
            break;
        case '2':
            system("cls");
            return 2;
            break;
        case '3':
            system("cls");  
            return 3;
            break;
        case '4':
            system("cls");  
            return 0;
            break;
        default:
            printf("voce deve escolher uma opcao valida\n");
            printf("Precione qualquer tecla para voltar ao menu\n");
            system("pause");
            goto inicio;
    }
    setbuf (stdin, NULL);
    getchar ();
}

