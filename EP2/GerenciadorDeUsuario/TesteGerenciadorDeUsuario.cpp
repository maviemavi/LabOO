#include "GerenciadorDeUsuario.h"
#include "Usuario.h"
#include "Data.h"
#include <iostream>

using namespace std;

int main() {
    GerenciadorDeUsuario* gerenciador = new GerenciadorDeUsuario(5);

    Usuario* usuario1 = new Usuario(1, "Maria", 10);
    Usuario* usuario2 = new Usuario(2, "Joao", 10);
    Usuario* usuario3 = new Usuario(3, "Ana", 10);

    if (gerenciador->adicionarUsuario(usuario1)) {
        cout << "Usuario 1 adicionado com sucesso." << endl;
    } else {
        cout << "Erro ao adicionar Usuario 1." << endl;
    }

    if (gerenciador->adicionarUsuario(usuario2)) {
        cout << "Usuario 2 adicionado com sucesso." << endl;
    } else {
        cout << "Erro ao adicionar Usuario 2." << endl;
    }

    if (gerenciador->adicionarUsuario(usuario3)) {
        cout << "Usuario 3 adicionado com sucesso." << endl;
    } else {
        cout << "Erro ao adicionar Usuario 3." << endl;
    }

    Usuario* busca = gerenciador->buscarUsuarioPorId(2);
    if (busca != nullptr) {
        cout << "Usuario encontrado: " << busca->getNome() << " (ID: " << busca->getId() << ")" << endl;
    } else {
        cout << "Usuario nao encontrado." << endl;
    }

    busca = gerenciador->buscarUsuarioPorId(4);
    if (busca != nullptr) {
        cout << "Usuario encontrado: " << busca->getNome() << " (ID: " << busca->getId() << ")" << endl;
    } else {
        cout << "Usuario com ID 4 nao encontrado." << endl;
    }

    delete gerenciador;

    return 0;
}
