#include <iostream>
#include <string>
using namespace std;

#include "Data.h"
#include "Registro.h"
#include "Usuario.h"
#include "GerenciadorDeUsuario.h"
#include "Catraca.h"

Data* fData(int hora, int minuto, int segundo, int dia, int mes, int ano) {
    Data *d = new Data(hora, minuto, segundo, dia, mes, ano);
    return d;
}

void opcao1(Catraca *catraca0, Catraca *catraca1) {
    int catraca, id, hora, min, seg, dia, mes, ano;

    cout << "Catraca: ";
    cin >> catraca;
    cout << endl;
    cout << "Id: ";
    cin >> id;
    cout << endl;
    cout << "Hora: ";
    cin >> hora;
    cout << endl;
    cout << "Minuto: ";
    cin >> min;
    cout << endl;
    cout << "Segundo: ";
    cin >> seg;
    cout << endl;
    cout << "Dia: ";
    cin >> dia;
    cout << endl;
    cout << "Mes: ";
    cin >> mes;
    cout << endl;
    cout << "Ano: ";
    cin >> ano;
    cout << endl;

    if(catraca == 0) {
        if(catraca0->entrar(id, fData(hora, min, seg, dia, mes, ano))) {
            cout << "[Entrada] Catraca 0 abriu: id " << id << endl << endl;
        } else {
            cout << "[Entrada] Catraca 0 travada" << endl << endl;
        }
    }

    if(catraca == 1) {
        if(catraca1->entrar(id, fData(hora, min, seg, dia, mes, ano))) {
            cout << "[Entrada] Catraca 1 abriu: id " << id << endl << endl;
        } else {
            cout << "[Entrada] Catraca 1 travada" << endl << endl;
        }
    }
}
void opcao2(Catraca *catraca0, Catraca *catraca1) {
    int pessoa, id, hora, min, seg, dia, mes, ano;

    cout << "Catraca: ";
    cin >> pessoa;
    cout << endl;
    cout << "Id: ";
    cin >> id;
    cout << endl;
    cout << "Hora: ";
    cin >> hora;
    cout << endl;
    cout << "Minuto: ";
    cin >> min;
    cout << endl;
    cout << "Segundo: ";
    cin >> seg;
    cout << endl;
    cout << "Dia: ";
    cin >> dia;
    cout << endl;
    cout << "Mes: ";
    cin >> mes;
    cout << endl;
    cout << "Ano: ";
    cin >> ano;
    cout << endl;

    if(pessoa == 0) {
        if(catraca0->sair(id, fData(hora, min, seg, dia, mes, ano))) {
            cout << "[Saida] Catraca 0 abriu: id " << id << endl << endl;
        } else {
            cout << "[Saida] Catraca 0 travada" << endl << endl;
        }
    }

    if(pessoa == 1) {
        if(catraca1->sair(id, fData(hora, min, seg, dia, mes, ano))) {
            cout << "[Saida] Catraca 1 abriu: id " << id << endl << endl;
        } else {
            cout << "[Saida] Catraca 1 travada" << endl << endl;
        }
    }
}
void opcao3(GerenciadorDeUsuario *gerenciador) {
    int id, hora, min, seg, dia, mes, ano;
    char eous;

    cout << "Entrada (e) ou Saida (s)? ";
    cin >> eous;
    cout << endl;
    cout << "Id: ";
    cin >> id;
    cout << endl;
    cout << "Hora: ";
    cin >> hora;
    cout << endl;
    cout << "Minuto: ";
    cin >> min;
    cout << endl;
    cout << "Segundo: ";
    cin >> seg;
    cout << endl;
    cout << "Dia: ";
    cin >> dia;
    cout << endl;
    cout << "Mes: ";
    cin >> mes;
    cout << endl;
    cout << "Ano: ";
    cin >> ano;
    cout << endl;

    if(eous == 'e') {
        if((gerenciador->getUsuario(id))->registrarEntradaManual(fData(hora, min, seg, dia, mes, ano))) {
            cout << "Entrada manual registrada: id " << id << endl << endl;
        } else {
            cout << "Erro ao registrar entrada manual" << endl << endl;
        }
    }

    if(eous == 's') {
        if((gerenciador->getUsuario(id))->registrarSaidaManual(fData(hora, min, seg, dia, mes, ano))) {
            cout << "Saida manual registrada: id " << id << endl << endl;
        } else {
            cout << "Erro ao registrar saida manual" << endl << endl;
        }
    }
}
void opcao4(GerenciadorDeUsuario *gerenciador) {
    int id;
    string nome;

    cout << "Id: ";
    cin >> id;
    cout << endl;
    cout << "Nome: ";
    cin >> nome;
    cout << endl;

    Usuario *u = new Usuario(id, nome, 10);

    if (gerenciador->adicionar(u)) {
        cout << "Usuario cadastrado com sucesso" << endl << endl;
    }
    else {
        cout << "Erro ao cadastrar o usuario" << endl << endl;
    }
}
void opcao5(GerenciadorDeUsuario *gerenciador) {
    int mes, ano;
    Usuario** usuarios = nullptr;
    usuarios = gerenciador->getUsuarios();

    cout << "Mes: ";
    cin >> mes;
    cout << endl;
    cout << "Ano: ";
    cin >> ano;
    cout << endl << endl;
    
    cout << "Relatorio de horas trabalhadas" << endl;

    for(int i = 0; i < gerenciador->getQuantidade(); i++) {
        cout << usuarios[i]->getNome() << ": " << usuarios[i]->getHorasTrabalhadas(mes, ano) << endl;
    }
    cout << endl;
}

void menu() {
    GerenciadorDeUsuario *gerenciador = new GerenciadorDeUsuario(10);
    Catraca *catraca0 = new Catraca(gerenciador);
    Catraca *catraca1 = new Catraca(gerenciador);

    int selecao;

    do {
    cout << "Acesso ao predio" << endl 
    << "1) Entrada" << endl 
    << "2) Saida" << endl 
    << "3) Registro manual" << endl
    << "4) Cadastro de usuario" << endl
    << "5) Relatorio" << endl
    << "0) Sair" << endl
    << "selecao uma opcao: ";
    cin >> selecao; 
    
    if (selecao == 1) {
        cout << endl << endl;
        opcao1(catraca0, catraca1);
    }

    if (selecao == 2) {
        cout << endl << endl;
        opcao2(catraca0, catraca1);
    }

    if (selecao == 3) {
        cout << endl << endl;
        opcao3(gerenciador);
    }

    if (selecao == 4) {
        cout << endl << endl;
        opcao4(gerenciador);
    }

    if (selecao == 5) {
        cout << endl << endl;
        opcao5(gerenciador);
    }

    } while (selecao != 0); 
}