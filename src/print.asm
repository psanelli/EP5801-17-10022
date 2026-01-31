; Paola Anelli
; 17 - 10022
; EP5801 - Programacion Avanzada en C de Bajo Nivel
; 30 de Enero de 2026
; filepath: src/print.asm



section .data
    preg db "Coloca tu nombre aqui: ", 0Ah  ; Mensaje con pregunta del programa
    preg_len equ $ - preg                   ; Longitud del mensaje
    msg db "Hola, ", 0                      ; Mensaje de saludo
    msg_len equ $ - msg                     ; Longitud del mensaje

section .bss
    name resb 32                            ; Espacio para el nombre

section .text
    global print_preg                       ; Hacer la etiqueta accesible desde C

print_preg:
    ; --- Imprimir la pregunta ---
    mov rax, 1              ; sys_write. ID para escritura
    mov rdi, 1              ; stdout. Pantalla
    mov rsi, preg           ; Dirección del mensaje
    mov rdx, preg_len       ; Longitud del mensaje
    syscall                 ; Llamar al SO para imprimir
    
    ; --- Leer la respuesta del usuario ---
    mov rax, 0              ; sys_read (ID para lectura)
    mov rdi, 0              ; stdin (Teclado)
    mov rsi, name           ; Dónde guardar lo que escriba
    mov rdx, 32             ; Máximo de bytes a leer
    syscall                 ; El SO espera a que el usuario presione Enter

    ; --- Imprimir el saludo con el nombre ---
    mov rax, 1              ; sys_write
    mov rdi, 1              ; stdout
    mov rsi, msg            ; Dirección del mensaje de saludo
    mov rdx, msg_len        ; Longitud del mensaje de saludo
    syscall                 ; Llamar al SO para imprimir

    ; --- Imprimir el nombre ingresado ---
    mov rax, 1              ; sys_write
    mov rdi, 1              ; stdout
    mov rsi, name           ; Dirección del nombre ingresado
    mov rdx, 32             ; Longitud máxima del nombre
    syscall                 ; Llamar al SO para imprimir

    ; --- Retornar al código C ---
    ret