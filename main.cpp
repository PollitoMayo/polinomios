#include "include/Polinomio.h"
#include "include/funciones.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    string a = "23 4";
    Lista Polinomios;
    /*string archivo;
    cout << "Ingrese el nombre y/o ruta del archivo a abrir, con su sextension: ";
    cin >> archivo;
    leerArchivo(archivo);*/

    Polinomio P1("P1=5#3");
    Polinomio P2("4#2#3#1#7#0");
    //agregarPolinomio(P1, Polinomios);
    //agregarPolinomio(P2, Polinomios);
    //verLista(Polinomios);
    P1.dividir(P2).mostrar();
    //P1.multiplicar(P2).mostrar();
    cout << endl;
    P1.mostrar();

    return 0;
}
