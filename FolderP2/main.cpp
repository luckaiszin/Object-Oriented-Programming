#include "BancoDeRegistradores.h"
#include "MemoriaRAM.h"
#include "ESMapeadaNaMemoria.h"
#include "Dispositivo.h"
#include "Teclado.h"
#include "TecladoDeChar.h"
#include "Monitor.h"
#include "MonitorDeChar.h"
#include "UnidadeDeControle.h"
#include "GerenciadorDeMemoria.h"
#include <iostream>
using namespace std;

void Emulador_de_MIPS(MemoriaRAM *ram,UnidadeDeControle *Unit);
void Memoria(MemoriaRAM *ram);
void Registradores(UnidadeDeControle *Unit);

int main() {
    BancoDeRegistradores* registradores = new BancoDeRegistradores;
    MemoriaRAM* ram = new MemoriaRAM(64);
    ESMapeadaNaMemoria * esmapeada = new ESMapeadaNaMemoria(ram);
    Teclado* teclado = new Teclado;
    TecladoDeChar* tecladochar = new TecladoDeChar;
    Monitor* monitor = new Monitor;
    MonitorDeChar* monitorchar = new MonitorDeChar;

    esmapeada->adicionar(teclado);
    esmapeada->adicionar(tecladochar);
    esmapeada->adicionar(monitor);
    esmapeada->adicionar(monitorchar);

    UnidadeDeControle* Unit = new UnidadeDeControle(registradores, esmapeada);

    Emulador_de_MIPS(ram, Unit);

    return 0;
}

// Interface
void Emulador_de_MIPS(MemoriaRAM *ram, UnidadeDeControle *Unit) {
    while (1) {
        int opcao;
        cout << "Emulador de MIPS" << endl
             << "1) Memoria" << endl
             << "2) Registradores" << endl
             << "3) Executar proxima instrucao" << endl
             << "4) Executar ate PC = 0" << endl
             << "5) Load" << endl
             << "6) Dump" << endl
             << "0) Sair" << endl
             << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) { //tela Memoria
            cout << endl;
            Memoria(ram);
        }

        if(opcao == 2) { //tela Registradores
            Registradores(Unit);
        }

        if(opcao == 3) { //Executar proxima instrucao
            try {
                cout << endl << "PC: " << Unit->getPC() << endl;
                Unit->executarInstrucao();
                cout << "Instrucao executada" << endl;
                cout << "PC: " << Unit->getPC() << endl << endl;

            } catch(logic_error *e) {
                cout << "Erro: " << e->what();
                delete e;
            }
        }

        if(opcao == 4) {
            do {
                try {
                Unit->executarInstrucao();
                } catch(logic_error *e) {
                    cout << "Erro: " << e->what();
                    delete e;
                    break;
                }
            } while(Unit->getPC() != 0);
        }

        if(opcao == 5) {
            try {
                string arquivo;
                cout<< "Arquivo origem: ";
                cin >> arquivo;
                GerenciadorDeMemoria* G1 = new GerenciadorDeMemoria;
                G1->load(arquivo, ram);
            } catch(runtime_error *e) {
                cout << "Erro: " << e->what();
                delete e;
            }
        }

        if(opcao == 6) {
            try {
                string arquivo;
                cout<< "Arquivo origem: ";
                cin >> arquivo;
                GerenciadorDeMemoria* G2 = new GerenciadorDeMemoria;
                G2->dump(arquivo, ram);
            } catch(runtime_error *e) {
                cout << "Erro: " << e->what();
                delete e;
            }
        }

        if (opcao == 0) {
            cout << endl;
            delete Unit;
            break;
        }
    }
}


void Memoria(MemoriaRAM *ram) {
    while (1) {
        int opcao;
        cout << "Memoria" << endl
             << "1) Alterar valor" << endl
             << "2) Imprimir" << endl
             << "0) Voltar" << endl
             << "Escolha uma opcao: ";
        cin >> opcao;

        if(opcao == 1) {
            int pos, novo;
            cout << endl << "Posicao a ser alterada: ";
            cin >> pos;
            cout << "Novo valor: ";
            cin >> novo;
            cout << endl;
            Dado * d = new Dado(novo);
            ram->escrever(pos, d);
        }

        if(opcao == 2) {
            cout << endl;
            ram->imprimir();
            cout << endl;
        }

        if(opcao == 0) {
            cout << endl;
            break;  
        }
    }
}

void Registradores(UnidadeDeControle* Unit) {
    while(1) {
        int opcao;
        cout << endl
             << "Registradores" << endl
             << "1) Alterar valor" << endl
             << "2) Imprimir" << endl
             << "0) Voltar" << endl
             << "Escolha uma opcao: ";
        cin >> opcao;

        if(opcao == 1) {
            int r, novo;
            cout << "Registrador a ser alterado: ";
            cin >> r;
            cout << "Novo valor: ";
            cin >> novo;
            Unit->getBancoDeRegistradores()->setValor(r, novo);
        }

        if(opcao == 2) {
            cout << endl;
            Unit->getBancoDeRegistradores()->imprimir();
        }

        if(opcao == 0) {
            cout << endl;
            break;
        }
    }
}
