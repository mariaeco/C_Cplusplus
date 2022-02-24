/***
   NAME
     Aula10_alocacaoDinamicaStructure.c
   AUTOR:
     Maria Cardoso - Sept 08, 2021
   PURPOSE
    Usar alocacao dinamica com structures
***/
#include  "stdio.h"
#include <stdlib.h>

typedef struct  {
    char *nome;
    float salario;

    /* estrutura dentro de uma estrutura */
    struct nascimento {
        int ano;
        int mes;
        int dia;
    } dt_nascimento;
} ST_DADOS;

int main(void) {
    /* ponteiro para a estrutura */
    ST_DADOS *p;

    /* aloca��o de mem�ria para o ponteiro da estrutura */

    p = (ST_DADOS*) malloc(sizeof(ST_DADOS));
    p->nome = malloc(sizeof(char)); // alocacao toda dinamica uhuuuuuuu

    /* Um string (vetor de caracteres) � um ponteiro, por isto a aus�ncia do & no uso da fun��o scanf */
    printf("\nEntre com o nome -> ");
    scanf("%[^\n]", p->nome);

    printf("Entre com o salario -> ");
    scanf("%f", &p->salario);

    /* x -> � chamado de pointer member (apontador de membro). Ele � usado para referenciar um campo da estrutura no lugar do ponto (.) */
    printf("Entre com o nascimento (dd/mm/aaaa)-> ");
    scanf("%d/%d/%d", &p->dt_nascimento.dia, &p->dt_nascimento.mes, &p->dt_nascimento.ano);

    printf("\n===== Dados digitados ====");
    printf("\nNome = %s", p->nome);
    printf("\nSalario = %0.2f", p->salario);
    printf("\nNascimento = %d/%d/%d\n", p->dt_nascimento.dia, p->dt_nascimento.mes, p->dt_nascimento.ano);


    /* Libera memoria alocada para o ponteiro de estrutura */
    free(p);
    return 0;
}
