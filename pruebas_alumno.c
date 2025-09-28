#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include "pa2m.h"
#include <stdio.h>
#include <assert.h>

void test_lista_vacia()
{
	lista_t *lista = lista_crear();
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

void test_lista_agregar()
{
	lista_t *lista = lista_crear();
	int a = 1, b = 2;
	assert(lista_agregar(lista, &a) == true);
	assert(lista_agregar(lista, &b) == true);
	assert(lista_cantidad(lista) == 2);
	assert(lista_agregar(NULL, &a) == false);
	lista_destruir(lista);
	printf("test_lista_agregar OK\n");
}

void test_lista_insertar()
{
	lista_t *lista = lista_crear();
	int a = 1, b = 2, c = 3;
	lista_agregar(lista, &a);
	lista_agregar(lista, &c);
	assert(lista_insertar(lista, &b, 1) == true);
	assert(lista_insertar(lista, &a, 0) == true);
	assert(lista_insertar(lista, &a, 100) == false);
	assert(lista_insertar(NULL, &a, 0) == false);
	lista_destruir(lista);
	printf("test_lista_insertar OK\n");
}

void test_lista_eliminar_elemento()
{
	lista_t *lista = lista_crear();
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

int comparador_int(const void *a, const void *nodo)
{
	return (*(int *)a) - (*(int *)nodo);
}

void test_lista_buscar_posicion()
{
	lista_t *lista = lista_crear();
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

void test_lista_buscar_elemento()
{
	lista_t *lista = lista_crear();
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

bool sumar_elementos(void *dato, void *extra)
{
	*(int *)extra += *(int *)dato;
	return true;
}

void test_lista_con_cada_elemento()
{
	lista_t *lista = lista_crear();
	int a = 1, b = 2, suma = 0;
	lista_agregar(lista, &a);
	lista_agregar(lista, &b);
	size_t recorridos =
		lista_con_cada_elemento(lista, sumar_elementos, &suma);
	assert(recorridos == 2);
	assert(suma == 3);
	assert(lista_con_cada_elemento(NULL, sumar_elementos, &suma) == 0);
	lista_destruir(lista);
	printf("test_lista_con_cada_elemento OK\n");
}

void test_iterador_crear()
{
	lista_t *lista = lista_crear();
	lista_agregar(lista, (void *)1);
	lista_iterador_t *it = lista_iterador_crear(lista);
	assert(it != NULL);
	lista_iterador_destruir(it);
	lista_destruir(lista);
}

void test_iterador_hay_mas_elementos()
{
	lista_t *lista = lista_crear();
	lista_agregar(lista, (void *)1);
	lista_iterador_t *it = lista_iterador_crear(lista);
	assert(lista_iterador_hay_mas_elementos(it) == true);
	lista_iterador_siguiente(it);
	assert(lista_iterador_hay_mas_elementos(it) == false);
	lista_iterador_destruir(it);
	lista_destruir(lista);
}

void test_iterador_obtener_actual()
{
	lista_t *lista = lista_crear();
	int valor = 42;
	lista_agregar(lista, &valor);
	lista_iterador_t *it = lista_iterador_crear(lista);
	assert(lista_iterador_obtener_actual(it) == &valor);
	lista_iterador_destruir(it);
	lista_destruir(lista);
}

void test_iterador_siguiente()
{
	lista_t *lista = lista_crear();
	int a = 1, b = 2;
	lista_agregar(lista, &a);
	lista_agregar(lista, &b);
	lista_iterador_t *it = lista_iterador_crear(lista);
	assert(lista_iterador_obtener_actual(it) == &a);
	lista_iterador_siguiente(it);
	assert(lista_iterador_obtener_actual(it) == &b);
	lista_iterador_destruir(it);
	lista_destruir(lista);
}

void test_iterador_destruir()
{
	lista_t *lista = lista_crear();
	lista_iterador_t *it = lista_iterador_crear(lista);
	lista_iterador_destruir(it);
	lista_destruir(lista);
}

int main()
{
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

	// --- Tests de Pila ---
	void test_pila_crear_y_vacia();
	void test_pila_apilar_y_cantidad();
	void test_pila_ver_primero();
	void test_pila_desapilar_LIFO();
	void test_pila_destruir_null();
	void test_pila_pop_sobre_vacia_repetido();
	void test_pila_push_pop_alternado();
	void test_pila_stress_push_muchos();

	test_pila_crear_y_vacia();
	test_pila_apilar_y_cantidad();
	test_pila_ver_primero();
	test_pila_desapilar_LIFO();
	test_pila_destruir_null();
	test_pila_pop_sobre_vacia_repetido();
	test_pila_push_pop_alternado();
	test_pila_stress_push_muchos();
	printf("Todos los tests de pila pasaron correctamente.\n");

	// --- Tests de Cola ---
	void test_cola_crear_y_vacia();
	void test_cola_encolar_y_cantidad();
	void test_cola_ver_primero();
	void test_cola_desencolar_FIFO();
	void test_cola_destruir_null();
	void test_cola_desencolar_vacia_repetido();
	void test_cola_push_pop_alternado();
	void test_cola_stress_encolar_muchos();

	test_cola_crear_y_vacia();
	test_cola_encolar_y_cantidad();
	test_cola_ver_primero();
	test_cola_desencolar_FIFO();
	test_cola_destruir_null();
	test_cola_desencolar_vacia_repetido();
	test_cola_push_pop_alternado();
	test_cola_stress_encolar_muchos();
	printf("Todos los tests de cola pasaron correctamente.\n");
	return 0;
}

// ---------------- Pila: tests ----------------
void test_pila_crear_y_vacia()
{
	pila_t *p = pila_crear();
	assert(p != NULL);
	assert(pila_cantidad(p) == 0);
	assert(pila_ver_primero(p) == NULL);
	assert(pila_desapilar(p) == NULL);
	pila_destruir(p);
	printf("test_pila_crear_y_vacia OK\n");
}

void test_pila_apilar_y_cantidad()
{
	pila_t *p = pila_crear();
	int a = 10, b = 20;
	assert(pila_apilar(p, &a) == true);
	assert(pila_cantidad(p) == 1);
	assert(pila_apilar(p, &b) == true);
	assert(pila_cantidad(p) == 2);
	assert(pila_apilar(p, NULL) == false);
	assert(pila_cantidad(p) == 2);
	pila_destruir(p);
	printf("test_pila_apilar_y_cantidad OK\n");
}

void test_pila_ver_primero()
{
	pila_t *p = pila_crear();
	int a = 1, b = 2;
	assert(pila_ver_primero(p) == NULL);
	pila_apilar(p, &a);
	assert(pila_ver_primero(p) == &a);
	pila_apilar(p, &b);
	assert(pila_ver_primero(p) == &b);
	pila_destruir(p);
	printf("test_pila_ver_primero OK\n");
}

void test_pila_desapilar_LIFO()
{
	pila_t *p = pila_crear();
	int a = 1, b = 2, c = 3;
	pila_apilar(p, &a);
	pila_apilar(p, &b);
	pila_apilar(p, &c);
	assert(pila_cantidad(p) == 3);
	assert(pila_desapilar(p) == &c);
	assert(pila_ver_primero(p) == &b);
	assert(pila_cantidad(p) == 2);
	assert(pila_desapilar(p) == &b);
	assert(pila_desapilar(p) == &a);
	assert(pila_desapilar(p) == NULL);
	assert(pila_cantidad(p) == 0);
	pila_destruir(p);
	printf("test_pila_desapilar_LIFO OK\n");
}

void test_pila_destruir_null()
{
	pila_destruir(NULL);
	printf("test_pila_destruir_null OK\n");
}

void test_pila_pop_sobre_vacia_repetido()
{
	pila_t *p = pila_crear();
	assert(pila_desapilar(p) == NULL);
	assert(pila_desapilar(p) == NULL);
	assert(pila_ver_primero(p) == NULL);
	assert(pila_cantidad(p) == 0);
	pila_destruir(p);
	printf("test_pila_pop_sobre_vacia_repetido OK\n");
}

void test_pila_push_pop_alternado()
{
	pila_t *p = pila_crear();
	int a = 1, b = 2, c = 3;
	assert(pila_apilar(p, &a) == true);
	assert(pila_ver_primero(p) == &a);
	assert(pila_desapilar(p) == &a);
	assert(pila_cantidad(p) == 0);
	assert(pila_apilar(p, &b) == true);
	assert(pila_apilar(p, &c) == true);
	assert(pila_ver_primero(p) == &c);
	assert(pila_desapilar(p) == &c);
	assert(pila_ver_primero(p) == &b);
	assert(pila_desapilar(p) == &b);
	assert(pila_desapilar(p) == NULL);
	pila_destruir(p);
	printf("test_pila_push_pop_alternado OK\n");
}

void test_pila_stress_push_muchos()
{
	pila_t *p = pila_crear();
	const int N = 1000;
	int valores[N];
	for (int i = 0; i < N; i++) {
		valores[i] = i;
		assert(pila_apilar(p, &valores[i]) == true);
		assert(pila_cantidad(p) == (size_t)(i + 1));
	}
	assert(*(int *)pila_ver_primero(p) == N - 1);
	for (int i = N - 1; i >= N - 5; i--) {
		int *x = (int *)pila_desapilar(p);
		assert(x && *x == i);
	}
	while (pila_desapilar(p) != NULL) {
	}
	assert(pila_cantidad(p) == 0);
	pila_destruir(p);
	printf("test_pila_stress_push_muchos OK\n");
}

// ---------------- Cola: tests ----------------
void test_cola_crear_y_vacia()
{
	cola_t *c = cola_crear();
	assert(c != NULL);
	assert(cola_cantidad(c) == 0);
	assert(cola_ver_primero(c) == NULL);
	assert(cola_desencolar(c) == NULL);
	cola_destruir(c);
	printf("test_cola_crear_y_vacia OK\n");
}

void test_cola_encolar_y_cantidad()
{
	cola_t *c = cola_crear();
	int a = 10, b = 20;
	assert(cola_encolar(c, &a) == true);
	assert(cola_cantidad(c) == 1);
	assert(cola_encolar(c, &b) == true);
	assert(cola_cantidad(c) == 2);
	assert(cola_encolar(c, NULL) == false);
	assert(cola_cantidad(c) == 2);
	cola_destruir(c);
	printf("test_cola_encolar_y_cantidad OK\n");
}

void test_cola_ver_primero()
{
	cola_t *c = cola_crear();
	int a = 1, b = 2;
	assert(cola_ver_primero(c) == NULL);
	cola_encolar(c, &a);
	assert(cola_ver_primero(c) == &a);
	cola_encolar(c, &b);
	assert(cola_ver_primero(c) == &a);
	cola_destruir(c);
	printf("test_cola_ver_primero OK\n");
}

void test_cola_desencolar_FIFO()
{
	cola_t *c = cola_crear();
	int a = 1, b = 2, c3 = 3;
	cola_encolar(c, &a);
	cola_encolar(c, &b);
	cola_encolar(c, &c3);
	assert(cola_cantidad(c) == 3);
	assert(cola_desencolar(c) == &a);
	assert(cola_ver_primero(c) == &b);
	assert(cola_cantidad(c) == 2);
	assert(cola_desencolar(c) == &b);
	assert(cola_desencolar(c) == &c3);
	assert(cola_desencolar(c) == NULL);
	assert(cola_cantidad(c) == 0);
	cola_destruir(c);
	printf("test_cola_desencolar_FIFO OK\n");
}

void test_cola_destruir_null()
{
	cola_destruir(NULL);
	printf("test_cola_destruir_null OK\n");
}

void test_cola_desencolar_vacia_repetido()
{
	cola_t *c = cola_crear();
	assert(cola_desencolar(c) == NULL);
	assert(cola_desencolar(c) == NULL);
	assert(cola_ver_primero(c) == NULL);
	assert(cola_cantidad(c) == 0);
	cola_destruir(c);
	printf("test_cola_desencolar_vacia_repetido OK\n");
}

void test_cola_push_pop_alternado()
{
	cola_t *c = cola_crear();
	int a = 1, b = 2, d = 4;
	assert(cola_encolar(c, &a) == true);
	assert(cola_ver_primero(c) == &a);
	assert(cola_desencolar(c) == &a);
	assert(cola_cantidad(c) == 0);
	assert(cola_encolar(c, &b) == true);
	assert(cola_encolar(c, &d) == true);
	assert(cola_ver_primero(c) == &b);
	assert(cola_desencolar(c) == &b);
	assert(cola_ver_primero(c) == &d);
	assert(cola_desencolar(c) == &d);
	assert(cola_desencolar(c) == NULL);
	cola_destruir(c);
	printf("test_cola_push_pop_alternado OK\n");
}

void test_cola_stress_encolar_muchos()
{
	cola_t *c = cola_crear();
	const int N = 1000;
	int valores[N];
	for (int i = 0; i < N; i++) {
		valores[i] = i;
		assert(cola_encolar(c, &valores[i]) == true);
		assert(cola_cantidad(c) == (size_t)(i + 1));
	}
	assert(*(int *)cola_ver_primero(c) == 0);
	for (int i = 0; i < 5; i++) {
		int *x = (int *)cola_desencolar(c);
		assert(x && *x == i);
	}
	while (cola_desencolar(c) != NULL) {
	}
	assert(cola_cantidad(c) == 0);
	cola_destruir(c);
	printf("test_cola_stress_encolar_muchos OK\n");
}