#include "Usuario.h"
#include "Data.h"
#include <iostream>

using namespace std;

int main() {
    // Criação de instâncias da classe Data para simular diferentes momentos
    Data* dataEntrada1 = new Data(9, 0, 0, 15, 10, 2024);  // 09:00:00 15/10/2024
    Data* dataSaida1 = new Data(17, 0, 0, 15, 10, 2024);   // 17:00:00 15/10/2024
    Data* dataEntrada2 = new Data(9, 0, 0, 16, 10, 2024);  // 09:00:00 16/10/2024
    Data* dataSaida2 = new Data(17, 0, 0, 16, 10, 2024);   // 17:00:00 16/10/2024

    Usuario* usuario = new Usuario(1, "Maria", 10);

    if (usuario->entrar(dataEntrada1)) {
        cout << "Entrada 1 registrada com sucesso." << endl;
    } else {
        cout << "Erro ao registrar entrada 1." << endl;
    }

    if (usuario->sair(dataSaida1)) {
        cout << "Saida 1 registrada com sucesso." << endl;
    } else {
        cout << "Erro ao registrar saída 1." << endl;
    }

    if (usuario->entrar(dataEntrada2)) {
        cout << "Entrada 2 registrada com sucesso." << endl;
    } else {
        cout << "Erro ao registrar entrada 2." << endl;
    }

    if (usuario->sair(dataSaida2)) {
        cout << "Saida 2 registrada com sucesso." << endl;
    } else {
        cout << "Erro ao registrar saida 2." << endl;
    }

    int horasTrabalhadas = usuario->getHorasTrabalhadas(10, 2024);
    cout << "Horas trabalhadas em outubro de 2024: " << horasTrabalhadas << " horas" << endl;

    // Liberação de memória
    delete usuario;
    delete dataEntrada1;
    delete dataSaida1;
    delete dataEntrada2;
    delete dataSaida2;

    return 0;
}
