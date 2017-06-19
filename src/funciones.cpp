#include "../include/funciones.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void test() {
    cout << "Prueba con exito" << endl;
}

int mayor(int a, int b) {
    if(a > b || a == b) {
        return a;
    }
    return b;
}

int obtenerGrado(string cadena) {
    int grado = -1;
    int aux;
    int almohadillas = 0;
    string actual;
    for(int i=0; i<cadena.length(); i++) {
        if(cadena[i] == '#' || i == cadena.length()-1) {
            almohadillas++;
            if(i == cadena.length()-1 && cadena[i] != '#') {
                actual += cadena[i];
            }
            if(almohadillas%2 == 0) {
                istringstream(actual) >> aux;
                grado = mayor(grado, aux);
            }
            actual = "";

        } else {
            actual += cadena[i];
        }
    }
    return grado;
}

void leerArchivo(string nombre) {
    ifstream archivo;

    archivo.open(nombre.c_str(), ios::in);
    if(archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }

    while(!archivo.eof()) {
        string linea;
        getline(archivo, linea);
        int c = 0;
        for(int i=0; i<linea.length(); i++) {
            if(linea[i] == '=') {
                cout << linea << endl;
                c++;
            }
        }
    }

    archivo.close();
}

void remover(string &cadena, char caracter) {
    string resultado = "";
    for(int i=0; i<cadena.length(); i++) {
        if(cadena[i] != caracter) {
            resultado += cadena[i];
        }
    }
    cadena = resultado;
}

void agregarPolinomio(Polinomio A, Lista &L){
    Lista p, q;
    p = L;

    q = new(nodo);
    q->info = A;
    q->Link = NULL;

    if (p == NULL){
        L = q;
    }
    else{
        while(p != NULL){
            p = p->Link;
        }
        p->Link = q;
    }
}

void verLista(Lista L){
    Lista p;
    p = L;
    if(p != NULL){
        while(p != NULL){
            p->info.mostrar();
            cout << endl;
            p = p->Link;
        }
    }
}
