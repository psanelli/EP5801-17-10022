# Variables:
# SRC: Archivos fuente en el directorio src
# EXE: Nombre del ejecutable a generar
# SENSORS: Subdirectorio de sensores dentro de src
# BUILD: Directorio de compilación
# BIN: Directorio donde se guardará el ejecutable generado
# FILES_C: Lista de archivos fuente .c en src y src/sensors
# FILES_OBJ: Lista de archivos objeto .o correspondientes a los archivos fuente

SRC := ./src
EXE := main
SENSORS := $(SRC)/sensors
BUILD := ./build
BIN := $(BUILD)/bin
FILES_C := $(wildcard $(SRC)/*.c) $(wildcard $(SENSORS)/*.c)
FILES_OBJ := $(patsubst %.c, $(BUILD)/%.o, $(notdir $(FILES_C)))

# Objetivo Principal.
Tarea3:  $(BIN)/$(EXE)

# Reglas:
# La regla % se aplica a cualquier archivo fuente en src con la extensión .c
# $<: Representa el archivo fuente actual
# $@: Representa el nombre del objetivo actual
# La regla clean elimina los archivos ejecutables generados

$(BIN)/$(EXE): $(FILES_OBJ)
	@mkdir -p $(BIN)
	@gcc $^ -o $@
	@echo "Compilación completada. Ejecutable generado en $(BIN)/$(EXE)"

$(BUILD)/%.o: $(SRC)/%.c
	@mkdir -p $(BUILD)
	@gcc -c $< -o $@

$(BUILD)/%.o: $(SENSORS)/%.c
	@mkdir -p $(BUILD)
	@gcc -c $< -o $@

clean:
	@rm -fr ${BUILD}
	@echo "Archivos generados eliminados."