CC=gcc

# TP1 integration
TP1_DIR=../TP1-ENUNCIADO/src
TP1_INC=-I$(TP1_DIR)
# Local includes (our src folder) so we can do #include "tp1.h"
LOCAL_INC=-Isrc

CFLAGS=-Wall -Wextra -std=c99 -g $(LOCAL_INC) $(TP1_INC)

SRC=src/lista.c src/pila.c src/cola.c
TEST=pruebas_alumno.c
OBJ=lista.o pila.o cola.o pruebas_alumno.o
OUT=pruebas_alumno

# Files to format with clang-format
FORMAT_FILES=$(wildcard src/*.c src/*.h) pruebas_alumno.c main.c

.PHONY: all run clean memcheck format format-check

VALGRIND=valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--errors-for-leak-kinds=all \
	--error-exitcode=1 \
	-s

all: $(OUT)

# Explicit target named like the expected harness binary
pruebas_alumno: $(OBJ)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ)

lista.o: src/lista.c src/lista.h
	$(CC) $(CFLAGS) -c src/lista.c -o lista.o

pila.o: src/pila.c src/pila.h src/lista.h
	$(CC) $(CFLAGS) -c src/pila.c -o pila.o

pruebas_alumno.o: pruebas_alumno.c src/lista.h src/pila.h
	$(CC) $(CFLAGS) -c pruebas_alumno.c -o pruebas_alumno.o

cola.o: src/cola.c src/cola.h src/lista.h
	$(CC) $(CFLAGS) -c src/cola.c -o cola.o

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ)

run: $(OUT)
	./$(OUT)

valgrind: $(OUT)
	$(VALGRIND) ./$(OUT)

clean:
	rm -f $(OUT) *.o pruebas_chanutron lista

# -------- Formatting (clang-format) --------
# Requires clang-format installed in PATH. Uses the .clang-format in this folder.
format:
	@echo "Formatting C sources with clang-format..."
	@clang-format -i --style=file $(FORMAT_FILES)
	@echo "Done."

# Check formatting without modifying files (fails if reformatting would occur)
format-check:
	@echo "Checking formatting..."
	@clang-format --dry-run -Werror --style=file $(FORMAT_FILES)
	@echo "Formatting is OK."

# -------- Main app (uses TP1) --------
MAIN=main

$(MAIN): main.o lista.o pila.o cola.o tp1.o
	$(CC) $(CFLAGS) -o $(MAIN) main.o lista.o pila.o cola.o tp1.o

main.o: main.c src/lista.h src/pila.h src/cola.h src/tp1.h
	$(CC) $(CFLAGS) -c main.c -o main.o

# Compile local TP1 implementation
tp1.o: src/tp1.c src/tp1.h
	$(CC) $(CFLAGS) -c src/tp1.c -o tp1.o

.PHONY: run-main valgrind-main

run-main: $(MAIN)
	./$(MAIN) ../TP1-ENUNCIADO/pokedex.csv --id 25

valgrind-main: $(MAIN)
	$(VALGRIND) ./$(MAIN) ../TP1-ENUNCIADO/pokedex.csv --id 25
