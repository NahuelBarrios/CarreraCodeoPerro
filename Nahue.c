/*
 ============================================================================
 Name        : Nahue.c
 Author      : Barrios
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
int Sumar(int nro1, int nro2);

int main(void) {

	int numero1;
	int numero2;
	int resultado;

	printf("Ingrese un numero:");
	scanf("%d",&numero1);
	printf("Ingrese un numero:");
	scanf("%d",&numero2);

	resultado = Sumar (numero1,numero2);

	printf("El resultado es: %d",resultado);

	return 0;
}

int Sumar(int nro1, int nro2){

	int resultado;

	resultado = nro1 * nro2;

	return resultado;

}
*/

int numeroiterador (int numero);

int main (void){

	int numero;
	int maximo;
	int minimo;
	int cantdevecesqueitera;
	int numeroiterador;
	int acumulador;
	int i;

	cantdevecesqueitera= (numeroiterador);

	printf("Ingrese un numero:");
	scanf("%d",&numero);

	maximo = numero;
	minimo = numero;
	acumulador = numero;

	for (i=0; i < cantdevecesqueitera;i++){

		printf("Ingrese un numero:");
		scanf("%d",&numero);

			if(numero > maximo){

				maximo = numero;
			}

			if(numero < minimo){

				minimo = numero;
			}

			acumulador = acumulador + numero;
	}


	printf("numero maximo: %d\n",maximo);
	printf("numero minimo: %d\n",minimo);
	printf("Promedio: %d",acumulador/cantdevecesqueitera);

	return 0;

}

int numeroiterador (int numero){


	printf("Ingrese el numero iterador:");
	scanf("%d",&numero);

	return numero;

}

/*

 int main (void){

 int resultadomaximo;
 int resultadominimo;

 if(calcularminimomaximo(CANT_ITERA,&resultadomaximo,&resultadominimo) ){

printf("El resultado maximo es %d y el resultado es minimo es %d":,resultado)

 }

return 0;



 }

int calcularminimomaximo (int cantidaddenumeros, int *resultadomaximo, int *resultadominimo

int numero;
numero i;
int maximo;
int minimo;
int retorno = -1;

if(cantidaddenumeros>0 && *resultadomaximo != NULL && resultadominimo != NULL){

for (i=; i< cantidaddenumeros;i++){

printf("Ingrese u numero:/n);
scanf("d%",&numero);

if(i==o || numero > maximo){

maximo = numero;
}

if (i==0 || numero <minimo){

minimo = numero;
}
}




}
*/

