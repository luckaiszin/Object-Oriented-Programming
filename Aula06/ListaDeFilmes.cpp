#include "ListaDeFilmes.h"

#include <iostream>

using namespace std;

// Implemente aqui os metodos necessarios
ListaDeFilmes::ListaDeFilmes(int quantidadeMaxima)
{
    filmes = new Filme *[quantidadeMaxima];
    this->quantidadeMaxima = quantidadeMaxima;
}

ListaDeFilmes::~ListaDeFilmes()
{
    delete filmes;
}

bool ListaDeFilmes::adicionar(Filme *f)
{

    for (int i = 0; i < this->quantidadeMaxima; i++)
    {
        if (filmes[i] == f)
        {
            return 0;
        }
        if (filmes[i] == NULL)
        {
            filmes[i] = f;
            return 1;
        }
    }
    return 0;
}

bool ListaDeFilmes::remover(Filme *f)
{

    int j;
    for (int i = 0; i < this->quantidadeMaxima; i++)
    {
        if (filmes[i] == f)
        {

            for (j = i; filmes[j + 1] != NULL; j++)
            {
                filmes[j] = filmes[j + 1];
            }
            filmes[j] = NULL;
            return 1;
        }
    }
    return 0;
}

int ListaDeFilmes::getQuantidadeDeFilmes()
{
    int i = 0;
    while (filmes[i] != NULL)
    {
        i++;
    }
    this->assistir = i;
    return this->assistir;
}

Filme **ListaDeFilmes::getFilmes()
{
    return filmes;
}

void ListaDeFilmes::imprimir()
{
    cout << "Lista com " << this->getQuantidadeDeFilmes() << " filmes a assistir:" << endl;
    for (int i = 0; i < this->getQuantidadeDeFilmes(); i++)
    {
        cout << "Filme " << i + 1 << ": ";
        this->getFilmes()[i]->imprimir();
        cout << endl;
    }
}
