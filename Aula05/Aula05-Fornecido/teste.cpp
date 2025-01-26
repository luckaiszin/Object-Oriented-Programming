#include <iostream>
#include <string>
#include "Filme.h"
#include "Catalogo.h"

using namespace std;

void teste1()
{
    // IMPLEMENTE seguindo o enunciado
    Filme *F1 = new Filme("Bao", 8);
    F1->imprimir();
    delete F1;
}

void teste2()
{
    // IMPLEMENTE seguindo o enunciado
    Catalogo *Cat = new Catalogo(4);
    Filme *F1 = new Filme("O magico de Oz", 100);
    Cat->adicionar(F1);
    Filme *F2 = new Filme("Alien", 120);
    Cat->adicionar(F2);
    Filme *F3= new Filme("E o vento levou", 240);
    Cat->adicionar(F3);
    Filme *F4= new Filme("Viagem ao Centro da Terra", 90);
    Cat->adicionar(F4);
    delete Cat;

}

int main()
{
    teste1();
    /*   teste2(); */
    return 0;
}
