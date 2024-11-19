#ifndef DATA_H
#define DATA_H
#include <ctime>

class Data {
private:
    tm* data = new tm;
public:
    // Construtor e Destrutor
    Data(int hora, int minuto, int segundo, int dia, int mes, int ano);
    virtual ~Data();

    // Getters
    int getHora();
    int getMinuto();
    int getSegundo();
    int getDia();
    int getMes();
    int getAno();
    void imprimir();

    // Método para calcular a diferença entre duas datas
    int diferenca(Data* d);
};



#endif
