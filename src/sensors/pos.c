#include <stdio.h>
#include "pos.h"

position* position_data;

void print_pos() {
    printf("x: %u, y: %u, z: %u\n", position_data->x, position_data->y, position_data->z);
}

// Función que asigna los datos del sensor de posiciones y retorna la función correspondiente
s_print pos_print(uint8_t* pos_data) {
    position_data = (position*) pos_data;
    return print_pos;
}