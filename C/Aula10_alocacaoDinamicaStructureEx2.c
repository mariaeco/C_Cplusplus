/***
   NAME
     Aula10_alocacaoDinamicaStructureEx1.c
   AUTOR:
     Maria Cardoso - Sept 13, 2021
   PURPOSE
    Vetores de Struct
***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _livro{
    char *titulo;
    unsigned int num_paginas;
    float preco;
} Livro;

//funcao para construtor para livro
Livro *create_livro(const char *titulo, unsigned int num_paginas, float preco){

    Livro *livro;
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


int main(){

    int n = 3; //numero de livros que quero guardar

    Livro **livros = (Livro**)malloc(n*sizeof(Livro*));
    //livros->titulo = malloc(sizeof(char));

    livros[0] = create_livro("Harry Potter e o Prisionerio de Askaban", 200, 25);
    livros[1] =  create_livro("O Senhor dos Aneis", 500, 35);
    livros[2] =  create_livro("Duna I", 100,20);

    print_livro(livros[0]);

 //  for(int i=0; i<n; i++){
  //          print_livro(livros[i]);
  // }

   //destroy
    for(int i=0; i<n; i++){
            destroiLivro(&livros[i]);
    }
    free(*livros);
    livros = NULL;

    return 0;
}






