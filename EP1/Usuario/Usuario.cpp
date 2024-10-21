#include "Usuario.h"
#include "Registro.h"
#include "Data.h"
#include <iostream>

// Construtor
Usuario::Usuario(int id, string nome, int maximo) {
    this->id = id;
    this->nome = nome;
    this->dentro = false;
    this->maximoRegistros = maximo;
    this->quantidadeRegistros = 0;
    this->registros = new Registro*[maximo];  // Alocação dinâmica de registros
}

// Destrutor
Usuario::~Usuario() {
    for (int i = 0; i < quantidadeRegistros; i++) {
        delete registros[i];  // Libera cada ponteiro de Registro
    }
    delete[] registros;  // Libera o vetor de registros
}

// Getters
string Usuario::getNome() {
    return nome;
}

int Usuario::getId() {
    return id;
}

// Função de entrada
bool Usuario::entrar(Data* d) {
    if (quantidadeRegistros >= maximoRegistros) return false;  // Limite de registros atingido
    if (dentro == true) return false;  // Usuário já está dentro
    if (quantidadeRegistros > 0 && registros[quantidadeRegistros - 1]->isEntrada()) return false;  // Última ação foi uma entrada

    registros[quantidadeRegistros] = new Registro(d, true, false);  // Cria um novo registro de entrada
    quantidadeRegistros++;
    dentro = true;  // Marca como "dentro"
    return true;
}

// Função de saída
bool Usuario::sair(Data* d) {
    if (quantidadeRegistros >= maximoRegistros) return false;  // Limite de registros atingido
    if (dentro == false) return false;  // Usuário já está fora
    if (quantidadeRegistros > 0 && !registros[quantidadeRegistros - 1]->isEntrada()) return false;  // Última ação foi uma saída

    registros[quantidadeRegistros] = new Registro(d, false, false);  // Cria um novo registro de saída
    quantidadeRegistros++;
    dentro = false;  // Marca como "fora"
    return true;
}

// Função para registrar entrada manual
bool Usuario::registrarEntradaManual(Data* d) {
    if (quantidadeRegistros >= maximoRegistros) return false;  // Limite de registros atingido
    if (dentro == true) return false;  // Usuário já está dentro
    if (quantidadeRegistros > 0 && registros[quantidadeRegistros - 1]->isEntrada()) return false;  // Última ação foi uma entrada

    registros[quantidadeRegistros] = new Registro(d, true, true);  // Registro manual de entrada
    quantidadeRegistros++;
    dentro = true;
    return true;
}

// Função para registrar saída manual
bool Usuario::registrarSaidaManual(Data* d) {
    if (quantidadeRegistros >= maximoRegistros) return false;  // Limite de registros atingido
    if (dentro == false) return false;  // Usuário já está fora
    if (quantidadeRegistros > 0 && !registros[quantidadeRegistros - 1]->isEntrada()) return false;  // Última ação foi uma saída

    registros[quantidadeRegistros] = new Registro(d, false, true);  // Registro manual de saída
    quantidadeRegistros++;
    dentro = false;
    return true;
}

// Função para calcular horas trabalhadas
int Usuario::getHorasTrabalhadas(int mes, int ano) {
    int totalSegundos = 0;

    for (int i = 0; i < quantidadeRegistros; i++) {
        Registro* reg = registros[i];
        if (reg->getData()->getMes() == mes && reg->getData()->getAno() == ano) {
            if (reg->isEntrada() && i + 1 < quantidadeRegistros && !registros[i + 1]->isEntrada()) {
                totalSegundos += registros[i + 1]->getData()->diferenca(reg->getData());  // Soma a diferença entre entrada e saída
            }
        }
    }

    return totalSegundos / 3600;  // Converte segundos para horas
}

// Retorna os registros
Registro** Usuario::getRegistros() {
    return registros;
}

// Retorna a quantidade de registros
int Usuario::getQuantidade() {
    return quantidadeRegistros;
}
