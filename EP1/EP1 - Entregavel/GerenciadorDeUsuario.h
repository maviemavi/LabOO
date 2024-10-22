#ifndef GERENCIADORDEUSUARIO_H
#define GERENCIADORDEUSUARIO_H

#include "Usuario.h" 

class GerenciadorDeUsuario {
private:
    Usuario** usuarios;
    int quantidadeUsuarios;
    int maximoUsuarios;

public:
    GerenciadorDeUsuario(int maximo);
    ~GerenciadorDeUsuario();

    bool adicionarUsuario(Usuario* u);
    Usuario* buscarUsuarioPorId(int id);

    Usuario** getUsuarios();
    int getQuantidade();
};

#endif
