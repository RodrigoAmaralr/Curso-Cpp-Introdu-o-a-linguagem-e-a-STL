#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

//g++ .\forca.cpp -o forca.exe ; .\forca.exe -std=c++11
//mingw32-make forca        Windows
//make forca                linux

string palavra_secreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_exite(char chute){
    for(char letra : palavra_secreta){
        if(chute == letra){
            return true;
        }
    }
    return false;
}

bool nao_acertou(){
    for(char letra : palavra_secreta){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

void imprime_cabecalho(){
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl;
    cout << endl;
}

void imprime_erros(){
    cout << "Chutes errados: ";
    for(char letra : chutes_errados){
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_palavra(){
    for(char letra : palavra_secreta){
        if(chutou[letra]){
            cout << letra << " ";
        }else{
            cout << "_ ";
        }
    }
    cout << endl;
}

void chuta(){
    cout << "Seu chute: ";
    char chute;
    cin >> chute;
    chutou[chute] = true;

    if(letra_exite(chute)){
        cout << "Voce acertou! Seu chute esta na palavra." << endl;
    }else{
        cout << "Voce errou! Seu chute nao esta na palavra" << endl;
        chutes_errados.push_back(chute);
    }
    cout << endl;
}

vector<string> le_arquivo(){
    ifstream arquivo;
    arquivo.open("palavras.txt");

    int quantidade_palavras;
    arquivo >> quantidade_palavras;

    vector<string> palavras_do_arquivo;
    for(int i = 0; i < quantidade_palavras; i++){
        string palavra_lida;
        arquivo >> palavra_lida;
        palavras_do_arquivo.push_back(palavra_lida);
    }
    return palavras_do_arquivo;
}

void sorteia_palavra(){
    vector<string> palavras = le_arquivo();
    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}

int main(){
    imprime_cabecalho();

    le_arquivo();
    sorteia_palavra();

    while(nao_acertou() && nao_enforcou()){
        imprime_erros();
        imprime_palavra();
        chuta();
    }
    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if(nao_acertou()){
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Parabens! Voce acertou a palavrar" << endl;
    }
}