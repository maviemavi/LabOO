#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Usuario.h"
#include "Registro.h"
#include "Data.h"
#include <string>

class Funcionario : public Usuario {
private:
    int maximoRegistros;
    int quantidadeRegistros;
    Registro** registros; // Array de ponteiros para registros
    bool dentro;

public:
    Funcionario(int id, std::string nome, int maximo);
    virtual ~Funcionario();

    int getHorasTrabalhadas(int mes, int ano) override;
    bool entrar(Data* d) override;
    bool sair(Data* d) override;
    bool registrarEntradaManual(Data* d) override;
    bool registrarSaidaManual(Data* d) override;

    Registro** getRegistros();
    int getQuantidade();
};
