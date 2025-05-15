#include <stdio.h>

// Este es el programa que el proceso hijo original intenta ejecutar con execv()
int main() {

	// Simplemente imprime un mensaje y retorna 18.
	puts("Hijo: Me convertí\n");
	return 18;

}