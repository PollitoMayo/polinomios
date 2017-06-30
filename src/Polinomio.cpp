#include "../include/Polinomio.h"
#include "funciones.cpp"
#include <iostream>
#include <sstream>

using namespace std;

Polinomio::Polinomio() {
    grado = 0;
    coeficientes = new int[grado+1];
    coeficientes[0] = 0;
}

Polinomio::Polinomio(int g) {
    grado = g;
    coeficientes = new int[grado+1];
    for(int i=0; i<grado+1; i++) {
        coeficientes[i] = 0;
    }
}

Polinomio::Polinomio(string cadena) {
    grado = obtenerGrado(cadena);
    coeficientes = new int[grado+1];
    for(int i=0; i<grado+1; i++) {
        coeficientes[i] = 0;
    }
    llenar(cadena);
}

void Polinomio::llenar(string cadena) {
    int almohadillas = 0;
    int coeficiente;
    int exponente;
    string actual = "";
    bool esNombre = true;
    for(int i=0; i<cadena.length(); i++) {
        if(cadena[i] != '=' && esNombre) {
            actual += cadena[i];
        } else if (cadena[i] == '=' && esNombre) {
            remover(actual, ' ');
            remover(actual, '-');
            remover(actual, '+');
            nombre = actual;
            actual = "";
            esNombre = false;
            i++;
        }
        if(!esNombre) {
            if(cadena[i] == '#' || i == cadena.length()-1) {
                almohadillas++;
                if(i == cadena.length()-1 && cadena[i] != '#') {
                    actual += cadena[i];
                }
                if(almohadillas%2 == 0) {
                    remover(actual, '-');
                    istringstream(actual) >> exponente;
                    coeficientes[exponente] += coeficiente;
                } else if(almohadillas%2 != 0) {
                    istringstream(actual) >> coeficiente;
                }
                actual = "";
            } else {
                actual += cadena[i];
            }
        }
        if(i+1 == cadena.length() && esNombre) {    // En caso de que el polinomio venga sin nombre
            i = 0;
            esNombre = false;
        }
    }
}

Polinomio::~Polinomio() {
    // delete [] coeficientes;
}

int Polinomio::getG() {
    return grado;
}

void Polinomio::setC(int i, int c) {
    coeficientes[i] = c;
}

void Polinomio::setN(string r){
    nombre = r;
}

int Polinomio::getC(int i) {
    return coeficientes[i];
}

string Polinomio::getN() {
    return nombre;
}

bool Polinomio::operator == (const Polinomio &P) const {
    bool cero1 = true;
    bool cero2 = true;
    for(int i=0; i<grado+1; i++) {
        if(coeficientes[i] != 0) {
            cero1 = false;
        }
    }
    for(int i=0; i<P.grado+1; i++) {
        if(P.coeficientes[i] != 0) {
            cero2 = false;
        }
    }
    if(cero1 == cero2) {
        return true;
    } else if (grado != P.grado) {
        return false;
    } else {
        for(int i=0; i<grado+1; i++) {
            if(P.coeficientes[i] != coeficientes[i]) {
                return false;
            }
        }
    }
    return true;
}

Polinomio Polinomio::operator + (const Polinomio P) {
    int mayor;
    if(grado >= P.grado) {
        mayor = grado;
    } else {
        mayor = P.grado;
    }
    Polinomio R(mayor);
    for(int i=0; i<=mayor; i++) {
        if(grado > P.grado){
            if(i > P.grado){
                R.coeficientes[i] = R.coeficientes[i] + coeficientes[i];
            }
            else{
                R.coeficientes[i] = R.coeficientes[i] + P.coeficientes[i] + coeficientes[i];
            }
        }
        else{
            if(P.grado > grado){
                if(i > grado){
                    R.coeficientes[i] = R.coeficientes[i] + P.coeficientes[i];
                }
                else{
                    R.coeficientes[i] = R.coeficientes[i] + P.coeficientes[i] + coeficientes[i];
                }
            }
            else{
                R.coeficientes[i] = R.coeficientes[i] + P.coeficientes[i] + coeficientes[i];
            }
        }
    }
    Polinomio vacio;
    if(R == vacio) {
        return vacio;
    }
    return R;
}

Polinomio Polinomio::operator - (const Polinomio P) {
    int mayor;
    if(grado >= P.grado) {
        mayor = grado;
    } else {
        mayor = P.grado;
    }
    Polinomio R(mayor);
    if(grado >= P.grado) {
        for(int i=0; i<=grado; i++){
            R.coeficientes[i] = coeficientes[i];
        }
    } else {
        R = P;
    }
    for(int i=0; i<mayor; i++) {
        if(grado > P.grado){
            if(i <= P.grado){
                R.coeficientes[i] = R.coeficientes[i] - P.coeficientes[i];
            }
        }
        else{
            if(P.grado > grado){
                if(i <= grado){
                    R.coeficientes[i] = coeficientes[i] - R.coeficientes[i];
                }
            }
            else{
                if(R == P){
                    for(int i=0;i<=R.grado;i++){
                        R.coeficientes[i] = 0;
                    }
                }
                else{
                    R.coeficientes[i] = R.coeficientes[i] - P.coeficientes[i];
                }
            }
        }
    }
    Polinomio vacio;
    if(R == vacio) {
        return vacio;
    }
    return R;
}

Polinomio Polinomio::operator * (const Polinomio P) {
    Polinomio R(grado + P.grado);
    for(int i=0; i<grado+1; i++) {
        for(int j=0; j<P.grado+1; j++) {
            R.coeficientes[i+j] += coeficientes[i] * P.coeficientes[j];
        }
    }
    Polinomio vacio;
    if(R == vacio) {
        return vacio;
    }
    return R;
}

Polinomio Polinomio::operator * (const int a) {
    Polinomio R(grado);
    for(int i=0; i<grado+1; i++) {
        R.coeficientes[i] += coeficientes[i] * a;
    }
    Polinomio vacio;
    if(R == vacio) {
        return vacio;
    }
    return R;
}

Polinomio Polinomio::operator / (const Polinomio P) {
    Polinomio Paux(grado);
    for(int i=0; i <= Paux.grado; i++){
        Paux.coeficientes[i] = coeficientes[i];
    }
    if(grado < P.grado) {
        return NULL;
    } else {
        int gradoDividendo = Paux.grado;
        int gradoDivisor, gradoCociente, aux;
        Polinomio R(Paux.grado - P.grado);
        while(gradoDividendo >= P.grado){
            gradoDivisor = P.grado;
            gradoCociente = gradoDividendo - gradoDivisor;
            aux = gradoDividendo;
            R.coeficientes[gradoCociente] = Paux.coeficientes[gradoDividendo]/P.coeficientes[gradoDivisor];
            while(gradoDivisor >= 0) {
                Paux.coeficientes[gradoDividendo] -= R.coeficientes[gradoCociente] * P.coeficientes[gradoDivisor];
                gradoDividendo--;
                gradoDivisor--;
            }
            gradoDividendo = aux;
            gradoDividendo--;
        }
        return R;
    }
}

Polinomio Polinomio::operator % (const Polinomio P) {
    if(grado < P.grado) {
        return NULL;
    } else {
        int gradoDividendo = grado;
        int gradoDivisor, gradoCociente, aux;
        Polinomio R(grado - P.grado);
        while(gradoDividendo >= P.grado){
            gradoDivisor = P.grado;
            gradoCociente = gradoDividendo - gradoDivisor;
            aux = gradoDividendo;
            R.coeficientes[gradoCociente] = coeficientes[gradoDividendo]/P.coeficientes[gradoDivisor];
            while(gradoDivisor >= 0) {
                coeficientes[gradoDividendo] -= R.coeficientes[gradoCociente] * P.coeficientes[gradoDivisor];
                gradoDividendo--;
                gradoDivisor--;
            }
            gradoDividendo = aux;
            gradoDividendo--;
        }
        return *this;
    }
}

Polinomio Polinomio::derivar() {
    Polinomio R(grado-1);
    for(int i=1; i<grado+1; i++) {
        R.setC(i-1, i*coeficientes[i]);
    }
    return R;

}

void Polinomio::listar() {
    for(int i=0; i<grado+1; i++) {
        cout << "P[" << i << "]: " << coeficientes[i] << endl;
    }
}

ostream &operator << (ostream &output, const Polinomio &P){
    bool primero = true;
    if(P.nombre != "") {
        output << P.nombre << " = ";
    }
    for(int i=P.grado; i>=0; i--) {
        if(P.coeficientes[i] != 0 && P.grado != 0) {
            if(P.coeficientes[i] > 0 && !primero) {
                output << "+";
            }
            if(P.coeficientes[i] == -1) {
                output << "-";
            } else if (P.coeficientes[i] != 1 || (P.coeficientes[i] == 1 && i == 0)) {
                output << P.coeficientes[i];
            }
            if(i != 0) {
                output << "x";
                if(i != 1) {
                    output << "^" << i;
                }
            }
            if(primero) {
                primero = false;
            }
        } else if (P.grado == 0) {
            output << P.coeficientes[i];
        }
    }
    return output;
}
