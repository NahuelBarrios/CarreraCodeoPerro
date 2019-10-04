#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "employeesArray.h"

/**
 * \brief Inicializa el status en un array de empleados
 * \param list Es el array en el cual buscar
 * \param len Indica la logitud del array
 * \param value Es el valor que se asignara a estatus
 * \return -
 *
 */
void initEmployees(Employee list[], int len,int value)
{
    int i;
    for(i=0;i < len; i++)
    {
        list[i].isEmpty = value;
    }
}

/**
 * \brief Busca la primer ocurrencia de un empleado mediante su id
 * \param list Es el array en el cual buscar
 * \param len Indica la logitud del array
 * \param code Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int buscarId(Employee list[],int len,int code)
{
    int i;
    for(i=0;i < len; i++)
    {
        if(list[i].id == code && list[i].isEmpty == 1)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param list Es el array en el cual buscar
 * \param len Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int buscarLugarLibre(Employee list[],int len)
{
    int i;
    for(i=0;i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Inicializa el status en un array de empleados
 * \param list Es el array en el cual buscar
 * \param len Indica la logitud del array
 * \return -
 *
 */
void promedioSalario (Employee list[],int len)
{
	int i;
	int contadorSalarios = 0;
	float acumulador = 0;
	float promediosSalarios = 0;
	int pasanElPromedio = 0;


	for(i=0;i < len;i++)
	{
		if(list[i].isEmpty == 1)
		{
			contadorSalarios++;

			acumulador = acumulador + list[i].salary;
		}

		promediosSalarios = acumulador / contadorSalarios;

	}

	for(i=0;i < len;i++)
	{
		if(list[i].isEmpty == 1 && list[i].salary > promediosSalarios)
		{
			pasanElPromedio++;
		}
	}


	printf("\nTOTAL DE SALARIOS: %d\n",contadorSalarios);
	printf("SALARIO PROMEDIO: %.2f\n",promediosSalarios);
	printf("EMPLEADOS QUE PASAN EL PROMEDIO: %d\n",pasanElPromedio);








}
