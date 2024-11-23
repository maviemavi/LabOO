#ifndef ENTRADA_H
#define ENTRADA_H

#include "Registro.h"

class Entrada : public Registro {
public:
    Entrada(Data* d, bool manual = false);
    virtual ~Entrada();
};

#endif
