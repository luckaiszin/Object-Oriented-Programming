#include "Filme.h"

#include <iostream>

using namespace std;

Filme::Filme(string nome, int duracao) : nome(nome), duracao(duracao), visualizacoes(0)
{
    if (this->getDuracao() <= 0)
        throw new invalid_argument("duracao invalida");
}

Filme::~Filme()
{
}

string Filme::getNome() const
{
    return this->nome;
}

int Filme::getDuracao() const
{
    return this->duracao;
}

int Filme::getVisualizacoes() const
{
    return this->visualizacoes;
}

void Filme::assistir(int tempo)
{
    double porcentagemAssistida = ((double)tempo) / duracao;
    if (porcentagemAssistida >= 0.7)
        visualizacoes++;
    if (tempo < 0 || tempo > this->getDuracao())
        throw new invalid_argument("tempo invalido");
}

void Filme::imprimir() const
{
    cout << this->nome << " - " << this->duracao << " minutos" << endl;
}
