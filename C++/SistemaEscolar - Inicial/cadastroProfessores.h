#ifndef CADASTROPROFESSORES_H
#define CADASTROPROFESSORES_H

//Cadastrar professor
std::vector<std::string> cadastrarProfessor(std::vector <std::string> &a);// Cadastrar um professor
//Imprimir professores cadastrados
void printProf(const std::vector <std::string> &vec); //imprime professores
//Achar professor
int findProf(std::vector <std::string> &vec);
//Atualizar cadastro
std::vector<std::string> replaceProf(std::vector <std::string> &vec);
// Deletar registro
std::vector<std::string> deleteProf(std::vector <std::string> &vec);

//Sort names
bool mycomp(std::string a, std::string b);  //compare strings to sort names
std::vector<std::string> alphabaticallySort(std::vector <std::string> a); //sortnames


#endif // CADASTROPROFESSORES_H