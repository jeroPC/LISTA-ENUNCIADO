<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# TDA LISTA/PILA/COLA

## Repositorio de JERONIMO PEREZ CORDOBA - (111939) - JEROPEREZ42@GMAIL.COM - JEPEREZC@FI.UBA.AR

El proyecto incluye un archivo Makefile. Para compilar, simplemente ejecuta make en la terminal

```bash
make
```

- Para ejecutar las pruebas:
```bash
make run
```

- Para ejecutar las pruebas con valgrind:
```bash
make valgrind
```


- Para ejecutar el programa principal con un ID diferente o Nombre 
```
./main ../TP1-ENUNCIADO/pokedex.csv --id (CUALQUIER ID)
./main ../TP1-ENUNCIADO/pokedex.csv --nombre (NOMBRE)
```


---
##  Funcionamiento

## LISTA ##

- LISTA_CREAR()
    Reserva memoria para la estructura principal de la lista usando `calloc`, lo que inicializa todos los campos en cero. Inicializa los punteros y el contador en cero. Complejidad: O(1) porque solo se realiza una asignación de memoria y no depende del tamaño de la lista.

- LISTA_VACIA()
    Chequeamos que la lista sea valida, con cantidad mayor a cero , en caso de que no se cumpla se devuelve false . Complejidad: O(1), porque solo se consulta un campo de la estructura sin recorrer la lista.

- LISTA_CANTIDAD()
    Devuelve el número de elementos almacenados, accediendo directamente al campo cantidad. Complejidad: O(1).

- LISTA_AGREGAR()
    Agrega un elemento al final de la lista. Usa el puntero ultimo para hacerlo en tiempo constante. Si la lista está vacía, actualiza ambos punteros (primero y ultimo). Complejidad:  al usar el puntero al ultimo nodo , su accion es en O(1)

- LISTA_INSERTAR()
    Inserta un elemento en una posición específica. Si es al principio, delega en una función auxiliar. Para otras posiciones, recorre la lista hasta la posición deseada. Complejidad: O(n) porque para insertar en una posición arbitraria (no al principio), hay que recorrer la lista hasta esa posición.


- LISTA_ELIMINAR_ELEMENTO 
    Elimina el elemento en la posición indicada. Si es el primero, lo elimina en tiempo constante. Para otras posiciones, recorre la lista hasta el nodo anterior. Complejidad: O(n) porque para eliminar en una posición arbitraria (no al principio), hay que recorrer la lista hasta el nodo anterior.

- LISTA_BUSCAR_POSICION()
    Busca la posición de un elemento usando una función de comparación. Recorre la lista hasta encontrar el elemento. Complejidad: O(n) porque busca un elemento recorriendo la lista y comparando uno por uno.

- LISTA_BUSCAR_ELEMENTO()
    Devuelve el elemento en la posición indicada, recorriendo la lista hasta llegar a esa posición.  Complejidad: O(n) porque accede a una posición arbitraria recorriendo la lista desde el principio.

- LISTA_CON_CADA_ELEMENTO()
    Recorre la lista y aplica una función a cada elemento, permitiendo cortar el recorrido si la función lo indica. Complejidad: O(n) porque recorre todos los elementos de la lista aplicando una función.

- LISTA_DESTRUIR Y LISTA_DESTRUIR_TODO
    Libera la memoria de todos los nodos. lista_destruir_todo además aplica una función destructora a cada dato almacenado. Complejidad: O(n) porque libera la memoria de todos los nodos recorriendo la lista.

Iterador externo (lista_iterador_crear, lista_iterador_hay_mas_elementos, lista_iterador_siguiente, lista_iterador_obtener_actual, lista_iterador_destruir)
Permite recorrer la lista desde afuera, manteniendo el estado actual. Complejidad: O(1) por operación, porque solo accede o avanza el puntero actual, sin recorrer la lista completa.

---
## COLA ##

- COLA_CREAR()
    Reserva memoria para la estructura principal de la cola usando 'calloc', inicializando los punteros y el contador en cero.  
    Complejidad :O(1), porque solo se realiza una asignación de memoria.

- COLA_ENCOLAR()
    Agrega un elemento al final de la cola usando el puntero al último nodo.  
    Complejidad: O(1), porque no es necesario recorrer la estructura.

- COLA_DESENCOLAR()
    Elimina el primer elemento de la cola y actualiza el puntero al nuevo primero.  
    Complejidad: O(1), porque solo se modifica el puntero y se libera un nodo.

- COLA_PRIMERO()
    Devuelve el elemento al frente de la cola sin eliminarlo.  
    Complejidad: O(1), porque accede directamente al puntero del primer nodo.

- COLA_VACIA()
    Verifica si la cola está vacía consultando el campo cantidad.  
    Complejidad: O(1), porque solo accede a un campo de la estructura.

- COLA_DESTRUIR()
    Libera la memoria de todos los nodos de la cola.  
    Complejidad: O(n), porque recorre y libera cada nodo.


## PILA ##

- PILA_CREAR()
    Reserva memoria para la estructura principal de la pila usando 'calloc', inicializando el puntero y el contador en cero.  
    Complejidad:O(1), porque solo se realiza una asignación de memoria.

- PILA_APILAR()
    Agrega un elemento en el tope de la pila, actualizando el puntero al nuevo nodo.  
    Complejidad: O(1), porque no es necesario recorrer la estructura.

- PILA_DESAPILAR()
    Elimina el elemento en el tope de la pila y actualiza el puntero al nuevo tope.  
    Complejidad: O(1), porque solo se modifica el puntero y se libera un nodo.

- PILA_TOPE()
    Devuelve el elemento en el tope de la pila sin eliminarlo.  
    Complejidad: O(1), porque accede directamente al puntero del tope.

- PILA_VACIA()
    Verifica si la pila está vacía consultando el campo cantidad.  
    Complejidad: O(1), porque solo accede a un campo de la estructura.

- PILA_DESTRUIR()
    Libera la memoria de todos los nodos de la pila.  
    Complejidad: O(n), porque recorre y libera cada nodo.



<div align="center">
<img width="70%" src="img/diagrama1.svg">
</div>

En el archivo `sarasa.c` la función `funcion1` utiliza `realloc` para agrandar la zona de memoria utilizada para conquistar el mundo. El resultado de `realloc` lo guardo en una variable auxiliar para no perder el puntero original en caso de error:

```c
int *vector = realloc(vector_original, (n+1)*sizeof(int));

if(vector == NULL)
    return -1;
vector_original = vector;
```


<div align="center">
<img width="70%" src="img/diagrama2.svg">
</div>

---

## Respuestas a las preguntas teóricas
Incluír acá las respuestas a las preguntas del enunciado (si aplica).
