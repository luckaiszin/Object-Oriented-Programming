#ifndef LANCAMENTO_H
#define LANCAMENTO_H
#include "Filme.h"
#include <string>

using namespace std;

class Lancamento : public Filme
{
public:
    Lancamento(string nome, int duracao);
    virtual ~Lancamento();
    virtual void assistir(int tempo);
};

#endif // LANCAMENTO_H
