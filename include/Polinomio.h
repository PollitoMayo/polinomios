#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>

using namespace std;

class Polinomio {
    public:
        bool error = false;
        Polinomio();
        Polinomio(int);
        Polinomio(string);
        virtual ~Polinomio();
        void setN(string);
        string getN();
        bool operator == (const Polinomio&) const;
        bool operator == (const int&) const;
        bool operator != (const Polinomio&) const;
        bool operator != (const int&) const;
        Polinomio operator + (const Polinomio);
        Polinomio operator += (const Polinomio);
        Polinomio operator - (const Polinomio);
        Polinomio operator -= (const Polinomio);
        Polinomio operator * (const Polinomio);
        Polinomio operator *= (const Polinomio);
        Polinomio operator * (const int);
        Polinomio operator *= (const int);
        Polinomio operator / (const Polinomio);
        Polinomio operator /= (const Polinomio);
        Polinomio operator % (const Polinomio);
        friend ostream &operator << (ostream &, const Polinomio &);
        Polinomio der();
    private:
        string nombre;
        int *coeficientes;
        int grado;
        void llenar(string);
};

#endif // POLINOMIO_H
