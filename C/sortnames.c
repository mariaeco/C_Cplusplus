// Ordenando nomes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//TIPOS
struct registro{
    char nome[10];
    int idade;
};

//FUNÇÕES
void main(){
    FILE *arq; // criando a variável do arquivo
    struct registro dados[5];
    int i,j, lixo;
    char aux[10];

  //abrindo o arquivo
    arq = fopen("arquivo_nomes.txt", "r+");

  //mensagem para o usuário
    if (arq == NULL){
        printf("ERRO! O arquivo não foi aberto!\n");
    }
    else{
        printf("O arquivo aberto com sucesso!");
    }

    i = 0;
    j=0;
    fscanf(arq, "%s", dados[i].nome);

    while(!feof(arq)){ //Enquanto não for fim de arquivo

        //dados[i].idade = idade;
        fscanf(arq, "%c", &lixo); //necessario para ler os espaços
        fscanf(arq, "%c", &lixo);
        fscanf(arq, "%c", &lixo);
        fscanf(arq, "%d", &dados[i].idade);
        i = i+1;
        fscanf(arq, "%s", dados[i].nome);
    }

  // fechando arquivo
    fclose(arq);

    for (i=0; i<5; i++){ //exibindo os dados iniciais
        printf("\n%s %d", dados[i].nome, dados[i].idade);
    }

    //Ordenando os vetores e exibindo o novo arquivo
	for(i=0;i<5;i++){
        for(j=i+1;j<5;j++){
            if(dados.nome[0]>dados[j].nome[0]){
                strcpy(aux,dados.nome[i]);
                strcpy(dados[i].nome[i],dados[j].nome[j]);
                strcpy(dados[j].nome[j],aux);
            }
        }
	}


    arq = fopen("arquivo_nomes.txt", "w+");
    if(!arq){
        printf("\nNao foi possivel abrir o arquivo de saida\n")
        return;
    }
    for (i=0; i<5; i++){ //exibindo os dados iniciais
        fprintf(arq,"\n%s %d", dados[i].nome, dados[i].idade);
    }


    return;

}


