#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/tp1.h"

static bool agregar_a_lista(struct pokemon *p, void *extra)
{
	lista_t *lista = (lista_t *)extra;

	return lista_agregar(lista, p);
}

static void imprimir_uso(const char *prog)
{
	fprintf(stderr,
		"Uso: %s <archivo_pokemones> [--id N | --nombre NOMBRE]\n",
		prog);
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		imprimir_uso(argv[0]);
		return 1;
	}

	const char *ruta = argv[1];

	tp1_t *tp = tp1_leer_archivo(ruta);
	if (!tp) {
		fprintf(stderr,
			"Error: no se pudo leer el archivo '%s' con TP1\n",
			ruta);
		return 1;
	}

	lista_t *lista = lista_crear();
	if (!lista) {
		fprintf(stderr, "Error creando lista\n");
		tp1_destruir(tp);
		return 1;
	}

	size_t cargados = tp1_con_cada_pokemon(tp, agregar_a_lista, lista);

	if (argc == 4 && strcmp(argv[2], "--id") == 0) {
		int id = atoi(argv[3]);
		struct pokemon *p = tp1_buscar_id(tp, id);
		if (p)
			printf("Encontrado: id=%d, nombre=%s, tipo=%d, atk=%d, def=%d, vel=%d\n",
			       p->id, p->nombre ? p->nombre : "(sin nombre)",
			       p->tipo, p->ataque, p->defensa, p->velocidad);
		else
			printf("No encontrado id=%d\n", id);
	} else if (argc == 4 && strcmp(argv[2], "--nombre") == 0) {
		const char *nombre = argv[3];
		struct pokemon *p = tp1_buscar_nombre(tp, nombre);
		if (p)
			printf("Encontrado: id=%d, nombre=%s, tipo=%d, atk=%d, def=%d, vel=%d\n",
			       p->id, p->nombre ? p->nombre : "(sin nombre)",
			       p->tipo, p->ataque, p->defensa, p->velocidad);
		else
			printf("No encontrado nombre=%s\n", nombre);
	} else {
		imprimir_uso(argv[0]);
		printf("Cargados: %zu pokemones\n", cargados);
	}

	lista_destruir(lista);
	tp1_destruir(tp);
	return 0;
}
