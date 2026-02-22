#include <stddef.h>
#include <stdio.h>

#include "sensors/sensor.h"
#include "sensors/gest.h"
#include "sensors/pos.h"

// IDs de los sensores de posición y gestos
#define pos_id 0xB7
#define gest_id 0xA7

int main() {
    printf("Iniciando el sistema de sensores...\n");

    // Datos del sensor de posición
    /*uint8_t sensor_read[] = {
        0xB7,       // ID del sensor de posición
        0x00, 0x01, // Coordenada X
        0x00, 0x02, // Coordenada Y
        0x00, 0x03  // Coordenada Z
    };*/

    // Datos del sensor de gestos
    uint8_t sensor_read[] = {
        0xA7,       // ID del sensor de gestos
        0x01,       // Gesto (tap activado)
        //0x02,       // Gesto (double_tap activado)
        //0x04        // Gesto (haptic_press activado)
    };

    // Puntero a función para imprimir los datos del sensor
    s_print print_data;

    // Determinar el tipo de sensor según el ID
    switch (sensor_read[0]) {
        case pos_id:
            print_data = pos_print(sensor_read);
            break;
    
        case gest_id:
            print_data = gest_print(sensor_read);
            break;
    
        default:
            printf("ID de sensor desconocido\n");
            return -1;
    }

    // Si se obtuvo una función de impresión, ejecutarla
    if (print_data != NULL) {
        print_data();
    } else {
        printf("No hay datos para imprimir.\n");
    }

    return 0;
}