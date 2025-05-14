#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Variables globales para bucles
long n = 0;
int i = 0;

int main() {

	int *dyn, buf[1000000]; // Asuma que un int ocupa 4 bytes (1 millón de int)

	for(n = 0; n < 1000000; n++) { // Inicialización del buffer
		buf[n] = rand(); // Se llena el buffer estático con 1 millón de números aleatorios
	}

	for(i = 0; i < 5; i++) { // Bucle principal
		printf ("Comienzo de iteración número %d\n\n", i + 1);
		sleep(4); // espera 4 segundos
		dyn = malloc(52428800); // Reserva 50 MB de memoria dinámica

		for(n = 0; n < (52428800 / 4); n++) {
			dyn[n] = rand() * rand() * rand(); // Se llena la memoria dinámica con datos aleatorios
		} // Esto genera valores grandes o incluso negativos

		sleep(4);
	} 
	/* IMPORTANTE: 
	No se libera la memoria (free) dentro del bucle,
	así que se pierden 50 MB por iteración (excepto la última).
	Esto genera fugas de memoria (memory leaks).*/

	printf("Finalizaron las iteraciones\n");
	sleep(4);
	free(dyn); // Libera la memoria dinámica usada en la última iteración solamente.
	printf("Presione CTRL+C para finalizar\n");
	pause(); // pausa el programa indefinidamente
	return 0;
}
