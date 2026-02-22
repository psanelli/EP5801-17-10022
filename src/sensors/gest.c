#include <stdio.h>
#include "gest.h"

gest* gesture_data;

void tap() {
    printf("tap.\n");
}

void double_tap() {
    printf("double tap.\n");
}

void haptic_press() {
    printf("haptic press.\n");
}

// Función que asigna los datos del sensor de gestos y retorna la función correspondiente
s_print gest_print(uint8_t* gest_data) {
    gesture_data = (gest*) gest_data;

    // Verificar qué gesto fue detectado y retornar la función correspondiente
    if (gesture_data->tap) {
        return tap;
    }

    if (gesture_data->double_tap) {
        return double_tap;
    }

    if (gesture_data->haptic_press) {
        return haptic_press;
    }

    return (s_print) NULL;
}