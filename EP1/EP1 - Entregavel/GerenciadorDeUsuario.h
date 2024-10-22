#ifndef GERENCIADORDEUSUARIO_H
#define GERENCIADORDEUSUARIO_H

#include "Usuario.h" 

class GerenciadorDeUsuario {
private:
    Usuario** usuarios = nullptr;
    int quantidadeUsuarios;
    int maximoUsuarios;

public:
    GerenciadorDeUsuario(int maximo);
    virtual ~GerenciadorDeUsuario();

    bool adicionar(Usuario* u);
    Usuario* getUsuario(int id);

    Usuario** getUsuarios();
    int getQuantidade();
};

#endif
