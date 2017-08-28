Estructura de Datos: Tarea Computacional
========================================

En este proyecto se buscar construir un programa que permita realizar operaciones aritméticas sobre polinomios. El programa debe lograr sumar, restar, multiplicar, dividir y derivar polinomios de una sola variable con coeficientes enteros. El programa debe soportar operaciones combinadas de estas operaciones.

### 1. Entrada de datos:

El programa debe leer los polinomios desde un archivo de texto. Asuma que la representación de un polinomio, siempre estará dada por pares de valores (coeficiente y exponente) separado por el símbolo `#` , en forma descendente (por exponente). Por ejemplo: 
El polinomio `P1 = 2x³-7x²+9x` estará representado por `P1 = 2#3#-7#2#9#1`.

*Considere como máximo: 5 polinomios de entrada; 6 expresiones. Donde cada expresión a lo más incluye 3 polinomios.*

```
Polinomios:
P1 = 2#3#-7#2#9#1
P2 = 5#2#10#1#-7#0
P3 = 4#2#-1#1#-10#0
P4 = 2#2#5#0

Expresiones:
P1+P2
(P1-P3)/p4
P1/P4
```

### 2. Salida de datos:

El programa debe mostrar por pantalla la lista completa de los polinomios, la operación y su
respectiva respuesta, según el siguiente formato.
```
Polinomios:
P1 = 2x^3-7x^2+9x^1
P2 = 5x^2+10x^1-7
P3 = 4x^2-1x^1-10
P4 = 2x^2+5

Operaciones:
P1+P2
Respuesta:
...
(P1-P3)/p4
Respuesta:
...
P1/P4
Respuesta:
...
```

Parte 1 (40%)
-------------

**Objetivo:** Realizar un diseño de la aplicación para dar respuesta a la problemática de operaciones de polinomios. Esta aplicación deberá contemplar, al menos, los siguientes aspectos:
- Elección de las estructuras de datos a utilizar.
- Esbozo de los algoritmos asociados a las siguientes acciones:
    - Captura de datos
    - Despliegue de resultados
    - Operaciones sobre polinomios
    - Otros

Parte 2 (60%)
-------------

**Objetivo:** Implementar en lenguaje C++ el diseño realizado en la **Parte 1**. Debe incorporar
P.O.O. y memoria dinámica, entre otros aspectos para la solución.

------------------

#### Autores:
- **Jorge Verdugo** ([@mapacheverdugo](https://github.com/mapacheverdugo/))
- **Javiera Vergara** ([@PollitoMayo](https://github.com/PollitoMayo/))

*Estructura de Datos*

*Primer semestre, 2017.*

*Facultad de Ingeniería*

*[Universidad Tecnológica Metropolitana](http://www.utem.cl)*
