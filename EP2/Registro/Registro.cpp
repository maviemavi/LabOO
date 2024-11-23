#include "Registro.h"

Registro::Registro(Data* d, bool entrada, bool manual) {
if (d==nullptr){ throw std::invalid_argument("data não pode ser um dia nulo");
}
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
