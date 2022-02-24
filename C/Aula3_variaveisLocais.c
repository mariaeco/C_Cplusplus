/*==================================================================
 ====================================================================
                       C Course
               C - Variaveis Locais
 ====================================================================
 ====================================================================*/
#include <stdio.h>

int main(){

    void teste(void);

    teste(); //Mandando rodar 3 vezes para observar o que acontece
    teste();
    teste();

    return 0;
}

void teste(void){

    int variavelLocalAutomatica = 2;
    variavelLocalAutomatica *=2;
    printf("Local Automatica = %i\n",variavelLocalAutomatica);

    static int variavelLocalEstatica =2;
    variavelLocalEstatica *=2;
    printf("Local Estatica = %i\n",variavelLocalEstatica);

    /* OBSERVAÇOES
    1) Quando tenho uma funcao void, nao precisa do return.
    2) As variaveis locais apenas a funcao pode acessar. Caso vc coloque
        o printf la na main, nao vai funcionar, pois a main nao acessa elas.
    */

    /*
    Observe que a variavel estatica guarda o valor da multiplicacao,
    e quando chamo a funcao novamente ela multiplica pelo ultimo valor,
    e nao pelo valor inicial. Ja a variabel local automatica nao guarda,
    sempre reinicia do zero.
    */
}
