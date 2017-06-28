#include "../include/funciones.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void menu(int &r) {
    bool error = false;

    do {
        if (error) {
            system("cls");
            cout << "\n\n\tError, debe ingresar una opcion valida." << endl;
        }

        error = true;
        cout << "\n\n\tMENU \n\n" << endl;
        cout << "\t1. Agregar un polinomio" << endl;
        cout << "\t2. Eliminar un polinomio" << endl;
        cout << "\t3. Operar un polinomio" << endl;
        cout << "\t4. Ejecutar una expresion" << endl;
        cout << "\t5. Ver los polinomios registrados" << endl;
        cout << "\t6. Leer polinomios y expresiones de un archivo" << endl << endl;
        cout << "\t0. Salir\n" << endl;
        cout << "\tIngrese el numero de la operacion a ejecutar: ";
        cin >> r;
    } while(r < 0 || r > 6);
}

void submenu(int &r) {
    bool error = false;
    system("cls");
    do {
        if (error) {
            system("cls");
            cout << "\n\n\tError, debe ingresar una opcion valida." << endl;
        }
        error = true;
        cout << endl << endl << endl;
        cout << "\t\t1. Sumar polinomios" << endl;
        cout << "\t\t2. Restar polinomios" << endl;
        cout << "\t\t3. Multiplicar polinomios" << endl;
        cout << "\t\t4. Dividir polinomios" << endl;
        cout << "\t\t5. Derivar polinomios" << endl << endl;
        cout << "\t\t0. Salir" << endl;
        cout << "\t\tIngrese el numero de la operacion a ejecutar: ";
        cin >> r;
    } while(r < 0 || r > 5);
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

void leerArchivo(string nombre, Lista &L) {
    bool esPolinomio = false;
    bool esExpresion = false;
    ifstream archivo;

    archivo.open(nombre.c_str(), ios::in);
    if(archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }

    while(!archivo.eof()) {
        string linea;
        getline(archivo, linea);
        if(linea == "Polinomios:") {
            esPolinomio = true;
            esExpresion = false;
        } else if (linea == "Expresiones:") {
            esExpresion = true;
            esPolinomio = false;
        } else if (linea != "") {
            if(esPolinomio) {
                Polinomio P(linea);
                agregarPolinomio(P, L);
            } else if (esExpresion) {
                // leerExpresion
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

void recibirPolinomio(Lista &L) {
    string polinomio;
    cout << "Ingrese un polinomio: ";
    cin >> polinomio;
    Polinomio P(polinomio);
    agregarPolinomio(P, L);
}

void agregarPolinomio(Polinomio A, Lista &L){
    Lista p, q;
    p = L;

    q = new(nodo);
    q->info = A;
    q->Link = NULL;

    if (L == NULL){
        L = q;
    }
    else{
        while(p->Link != NULL){
            p = p->Link;
        }
        p->Link = q;
    }
}

void verPolinomios(Lista L) {
    if(L != NULL) {
        while(L != NULL) {
            L->info.mostrar();
            cout << endl;
            L = L->Link;
        }
    } else {
        cout << "No hay polinomios registrados" << endl;
    }
}

Polinomio buscarPolinomio(Lista L, string nombre) {
    if(L != NULL) {
        while(L != NULL) {
            if(L->info.getN() == nombre) {
                return L->info;
            }
            L = L->Link;
        }
    }
    return NULL;
}

void eliminarPolinomio(Lista &L, string nombre){
    if(L != NULL) {
        while(L != NULL) {
            if(L->info.getN() == nombre) {
                return L->info;
            }
            L = L->Link;
        }
    }
    return NULL;
}
