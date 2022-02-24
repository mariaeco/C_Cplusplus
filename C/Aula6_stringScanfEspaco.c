/*==================================================================
 ====================================================================
                       C Course
                 C - String com espa�o usando scanf


 ====================================================================
 ====================================================================*/
#include <stdio.h>
//Fun�oes definidas


int main(void){

    char linha[100];//
    char caractere;
    int i;


    do{
        scanf("%[^\n]",linha);

    }while(caractere =! '\n');// \n eh o enter

    printf("\n%s \n",linha);
    system("pause");
    return 0;
}
