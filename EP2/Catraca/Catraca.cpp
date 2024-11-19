#include "Catraca.h"
#include "GerenciadorDeUsuario.h"
#include "Usuario.h"

Catraca::Catraca (GerenciadorDeUsuario* g){
    this->gerenciador = g;
}

Catraca::~Catraca(){

}

bool Catraca::entrar (int id, Data* d){
    if (gerenciador-> getUsuario(id) == nullptr){
        return false;
    }
    return (gerenciador->getUsuario(id)->entrar(d));
}

bool Catraca::sair (int id, Data* d){
    if (gerenciador-> getUsuario(id) == nullptr){
        return false;
    }
    return (gerenciador->getUsuario(id)->sair(d));
}