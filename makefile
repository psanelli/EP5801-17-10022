# Variables
CC = gcc
CFLAGS = -Wall -Wextra -O2
EXE = main calculator

# Objetivo Principal
Tarea1:  $(EXE)

# Reglas
main: src/main.c
	@echo "Compiling main.c..."
	@$(CC) $(CFLAGS) -o main src/main.c
	@./main
	@echo

calculator: src/calculator.c
	@echo "Compiling calculator.c..."
	@$(CC) $(CFLAGS) -o calculator src/calculator.c
	@./calculator

clean:
	rm -f $(EXE)