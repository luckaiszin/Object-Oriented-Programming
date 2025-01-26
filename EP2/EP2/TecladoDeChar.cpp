#include "TecladoDeChar.h"
#include <stdexcept>
#include <iostream>

using namespace std;

TecladoDeChar::TecladoDeChar()
{
}

TecladoDeChar::~TecladoDeChar()
{
}

Dado *TecladoDeChar::ler()
{
    char caractere;
    cout << "Digite um caractere: ";
    cin >> caractere;
    Dado *d = new Dado((int)caractere);
    return d;
}
