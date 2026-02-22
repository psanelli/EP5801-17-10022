#include <stdio.h>
#include "pos.h"

position position_data;

void print_pos() {
    printf("Posición actual:\n");
    printf("ID: %u, x: %u, y: %u, z: %u\n", 
        position_data.ID,
        position_data.x, 
        position_data.y, 
        position_data.z);
}

// Función que asigna los datos del sensor de posiciones y retorna la función correspondiente
s_print pos_print(uint8_t* pos_data) {
    //position_data = (position*) pos_data;

    // Combinar los bytes para obtener las coordenadas correctas
    position_data.ID = pos_data[0];
    position_data.x = (pos_data[1] << 8) | pos_data[2];
    position_data.y = (pos_data[3] << 8) | pos_data[4];
    position_data.z = (pos_data[5] << 8) | pos_data[6];

    return print_pos;
}