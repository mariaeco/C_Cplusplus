/***
   NAME
     Aula10_alocacaoDinamicaStructureEx1.c
   AUTOR:
     Maria Cardoso - Sept 13, 2021
   PURPOSE
    Um programa que usa um struct apontando para outro struct.
    O struct livro, seria minha livraria, e tenho os alunos que utilizam essa livraria.
    Assim, tenho um struct Aluno que utiliza o struct livro, mas o livro nao depende do aluno.
***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _livro{
    char titulo[100];
    unsigned int num_paginas;
    float preco;
} Livro;

/*Nesse formato acima Livro nao eh minha variavel, mas eh o meu tipo, e _livro e o apelido, que nao irei utilizar
No formato abaixo, o nome da minha struct sera _livro e a variavel eh Livro:
struct _livro{
    char titulo[100];
    unsigned int num_paginas;
    float preco;
}; Livro; // seria o mesmo que struct _livro Livro
*/
typedef struct _aluno{
    char nome[100];
    int idade;
    Livro *livro_fav; // veja que aqui o tipo eh Livro
} Aluno;

//funcao para construtor para livro
Livro *create_livro(const char *titulo, unsigned int num_paginas, float preco){
    Livro *livro = (Livro*)malloc(sizeof(Livro)); // alocando espaco para minha struct Livro na variavel livro

    strcpy(livro->titulo, titulo);
    livro->num_paginas = num_paginas;
    livro->preco = preco;

    return livro;
}

//funcao para imprimir o livro
void print_livro(const Livro *livro){
    puts("MINHA BIBLIOTECA");
    printf("Titulo: %s\n", livro->titulo);
    printf("Num paginas: %d\n", livro->num_paginas);
    printf("Valor: R$%0.2f\n", livro->preco);
    puts("***************************************");
}

//Desalocar Livro
void destroiLivro(Livro **livro_ref){
    Livro *livro = *livro_ref;
    free(livro);
    *livro_ref = NULL;
}

Livro *copy_livro(const Livro *livro) {
    return create_livro(livro->titulo, livro->num_paginas, livro->preco);
}

Aluno *create_aluno(const char *nome, int idade,  const Livro *livro_fav) {

    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));

    strcpy(aluno->nome, nome);
    aluno->idade = idade;
    aluno->livro_fav = copy_livro(livro_fav);
    //O ideal eh fazer uma  copia do livro, para isso  criamos a funcao copy_livro
    // assim,  quando formos desalocar nos desalocamos a copia,
    // e nao  apagamos  todos os registros do livro, que poderiam ainda ser utilizados por outro aluno.

    return aluno;
}


void print_aluno(const Aluno *aluno){
    puts("\n\nALUNO:");
    printf("Nome: %s\n", aluno->nome);
    printf("Idade: %d\n", aluno->idade);
    puts("Livro Favorito:");
    puts("-----");
    print_livro(aluno->livro_fav);
}

void destroy_aluno(Aluno **aluno_ref) {
    Aluno *aluno = *aluno_ref;

    destroiLivro(&aluno->livro_fav);
    free(aluno);
    *aluno_ref = NULL;
}
int main(){


    Livro *livro1 = create_livro("Harry Potter e o Prisionerio de Askaban", 200, 25);
    Livro *livro2 = create_livro("O Senhor dos Aneis", 500, 35);

    print_livro(livro1);
    print_livro(livro2);

    Aluno *ted = create_aluno("Ted", 17, livro2);

    print_aluno(ted);

    destroiLivro(&livro1); // tem q passar o endereco de memoria
    destroiLivro(&livro2);
    destroy_aluno(&ted);
    puts("\n\nTestando o desalocamento:");
    printf("livro1==NULL? %d\n", livro1 == NULL);// Se desalocou, tá 1, ok



    return 0;
}






