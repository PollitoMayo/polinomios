#include "include/Polinomio.h"
#include "include/funciones.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main() {
    /*Polinomio P("1#5#2#3#-1#1#-8#0");
    Polinomio Q("1#2#-2#1#1#0");
    Polinomio P1("2#2");
    Polinomio P2("-2#2");
    Polinomio R = P1+P;
    cout << R << endl;*/

    int opcion1, opcion2;
    string archivo, nombre;
    Lista listaPolinomios = NULL;

    while(true) {

        menu(opcion1);

        switch(opcion1){
        case 1:
            system("cls");
            recibirPolinomio(listaPolinomios);
            break;
        case 2:
            system("cls");
            cout << "Ingrese el nombre del polinomio que desea eliminar: ";
            cin >> nombre;
            eliminarPolinomio(listaPolinomios, nombre);
            break;
        case 3:
            system("cls");
            verPolinomios(listaPolinomios);
            cout << "Ingrese el nombre del polinomio que quiere operar: ";
            cin >> nombre;
            //switchSubmenu(opcion2, listaPolinomios, nombre);
            break;
        case 4:
            system("cls");
            // leerExpresion
            break;
        case 5:
            system("cls");
            verPolinomios(listaPolinomios);
            break;
        case 6:
            system("cls");
            cout << "Ingrese el nombre y/o ruta del archivo a abrir, con su sextension: ";
            cin >> archivo;
            leerArchivo(archivo, listaPolinomios);
            break;
        default:
            system("cls");
            cout << "Terminando el programa..." << endl;
            return 0;
            break;
        }
    }
}
