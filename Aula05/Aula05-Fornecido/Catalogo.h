#ifndef CATALOGO_H
#define CATALOGO_H

#include "Filme.h"
using namespace std;


class Catalogo
{
private:
    Filme **filmes;
    int quantidadeMaxima;
    int quantidade;

public:
    Catalogo(int quantidadeMaxima);
    ~Catalogo();

    Filme **getFilmes();
    int getQuantidadeFilmes();
    int getQuantidadeMaximaFilmes();

    bool adicionar(Filme *filme);

    void imprimir();
};

#endif // CATALOGO_H
