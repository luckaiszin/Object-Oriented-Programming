#include "Catalogo.h"

#include <iostream>

Catalogo::Catalogo(int quantidadeMaxima)
{
    this->quantidadeMaxima = quantidadeMaxima;
    this->quantidade = 0;
    Filme **filmes = new Filme *[quantidadeMaxima];
}

Catalogo::~Catalogo()
{
    cout << "Catalogo com " << this->getQuantidadeFilmes() << " filme(s) destruido" << endl;

    for (int i = 0; i < quantidade; i++)
    {
        delete filmes[i];
    }
    delete[] filmes;
}

Filme **Catalogo::getFilmes()
{
    return this->filmes;
}

int Catalogo::getQuantidadeFilmes()
{
    return this->quantidade;
}

int Catalogo::getQuantidadeMaximaFilmes()
{
    return this->quantidadeMaxima;
}

bool Catalogo::adicionar(Filme *filme)
{
    if (this->quantidade >= this->quantidadeMaxima)
        return false;

    this->filmes[this->quantidade++] = filme;
    return true;
}

void Catalogo::imprimir()
{
    cout << "Catalogo com " << this->quantidade << " filmes" << endl;
    for (int i = 0; i < this->quantidade; i++)
        this->filmes[i]->imprimir();
}
