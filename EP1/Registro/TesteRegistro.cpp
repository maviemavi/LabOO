#include "Registro.h"
#include "Data.h"
#include <iostream>

using namespace std;

void teste1() {
    Data* data = new Data(10, 0, 0, 21, 10, 2024);
    Registro* reg = new Registro(data, true, false); 
    
    cout << "Teste 1 - Registro de Entrada Automático:\n";
    cout << "Data do registro: ";
    reg->getData()->imprimir();
    cout << "Tipo: " << (reg->isEntrada() ? "Entrada" : "Saída") << endl;
    cout << "Registro " << (reg->isManual() ? "manual" : "automático") << endl;

    delete reg;
}

void teste2() {
    Data* data = new Data(18, 30, 0, 22, 10, 2024); 
    Registro* reg = new Registro(data, false, true);

    cout << "\nTeste 2 - Registro de Saida Manual:\n";
    cout << "Data do registro: ";
    reg->getData()->imprimir();
    cout << "Tipo: " << (reg->isEntrada() ? "Entrada" : "Saida") << endl;
    cout << "Registro " << (reg->isManual() ? "manual" : "automatico") << endl;

    delete reg;
}
