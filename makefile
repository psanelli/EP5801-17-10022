# Variables:
# gcc: GNU Compiler Collection
# CFLAGS: Flags para el compilador
# SRC: Archivos fuente en el directorio src
# EXE: Nombres de los ejecutables generados

CC = gcc
ASM = nasm
CFLAGS = -Wall -Wextra -O2 -no-pie
ASMFLAGS = -f elf64
SRC_C = $(wildcard src/*.c)
SRC_ASM = $(wildcard src/*.asm)
OBJ_C = $(SRC_C:src/%.c=%.o)
OBJ_ASM = $(SRC_ASM:src/%.asm=%.o)
EXE = main

# Objetivo Principal.
Tarea2:  $(EXE)

# Reglas:
# La regla % se aplica a cualquier archivo fuente en src con la extensión .c
# $<: Representa el archivo fuente actual
# $@: Representa el nombre del objetivo actual
# La regla clean elimina los archivos ejecutables generados

$(EXE): $(OBJ_C) $(OBJ_ASM)
	@$(CC) $(CFLAGS) $(OBJ_C) $(OBJ_ASM) -o $(EXE)
	@echo "Enlazado $^ a $@"
	@echo
	@./$(EXE)

%.o: src/%.c
	@echo "Compilando $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: src/%.asm
	@echo "Ensamblando $<..."
	@$(ASM) $(ASMFLAGS) $< -o $@

clean:
	@rm -f $(EXE) $(OBJ_C) $(OBJ_ASM)
	@echo "Archivos generados eliminados."