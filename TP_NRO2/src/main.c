/*
 ============================================================================
 Name        : TP_NRO2.c
 Author      : Barrios
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "employeesArray.h"

int main(void)
{
		// --- Arrays de empleados ---
	    Employee empleadosArray[QTY];
	    // --- Auxiliar para realizar el ordenamiento ---
	    Employee empleadosAux;


	    // --- Auxiliares para asignarles el valor que el usuario desea y luego reemplazarlos en los campos de la estructura. ---
	    char idAuxStr[51];
	    int idAux;
	    char lastNameAux[51];
	    char nameAux[51];
	    char salaryAuxStr[51];
	    float salaryAux;
	    char sectorAuxStr[51];
	    int sectorAux;

	    int espacioLibre;
	    int encontrarEspacio;
	    int option = 0;

	    int i,j;

	    // --- inicio el Array de empleados. Cargo todos los datos en 0. ---
	    initEmployees (empleadosArray,QTY,0);

	    while(option != 5)
	    {
	         option = getInt("\n\n\n1 - ALTA EMPLEADOS \n2 - MODIFICAR EMPLEADOS \n3 - BAJAR EMPLEADO\n4 - ORDENAR Y LISTAR EMPLEADOS \n5 - SALIR\n\n\n");

	         switch(option)
	         {
	            case 1: // --- ALTA ---

	                espacioLibre = buscarLugarLibre(empleadosArray,QTY); // Busco si hay espacio libre.

	                if(espacioLibre == -1)
	                {
	                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
	                    break;
	                }

	                printf("\nALTA\n");

	                // --- Validaciones ---
	                if (!getStringNumeros("Ingrese el id: ",idAuxStr))
	                {
	                    printf ("El id debe ser numerico\n");
	                    break;
	                }
	                idAux = atoi(idAuxStr);

	                if(buscarId(empleadosArray,QTY,idAux) != -1)
	                {
	                    printf("\n\nEL ID YA EXISTE!!!\n");
	                    break;
	                }


	                if (!getStringLetras("Ingrese el apellido: ",lastNameAux))
	                {
	                    printf ("El apellido debe estar compuesta solo por letras\n");
	                    break;
	                }

	                if (!getStringLetras("Ingrese el nombre: ",nameAux))
	                {
	                	printf ("El nombre debe estar compuesta solo por letras\n");
	                    break;
	                }

	                if (!getStringNumerosFlotantes("Ingrese el salario: ",salaryAuxStr))
	                {
	                    printf ("El salario debe ser numerico\n");
	                    break;
	                }
	                salaryAux = atof(salaryAuxStr);

	                if (!getStringNumeros("Ingrese el sector: ",sectorAuxStr))
	                {
	                    printf ("El sector debe ser numerico\n");
	                    break;
	                }
	                sectorAux = atoi(sectorAuxStr);

	                // --- Cargo los datos en los campos ---
	                empleadosArray[espacioLibre].id = idAux;
	                strcpy(empleadosArray[espacioLibre].lastName,lastNameAux);
	                strcpy(empleadosArray[espacioLibre].name,nameAux);
	                empleadosArray[espacioLibre].salary = salaryAux;
	                empleadosArray[espacioLibre].sector = sectorAux;
	                empleadosArray[espacioLibre].isEmpty = 1;

	                break;

	            case 2: // --- MODIFICAR ---

	            	if (!getStringNumeros("Ingrese el id a modificar: ",idAuxStr))
	            	{
	            		printf ("El id debe ser numerico\n");
	            		break;
	            	}
	            	idAux = atoi(idAuxStr);

	            	encontrarEspacio = buscarId(empleadosArray,QTY,idAux);

	            	if(encontrarEspacio == -1)
	            	{
	            		printf("\n\nNO SE ENCUENTRA ESE ID\n");
	            		break;
	            	}

	            	if (!getStringLetras("Ingrese el apellido: ",lastNameAux))
	            	{
	            		printf ("El apellido debe estar compuesta solo por letras\n");
	            		break;
	            	}

	            	if (!getStringLetras("Ingrese el nombre: ",nameAux))
	            	{
	            		printf ("El nombre debe estar compuesta solo por letras\n");
	            		break;
	            	}

	            	if (!getStringNumerosFlotantes("Ingrese el salario: ",salaryAuxStr))
	            	{
	            		printf ("El salario debe ser numerico\n");
	            		break;
	            	}
	            	salaryAux = atof(salaryAuxStr);

	            	if (!getStringNumeros("Ingrese el sector: ",sectorAuxStr))
	            	{
	            		printf ("El sector debe ser numerico\n");
	            		break;
	            	}
	            	sectorAux = atoi(sectorAuxStr);;

	            	// --- Le asigno la modificacion nueva. ---
	            	strcpy(empleadosArray[encontrarEspacio].lastName,lastNameAux);
	            	strcpy(empleadosArray[encontrarEspacio].name,nameAux);
	            	empleadosArray[encontrarEspacio].salary = salaryAux;
	            	empleadosArray[encontrarEspacio].sector = sectorAux;
	            	empleadosArray[encontrarEspacio].isEmpty = 1;
	            	break;


	         case 3: // --- BAJAS ---
	        	 if (!getStringNumeros("Ingrese el id  a dar de baja: ",idAuxStr))
	        	 {
	        		 printf ("El id debe ser numerico\n");
					break;
	        	 }
	        	 idAux = atoi(idAuxStr);

	        	 encontrarEspacio = buscarId(empleadosArray,QTY,idAux);

	        	 if(encontrarEspacio == -1)
	        	 {
	        		 printf("\n\nNO FUE POSIBLE ENCONTRAR ESE ID\n");
	        		 break;
	        	 }
	        	 empleadosArray[encontrarEspacio].isEmpty = 0; // = 0 osea inactivo.

	         	 break;


	         case 4: // --- ORDENAMIENTO Y LISTAR ---

	        	 for(i=0; i < QTY - 1; i++)
	        	 {
	        		 if(empleadosArray[i].id == 0)
	        		 {
	        			 continue;
	        		 }
	        		 for(j=i+1; j < QTY; j++)
	        		 {
	        			 if(empleadosArray[i].id == 0)
	        			 {
	        				 continue;
	        			 }
	        			 if(strcmp(empleadosArray[j].lastName,empleadosArray[i].lastName) > 0)
	        			 {
	        				 empleadosAux = empleadosArray[j];
	        				 empleadosArray[j] = empleadosArray[i];
	        				 empleadosArray[i] = empleadosAux;
	        			 }

	        			 else if (strcmp(empleadosArray[j].lastName,empleadosArray[i].lastName) == 0 && empleadosArray[j].sector < empleadosArray[i].sector)
						 {
	        				 empleadosAux = empleadosArray[j];
	        				 empleadosArray[j] = empleadosArray[i];
	        				 empleadosArray[i] = empleadosAux;


	        			 }
	        		 }

	        	 }


	        	 	 printf("\nAPELLIDO - NOMBRE - SALARIO - SECTOR - ID\n");
	        	 	 for(i=0;i < QTY; i++)
	        	 	 {
	        	 		if(empleadosArray[i].isEmpty != 0)
	        		 {
	        			 printf("\n%s - %s - %.2f - %d - %d",empleadosArray[i].lastName,empleadosArray[i].name,empleadosArray[i].salary,empleadosArray[i].sector,empleadosArray[i].id);
	        		 }
	        	 	 }

	        	 	 // INFORMO EL SALARIO Y PROMEDIO

	        	 	 printf("\n");

	        	 	promedioSalario (empleadosArray,QTY);



	        	 break;


	    }
	    		}
			}

