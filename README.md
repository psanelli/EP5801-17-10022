# EP5801 - Programación Avanzada en C

## Tarea 4

### Descripción
  1. Reemplazar la memoria dinámica por memoria estática en los alojadores.
  2. Utilizar el alojador de stack para construir una calculadora de stack usando Reverse Polish Notation (RPN).

---

### Estructura del Proyecto
El proyecto está estructurado de la siguiente manera:
- **src/**: Contiene los archivos fuente del proyecto:
  - `main.c`: Punto de entrada del programa.
  - **arena/**:
    - `arena_linear.h` / `arena_linear.c`: Implementación del alojador lineal con memoria estática.
    - `arena_stack.h` / `arena_stack.c`: Implementación del alojador tipo stack con memoria estática.
  - **calculator/**:
    - `rpn.h` / `rpn.c`: Calculadora RPN y manejo de estados de error.

- `build.mk`: Reglas de compilación normal.
- `debug.mk`: Reglas de compilación con flags de depuración.
- `build/`: Binarios/objetos generados por la compilación.
---

### Diagrama de la Estructura
El proyecto sigue la estructura del siguiente diagrama:

![alt text](image.png)

