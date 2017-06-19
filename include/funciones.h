#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct nodo{
    Polinomio info;
    struct nodo *Link;
};

typedef nodo *Lista;

int mayor(int, int);
int obtenerGrado(string);
void leerArchivo(string);
void remover(string &, char);
void agregarPolinomio(Polinomio, Lista &);
void verLista(Lista);

#endif // FUNCIONES_H_INCLUDED
