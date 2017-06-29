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
        void listar();
        void setC(int, int);
        void setN(string);
        int getG();
        int getC(int);
        string getN();
        bool operator == (const Polinomio&) const;
        Polinomio operator + (const Polinomio);
        Polinomio operator - (const Polinomio);
        Polinomio operator * (const Polinomio);
        Polinomio operator * (const int);
        Polinomio operator / (const Polinomio);
        Polinomio operator % (const Polinomio);
        friend ostream &operator << (ostream &, const Polinomio &);
        Polinomio derivar();
    private:
        string nombre;
        int *coeficientes;
        int grado;
        void llenar(string);
};

#endif // POLINOMIO_H
