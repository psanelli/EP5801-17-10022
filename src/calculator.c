// Paola Anelli
// 17 - 10022
// EP5801 - Programacion Avanzada en C de Bajo Nivel
// 26 de Enero de 2026
// Calculadora in C

#include <stdio.h>

int calculator(char operator, float num1, float num2) {
    float result;       // Resultado de la operación

    // Estructura de diversos casos para determinar la operación a realizar
    switch (operator) {
        case '+':       // Suma
            result = num1 + num2;
            printf("\nResultado: %.2f\n", result);
            break;
        case '-':       // Resta
            result = num1 - num2;
            printf("\nResultado: %.2f\n", result);
            break;
        case '*':       // Multiplicación
            result = num1 * num2;
            printf("\nResultado: %.2f\n", result);
            break;
        case '/':       // División
            if (num2 != 0) {
                result = num1 / num2;
                printf("\nResultado: %.2f\n", result);
            } else {
                printf("\nHORROR >:C\n");
            }
            break;
        default:
            printf("\nError :S\n");
    }

    return 0;
}

int main() {

    // Declaración de variables
    char op;        // Operador
    float n, m;     // Números

    printf("\n--- Calculadora Simple en C ---\n");  // Título

    printf("Ingrese el primer numero: ");   // No me agarra los acentos :C
    scanf("%f", &n);

    printf("Ingrese el segundo numero: ");
    scanf("%f", &m);

    printf("Inserte la operacion a realizar (+, -, *, /): ");
    scanf(" %c", &op);

    calculator(op, n, m);   // Llamada a la función calculadora

    return 0;
}