 /*==================================================================
 ====================================================================
                       C Course
                     C - FUNÇÕES
 ====================================================================
 ====================================================================*/
#include <stdio.h>

int main(){
    float x, y;
    float calcularAreaRetang(float x, float y);

    float area = calcularAreaRetang(x,y);
    printf("A area eh: %f", area);
    return 0;
}

float calcularAreaRetang(float base, float altura){

    printf("Digite a Base do Retangulo:\n");
    scanf("%f",&base);
    printf("Digite a Altura do Retangulo:\n");
    scanf("%f", &altura);
    float area = base*altura;

    return area;
}

