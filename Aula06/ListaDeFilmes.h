#ifndef LISTADEFILMES_H
#define LISTADEFILMES_H

#include "Filme.h"

class ListaDeFilmes
{
private:
    int quantidadeMaxima;
    int assistir;
    Filme **filmes;
    Filme *f;

public:
    ListaDeFilmes(int quantidadeMaxima);
    virtual ~ListaDeFilmes();

    bool adicionar(Filme *f);
    bool remover(Filme *f);
    Filme **getFilmes();
    int getQuantidadeDeFilmes();

    void imprimir();
};

#endif // LISTADEFILMES_H
