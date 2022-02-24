/*
                AULA 3 C++: Entrada e Saída
 */

 #include <iostream>
 #include <string>
 #include <stdio.h>

 using namespace std;

 int main(){

    string nome;

//    cout << "Digite seu nome completo:" << endl;
//    cin >> nome; // pega apenas a primeira palavra
//    cout << nome << endl;

    cout << "Digite seu nome completo:" << endl;
    getline(cin, nome);//leh uma linha
    cout << nome << endl;


    int x = 10;
    double dolar = 5.7;

    printf("x = %d\n", x); // veja q tb posso utilizar o printf em c++
    cout << (dolar);

    // Digitando varios valores
    int n1, n2, n3, media;


    cout << "\n\nDigite 3 notas" << endl;
    cin >> n1 >> n2 >> n3;

    media = (n1+n2+n3)/3;

    cout << "A media eh: " << media << endl;

    return 0;

 }
