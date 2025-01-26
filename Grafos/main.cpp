#include "Grafo.h"

using namespace std;

int main()
{

    Grafo *G = new Grafo(4);
    G->imprimir();
    cout << G->Grau(2) << endl;
    delete G;

    return 0;
}