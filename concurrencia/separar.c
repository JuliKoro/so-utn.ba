#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sched.h>

// Define una estructura
struct argumento {
	char mensaje[9]; // un msj (ej. "aa.bb.cc")
	int hilo; // Un nro de hilo (0 o 1).
};

void mifuncion(struct argumento *str);

int main() {
	int i, hilos = 2;

	// Se crean dos estructuras diferentes, una para cada hilo
	struct argumento hilo0 = {"aa.bb.cc", 0};
	struct argumento hilo1 = {"11.22.33", 1};

	pthread_t tid[hilos];

	// Crea dos hilos, c/u ejecuta mifuncion con su respectivo argumento
	pthread_create(&tid[0], NULL, (void*) mifuncion, (void *) &hilo0);
	pthread_create(&tid[1], NULL, (void*) mifuncion, (void *) &hilo1);


	// Espero finalizacion de todos los hilos para continuar
	for (i = 0; i < hilos; i++) {
		pthread_join(tid[i], NULL);
	}

	printf ("Finalizó la separación\n\n\n");
	return EXIT_SUCCESS;
}

/**
 * @brief Divide una cadena de char, y las delimita con un '.'
 * @param argumento struct que contiene el mensaje y nro de hilo
 */
void mifuncion(struct argumento *str) {

	int i;
	char *partes_mensaje[3]; // Para dividir el msj en 3

	partes_mensaje[0] = strtok (str->mensaje,"."); // SC
	partes_mensaje[1] = strtok (NULL,".");

	// cede voluntariamente la CPU al otro hilo
	sched_yield();

	partes_mensaje[2] = strtok (NULL,".");

	for (i = 0; i < 3; i++) {
		printf("Subcadena del hilo %d - %s\n",str->hilo, partes_mensaje[i]);

	}
}
