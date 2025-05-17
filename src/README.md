# Evaluador de Notación Polaca Inversa (RPN) con Árboles Binarios

## 📝 Descripción:
Programa en C que evalúa expresiones matemáticas en notación polaca inversa (RPN) utilizando una pila implementada manualmente. Soporta operadores básicos (+, -, *, /, ^) y puede leer entradas desde consola o archivos.


### 📚 Notación Polaca Inversa (RPN)

La notación polaca inversa (o postfija) es un formato matemático donde los operadores siguen a sus operandos. Elimina la necesidad de paréntesis al definir explícitamente el orden de las operaciones.

🔗 Wikipedia: [Notación Polaca Inversa](https://es.wikipedia.org/wiki/Notaci%C3%B3n_polaca_inversa)
Ejemplo:

    Infija (tradicional): (3 + 4) * 2

    RPN (postfija): 3 4 + 2 * → Resultado: 14

🛠️ Funcionalidades

    Lectura de entrada:

        Desde consola (interactivo).

        Desde archivo (ruta pasada como argumento).

    Operadores soportados:

        Aritméticos: +, -, *, /.

        Exponenciación: ^ o exp.

    Manejo de pila:

        Apila números hasta encontrar un operador.

        Desapila 2 elementos, opera y apila el resultado.

    Validación:

        Verifica que la expresión esté bien formada (al final solo queda un elemento en la pila).



### 🚀 Compilación y Ejecución
Requisitos:

    GCC (sudo apt install gcc en Ubuntu).

    Biblioteca matemática (libm).

Compilar:
bash

gcc src/main.c src/stack.c -o bin/rpn -Iinclude -lm

Ejecutar:

    Modo consola:
    bash

./bin/rpn

Ingresa expresiones como: 3 4 + 2 * (resultado: 14).

Modo archivo:
bash

    ./bin/rpn samples/input_file.txt

### 📝 Ejemplos de Entrada/Salida
Expresión 1:

    Entrada: 5 1 - 2 /

    Proceso:

        Apila 5 y 1.

        Opera -: 5 - 1 = 4.

        Apila 2.

        Opera /: 4 / 2 = 2.

    Salida: 2.000000

Expresión 2:

    Entrada: 2 3 ^ 4 +

    Proceso:

        Apila 2 y 3.

        Opera ^: 2^3 = 8.

        Apila 4.

        Opera +: 8 + 4 = 12.

    Salida: 12.000000

