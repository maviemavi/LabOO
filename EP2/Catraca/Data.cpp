#include "Data.h"
#include <iostream>

using namespace std;

Data::Data(int hora, int minuto, int segundo, int dia, int mes, int ano) {
    this->data->tm_hour = hora;
    this->data->tm_min = minuto;
    this->data->tm_sec = segundo;
    this->data->tm_mday = dia;
    this->data->tm_mon = mes - 1;
    this->data->tm_year = ano - 1900;
}

Data::~Data() {
}

int Data::getHora() {
    return data->tm_hour;
}

int Data::getMinuto() {
    return data->tm_min;
}

int Data::getSegundo() {
    return data->tm_sec;
}

int Data::getDia() {
    return data->tm_mday;
}

int Data::getMes() {
    return data->tm_mon + 1;
}

int Data::getAno() {
    return data->tm_year + 1900;
}

int Data::diferenca(Data* d) {
    time_t t2 = mktime(d->data);
    time_t t1 = mktime(data);

    double diferencaSegundos = difftime(t1, t2);

    return (int) diferencaSegundos;
}