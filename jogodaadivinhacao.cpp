// c++ jogodaadivinhacao.cpp -o prog ; ./prog
#include <iostream>

using namespace std;    //o marcador de uso das funções padrão de C++

int main(){
    cout << "*************************************" << endl;
    cout << "* Bem-Vindos ao jogo da adivinhacao *" << endl;
    cout << "*************************************" << endl;

    const int NUMERO_SECRETO = 42;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;
    
    while (nao_acertou){
        tentativas++;
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual e seu chute: ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos = pontos - pontos_perdidos;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;


        if(acertou){
            cout << "Parabens! Voce acertou o numero!" << endl;
            nao_acertou = false;
        }
        else if(maior){
            cout << "Seu chute " << chute 
            << " foi MAIOR que o numero secreto" << endl;
        }
        else{
            cout << "Seu chute " << chute 
            << " foi MENOR que o numero secreto" << endl;
        }
    }
    cout << "Fim de jogo!" << endl;
    cout << "Voce acertou o numero secreto em " << tentativas 
            << " tentativas" << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
}