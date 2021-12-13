#include <iostream>
#include <string>
using namespace std;

//g++ .\forca.cpp -o forca.exe ; .\forca.exe -std=c++11
//mingw32-make forca        Windows
//make forca                linux

const string PALAVRA_SECRETA = "MELANCIA";

bool letra_exite(char chute){
    for(char letra : PALAVRA_SECRETA){
        if(chute == letra){
            return true;
        }
    }
    return false;
}

int main(){
    cout << PALAVRA_SECRETA << endl;

    bool nao_acertou = true;
    bool nao_enforcou = true;

    while(nao_acertou && nao_enforcou){
        char chute;
        cin >> chute;
        if(letra_exite(chute)){
            cout << "Voce acertou! Seu chute esta na palavra." << endl;
        }else{
            cout << "Voce errou! Seu chute nao esta na palavra" << endl;
        }
    }
}