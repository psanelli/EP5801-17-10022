; Paola Anelli
; 17 - 10022
; EP5801 - Programacion Avanzada en C de Bajo Nivel
; 30 de Enero de 2026
; filepath: src/print.asm

section .data
    msg db "Hello, World!", 0Ah  ; Mensaje a imprimir con salto de línea
    len equ $ - msg              ; Longitud del mensaje

section .text
    global print_hello           ; Hacer la etiqueta accesible desde C

print_hello:
    ; Llamada al sistema write (sys_write)
    mov eax, 4       ; Número de syscall para sys_write
    mov ebx, 1       ; File descriptor (stdout)
    mov ecx, msg     ; Dirección del mensaje
    mov edx, len     ; Longitud del mensaje
    int 0x80         ; Interrupción para llamar al kernel

    ; Salir del programa
    ;mov eax, 1       ; Número de syscall para ExitProcess
    ;xor ebx, ebx     ; Código de salida (0)
    ;int 0x80

    ; Retornar al código C
    ret