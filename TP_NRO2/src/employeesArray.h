#ifndef EMPLOYEESARRAY_H_
#define EMPLOYEESARRAY_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY 1000


struct
{

 int id;
 char lastName[51];
 char name[51];
 float salary;
 int sector;
 int isEmpty; // *Activo == (1) || *Inactivo == (0)

}typedef Employee;


void initEmployees(Employee list[],int len,int value);
int buscarLugarLibre(Employee list[],int len);
int buscarId(Employee list[],int len,int code);


#endif /* EMPLOYEESARRAY_H_ */
