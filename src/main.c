#include <stdint.h>
#include <stdio.h>

#include "arena/arena_stack.h"
#include "arena/arena_linear.h"
#include "calculator/rpn.h"

uint8_t mem_stack[1024] = {0};
uint8_t mem_linear[512] = {0};

int main(void) {
    // Crear arena stack con memoria preasignada
    s_arena_stack st = arena_stack_create(mem_stack, sizeof(mem_stack));

    // Crear arena linear con memoria preasignada
    s_arena_linear lin = arena_linear_create(mem_linear, sizeof(mem_linear));

    // Leer expresión RPN desde la entrada estándar
    char line[256];
    printf("Ingrese expresion RPN: ");
    if (!fgets(line, sizeof(line), stdin)) return 1;

    // Evaluar la expresión RPN
    int result = 0;
    rpn_status_t rc = rpn_eval_with_linear(line, &st, &lin, &result);

    // Imprimir resultado o error
    if (rc == RPN_OK) {
        printf("Resultado: %d\n", result);
    } else {
        printf("Error RPN (%d): %s\n", rc, rpn_status_str(rc));
    }

    return 0;
}