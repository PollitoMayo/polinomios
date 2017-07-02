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
void submenu(int &, Lista, string);
int switchSubmenu(int, Lista, string);
void verPolinomios(Lista);
int mayor(int, int);
int obtenerGrado(string);
void leerArchivo(string, Lista &);
void remover(string &, char);
void recibirPolinomio(Lista &);
void agregarPolinomio(Polinomio, Lista &);
void eliminarPolinomio(Lista &, string);
Polinomio buscarPolinomio(Lista, string);
Polinomio leerExpresion(string, Lista);
Polinomio operarExpresion(string, Lista);
Polinomio eval(string, Lista);

#endif // FUNCIONES_H_INCLUDED
