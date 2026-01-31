# EP5801 - Programación Avanzada en C

## Tarea 2

### Descripción
Este proyecto incluye dos programas:
1. Print: Pregunta al usuario su nombre y le responde con un saludo.
2. Main: Funcion que ejecuta el programa Print.

Se utilizó una distribución de Linux, Ubuntu, con WSL (Windows Subsystem for Linux) para compilar y ejecutar los archivos `.asm`. Para acceder a esta distribución, se debe escribir `wsl` en el terminal y navegar a la carpeta donde está el repositorio.

El entorno de trabajo utilizado para este proyecto es el siguiente:
- Sistema Operativo: Linux (Ubuntu 64 bits)
- Ensamblador: NASM (Netwide Assembler)
- Compilador: GCC para enlazar con código en C
- Formato de salida: ELF64

---

### Estructura del Proyecto
El proyecto está estructurado de la siguiente manera:
- **src/**: Contiene los archivos fuente del proyecto:
  - `print.asm`: Archivo Assembly que solicita al usuario un string y lo almacena.
  - `main.c`: Archivo en C que interactúa con el código Assembly.
- **makefile**: Archivo que define las reglas para compilar y ejecutar los programas.
