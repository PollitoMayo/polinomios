#include "../include/funciones.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

void remover(string &cadena, char caracter) {
    string resultado = "";
    for(int i=0; i<cadena.length(); i++) {
        if(cadena[i] != caracter) {
            resultado += cadena[i];
        }
    }
    cadena = resultado;
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
        cout << "\t3. Eliminar TODOS los polinomio" << endl;
        cout << "\t4. Operar un polinomio" << endl;
        cout << "\t5. Ejecutar una expresion" << endl;
        cout << "\t6. Ver los polinomios registrados" << endl;
        cout << "\t7. Leer polinomios y expresiones de un archivo (Recomendado)" << endl << endl;
        cout << "\t0. Salir\n" << endl;
        cout << "\tIngrese el numero de la operacion a ejecutar: ";
        cin >> r;
    } while(r < 0 || r > 7);
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
        cout << "\t\t5. Dividir polinomios y obtener el resto" << endl << endl;
        cout << "\t\t6. Derivar polinomio" << endl << endl;
        cout << "\t\t0. Salir" << endl << endl;
        cout << "\t\tIngrese el numero de la operacion a ejecutar: ";
        cin >> r;
    } while(r < 0 || r > 6);
}

int switchSubmenu(int opcion, Lista L, string nombreP1){
    string nombreP2;
    Polinomio P1, P2, PolinomioResultado; //P1 es el Polinomio ingresado por parametro, P2 es el Polinomio elegido dentro del submenu.
    P1 = buscarPolinomio(L, nombreP1);
    while(true){
        submenu(opcion);
        switch(opcion){
        case 1:
            system("cls");
            verPolinomios(L);
            cout << endl << P1 << endl << endl;
            cout << "Ingrese el nombre del polinomio que desea sumar: ";
            cin >> nombreP2;
            while(!existePolinomio(nombreP2, L)) {
                system("cls");
                verPolinomios(L);
                cout << endl << P1 << endl;
                cout << endl << "Error: No existe ningun polinomio con el nombre " << nombreP2 << endl;
                cout << "Ingrese el nombre del polinomio que quiere operar: ";
                cin >> nombreP2;
            }
            P2 = buscarPolinomio(L, nombreP2);
            PolinomioResultado = P1 + P2;
            system("cls");
            cout << P1 << endl;
            cout << P2 << endl;
            cout << endl << P1.getN() << "+" << P2.getN() << " = " << PolinomioResultado << endl;
            break;
        case 2:
            system("cls");
            verPolinomios(L);
            cout << endl << P1 << endl << endl;
            cout << "Ingrese el nombre del polinomio que desea restar: ";
            cin >> nombreP2;
            while(!existePolinomio(nombreP2, L)) {
                system("cls");
                verPolinomios(L);
                cout << endl << P1 << endl;
                cout << endl << "Error: No existe ningun polinomio con el nombre " << nombreP2 << endl;
                cout << "Ingrese el nombre del polinomio que quiere operar: ";
                cin >> nombreP2;
            }
            P2 = buscarPolinomio(L, nombreP2);
            PolinomioResultado = P1 - P2;
            system("cls");
            cout << P1 << endl;
            cout << P2 << endl;
            cout << endl << P1.getN() << "-" << P2.getN() << " = " << PolinomioResultado << endl;
            break;
        case 3:
            system("cls");
            verPolinomios(L);
            cout << endl << P1 << endl << endl;
            cout << "Ingrese el nombre del polinomio que desea multiplicar: ";
            cin >> nombreP2;
            while(!existePolinomio(nombreP2, L)) {
                system("cls");
                verPolinomios(L);
                cout << endl << P1 << endl;
                cout << endl << "Error: No existe ningun polinomio con el nombre " << nombreP2 << endl;
                cout << "Ingrese el nombre del polinomio que quiere operar: ";
                cin >> nombreP2;
            }
            P2 = buscarPolinomio(L, nombreP2);
            PolinomioResultado = P1 * P2;
            system("cls");
            cout << P1 << endl;
            cout << P2 << endl;
            cout << endl << P1.getN() << "*" << P2.getN() << " = " << PolinomioResultado << endl;
            break;
        case 4:
            system("cls");
            verPolinomios(L);
            cout << endl << P1 << endl << endl;
            cout << "Ingrese el nombre del polinomio que desea dividir: ";
            cin >> nombreP2;
            while(!existePolinomio(nombreP2, L)) {
                system("cls");
                verPolinomios(L);
                cout << endl << P1 << endl;
                cout << endl << "Error: No existe ningun polinomio con el nombre " << nombreP2 << endl;
                cout << "Ingrese el nombre del polinomio que quiere operar: ";
                cin >> nombreP2;
            }
            P2 = buscarPolinomio(L, nombreP2);
            PolinomioResultado = P1 / P2;
            system("cls");
            cout << P1 << endl;
            cout << P2 << endl;
            if(PolinomioResultado.error) {
                cout << "No se pudo realizar la operacion. El dividendo tiene menor grado que el divisor." << endl;
            } else {
                cout << endl << P1.getN() << "/" << P2.getN() << " = " << PolinomioResultado << endl;
            }
            break;
        case 5:
            system("cls");
            verPolinomios(L);
            cout << endl << P1 << endl << endl;
            cout << "Ingrese el nombre del polinomio que desea dividir para obtener el resto: ";
            cin >> nombreP2;
            while(!existePolinomio(nombreP2, L)) {
                system("cls");
                verPolinomios(L);
                cout << endl << P1 << endl;
                cout << endl << "Error: No existe ningun polinomio con el nombre " << nombreP2 << endl;
                cout << "Ingrese el nombre del polinomio que quiere operar: ";
                cin >> nombreP2;
            }
            P2 = buscarPolinomio(L, nombreP2);
            system("cls");
            cout << P1 << endl;
            PolinomioResultado = P1 % P2;
            cout << P2 << endl;

            if(PolinomioResultado.error) {
                cout << "No se pudo realizar la operacion. El dividendo tiene menor grado que el divisor." << endl;
            } else {
                cout << endl << P1.getN() << "%" << P2.getN() << " = " << PolinomioResultado << endl;
            }
            break;
        case 6:
            system("cls");
            P1.setN("");
            cout << "f(x) = " << P1 << endl << endl;
            PolinomioResultado = P1.der();
            cout << "f'(x) = " << PolinomioResultado << endl;
            break;
        default:
            system("cls");
            cout << "Terminando con las operaciones . . ." << endl;
            return 0;
        }
    }
}

int contarPolinomios(Lista L) {
    int c = 0;
    if(L != NULL) {
        while(L != NULL) {
            c++;
            L = L->Link;
        }
    }
    return c;
}

bool existePolinomio(string nombre, Lista L) {
    if(L != NULL) {
        while(L != NULL) {
            if(L->info.getN() == nombre) {
                return true;
            }
            L = L->Link;
        }
    }
    return false;
}

void eliminarTodos(Lista &L) {
    Lista p = L;
    if(L != NULL) {

        while(p != NULL) {
            L->Link = p->Link;
            delete p;
            p = L;
        }
    }
    return false;
}

Polinomio validarPolinomio(Polinomio P, Lista L) {
    Polinomio R = P;
    string aux;
    while(existePolinomio(R.getN(), L) || R.getN() == "der" || R.getN() == "") {
        cout << "Error: No se puede agregar el polinomio " << R;
        if(R.getN() == "der") {
            cout << ". Hay un conflico con la funcion der()" << endl;
        } else if (R.getN() == ""){
            cout << ". Debe tener un nombre definido." << endl;
        } else {
            cout << ". Ya existe un polinomio con ese nombre" << endl;
        }
        cout << endl << "Ingrese un nombre distinto para el polinomio: ";
        cin >> aux;
        R.setN(aux);
        system("cls");
    }
    return R;
}

void recibirPolinomio(Lista &L) {
    string polinomio;
    cout << "Ingrese un polinomio: ";
    cin >> polinomio;
    Polinomio P(polinomio);

    agregarPolinomio(P, L);
}

void leerArchivo(Lista &L) {
    string nombre;
    int errores = 0;
    int agregados = 0;
    bool esPolinomio = false;
    bool esExpresion = false;
    ifstream archivo;

    do {
        if (errores > 0) {
            system("cls");
            cout << "Error. No se pudo abrir el archivo." << endl;
        }
        cout << "Ingrese el nombre y/o ruta del archivo a abrir, con su extension: ";
        cin >> nombre;
        archivo.open(nombre.c_str(), ios::in);
        errores++;
    } while (archivo.fail());

    system("cls");

    while(!archivo.eof()) {

        string linea;
        getline(archivo, linea);
        remover(linea, ' ');
        if(linea == "Polinomios:") {
            esPolinomio = true;
            esExpresion = false;
        } else if (linea == "Expresiones:") {
            cout << "Polinomios:" << endl;
            verPolinomios(L);
            cout << endl << "Expresiones:" << endl;
            esExpresion = true;
            esPolinomio = false;
        } else if (linea != "") {
            if(esPolinomio) {
                Polinomio P(linea);
                agregarPolinomio(P, L);
                agregados++;
            } else if (esExpresion) {
                if(eval(linea, L).error) {
                    cout << "No se pudo operar la expresion '" << linea << "'. Puede que exista una division incorrecta." << endl;
                } else {
                    cout << eval(linea, L) << endl;
                }

            }
        }
    }

    if (agregados != 1) {
        cout << endl << agregados << " polinomios agregados";
    } else {
        cout << endl << agregados << " polinomio agregado";
    }
    archivo.close();
}

void agregarPolinomio(Polinomio A, Lista &L){
    Lista p, q;
    p = L;

    q = new(nodo);
    q->info = validarPolinomio(A, L);
    q->Link = NULL;

    if (L == NULL){
        L = q;
    } else {
        while(p->Link != NULL){
            p = p->Link;
        }
        p->Link = q;
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
        cout << "Se eliminó correctamente el polinomio " << p->info << endl;
        delete p;
    } else {
        if(p->Link != NULL){
            q = p;
            p = p->Link;
            while(p != NULL){
                if(p->info.getN() == nombre){
                    q->Link = p->Link;
                    cout << "Se eliminó correctamente el polinomio " << p->info << endl;
                    delete p;
                }
                q = q->Link;
                p = q->Link;
            }
        }
    }
}

// EVAAAAAAAAAAAAAAAAAL

Polinomio eval(string cadena, Lista P) {
    class local {
    public:
        int pos;
        char ch;
        string str;
        Lista L;
        Polinomio parsearTermino(string);
        Polinomio parsearFactor(string);

        local(string c, Lista A) {
            pos = -1;
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

            Polinomio R;
            int posInicial = pos;
            if (esSiguiente('(')) {
                R = parsearTermino();
                esSiguiente(')');
            } else if (ch == 'd' && str[pos+1] == 'e' && str[pos+2] == 'r') {
                while (ch != '(') {
                    avanza();
                }
                R = parsearTermino();
                R = R.der();
            } else if (ch != '/' && ch != '*' && ch != '+' && ch != '-' && ch != '(' && ch != ')' && ch != NULL) {
                while (ch != '/' && ch != '*' && ch != '+' && ch != '-' && ch != '(' && ch != ')' && ch != NULL) {
                    avanza();
                }
                R = buscarPolinomio(L, str.substr(posInicial, pos-posInicial));
                // cout << "Polinomio: " << R << endl;
                // cout << "Nombre: " << str.substr(posInicial, pos-posInicial) << endl;
            } else {
                cout << "Error, caracter '" << ch << "' inesperado en la posicion " << pos;
            }

            return R;
        }

        Polinomio parsearFactor() {
            Polinomio R = parsearVariable();
            for (;;) {
                if (esSiguiente('*')) {
                    R = R * parsearVariable();
                } else if (esSiguiente('/')) {
                    R = R / parsearVariable();
                } else {
                    return R;
                }
            }
        }

        Polinomio parsearTermino() {
            Polinomio R = parsearFactor();
            for(;;) {
                if (esSiguiente('+')) {
                    R = R + parsearFactor();
                } else if (esSiguiente('-')) {
                    R = R - parsearFactor();
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
        cout << "Error, caracter '" << E.ch << "' inesperado en la posicion " << E.pos;
    }
    return R;
}
