#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct nodo{
    Polinomio info;
    struct nodo *Link;
};

typedef nodo *Lista;

void menu(int &);
void submenu(int &);
void verPolinomios(Lista);
int mayor(int, int);
int obtenerGrado(string);
void leerArchivo(string, Lista &);
void remover(string &, char);
void recibirPolinomio(Lista &);
void agregarPolinomio(Polinomio, Lista &);
Polinomio buscarPolinomio(Lista, string);

#endif // FUNCIONES_H_INCLUDED
