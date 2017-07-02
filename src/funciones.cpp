#include "../include/funciones.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

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

int switchSubmenu(int opcion, Lista L, string nombreP1){
    string nombreP2;
    Polinomio P1, P2, PolinomioResultado; //P1 es el Polinomio ingresado por parametro, P2 es el Polinomio elegido dentro del submenu.
    P1 = buscarPolinomio(L, nombreP1);
    while(true){
        submenu(opcion);
        switch(opcion){
        case 1:
            verPolinomios(L);
            cout << "\nIngrese el nombre del polinomio que desea sumar: ";
            cin >> nombreP2;
            P2 = buscarPolinomio(L, nombreP2);
            PolinomioResultado = P1 + P2;
            system("cls");
            cout << PolinomioResultado << endl;
            break;
        case 2:
            verPolinomios(L);
            cout << "\nIngrese el nombre del polinomio que desea restar: ";
            cin >> nombreP2;
            P2 = buscarPolinomio(L, nombreP2);
            PolinomioResultado = P1 - P2;
            system("cls");
            cout << PolinomioResultado << endl;
            break;
        case 3:
            verPolinomios(L);
            cout << "\nIngrese el nombre del polinomio que desea multiplicar: ";
            cin >> nombreP2;
            P2 = buscarPolinomio(L, nombreP2);
            PolinomioResultado = P1 * P2;
            system("cls");
            cout << PolinomioResultado << endl;
            break;
        case 4:
            verPolinomios(L);
            cout << "\nIngrese el nombre del polinomio que desea dividir: ";
            cin >> nombreP2;
            P2 = buscarPolinomio(L, nombreP2);
            PolinomioResultado = P1 / P2;
            system("cls");
            cout << PolinomioResultado << endl;
            break;
        case 5:
            system("cls");
            PolinomioResultado = P1.derivar();
            cout << "La derivada es: " << PolinomioResultado << endl;
            break;
        default:
            system("cls");
            cout << "Terminando con las operaciones..." << endl;
            return 0;
        }
    }
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
            cout << "Polinomios:" << endl;
            esPolinomio = true;
            esExpresion = false;
        } else if (linea == "Expresiones:") {
            cout << endl << "Expresiones:" << endl;
            esExpresion = true;
            esPolinomio = false;
        } else if (linea != "") {
            if(esPolinomio) {
                Polinomio P(linea);
                cout << P << endl;
                agregarPolinomio(P, L);
            } else if (esExpresion) {
                cout << eval(linea, L) << endl;
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
    string nombrePolinomio;
    bool validar = true;
    int contador = 0;
    Lista p = L;

    while(validar){
        if(contador != 0){
            system("cls");
            cout << "\n\tError, este nombre ya existe.\n" << endl;
        }
        cout << "Ingrese un nombre para un polinomio: ";
        cin >> nombrePolinomio;
        if(p == NULL){
            validar = false;
        }
        else{
            while(p != NULL){
                if(nombrePolinomio.compare(p->info.getN()) == 0){
                    contador++;
                }
                p = p->Link;
            }
            if(contador == 0){
                validar = false;
            }
        }
    }
    cout << "Ingrese un polinomio: ";
    cin >> polinomio;

    Polinomio P(polinomio);
    P.setN(nombrePolinomio);
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
        cout << "Polinomio agregado." << endl;
    }
    else{
        while(p->Link != NULL){
            p = p->Link;
        }
        p->Link = q;
        cout << "Polinomio agregado." << endl;
    }
}

void verPolinomios(Lista L) {
    if(L != NULL) {
        while(L != NULL) {
            cout << L->info << endl;
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
    Lista p, q;
    int contador = 0;
    p = L;
    if(p->info.getN() == nombre){
        L = p->Link;
        delete p;
        contador++;
        cout << "Polinomio eliminado" << endl;
    }
    else{
        if(p->Link != NULL){
            q = p;
            p = p->Link;
            while(p != NULL){
                if(p->info.getN() == nombre){
                    q->Link = p->Link;
                    delete p;
                    contador++;
                    cout << "Polinomio eliminado" << endl;
                }
                p = p->Link;
                q = q->Link;
            }
        }
    }
    if(contador == 0){
        cout << "No hay un polinomio registrado con ese nombre" << endl;
    }
}

// EVAAAAAAAAAAAAAAAAAL

Polinomio eval(string cadena, Lista P) {
    class local {
    public:
        int pos = -1;
        char ch;
        string str;
        Lista L;
        Polinomio parsearTermino(string);
        Polinomio parsearFactor(string);

        local(string c, Lista A) {
            str = c;
            L = A;
        }

        void avanza() {
            pos++;
            if(pos < str.length()) {
                ch = str[pos];
            } else {
                ch = NULL;
                pos = -1;
            }
        }

        bool esSiguiente(char c) {
            while (ch == ' ') {
                avanza();
            }
            if (ch == c) {
                avanza();
                return true;
            }
            return false;
        }

        Polinomio parsearVariable() {
            /*if (esSiguiente('+')) {
                return parsearVariable(); // unary plus
            }
            if (esSiguiente('-')) {
                return -parsearVariable(); // unary minus
            }*/

            Polinomio R;
            int posInicial = pos;
            if (esSiguiente('(')) { // parentheses
                R = parsearTermino();
                esSiguiente(')');
            } else if (ch != '/' && ch != '*' && ch != '+' && ch != '-' && ch != NULL) { // numbers
                while (ch != '/' && ch != '*' && ch != '+' && ch != '-' && ch != NULL) {
                    avanza();
                }
                R = buscarPolinomio(L, str.substr(posInicial, pos-posInicial));
                cout << "Nombre: " << str.substr(posInicial, pos-posInicial) << endl;
                cout << "Polinomio; " << R << endl;
            /*} else if (ch >= 'a' && ch <= 'z') { // functions
                while (ch >= 'a' && ch <= 'z') {
                    avanzaChar();
                }
                string func = str.substr(startPos, this.pos);
                x = parseFactor();
                if (func == "sqrt") {
                    x = sqrt(x);
                } else if (func == "sin") {
                    x = sin(x);
                } else if (func == "cos") {
                    x = cos(x);
                } else if (func == "tan") {
                    x = tan(x);
                } else {
                    cout << "Error, se encontró una función desconocida: " << func << "()" << endl;
                }*/
            } else {
                cout << "Error, caracter inesperado: " << ch;
            }
            //if(eat('^')) x = Math.pow(x, parseFactor()); // exponentiation

            return R;
        }

        Polinomio parsearFactor() {
            Polinomio R = parsearVariable();
            for (;;) {                  // for infinito
                if (esSiguiente('*')) {
                    R = R * parsearVariable(); // multiplicacion
                } else if (esSiguiente('/')) {
                    R = R / parsearVariable(); // division
                } else {
                    return R;
                }
            }
        }

        Polinomio parsearTermino() {
            Polinomio R = parsearFactor();
            for(;;) {                    // for infinito
                if (esSiguiente('+')) {
                    R = R + parsearFactor(); // addition
                } else if (esSiguiente('-')) {
                    R = R - parsearFactor(); // subtraction
                } else {
                    return R;
                }
            }
        }
    };

    local E(cadena, P);
    E.avanza();
    Polinomio R = E.parsearTermino();
    if (E.pos < cadena.length()) {
        cout << "Error, caracter inesperado: " << E.ch;
    }
    return R;
}

Polinomio leerExpresion(string c, Lista L) {
    Polinomio R;
    int abreP = c.find_last_of('(');
    int parentesis = 0;
    bool primero = true;
    while(abreP != c.npos) {
        int cierraP = c.find_first_of(')');
        string expresion = c.substr(abreP+1, cierraP-abreP-1);
        if(primero) {

        }
        cout << expresion << endl;
        c.erase(abreP, cierraP-abreP+1);
        abreP = c.find_last_of('(');
    }
    cout << c << endl;
    return NULL;
}
