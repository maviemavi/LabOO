#include "Registro.h"

Registro::Registro(Data* d, bool entrada, bool manual) {
    this->data = d;
    this->entrada = entrada;
    this->manual = manual;
}

Registro::~Registro() {
    delete data;
}

Data* Registro::getData() {
    return data;
}

bool Registro::isEntrada() {
    return entrada;
}

bool Registro::isManual() {
    return manual;
}