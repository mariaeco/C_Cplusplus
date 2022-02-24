#ifndef CADASTROTURMA_H
#define CADASTROTURMA_H
/*
    Prototipagem das variaveis e funcoes Cadastro Turma
*/

struct TURMA{
    int ano;
    char turma;
};

void criarTurma();
void alteraTurma();
void deletaTurma();
void printTurmas(); // imprime turmas cadastradas



#endif  // CADASTROTURMA_H