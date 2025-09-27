CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g

SRC=src/lista.c src/pila.c src/cola.c
TEST=pruebas_alumno.c
OBJ=lista.o pila.o cola.o pruebas_alumno.o
OUT=test_lista

all: $(OUT)

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

clean:
	rm -f $(OUT) *.o
