/*
    Funcoes para cadastro de turma
*/
#include <iostream>
#include <string> //biblioteca para strings
#include <conio.h>
#include <vector>
#include "cadastroTurma.h"

using namespace std;


// FUNCOES ---------------------------------------------------------------------------------------------------
void imprimeTurmas(const vector<TURMA> &vec){


    cout << "TURMAS CADASTRADAS:" << endl;
    for(int i; i < vec.size(); i++){
        cout << "Turma " << i << ":" << vec[i].ano << vec[i].turma << endl;
    }

}


void criarTurma(){

    
    vector <TURMA> turmas;

    TURMA temp;

    cout << "Digite os dados da turma" <<  endl;
    cout << "Serie (1, 2, 3...): " <<  endl;//
    cin >> temp.ano;
    fflush(stdin);// para limpar o buffer
    cout << "Turma (A, B, C...): " <<  endl;//criarConta();
    cin >> temp.turma;

    system("cls");

	turmas.push_back(temp);

    cout << "Turma adicioada com sucesso" << endl;
    cout << "Turma :" << temp.ano << temp.turma << endl;
}

void printTurmas(){


    system("pause"); 
}

void alteraTurma(){
    std::cout << "TESTE OK!" << std::endl;
    system("pause"); 
}

void deletaTurma(){
    std::cout << "TESTE OK!" << std::endl;
    system("pause"); 
}


