#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>

using namespace std;

class Polinomio {
    public:
        string nombre;
        Polinomio();
        Polinomio(int);
        Polinomio(string);
        virtual ~Polinomio();
        int grado();
        void mostrar();
        void listar();
    private:
        int *coeficientes;
        int g;
        void llenar(string);
};

#endif // POLINOMIO_H
