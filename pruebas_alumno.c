#include "src/lista.h"
#include <stdio.h>
#include <assert.h>

void test_lista_vacia() {
    lista_t* lista = lista_crear();
    assert(lista_vacia(lista) == true);
    int a = 1;
    lista_agregar(lista, &a);
    assert(lista_vacia(lista) == false);
    lista_eliminar_elemento(lista, 0);
    assert(lista_vacia(lista) == true);
    assert(lista_vacia(NULL) == true);
    lista_destruir(lista);
    printf("test_lista_vacia OK\n");
}

void test_lista_agregar() {
    lista_t* lista = lista_crear();
    int a = 1, b = 2;
    assert(lista_agregar(lista, &a) == true);
    assert(lista_agregar(lista, &b) == true);
    assert(lista_cantidad(lista) == 2);
    assert(lista_agregar(NULL, &a) == false);
    lista_destruir(lista);
    printf("test_lista_agregar OK\n");
}

void test_lista_insertar() {
    lista_t* lista = lista_crear();
    int a = 1, b = 2, c = 3;
    lista_agregar(lista, &a);
    lista_agregar(lista, &c);
    assert(lista_insertar(lista, &b, 1) == true); // Inserta en el medio
    assert(lista_insertar(lista, &a, 0) == true); // Inserta al principio
    assert(lista_insertar(lista, &a, 100) == false); // Posición inválida
    assert(lista_insertar(NULL, &a, 0) == false);
    lista_destruir(lista);
    printf("test_lista_insertar OK\n");
}

void test_lista_eliminar_elemento() {
    lista_t* lista = lista_crear();
    int a = 1, b = 2;
    lista_agregar(lista, &a);
    lista_agregar(lista, &b);
    assert(lista_eliminar_elemento(lista, 0) == &a);
    assert(lista_eliminar_elemento(lista, 0) == &b);
    assert(lista_eliminar_elemento(lista, 0) == NULL);
    assert(lista_eliminar_elemento(NULL, 0) == NULL);
    lista_destruir(lista);
    printf("test_lista_eliminar_elemento OK\n");
}

int comparador_int(const void* a, const void* nodo) {
    // nodo es un nodo_t*, pero en la función se pasa el dato directamente
    return (*(int*)a) - (*(int*)nodo);
}

void test_lista_buscar_posicion() {
    lista_t* lista = lista_crear();
    int a = 1, b = 2;
    lista_agregar(lista, &a);
    lista_agregar(lista, &b);
    assert(lista_buscar_posicion(lista, &a, comparador_int) == 0);
    assert(lista_buscar_posicion(lista, &b, comparador_int) == 1);
    int c = 3;
    assert(lista_buscar_posicion(lista, &c, comparador_int) == -1);
    assert(lista_buscar_posicion(NULL, &a, comparador_int) == -1);
    lista_destruir(lista);
    printf("test_lista_buscar_posicion OK\n");
}

void test_lista_buscar_elemento() {
    lista_t* lista = lista_crear();
    int a = 1, b = 2;
    lista_agregar(lista, &a);
    lista_agregar(lista, &b);
    assert(lista_buscar_elemento(lista, 0) == &a);
    assert(lista_buscar_elemento(lista, 1) == &b);
    assert(lista_buscar_elemento(lista, 2) == NULL);
    assert(lista_buscar_elemento(NULL, 0) == NULL);
    lista_destruir(lista);
    printf("test_lista_buscar_elemento OK\n");
}

bool sumar_elementos(void* dato, void* extra) {
    *(int*)extra += *(int*)dato;
    return true;
}

void test_lista_con_cada_elemento() {
    lista_t* lista = lista_crear();
    int a = 1, b = 2, suma = 0;
    lista_agregar(lista, &a);
    lista_agregar(lista, &b);
    size_t recorridos = lista_con_cada_elemento(lista, sumar_elementos, &suma);
    assert(recorridos == 2);
    assert(suma == 3);
    assert(lista_con_cada_elemento(NULL, sumar_elementos, &suma) == 0);
    lista_destruir(lista);
    printf("test_lista_con_cada_elemento OK\n");
}



void test_iterador_crear() {
    lista_t* lista = lista_crear();
    lista_agregar(lista, (void*)1);
    lista_iterador_t* it = lista_iterador_crear(lista);
    assert(it != NULL);
    lista_iterador_destruir(it);
    lista_destruir(lista);
}

void test_iterador_hay_mas_elementos() {
    lista_t* lista = lista_crear();
    lista_agregar(lista, (void*)1);
    lista_iterador_t* it = lista_iterador_crear(lista);
    assert(lista_iterador_hay_mas_elementos(it) == true);
    lista_iterador_siguiente(it);
    assert(lista_iterador_hay_mas_elementos(it) == false);
    lista_iterador_destruir(it);
    lista_destruir(lista);
}

void test_iterador_obtener_actual() {
    lista_t* lista = lista_crear();
    int valor = 42;
    lista_agregar(lista, &valor);
    lista_iterador_t* it = lista_iterador_crear(lista);
    assert(lista_iterador_obtener_actual(it) == &valor);
    lista_iterador_destruir(it);
    lista_destruir(lista);
}

void test_iterador_siguiente() {
    lista_t* lista = lista_crear();
    int a = 1, b = 2;
    lista_agregar(lista, &a);
    lista_agregar(lista, &b);
    lista_iterador_t* it = lista_iterador_crear(lista);
    assert(lista_iterador_obtener_actual(it) == &a);
    lista_iterador_siguiente(it);
    assert(lista_iterador_obtener_actual(it) == &b);
    lista_iterador_destruir(it);
    lista_destruir(lista);
}

void test_iterador_destruir() {
    lista_t* lista = lista_crear();
    lista_iterador_t* it = lista_iterador_crear(lista);
    lista_iterador_destruir(it); // No debe dar error
    lista_destruir(lista);
}

int main() {
	test_lista_vacia();
    test_lista_agregar();
    test_lista_insertar();
    test_lista_eliminar_elemento();
    test_lista_buscar_posicion();
    test_lista_buscar_elemento();
    test_lista_con_cada_elemento();
    printf("Todos los tests de lista pasaron correctamente.\n");

    test_iterador_crear();
    test_iterador_hay_mas_elementos();
    test_iterador_obtener_actual();
    test_iterador_siguiente();
    test_iterador_destruir();
    printf("Todos los tests del iterador pasaron correctamente.\n");
    return 0;
}