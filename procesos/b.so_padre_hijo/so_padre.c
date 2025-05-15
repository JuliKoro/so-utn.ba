#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Función auxiliar que reserva memoria
 * 
 * @param num puntero a int
 * @param n bytes a reservar
 */
void aumentar_memoria(int *num, int n);

int main(void)
{
	pid_t pid_hijo;
	// num es un puntero a int, que se utilizará para reservar memoria
	// retorno_hijo: variable para guardar el estado de salida del hijo.
	int *num, retorno_hijo = 1;

	puts("Padre: Aumentamos el tamaño del proceso"); // Para realizar un análisis con HTOP
	aumentar_memoria(num, 262144000); // Se intenta aumentar la memoria de num (250 MB)
	// Y en realidad, la función no modifica realmente la memoria como se espera

	pid_hijo = fork(); // creamos un proceso hijo (y retorna un valor)

	if(pid_hijo > 0){ // si es proceso padre (el PID del hijo)

		puts("Padre: Empezando a dormir por 20 segundos\n");
		sleep(20);
		puts("Padre: Me desperté de la siesta");

		wait(&retorno_hijo);	// esperando estado de finalización algún proceso hijo

		// Imprime el valor de retorno del hijo usando WEXITSTATUS.
		printf("Padre: El proceso hijo retornó %d\n", WEXITSTATUS(retorno_hijo));

	}
	else { // = 0 en el proceso hijo
		char *programa[] = {"so_hijo", NULL}; // array para guardar el nombre del nuevo proceso

		puts("Hijo: Aumentamos el tamaño del proceso"); // Para realizar un análisis con HTOP
		aumentar_memoria (num, 524288000); // Reserva memoria (500 MB)

		puts("Hijo: Empezando a dormir\n");
		sleep(10);

		puts("Hijo: Fin de este programa");

		execv("so_hijo", programa); // reemplaza la imagen actual del proceso por la del programa so_hijo.
		// Si execv tiene éxito, el resto del código no se ejecuta.
		
		// Si falla, se ejecuta el return 10.
		return (10);
	}
	// faltaría un <0 si hubo error.

	return 0;
}

void aumentar_memoria(int *num, int n) {

	int i = 0;
	num = malloc(n); // Reserva n bytes (mal uso del parámetro)
	for (i = 0; i < 0; i++) { // ¡nunca entra al for!
		num[i] = i + 1;
	}
	/* PROBLEMAS:
	- El puntero num se pasa por valor, por lo que la reserva de memoria no afecta a la variable del main.
	- El for nunca se ejecuta.
	SOLUCIÓN: Debería recibir un int** y hacer un bucle válido.
	*/
}