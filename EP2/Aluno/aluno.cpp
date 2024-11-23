#include "Aluno.h"
#include <stdexcept>

int Aluno::horaFim = 23;
int Aluno::minutoFim = 0;

Aluno::Aluno(int id, std::string nome) : Usuario(id, nome) {}

Aluno::~Aluno() {}

void Aluno::setHorarioFim(int hora, int minuto) {
    if (hora < HORARIO_INICIO || hora > 23 || minuto < 0 || minuto > 59) {
        throw std::logic_error("Horário de fim inválido");
    }
    horaFim = hora;
    minutoFim = minuto;
}

int Aluno::getHoraFim() {
    return horaFim;
}

int Aluno::getMinutoFim() {
    return minutoFim;
}

bool Aluno::entrar(Data* d) {
    if (d->getHora() < HORARIO_INICIO || 
        d->getHora() > horaFim || 
        (d->getHora() == horaFim && d->getMinuto() > minutoFim)) {
        return false;
    }
    return true;
}

bool Aluno::sair(Data* d) {
    return true; 
}

bool Aluno::registrarEntradaManual(Data* d) {
    return false; 
}

bool Aluno::registrarSaidaManual(Data* d) {
    return true; 
