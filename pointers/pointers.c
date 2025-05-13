#include <stdlib.h>
#include <stdio.h>

int main(void){
   int *p = malloc(sizeof(int));
   *p = 1;
   printf("p = %d\n", p); // valor o dato
   printf("&p = %p\n", &p); // direccion de memoria
   return 0;
}