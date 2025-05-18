/* 
    Código de prueba, realizado por Daniel Peralta, subido al repositorio
    notacionPolacaInversa. 
    Usuario Git: @dperalta86
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Definición de la pila
typedef struct StackNode {
    double data;
    struct StackNode* next;
} StackNode;

double recorrerNotacionPolacaInversa(const char*);
void push(StackNode**, double);
double pop(StackNode**);

int main(int argc,char *argv[]){
    int existeArgumentos = 0;
    char expression[256]; // ver si se puede optimizar
    char *pathArchivo=NULL;

    // Manejo de argumentos
    if (argc > 2){
    printf("archivo: %s, se esperaba como máximo un argumento adicional.", argv[0]);
    return EXIT_FAILURE;
    }
    if (argc==2){
        pathArchivo = argv[1];
        existeArgumentos = 1;
    }
   
    if (existeArgumentos){
        FILE *f;
        if (f=fopen(pathArchivo, "r")){
        fgets(expression, sizeof(expression), f);
        fclose(f);
        }else{
        printf("Error al intentar acceder al archivo: %s.", argv[1]);
        return EXIT_FAILURE;
        }

    }else{
        // Si no existe parámetro para buscar archivo, pido que se ingrese por consola
        printf("Ingrese la expresión en notación polaca inversa (ej: '3 4 + 2 *'): ");
        fgets(expression, sizeof(expression), stdin);
    }

    expression[strcspn(expression, "\n")] = '\0'; // Eliminar el salto de línea

    double result = recorrerNotacionPolacaInversa(expression);
    printf("Resultado: %f\n", result);


    return 0;
    
}

// Funciones de pila (stack)
void push(StackNode** top, double data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

double pop(StackNode** top) {
    if (*top == NULL) {
        fprintf(stderr, "Error: pila vacía\n");
        exit(EXIT_FAILURE);
    }
    StackNode* temp = *top;
    double data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

// Función para evaluar la expresión RPN
double recorrerNotacionPolacaInversa(const char* expression) {
    StackNode* stack = NULL;
    char* token;
    char* rest = strdup(expression); // Copia para strtok_r

    while ((token = strtok_r(rest, " ", &rest))) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // Es un número
            push(&stack, atof(token));
        } else {
            // Es un operador
            double b = pop(&stack);
            double a = pop(&stack);
            switch (token[0]) {
                case '+': push(&stack, a + b); break;
                case '-': push(&stack, a - b); break;
                case '*': push(&stack, a * b); break;
                case '/': push(&stack, a / b); break;
                case '^': push(&stack, pow(a, b)); break;
                default:
                    fprintf(stderr, "Operador desconocido: %c\n", token[0]);
                    exit(EXIT_FAILURE);
            }
        }
    }

    if (stack == NULL || stack->next != NULL) {
        fprintf(stderr, "Expresión inválida\n");
        exit(EXIT_FAILURE);
    }

    double result = pop(&stack);
    return result;
}

