#include "Catalogo.h"
#include <iostream>

// Faca os includes necessarios e implemente os metodos pedidos no enunciado

Catalogo::Catalogo(int tamanhoMaximo) : tamanhoMaximo(tamanhoMaximo)
{
    filmes = new Filme *[tamanhoMaximo];
    quantidadeFilmes = 0;
    categorias = new string[tamanhoMaximo];
    quantidadeCategorias = 0;
}

Catalogo::~Catalogo()
{
    delete[] filmes;
    delete[] categorias;
}

bool Catalogo::adicionar(Filme *f)
{
    if (quantidadeFilmes >= tamanhoMaximo)
        return false;
    for (int i = 0; i < quantidadeFilmes; i++)
        if (f == filmes[i])
            return false;
    filmes[quantidadeFilmes++] = f;
    return true;
}

bool Catalogo::adicionar(string categoria)
{
    if (quantidadeCategorias >= tamanhoMaximo)
        return false;
    for (int i = 0; i < quantidadeCategorias; i++)
        if (categoria == categorias[i])
            return false;
    categorias[quantidadeCategorias++] = categoria;
    return true;
}

int Catalogo::getDuracaoTotal()
{
    int duracaoTotal = 0;
    for (int i = 0; i < quantidadeFilmes; i++)
        duracaoTotal += filmes[i]->getDuracao();
    return duracaoTotal;
}

int Catalogo::getTotalDeVisualizacoes()
{
    int visualizacoes = 0;
    for (int i = 0; i < quantidadeFilmes; i++)
        visualizacoes += filmes[i]->getVisualizacoes();
    return visualizacoes;
}

Filme **Catalogo::getFilmes()
{
    return filmes;
}

string *Catalogo::getCategorias()
{
    return categorias;
}

void Catalogo::imprimir()
{
    cout << this->quantidadeFilmes << " Filmes e " << this->quantidadeCategorias << " Categorias" << endl;
    for (int i = 0; i < this->quantidadeFilmes; i++)
    {
        filmes[i]->imprimir();
    }
}

Lancamento** Catalogo::getLancamentos(int &quantidadeLancamentos){

    Lancamento** L;
    L= new Lancamento*(tamanhoMaximo);


}
