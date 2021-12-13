// c++ jogodaadivinhacao.cpp -o prog ; ./prog
#include <iostream>
#include <cstdlib>

using namespace std;    //o marcador de uso das funções padrão de C++

int main(){
    cout << "*************************************" << endl;
    cout << "* Bem-Vindos ao jogo da adivinhacao *" << endl;
    cout << "*************************************" << endl;

    cout << "Escolha o seu nivel de dificuldade: " << endl;
    cout << "Facil (F), Medio (M) ou Dificil (D)" << endl;

    char dificuldade;
    cin >> dificuldade;
    
    int numero_de_tentativas;
    
    if(dificuldade == 'F')
        numero_de_tentativas = 15;
    else if(dificuldade == 'M')
        numero_de_tentativas = 10;
    else 
        numero_de_tentativas = 5;

    const int NUMERO_SECRETO = rand();

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;
    
    for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){
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
            break;
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
    if(nao_acertou){
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Voce acertou o numero secreto em " << tentativas 
            << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
    }
    
}