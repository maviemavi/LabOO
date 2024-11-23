#include "Funcionario.h"
#include <iostream>

// Construtor
Funcionario::Funcionario(int id, std::string nome, int maximo)
    : Usuario(id, nome), maximoRegistros(maximo), quantidadeRegistros(0), dentro(false) {
    registros = new Registro*[maximo];
}

// Destrutor
Funcionario::~Funcionario() {
    for (int i = 0; i < quantidadeRegistros; i++) {
        delete registros[i];
    }
    delete[] registros; 

bool Funcionario::entrar(Data* d) {
    if (quantidadeRegistros >= maximoRegistros) return false; 
    if (dentro) return false;
    if (quantidadeRegistros > 0 && registros[quantidadeRegistros - 1]->isEntrada()) return false; // Última ação foi entrada

    registros[quantidadeRegistros] = new Registro(d, true, false); 
    quantidadeRegistros++;
    dentro = true;
    return true;
}

bool Funcionario::sair(Data* d) {
    if (quantidadeRegistros >= maximoRegistros) return false;
    if (!dentro) return false; 
    if (quantidadeRegistros > 0 && !registros[quantidadeRegistros - 1]->isEntrada()) return false; // Última ação foi saída

    registros[quantidadeRegistros] = new Registro(d, false, false); 
    quantidadeRegistros++;
    dentro = false;
    return true;
}

bool Funcionario::registrarEntradaManual(Data* d) {
    if (quantidadeRegistros >= maximoRegistros) return false;
    if (dentro) return false;
    if (quantidadeRegistros > 0 && registros[quantidadeRegistros - 1]->isEntrada()) return false;

    registros[quantidadeRegistros] = new Registro(d, true, true); 
    quantidadeRegistros++;
    dentro = true;
    return true;
}


bool Funcionario::registrarSaidaManual(Data* d) {
    if (quantidadeRegistros >= maximoRegistros) return false;
    if (!dentro) return false;
    if (quantidadeRegistros > 0 && !registros[quantidadeRegistros - 1]->isEntrada()) return false;

    registros[quantidadeRegistros] = new Registro(d, false, true); 
    quantidadeRegistros++;
    dentro = false;
    return true;
}


int Funcionario::getHorasTrabalhadas(int mes, int ano) {
    int totalSegundos = 0;

    for (int i = 0; i < quantidadeRegistros; i++) {
        Registro* reg = registros[i];
        if (reg->getData()->getMes() == mes && reg->getData()->getAno() == ano) {
            if (reg->isEntrada() && i + 1 < quantidadeRegistros && !registros[i + 1]->isEntrada()) {
                totalSegundos += registros[i + 1]->getData()->diferenca(reg->getData());
            }
        }
    }

    return totalSegundos / 3600; 
}


Registro** Funcionario::getRegistros() {
    return registros;
}

int Funcionario::getQuantidade() {
    return quantidadeRegistros;
}
