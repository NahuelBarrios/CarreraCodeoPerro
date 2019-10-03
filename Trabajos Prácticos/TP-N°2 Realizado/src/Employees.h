#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY 1000
#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_

typedef struct{
    char description[51];
    int code;
    int qty;
    float price;
    int status; /**< Active (1) or Inactive (0)  */
}Product;

struct
{

 int id;
 char lastName[51];
 char name[51];
 float salary;
 int sector;
 int isEmpty; // *Activo (0) || *Inactivo (-1)

}typedef Employee;


void initEmployees(Employee list[],int len,int value);
int findEmptyPlace(Employee list[],int len);
int findProductByCode(Employee list[],int len,int code);



#endif /* EMPLOYEES_H_ */
