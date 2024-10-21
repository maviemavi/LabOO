#include "GerenciadorDeUsuario.h"
#include <iostream>

GerenciadorDeUsuario::GerenciadorDeUsuario(int maximo) {
    this->maximoUsuarios = maximo;
    this->quantidadeUsuarios = 0;
    this->usuarios = new Usuario*[maximo];
}

GerenciadorDeUsuario::~GerenciadorDeUsuario() {
    for (int i = 0; i < quantidadeUsuarios; i++) {
        delete usuarios[i];
    }
    delete[] usuarios;
}

bool GerenciadorDeUsuario::adicionarUsuario(Usuario* u) {
    if (quantidadeUsuarios >= maximoUsuarios) return false;
    usuarios[quantidadeUsuarios] = u;
    quantidadeUsuarios++;
    return true;
}

Usuario* GerenciadorDeUsuario::buscarUsuarioPorId(int id) {
    for (int i = 0; i < quantidadeUsuarios; i++) {
        if (usuarios[i]->getId() == id) {
            return usuarios[i];
        }
    }
    return nullptr;
}

Usuario** GerenciadorDeUsuario::getUsuarios() {
    return usuarios;
}

int GerenciadorDeUsuario::getQuantidade() {
    return quantidadeUsuarios;
}

