#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorn = -1;
	Employee* pEAux;

	char idAux[51],nombreAux[51],horasTrabajadasAux[51],sueldoAux[51];

	 if(pFile != NULL && pArrayListEmployee != NULL)
	 {
		 do
		 {

			 fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",&idAux,&nombreAux,&horasTrabajadasAux,&sueldoAux);

			 pEAux = employee_newParametros(idAux,nombreAux,horasTrabajadasAux,sueldoAux);

			 if(pEAux != NULL)
			 {
				 ll_add(pArrayListEmployee,pEAux);// le agrego un nuevo empleado al final del linkedlist
				 retorn = 0;

			 }

		 }while(!feof(pFile)); // verifica que haya lectura


	 }
	 return retorn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorn = -1;

	Employee* pEAux;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do{
			pEAux = employee_new();

			fread(pEAux,sizeof(Employee),1,pFile);

			if(pEAux != NULL)
			{

				ll_add(pArrayListEmployee,pEAux);

			}

		}while(!feof(pFile));
	}
    return retorn;
}
