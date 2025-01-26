// Faca os includes necessarios
#include <iostream>
#include "Filme.h"
#include "Catalogo.h"

using namespace std;

void teste1()
{
    /*Implemente conforme o enunciado*/
    try
    {
        Filme *F1 = new Filme("", -1);
        Filme *F2 = new Filme("Matrix", 136);
        F2->assistir(-1);
        F2->assistir(137);
    }
    catch (invalid_argument *e)
    {
        cout << "Erro: " << e->what() << endl;
        delete e;
    }
}

void teste2()
{
    int i;
    /*Implemente conforme o enunciado*/
    Filme *F1 = new Filme("Matrix", 136);
    Filme *F2 = new Filme("Smurfs", 100);
    Catalogo *C = new Catalogo(2);
    C->adicionar(F1);
    C->adicionar(F2);
    try
    {
        Filme *F3;
        F3 = C->getFilmeMaisVisto();
    }
    catch ( SemVisualizacoes *e)
    {
        cout << "Erro: " << e->what()<<endl;
        delete e;
    }
}

void teste3()
{
    /*Implemente conforme o enunciado*/
}

int main()
{
    teste1(); // Substitua pelo teste que deseja efetuar
    return 0;
}
