#include "BancoDeRegistradores.h"
#include <stdexcept>

using namespace std;

BancoDeRegistradores::BancoDeRegistradores() {

    for (int i = 0; i < QUANTIDADE_REGISTRADORES; i++) {
        registradores[i]= 0;
    }
}

BancoDeRegistradores::~BancoDeRegistradores() {
    delete[] registradores;
}

int BancoDeRegistradores::getValor(int registrador) {
    if (registrador < 0 || registrador > QUANTIDADE_REGISTRADORES)
        throw new logic_error ("Registrador Invalido");
    
    if (registrador > 0 && registrador < 32)
        return registradores[registrador];
    
    return 0;
}

void BancoDeRegistradores::setValor(int registrador, int valor) {
    if (registrador < 0 || registrador > QUANTIDADE_REGISTRADORES)
        throw new logic_error ("Registrador Invalido");
    
    if(registrador >= 0 && registrador < QUANTIDADE_REGISTRADORES)
        registradores[registrador] = valor;
}

void BancoDeRegistradores::imprimir() {
    for (int i = 0; i < QUANTIDADE_REGISTRADORES; i++) {
        cout << i << ":" << registradores[i] << endl;
    }
}