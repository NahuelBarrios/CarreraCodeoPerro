/*
 ============================================================================
 Name        : ludmila.c
 Author      : ludmila
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pideSuma(int* resultado);


int main(void) {
	int resultado;
	if(pideSuma(&resultado)==0)
		{
			printf("El resultado es %d",resultado);
		}
	else
		{
			printf("ERROR");
		}


}

int pideSuma(int* resultado)
{
	int numeroUno;
	int numeroDos;
	int suma;

	printf("Ingrese el numero uno: ");
	scanf("%d",&numeroUno);
	printf("Ingrese el numero dos: ");
	scanf("%d",&numeroDos);
	suma = numeroUno+numeroDos;
	printf("El resultado de la suma es: %d",suma);
	return 0;

}
