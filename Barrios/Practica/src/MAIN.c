/*
 ============================================================================
 Name        : Practica.c
 Author      : Barrios
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"
#include "getArray.h"
#define QTY 1000



int primerOcurrencia (Employee arrayEmpleados[],int limite, int valor);



int main()
{

	int auxiliarId;
	char auxiliarName[50];
	char auxiliarLastName[50];
	//float auxiliarSalary;
	int auxiliarSector;
	//int auxiliarIsEmpty;

	int lugarLibre;
	//int resultadoBusqueda;
	int opcion = 0;
	//int i,j;

	Employee Empleados[QTY]; // Inicializo la estructura con 1000 Empleados.

	InicializarEmpleados(Empleados,QTY,-1);

	while(opcion != 5)
	{
		opcion = ObtenerResultado("\n 1- ALTA \n 2- BAJA \n 3- MODIFICAR \n 4- INFORMAR \n 5- SALIR ");

		switch(opcion)
		{
			case 1:

			lugarLibre = primerOcurrencia(Empleados,QTY,-1);

			if(lugarLibre == -1)
			{
				printf("\n NO QUEDAN ESPACIOS LIBRES \n");
				break;
			}

			printf("\n ALTAS \n");

			if(!getStringNumeros("Ingrese el id:",&auxiliarId))
			{
				printf("\n EL ID DEBE SER SOLO NUMEROS \n");
				break;
			}


			if(!getStringLetras("Ingrese el nombre: ",auxiliarName))
			{
				printf("\n EL NOMBRE DEBE ESTAR FORMADO POR SOLO LETRAS");
				break;
			}

			if(!getStringLetras("Ingrese el apellido: ",auxiliarLastName))
			{
				printf("\n EL APELLIDO DEBE ESTAR FORMADO POR SOLO LETRAS");
				break;
			}


			if(!getStringNumeros("Ingrese el sector:",&auxiliarSector))
			{
				printf("\n EL SECTOR DEBE SER SOLO NUMEROS \n");
				break;
			}



			Empleados[lugarLibre].id=auxiliarId;
			strcpy(Empleados[lugarLibre].name,auxiliarName);
			strcpy(Empleados[lugarLibre].lastName,auxiliarLastName);

			break;

			case 2:

				if(!getStringNumeros("Ingrese el id a dar de baja:",&auxiliarId))
				{
					printf("\n EL ID DEBE SER SOLO NUMEROS \n");
					break;
				}




		}

	}

}

int primerOcurrencia (Employee arrayEmpleados[],int limite, int valor)
{
	int i;

	for(i=0;i<limite;i++)
	{
		if(arrayEmpleados[i].id == valor)
		{
			return i;
		}

	}

	return -1;

}
