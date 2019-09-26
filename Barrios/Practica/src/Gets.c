
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"

int ObtenerResultado(char msj[])
{
	int input;

	printf(msj);
	scanf("%d",&input);

	return input;
}


int getInt(char msj[])
{
	int numero;

	printf(msj);
	scanf("%d",&numero);

	return numero;
}



int esNumerico (char str[])
{
	int i=0;

	while(str[i] != '\0')
	{
		if(str[i] < '0' || str > '9')

			return 0;
		i++;


	}

	return 1;
}

int esSoloLetras(char str[])
{
	int i = 0;

	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
			return 0;
		i++;

	}
	return 1;
}



void getString(char msj[], char input[])
{
	printf("%s",msj);
	scanf("%s",input);

}

int getStringLetras(char msj[],char input[])
{
	char auxiliar[256];
	getString(msj,auxiliar);

	if(esSoloLetras(auxiliar))
	{
		strcpy(input,auxiliar);

		return 1;
	}

	return 0;
}

int getStringNumeros(char msj[],int *input)
{
	int auxiliar;

	if(esNumerico(auxiliar))
	{
		strcpy(input,auxiliar);

		return 1;
	}

	return 0;
}
