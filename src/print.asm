; filepath: src/print.asm
section .data
    msg db "Hello, World!", 0Ah  ; Mensaje a imprimir con salto de línea
    len equ $ - msg              ; Longitud del mensaje

section .text
    global _start

_start:
    ; Llamada a la API de Windows para imprimir en consola
    mov edx, len     ; Longitud del mensaje
    mov ecx, msg     ; Dirección del mensaje
    mov ebx, 1       ; File descriptor (stdout)
    mov eax, 4       ; Número de syscall para WriteConsoleA
    int 0x80         ; Interrupción para llamar al kernel

    ; Salir del programa
    mov eax, 1       ; Número de syscall para ExitProcess
    xor ebx, ebx     ; Código de salida (0)
    int 0x80