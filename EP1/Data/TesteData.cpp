#include "Data.h"

#include <iostream>

using namespace std;

void teste1() {
    Data* dt1 = new Data(10, 0, 0, 21, 10, 2024);
    Data* dt2 = new Data(9, 0, 0, 21, 10, 2024);

    cout << "Data 1: ";
    dt1->imprimir();
    
    cout << "Data 2: ";
    dt2->imprimir();

    int diferenca = dt1->diferenca(dt2);
    cout << "Diferenca entre Data 1 e Data 2 em segundos: " << diferenca << " segundos" << endl;

    delete dt1;
    delete dt2;
}

void teste2() {
    Data* dt1 = new Data(10, 0, 0, 22, 10, 2024);
    Data* dt2 = new Data(9, 0, 0, 21, 10, 2024);

    cout << "Data 1: ";
    dt1->imprimir();
    
    cout << "Data 2: ";
    dt2->imprimir();

    int diferenca = dt1->diferenca(dt2);
    cout << "Diferenca entre Data 1 e Data 2 em segundos: " << diferenca << " segundos" << endl;

    delete dt1;
    delete dt2;
}