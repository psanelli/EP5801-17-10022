#ifndef GEST_H
#define GEST_H

#include <stdint.h>
#include "sensor.h"

// Estructura para representar los gestos detectados por el sensor
typedef struct GEST {
    uint8_t ID;                 // Identificador del sensor de gestos
    uint8_t tap: 1;             // Bit para indicar si se detectó un "tap" (1 bit)
    uint8_t double_tap: 1;      // Bit para indicar si se detectó un "double tap" (1 bit)
    uint8_t haptic_press: 1;    // Bit para indicar si se detectó una "presión háptica" (1 bit)
    uint8_t reserve: 5;         // Bits reservados (5 bits)
} gest;

// Recibe un puntero a un arreglo de 8 bits que representa los datos del sensor de gestos
s_print gest_print(uint8_t * gest_data);

#endif