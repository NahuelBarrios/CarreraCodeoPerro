/*
 * utn.c
 *
 *  Created on: 29 ago. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int calculoMaxYMin(int *flagFun,int numeroFun,int *MaxFun, int *MinFun);

int main(void)
{
	int numero;
	char respuesta;
	int Max = 0;
	int Min = 0;
	int flag = 0;

	do
	{
		//printf("\nIngrese un numero");
		//scanf("%d",&numero);
		getNumero(&Numero,0,100,3,"Numero:","error");
		calculoMaxYMin(&flag,numero,&Max,&Min);
		printf("\nDesea continuar? s/n");
		scanf("%c",&respuesta);

	} while(respuesta != 'n');

	printf("El Maximo es %d ",Max);
	printf("El Minimo es %d ",Min);


}

int calculoMaxYMin(int* pFlag,int numeroFun,
				   int* pMax,int* pMin)
{
	int max = *pMax;
	int min = *pMin;
	int flag = *pFlag;


	//pregunto si es la primera vez que entro
	if(flag==0)
	{
		max = numeroFun;
		min = numeroFun;
		*pFlag=1; // paso el flag externo a 1
	}


	if(numeroFun > max)
	{
		max = numeroFun;
	}
	*pMax = max;


	if(numeroFun < min)
	{
		min = numeroFun;
	}
	*pMin = min;


	return 0;
}

/*
int main (){

	int edad;

	char* t = "hola";
	printf("%s",t);



	 getNumero(&edad,120,1,3,MSG_EDAD,MSG_ERR);

}
*/


int getNumero ( int* pNumero, int rangoMax, int rangoMin, int reintentos,char* pMsg, char* pMsgErr){


 	 int numero,i;
 	 int ret=-1; // cargo con error or default

 	 for(i=0;i < reintentos;i++){

	 //pedido
 	 printf(pMsg);
 	 scanf("%s",pMsg);

	//validacion


	 	 if(numero >= rangoMin && numero <= rangoMax){

	 		 //el numero esta bien

	 		 *pNumero = numero;
	 		 ret = 0;
	 		 break;
	 	 }

	 	 else{
		 printf(pMsgErr);
	 	 }

	}

 	 return ret;


 }
