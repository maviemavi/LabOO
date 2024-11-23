#include "Visitante.h"
#include <stdexcept>

Visitante::Visitante(int id, std::string nome, Data* inicio, Data* fim) 
    : Usuario(id, nome), inicio(inicio), fim(fim), dentro(false) {
    if (!inicio || !fim || inicio->diferenca(fim) >= 0) {
        throw std::logic_error("Datas inválidas para visitante");
    }
}

Visitante::~Visitante() {
    delete inicio;
    delete fim;
}

bool Visitante::entrar(Data* d) {
    if (dentro) return false; // Visitante já está dentro
    if (inicio->diferenca(d) > 0 || d->diferenca(fim) >= 0) {
        return false; 
    }
    dentro = true;
    return true;
}

bool Visitante::sair(Data* d) {
    if (!dentro) return false;
    dentro = false;
    return true;
}

bool Visitante::registrarEntradaManual(Data* d) {
    return false; 
}

bool Visitante::registrarSaidaManual(Data* d) {
    return false; 

Data* Visitante::getDataInicio() {
    return inicio;
}

Data* Visitante::getDataFim() {
    return fim;
}
