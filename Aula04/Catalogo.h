#ifndef CATALOGO_H
#define CATALOGO_H

#define NUMERO_MAXIMO_VALORES 10

#include "Filme.h"

class Catalogo
{
private:
    Filme *f = new Filme;
    Filme *vetor_filme[NUMERO_MAXIMO_VALORES];
    int durTotal = 0;
    int quantidade = 0;

public:
    bool adicionar(Filme *f);
    int getQuantidade();
    int getDuracaoTotal();
    void imprimir();
};

#endif