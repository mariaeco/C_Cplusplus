/*==================================================================
 ====================================================================
                       C Course
        C - Structure usando vetores e passando por funcao
 ====================================================================
 ====================================================================*/
#include <stdio.h>
// Variavel Global
int n = 3;
//Estruturas
struct cadastroPassageiros {
    char nome[20];
    int idade;
};

//Funções
void receberCadastro(struct cadastroPassageiros list[n]); //chamando a funcao


int main(void){

    struct cadastroPassageiros listaCadastro[n]; //minha variavel de lista eh um vetor
    receberCadastro(listaCadastro); //chamar funcao

    return 0;
}

void receberCadastro(struct cadastroPassageiros x[n]){
    int i;

    for(i=0;i<n;i++){
        printf("Digite o nome do passageiro %i:", i+1);
        scanf("%s", x[i].nome);//%s[^\n]
        printf("Digite a idade do passageiro %i: ", i+1);
        scanf("%i", &x[i].idade);
    }
    for(i=0;i<n;i++){
        printf("Passageiro %i:\n ", i+1);
        printf("    Nome: %s\n", x[i].nome);
        printf("    Idade: %i\n", x[i].idade);
    }
}
