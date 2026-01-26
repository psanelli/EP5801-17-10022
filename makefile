# Variables:
# gcc: GNU Compiler Collection
# CFLAGS: Flags para el compilador
# SRC: Archivos fuente en el directorio src
# EXE: Nombres de los ejecutables generados

CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = $(wildcard src/*.c)
EXE = $(patsubst src/%.c, %, $(SRC)) 

# Objetivo Principal.
Tarea1:  $(EXE)

# Reglas:
# La regla % se aplica a cualquier archivo fuente en src con la extensión .c
# $<: Representa el archivo fuente actual
# $@: Representa el nombre del objetivo actual
# La regla clean elimina los archivos ejecutables generados

%: src/%.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -o $@ $<
	@./$@
	@echo

clean:
	rm -f $(EXE)