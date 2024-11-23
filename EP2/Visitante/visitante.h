#ifndef VISITANTE_H
#define VISITANTE_H

#include "Usuario.h"
#include "Data.h"

class Visitante : public Usuario {
private:
    Data* inicio;
    Data* fim;
    bool dentro;

public:
    Visitante(int id, std::string nome, Data* inicio, Data* fim);
    virtual ~Visitante();

    bool entrar(Data* d) override;
    bool sair(Data* d) override;
    bool registrarEntradaManual(Data* d) override;
    bool registrarSaidaManual(Data* d) override;

    Data* getDataInicio();
    Data* getDataFim();
};

#endif
