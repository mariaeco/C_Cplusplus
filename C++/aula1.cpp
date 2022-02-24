//AULA 1 C++
#include <iostream>

//int main(){
//
//    std::cout << "Hello Word!" << std::endl;
//
//    return 0;
//}

//Tambem pode ser feito como abaixo, padronizando std antes para nao precisar chamar std toda vez q for usar
//using namespace std
//Mas nao eh uma boa pratica de programacao,pois pode dar conflito com funcoes com mesmo nome de outras bibliotecas

/* int main(){
 *
 *     cout << "Hello Word!" << endl;
 *
 *     return 0;
 * } */

 // o ideal eh usar dentro da funcao, e nao como global, assim:

 int main(){

    {
        using namespace std;
        cout << "Aqui nao precisa de std!" << endl;
    }
    std::cout << "Aqui precisa!" << std::endl;

    return 0;
}
