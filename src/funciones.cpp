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
                cout << linea;
                c++;
            }
        }
    }

    archivo.close();
}

