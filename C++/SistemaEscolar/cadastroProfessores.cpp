/*
PROGRAMA: GerenciamentoEscolar
Objetivos: CADASTRO DE PROFESSORES

*/
#include <iostream>
#include <string>
#include<vector>
#include <bits/stdc++.h> //sort function
#include <algorithm>
#include "cadastroProfessores.h"
#include "menu.h"

using namespace std;

Professor::Professor(){

    Professor p;
    cout << "Digite o nome do professor: \n\n" << endl;
    cin >> p.nome;
    
}

vector<string> cadastrarProfessor(vector <string> &a){
    
}

void printProf(const vector <string> &vec){
    //function to sort names alphabetically
    if (vec.empty()){
        cout << "Nao ha professores cadastrados.\n\n" << endl;
        system("pause");
    }else{   
        vector <string> names;
        names = alphabaticallySort(vec);

        cout << "Professores cadastrados:" << endl;
        for(int i = 0; i < names.size(); i++){
            cout << i+1  << ": " << names[i] << endl;
        }
        puts("\n\n");
        system("pause");
    }
}

int findProf(vector <string> &vec){

    system("cls");

    string item;
    cout << "Digite a palavra que deseja encontrar:" << endl;
    cin >> item;
    int index;
    auto it = find(vec.begin(), vec.end(), item);

    if (find(vec.begin(), vec.end(), item)!=vec.end()) {
        cout << "Registro encontrado!\n\n" << endl;
        index = distance(vec.begin(), it);
    } else {
        cout << "Nao Registrado" << endl;
    }
 //   system("pause");

    return index;
}


vector<string> replaceProf(vector <string> &vec){

    string item, new_name;

    cout << "Digite o nome que deseja atualizar:" << endl;
    cin >> item;

    if (find(vec.begin(), vec.end(), item)!=vec.end()) {
        cout << "Registro Encontrado." << endl;
        cout << "Digite o nome atualizado:" << endl;
        cin >> new_name;
        replace(vec.begin(), vec.end(), item, new_name);
       
    } else {
        cout << "Nao Registrado" << endl;
    }
    system("pause");
   
   return vec;
}

vector<string> deleteProf(vector <string> &vec){
    
    int op;
    int index = findProf(vec);
    
    cout << "Deseja remover este Cadastro (Sim- 1; Nao:0)? " << endl;
    cin >> op;

    if(op==1){
        vec.erase(vec.begin() + index);
        cout << "Cadastro removido com sucesso" << endl;
        system("pause");
    }else{
        cout << "Cadastro nao removido" << endl;
        system("pause");
    }
    //remove(vec.begin(),vec.end(),item); //remove by value

    return vec;
}


/*@brief funcoes para ordenar nomes*/
bool mycomp(string a, string b){
 	//returns 1 if string a is alphabetically 
 	//less than string b
 	//quite similar to strcmp operation
 	return a<b;
}

vector<string> alphabaticallySort(vector <string> a){
 	int n=a.size();
 	//mycomp function is the defined function which 
 	//sorts the strings in alphabatical order
 	sort(a.begin(),a.end(),mycomp);
 	return a;
}

