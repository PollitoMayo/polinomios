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
void remover(string &, char);
bool existePolinomio(string, Lista);
Polinomio validarPolinomio(Polinomio, Lista);
int contarPolinomios(Lista);

void menu(int &);

void recibirPolinomio(Lista &);
void agregarPolinomio(Polinomio, Lista &);

void eliminarPolinomio(Lista &, string);

Polinomio leerExpresion(string, Lista);

void verPolinomios(Lista);

void submenu(int &, Lista, string);
int switchSubmenu(int, Lista, string);

void leerArchivo(Lista &);

Polinomio eval(string, Lista);
Polinomio buscarPolinomio(Lista, string);

#endif // FUNCIONES_H_INCLUDED
