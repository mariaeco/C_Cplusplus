/*==================================================================
 ====================================================================
                       C Course
              C - Variaveis Globais
 ====================================================================
 ====================================================================*/
#include <stdio.h>

int gvariavelGlobal =2; //Recomendado colocar o g na frente como padrao para saber que eh variavel global

int main(){

    void teste(void);
    printf("Global = %i\n",gvariavelGlobal);
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

    gvariavelGlobal *=2;
    printf("Global = %i\n",gvariavelGlobal);

    /* OBSERVAÇOES
    Veja que a global funciona tanto no main como na funcao.
    Observe que a Global funciona como estatica, pois guarda o valor a cada rodagem.
    */
}
