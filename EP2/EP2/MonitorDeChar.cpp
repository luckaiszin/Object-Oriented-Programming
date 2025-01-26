#include "MonitorDeChar.h"
#include "Dado.h"
#include <stdexcept>

using namespace std;

MonitorDeChar::MonitorDeChar(){
}

MonitorDeChar::~MonitorDeChar(){
}

Dado* MonitorDeChar::ler(){
    throw new logic_error("");
}

void MonitorDeChar::escrever(Dado *d){
    cout << (char) d->getValor();
}
