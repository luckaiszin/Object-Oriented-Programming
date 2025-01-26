#ifndef GERENCIADOR_DE_MEMORIA_H
#define GERENCIADOR_DE_MEMORIA_H

#include "fstream"
#include "MemoriaRAM.h"

#include <string>

class GerenciadorDeMemoria{
private:
    ifstream input;
    ofstream output;
public:
    GerenciadorDeMemoria();
    virtual ~GerenciadorDeMemoria();
    virtual void load(string arquivo, MemoriaRAM* m);
    virtual void dump(string arquivo, MemoriaRAM* m);
};

#endif