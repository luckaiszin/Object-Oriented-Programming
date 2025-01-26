#ifndef DADO_H
#define DADO_H

using namespace std;

class Dado {
    private:
        int valor;
    public:
        Dado(int valor);
        virtual ~Dado();
        virtual int getValor();
        virtual void imprimir();
};

#endif