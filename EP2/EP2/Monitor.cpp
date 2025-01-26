#include "Monitor.h"
#include <stdexcept>

using namespace std;

Monitor::Monitor(){
}

Monitor::~Monitor(){
}

Dado* Monitor::ler(){
    throw new logic_error("");
}

void Monitor::escrever(Dado *d){
    cout << d->getValor();
}