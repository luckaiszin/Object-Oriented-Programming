#include "Lancamento.h"

using namespace std;

Lancamento::Lancamento(int preco, int dataDeLancamento, string nome, int duracao) : Filme(nome, duracao), preco(preco), dataDeLancamento(dataDeLancamento)
{
}

Lancamento::~Lancamento()
{
}

int Lancamento::getPreco()
{
    return this->preco;
}

int Lancamento::getDataDeLancamento()
{
    return this->dataDeLancamento;
}

void Lancamento::imprimir()
{
    cout << this->nome << " sai em " << this->dataDeLancamento << " por " << this->preco << " reais" << endl;
}