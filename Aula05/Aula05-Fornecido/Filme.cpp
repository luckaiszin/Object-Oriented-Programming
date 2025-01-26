#include "Filme.h"

#include <iostream>

Filme::Filme(string nome, int duracao)
{
    this->nome = nome;
    this->duracao = duracao;
}

Filme::~Filme()
{
    cout <<"Filme "<<this->getNome() << " Destruido" << endl;
}

string Filme::getNome()
{
    return this->nome;
}

int Filme::getDuracao()
{
    return this->duracao;
}

void Filme::imprimir()
{
    cout << this->nome << " - " << this->duracao << " minutos" << endl;
}
