#ifndef RPN_H
#define RPN_H

#include "../arena/arena_stack.h"
#include "../arena/arena_linear.h"

// Código de estado para la función rpn_eval
typedef enum {
    RPN_OK = 0,
    RPN_ERR_NULL,
    RPN_ERR_BAD_TOKEN,
    RPN_ERR_STACK_UNDERFLOW,
    RPN_ERR_STACK_OVERFLOW,
    RPN_ERR_DIV_ZERO,
    RPN_ERR_EXTRA_OPERANDS
} rpn_status_t;

// Prototipos
rpn_status_t rpn_eval(const char* expr, s_arena_stack* st, int* out);

rpn_status_t rpn_eval_with_linear(
    const char* expr,
    s_arena_stack* st,
    s_arena_linear* lin,
    int* out
);

const char* rpn_status_str(rpn_status_t status);

#endif