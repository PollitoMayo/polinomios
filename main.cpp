#include "include/Polinomio.h"
#include "include/funciones.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    int opcion;
    string archivo;
    Lista listaPolinomios;
    listaPolinomios = NULL;

    while(true) {

        menu(opcion);

        switch(opcion){
        case 1:
            system("cls");
            recibirPolinomio(listaPolinomios);
            break;
        case 2:
            system("cls");
            //Eliminar
            break;
        case 3:
            system("cls");
            //Operar
            //Submenu
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
