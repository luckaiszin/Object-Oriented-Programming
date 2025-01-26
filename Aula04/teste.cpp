#include <iostream>
#include <string>
#include "Filme.h"
#include "Catalogo.h"

using namespace std;

void teste1()
{
    Filme *F1 = new Filme;
    F1->setNome("Bao");
    F1->setDuracao(8);
    F1->imprimir();
}

void teste2()
{

    Filme *F1 = new Filme;
    F1->setNome("O Magico de Oz");
    F1->setDuracao(100);
    Filme *F2 = new Filme;
    F2->setNome("Alien");
    F2->setDuracao(120);
    Catalogo *Cat = new Catalogo;
    Cat->adicionar(F1);
    Cat->adicionar(F2);
    Cat->imprimir();
}

int main()
{
    teste1();
    teste2();
    return 0;
}