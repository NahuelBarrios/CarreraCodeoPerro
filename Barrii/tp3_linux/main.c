#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************\
    \nMenu:\
     \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\
     \n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\
     \n3. Alta de empleado\
     \n4. Modificar datos de empleado\
     \n5. Baja de empleado\
     \n6. Listar empleados\
     \n7. Ordenar empleados\
     \n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\
     \n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\
    \n10. Salir\
\n*****************************************************/



int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	utn_getUnsignedInt("\n/****************************************************\
    \nMenu:\
     \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\
     \n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\
     \n3. Alta de empleado\
     \n4. Modificar datos de empleado\
     \n5. Baja de empleado\
     \n6. Listar empleados\
     \n7. Ordenar empleados\
     \n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\
     \n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\
    \n10. Salir\
	\n*****************************************************\
    \nInfrese una opcion: ","Opcion Incorrecta",1,sizeof(int),1,8,3,&option);


        switch(option)
        {

            case 1:// --- CARGAR DATOS EN TEXTO ---

                controller_loadFromText("dataTexto.csv",listaEmpleados);
                printf("OK");
                break;

            case 2: // --- CARGAR DATOS EN BINARIO ---

            	controller_loadFromBinary("dataBinario.csv" ,listaEmpleados);


            	break;
            case 3: // --- ALTA ---

            	// ll_sort: ordena por burbujeo. º employee* pE1 = (Employee*) argumento1;
            	// retunr strcomp(PE1->nombre,PE2->nombre);

            	break;
        }
    }while(option != 10);
    return 0;
}

