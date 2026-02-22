#include <stdio.h>
#include "gest.h"

gest gesture_data;

void tap() {
    printf("Se detectó: tap.\n");
}

void double_tap() {
    printf("Se detectó: double tap.\n");
}

void haptic_press() {
    printf("Se detectó: haptic press.\n");
}

// Función que asigna los datos del sensor de gestos y retorna la función correspondiente
s_print gest_print(uint8_t* gest_data) {
    // Copiar los datos del arreglo a la estructura
    gesture_data.ID = gest_data[0];
    gesture_data.tap = (gest_data[1] & 0x01) ? 1 : 0;
    gesture_data.double_tap = (gest_data[1] & 0x02) ? 1 : 0;
    gesture_data.haptic_press = (gest_data[1] & 0x04) ? 1 : 0;

    // Depuración: imprimir los datos del sensor
    printf("Datos del sensor de gestos:\n");
    printf("ID: %u, tap: %u, double_tap: %u, haptic_press: %u\n", 
        gesture_data.ID, 
        gesture_data.tap, 
        gesture_data.double_tap, 
        gesture_data.haptic_press);

    // Retornar la función correspondiente al gesto detectado
    if (gesture_data.tap) {
        return tap;
    }
    if (gesture_data.double_tap) {
        return double_tap;
    }
    if (gesture_data.haptic_press) {
        return haptic_press;
    }

    return NULL;
}