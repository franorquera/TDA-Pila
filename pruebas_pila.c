#include "pila.h"
#include "testing.h"
#include "stdlib.h"

static void prueba_pila_vacia(void) {
    pila_t *pila = pila_crear();
    print_test("La pila se puede crear", pila);
    print_test("La pila esta vacia ", pila_esta_vacia(pila));
    pila_destruir(pila);
}

static void prueba_pila_apilar(void) {
    pila_t *pila = pila_crear();
    print_test("La pila se puede crear", pila);
    int elem1 = 1;
    char elem2[] = "segundo elemento";
    int *elem3 = NULL;
    print_test("Mi pila recien creada esta vacia", pila_esta_vacia(pila));
    print_test("No puedo ver el tope de mi pila vacia", pila_ver_tope(pila) == NULL);
    print_test("Puedo apilar un elemento", pila_apilar(pila, &elem1));
    print_test("Puedo apilar un segundo elemento", pila_apilar(pila, &elem2));
    print_test("Puedo apilar el elemento NULL", pila_apilar(pila, elem3));
    print_test("Puedo ver el tope de mi pila", pila_ver_tope(pila) == NULL);
    print_test("Mi pila no esta vacia", pila_esta_vacia(pila) == false);
    print_test("Puedo desapilar el elemento NULL", pila_desapilar(pila) == NULL);
    pila_destruir(pila);
}

static void prueba_pila_desapilar(void) {
    pila_t *pila = pila_crear();
    print_test("La pila se puede crear", pila);
    int elem1 = 1;
    int elem2 = 2;
    print_test("Mi pila recien creada esta vacia", pila_esta_vacia(pila));
    print_test("No puedo desapilar un elemento de mi pila vacia", pila_desapilar(pila) == NULL);
    print_test("Puedo apilar un elemento", pila_apilar(pila, &elem1));
    print_test("Mi pila ya no esta vacia", pila_esta_vacia(pila) == false);
    print_test("Puedo apilar un segundo elemento", pila_apilar(pila, &elem2));
    print_test("Puedo desapilar un elemento", pila_desapilar(pila));
    print_test("Puedo desapilar un segundo elemento", pila_desapilar(pila));
    print_test("No puedo desapilar un tercer elemento que no esta", pila_desapilar(pila) == NULL);
    print_test("La pila luego de desapilar todos los elementos esta vacia", pila_esta_vacia(pila));
    print_test("No puedo ver el tope de mi pila vacia", pila_ver_tope(pila) == NULL);
    pila_destruir(pila);
}

static void prueba_pila_null(void) {
    pila_t *pila = pila_crear();
    print_test("La pila se puede crear", pila);
    int *null = NULL;
    print_test("Puedo apilar el elemento NULL otra vez", pila_apilar(pila, null));
    print_test("Mi pila con NULL no esta vacia", pila_esta_vacia(pila) == false);
    print_test("Puedo ver el tope de la pila con NULL", pila_ver_tope(pila) == NULL);
    print_test("Puedo desapilar el elemento NULL", pila_desapilar(pila) == NULL);
    pila_destruir(pila);
}

static void prueba_pila_volumen(void) {
    pila_t *pila = pila_crear();
    print_test("La pila se puede crear", pila);
    int *elems[1000] = {0};
    bool apilado = true;
    bool desapilado = true;
    for (int i = 0; i < 1000; i++) {
        if (apilado) {
            apilado = pila_apilar(pila, &i);
            elems[i] = &i;
        }
    }
    print_test("Puedo ver el tope de mi pila DE 1000 ELEMENTOS", pila_ver_tope(pila));
    print_test("El tope de mi pila es el mismo que el ultimo que apile", pila_ver_tope(pila) == elems[999]);
    print_test("Mi pila de 1000 elementos no esta vacia", pila_esta_vacia(pila) == false);
    for (int i = 999; i >= 0; i--) {
        if (desapilado) {
            desapilado = pila_desapilar(pila) == elems[i];
        }
    }
    print_test("No puedo ver el tope de mi pila una vez desapilada", pila_ver_tope(pila) == NULL);
    print_test("Mi pila esta vacia", pila_esta_vacia(pila));
    print_test("No puedo seguir desapilando", pila_desapilar(pila) == NULL);
    pila_destruir(pila);
}

void pruebas_pila_estudiante() {
    prueba_pila_vacia();
    prueba_pila_apilar();
    prueba_pila_desapilar();
    prueba_pila_null();
    prueba_pila_volumen();
}

/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_pila_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
