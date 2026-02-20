#ifndef SENSORS_H
#define SENSORS_H

// Enumeración para identificar los tipos de sensores disponibles
//  POS: Sensor de posición
//  GEST: Sensor de gestos
enum sensors {
    POS = 0x01,
    GEST = 0x10,
};

// Definición de un puntero a función para imprimir información de los sensores
typedef void (*s_print)();

#endif