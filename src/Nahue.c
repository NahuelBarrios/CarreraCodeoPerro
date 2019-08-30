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

#define ITERA_DOR 5

int calculoMaximoyMin (int *pMax, int *pMin, int *pAcumulador, float *pPromedio );

int main (void){

	int maximo=0;
	int minimo=0;
	int acumulador;
	float promedio;


	calculoMaximoyMin(&maximo,&minimo,&acumulador,&promedio);

	printf("El maximo es: %d\n",maximo);
	printf("El minimo es: %d\n",minimo);

	printf("El promedio es:%f\n",promedio);

return 0;



}

int calculoMaximoyMin (int *pMax, int *pMin, int *pAcumulador,float *pPromedio ){

	int numero;
	int i;
	int flag = 0;

	for (i = 0; i < ITERA_DOR;i++){

		printf("Ingrese un numero:");
		scanf("%d",&numero);

		if(flag == 0){
			*pMax = numero;
			*pMin = numero;
			flag =1;

		}

		else{

		if (numero > *pMax){

			*pMax = numero;
		}

		if (numero < *pMin)

			*pMin = numero;

		}

		*pAcumulador = *pAcumulador + numero;




	}

	*pPromedio = *pAcumulador / ITERA_DOR;

		return 0;

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

