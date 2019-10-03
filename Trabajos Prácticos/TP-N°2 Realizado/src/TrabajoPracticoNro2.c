/*
 ============================================================================
 Name        : TrabajoPracticoNro2.c
 Author      : Barrios
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Employees.h"

int main(void)
{
	// arrays de empleados
	    Employee empleadosArray[QTY];
	    //_________________________________________________
	    Employee empleadosAux;

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

	    initEmployees (empleadosArray,QTY,-1);

	    while(option != 6)
	    {
	         option = getInt("\n\n\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - SALIR\n\n\n");

	         switch(option)
	         {
	            case 1:

	                espacioLibre = findEmptyPlace(empleadosArray,QTY);

	                if(espacioLibre == -1)
	                {
	                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
	                    break;
	                }

	                printf("\nALTA\n");

	                if (!getStringNumeros("Ingrese el id: ",idAuxStr))
	                {
	                    printf ("El id debe ser numerico\n");
	                    break;
	                }
	                idAux = atoi(idAuxStr);

	                if(findProductByCode(empleadosArray,QTY,idAux) != -1)
	                {
	                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
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

	                empleadosArray[espacioLibre].id = idAux;
	                strcpy(empleadosArray[espacioLibre].lastName,lastNameAux);
	                strcpy(empleadosArray[espacioLibre].name,nameAux);
	                empleadosArray[espacioLibre].salary = salaryAux;
	                empleadosArray[espacioLibre].sector = sectorAux;
	                empleadosArray[espacioLibre].isEmpty = 0;

	                break;

	         case 2:
	        	 if (!getStringNumeros("Ingrese el id  a dar de baja: ",idAuxStr))
	        	 {
	        		 printf ("El id debe ser numerico\n");
					break;
	        	 }
	        	 idAux = atoi(idAuxStr);

	        	 encontrarEspacio = findProductByCode(empleadosArray,QTY,idAux);

	        	 if(encontrarEspacio == -1)
	        	 {
	        		 printf("\n\nNO FUE POSIBLE ENCONTRAR ESE ID\n");
	        		 break;
	        	 }
	        	 empleadosArray[encontrarEspacio].isEmpty = -1;

	         	 break;

	         case 3:
	        	 if (!getStringNumeros("Ingrese el id a modificar: ",idAuxStr))
	        	 {
	        		 printf ("El id debe ser numerico\n");
	        		 break;
	        	 }
	        	 idAux = atoi(idAuxStr);

	        	 encontrarEspacio = findProductByCode(empleadosArray,QTY,idAux);

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

	        	 strcpy(empleadosArray[encontrarEspacio].lastName,lastNameAux);
	        	 strcpy(empleadosArray[encontrarEspacio].name,nameAux);
	        	 empleadosArray[encontrarEspacio].salary = salaryAux;
	        	 empleadosArray[encontrarEspacio].sector = sectorAux;
	        	 empleadosArray[encontrarEspacio].isEmpty = 0;
	        	 break;

	         case 4:
	        	 printf("\nLISTAR\n");
	        	 for(i=0;i < QTY; i++)
	        	 {
	        		 if(empleadosArray[i].id != -1)
	        		 {
	        			 printf("\n%d - %s  - %s - %.2f - %d",empleadosArray[i].id,empleadosArray[i].lastName,empleadosArray[i].name,empleadosArray[i].salary,empleadosArray[i].sector);
	        		 }
	        	 }
	        	 break;

	         case 5:
	        	 printf("\nORDENADO\n");

	        	 for(i=0; i < QTY - 1; i++)
	        	 {
	        		 if(empleadosArray[i].id == -1)
	        		 {
	        			 continue;
	        		 }
	        		 for(j=i+1; j < QTY; j++)
	        		 {
	        			 if(empleadosArray[i].id == -1)
	        			 {
	        				 continue;
	        			 }
	        			 if(strcmp(empleadosArray[j].lastName,empleadosArray[i].lastName))
	        			 {
	        				 empleadosAux = empleadosArray[j];
	        				 empleadosArray[j] = empleadosArray[i];
	        				 empleadosArray[i] = empleadosAux;
	        			 }
	        		 }


	        	  }
	        	 break;
	    }
	    		}
			}











