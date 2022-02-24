/*
                AULA 2 C++: TIPOS: string
 Eh uma sequencia de caracteres
 Principais metodos:
 - size();//return length of a strings
 - empty();//test if string is empty
 - at(int i);//get character in a string
 - erase(); //Erase character from a string
 - replace();// replace portion of a string
 - copy(); //copy sequence of characters from a string
 - find(); //find content in a string
 - substr(); //generate substring
 - compare(); //compare two strings

 */
#include <iostream>
#include <string> //biblioteca para strings

int main(){

    using namespace std;

    string my_string1 = "My string";
    //string my_string1 ("My string"); // outra forma de atribuir valor a uma variavel
    string my_string2 = " is this!";
    string my_string3 = my_string1+my_string2; //concatenat two strings

    //print my_string3
    cout << my_string3 << endl;

// testando os metodos acima

    //1) empty(0
    if (my_string1.empty()){
        cout << "string vazia" << endl;
    }else{
        cout << "string preenchida" << endl;
    }

    //get a substring
    string strTest = my_string3.substr(3,6); // From my string3 I get "string"
    cout << strTest << endl;

    //find position -------------------------------------------------------------------------------------------------------------------------------------
    size_t posicao = my_string3.find("is"); // para o find precisamos do size_t --> tamanho
    cout << posicao << endl; // posicao inicial de "is"

    strTest = my_string3.substr(posicao); // from this position to the end
    cout << strTest << endl;

    //brincando:
    string frase ("There are two needles in this haystack with needles.");
    string tofind ("needle");
    size_t found = frase.find(tofind); //found eh do tipo size - find get the position
    if (found!=string::npos) //npos is a static member constant value with the greatest possible value for an element of type size_t.
        cout << "first 'needle' found at: " << found << '\n';

        //!=string::npos means different from the end of string


    //get a character -------------------------------------------------------------------------------------------------------------------------------------
    int i = 0; //posicao que quero extrair o caracter
    for (i=0; i<my_string1.length(); i++){
        cout << my_string1.at(i)<< endl;
    }

    //erase a character -------------------------------------------------------------------------------------------------------------------------------------
    cout << my_string3.erase(10)<< endl;// erase from position 10
    cout << my_string3<< endl;// vendo como ficou, remove direto na variavel

    //copy -------------------------------------------------------------------------------------------------------------------------------------
    char buffer[20];
    string str ("Test string...");
    size_t length = str.copy(buffer,6,5); // len = 6; Number of characters to copy
                                          // pos = 5; Position of the first character to be copied.
    cout << "buffer contains: " << buffer << '\n'; // endl == \n
    //observe que vai com um erro ao final, temos que inserir o caractere de finalzacao \0
    buffer[length]='\0';
    cout << "buffer contains: " << buffer << endl;/// veja que agora deu certo


    //replace -------------------------------------------------------------------------------------------------------------------------------------
    string replaceTeste = "poor writing";
    string substituindo = my_string3.replace(3,6,replaceTeste);
    cout << substituindo<< endl;
    //3 onde começo a substituir e 6 eh o numero de caracteres a serem substituidos
    //Nesse caso substitui a palavra string que consiste em 6 caracteres

    //compare -------------------------------------------------------------------------------------------------------------------------------------
    string strComp1 ("apple");
    string strComp2 ("apple");
    string strComp3 ("orange");

    if (strComp1.compare(strComp2) != 0){
        cout << strComp1 << " is not " << strComp2 << '\n';
    }else{
        cout << strComp1 << " is " << strComp2 << '\n';
    }

    if (strComp1.compare(strComp3) != 0){
        cout << strComp1 << " is not " << strComp3 << '\n';
    }else{
        cout << strComp1 << " is " << strComp3 << '\n';
    }

    return 0;
}
