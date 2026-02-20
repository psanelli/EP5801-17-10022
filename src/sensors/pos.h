#ifndef POS_H
#define POS_H

#include <stdint.h>
#include "sensor.h"

// Estructura para representar la posición en un espacio tridimensional
typedef struct POSITION {
    uint8_t ID; // Identificador del sensor de posición
    uint16_t x; // Coordenada X (16 bits)
    uint16_t y; // Coordenada Y (16 bits)
    uint16_t z; // Coordenada Z (16 bits)
} position;

// Recibe un puntero a un arreglo de 8 bits que representa la posición actual
s_print pos_print(uint8_t * pos_data);

#endif