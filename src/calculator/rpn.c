#include "rpn.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Función auxiliar para verificar si un carácter es un operador válido
static int is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Función para convertir el código de estado RPN a una cadena legible
const char* rpn_status_str(rpn_status_t status) {
    switch (status) {
        case RPN_OK: return "OK";                                                               // 0
        case RPN_ERR_NULL: return "Argumento nulo";                                             // 1
        case RPN_ERR_BAD_TOKEN: return "Token inválido";                                        // 2
        case RPN_ERR_STACK_UNDERFLOW: return "Desbordamiento de pila (faltan operandos)";       // 3
        case RPN_ERR_STACK_OVERFLOW: return "Subdesbordamiento de pila (sin espacio en arena)"; // 4
        case RPN_ERR_DIV_ZERO: return "División por cero";                                      // 5
        case RPN_ERR_EXTRA_OPERANDS: return "Operandos extra en la expresión";                  // 6
        default: return "Desconocido";
    }
}

// Función principal para evaluar una expresión RPN
rpn_status_t rpn_eval_with_linear(
    const char* expr,
    s_arena_stack* st,
    s_arena_linear* lin,
    int* out
) {
    // Validar argumentos
    if (!expr || !st || !lin || !out) return RPN_ERR_NULL;

    st->offset = 0;     // Inicializar el stack
    lin->offset = 0;    // Inicializar el arena linear

    // Copiar la expresión a un buffer en el arena linear para tokenizar
    size_t n = strlen(expr) + 1;
    char* buf = arena_linear_allocate(lin, n, (void*)expr);
    if (!buf) return RPN_ERR_STACK_OVERFLOW;    // No hay espacio en el arena linear

    // Tokenizar la expresión usando strtok
    char* tok = strtok(buf, " \t\r\n");
    while (tok) {
        char* end = NULL;
        long v = strtol(tok, &end, 10);

        // Si el token es un número válido, lo empujamos al stack
        if (end != tok && *end == '\0') {
            int x = (int)v;
            if (!arena_stack_push(st, sizeof(int), &x)) return RPN_ERR_STACK_OVERFLOW;
        } else if (tok[1] == '\0' && (tok[0]=='+'||tok[0]=='-'||tok[0]=='*'||tok[0]=='/')) {
            int b = 0, a = 0, r = 0;
            if (!arena_stack_pop(st, &b)) return RPN_ERR_STACK_UNDERFLOW;
            if (!arena_stack_pop(st, &a)) return RPN_ERR_STACK_UNDERFLOW;

            // Realizar la operación
            switch (tok[0]) {
                case '+': r = a + b; break; // Suma
                case '-': r = a - b; break; // Resta
                case '*': r = a * b; break; // Multiplicación
                case '/':                    // División      
                    if (b == 0) return RPN_ERR_DIV_ZERO;
                    r = a / b;
                    break;
            }

            // Guardar el resultado de la operación en el stack
            if (!arena_stack_push(st, sizeof(int), &r)) return RPN_ERR_STACK_OVERFLOW;
        } else {
            // Token no es ni un número ni un operador válido
            return RPN_ERR_BAD_TOKEN;
        }

        // Obtener el siguiente token
        tok = strtok(NULL, " \t\r\n");
    }

    // Al finalizar, el resultado debe ser el único elemento en el stack
    if (!arena_stack_pop(st, out)) return RPN_ERR_STACK_UNDERFLOW;

    // Si queda algo más en stack, la expresión tenía operandos extras
    int extra = 0;
    if (arena_stack_pop(st, &extra)) return RPN_ERR_EXTRA_OPERANDS;

    return RPN_OK;
}