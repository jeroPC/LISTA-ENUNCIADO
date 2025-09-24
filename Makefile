CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g

SRC=src/lista.c
TEST=pruebas_alumno.c
OBJ=lista.o pruebas_alumno.o
OUT=test_lista

all: $(OUT)

lista.o: src/lista.c src/lista.h
	$(CC) $(CFLAGS) -c src/lista.c -o lista.o

pruebas_alumno.o: pruebas_alumno.c src/lista.h
	$(CC) $(CFLAGS) -c pruebas_alumno.c -o pruebas_alumno.o

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT) *.o
