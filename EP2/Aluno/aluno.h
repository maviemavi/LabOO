#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include "Data.h"

class Aluno : public Usuario {
private:
    static int horaFim;
    static int minutoFim;
    static const int HORARIO_INICIO = 6;

public:
    Aluno(int id, std::string nome);
    virtual ~Aluno();

    static void setHorarioFim(int hora, int minuto);
    static int getHoraFim();
    static int getMinutoFim();

    bool entrar(Data* d) override;
    bool sair(Data* d) override;
    bool registrarEntradaManual(Data* d) override;
    bool registrarSaidaManual(Data* d) override;
};

#endif
