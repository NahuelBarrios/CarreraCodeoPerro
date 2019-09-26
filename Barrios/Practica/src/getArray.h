/*
 * getArray.h
 *
 *  Created on: 19 sep. 2019
 *      Author: alumno
 */

#ifndef GETARRAY_H_
#define GETARRAY_H_

typedef struct
{
 int id;
 char name[50];
 char lastName[50];
 float salary;
 int sector;
 int isEmpty;

} Employee;

void InicializarEmpleados(Employee list[],int len,int valor);

#endif /* GETARRAY_H_ */
