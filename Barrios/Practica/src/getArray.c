#include <stdio.h>
#include <stdlib.h>
#include "getArray.h"

void InicializarEmpleados(Employee list[],int len,int valor)
{
	int i;

	for(i=0;i<len;i++)
	{
		list[i].id = valor;

	}

}

