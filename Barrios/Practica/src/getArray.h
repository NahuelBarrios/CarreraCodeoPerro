/*
 * getArray.h
 *
 *  Created on: 19 sep. 2019
 *      Author: alumno
 */

#ifndef GETARRAY_H_
#define GETARRAY_H_

int initArrayInt(int *pArray , int limite, int valor);
int printArrayInt(int *pArray , int limite);
int getArrayInt(int *pArray,int limite,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int minMaxArrayInt(int* pArray,int limite,int* minimo,int* maximo);
int sumaArrayInt(int* pArray,int limite,int* resultado);
int promedioArrayInt(int* pArray,int limite,int* resultadoProm);
int OrdenaArrayInt(int* pArray,int limite);


#endif /* GETARRAY_H_ */
