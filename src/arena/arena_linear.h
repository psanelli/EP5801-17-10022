#ifndef ARENA_LINEAR_H
#define ARENA_LINEAR_H

#include <stdint.h>
#include <stddef.h>

/* Base structure definition*/
typedef struct S_ARENA_LINEAR {
    size_t max_size;
    size_t offset;
    uint8_t *memory;
} s_arena_linear;

/* Functions Signatures */
typedef s_arena_linear (*f_arena_create) (uint8_t*, size_t);
typedef void* (*f_arena_allocate) (s_arena_linear*, size_t, void*);

/* Object definition*/
typedef struct OBJ_ARENA_LINEAR {
    s_arena_linear arena;
    struct  {
        f_arena_create create;
        f_arena_allocate allocate;
    } functions;
} obj_arena_linear;

/* Prototypes */
s_arena_linear arena_linear_create(uint8_t* item_array, size_t item_size);
void* arena_linear_allocate(s_arena_linear* arena, size_t data_size, void* data);

#endif /* ARENA_LINEAR_H */