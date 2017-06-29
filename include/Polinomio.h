#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>

using namespace std;

class Polinomio {
    public:
        Polinomio();
        Polinomio(int);
        Polinomio(string);
        virtual ~Polinomio();
        int grado();
        void mostrar();
        void listar();
        void setC(int, int);
        void setN(string);
        int getC(int);
        string getN();
        int d(int);
        Polinomio sumar(Polinomio);
        Polinomio sumar(Polinomio, Polinomio);
        Polinomio restar(Polinomio);
        Polinomio restar(Polinomio, Polinomio);
        Polinomio multiplicar(Polinomio);
        Polinomio multiplicar(Polinomio, Polinomio);
        Polinomio dividir(Polinomio);
        Polinomio derivar();
    private:
        string nombre;
        int *coeficientes;
        int g;
        void llenar(string);
};

#endif // POLINOMIO_H
