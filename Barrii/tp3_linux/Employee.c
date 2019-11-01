#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
	Employee* emp = (Employee*)malloc( sizeof(Employee));

	if(emp != NULL)
	{
	    emp->id = 0;
	    strcpy(emp->nombre, "");
	    emp->horasTrabajadas = 0;
	    emp->sueldo = 0;

	}
	return emp;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* emp = (Employee*)malloc( sizeof(Employee));

	if(emp != NULL)
	{
		strcpy(emp->id, idStr);
		strcpy(emp->nombre, nombreStr);
		strcpy(emp->horasTrabajadas, horasTrabajadasStr);
		strcpy(emp->sueldo, sueldoStr);
	}
	    return emp;


}

//-------------------------------------------------------------------
void employee_delete()
{


}


//------------------------------------------------------------------
int employee_setId(Employee* this,int id)
{
	 int todoOk = 0;

	   if( this != NULL && id > 0 ){

	    this->id = id;
	    todoOk = 1;
	   }

	   return todoOk;
}

int employee_getId(Employee* this,int* id)
{
	   int todoOk = 0;

	    if( this != NULL && id != NULL){

	        *id = this->id;
	        todoOk = 1;
	    }

	    return todoOk;

}
//----------------------------------------------------------------------------

int employee_setNombre(Employee* this,char* nombre)
{
	 int todoOk = 0;

	   if( this != NULL && nombre > 0 ){

	    strcpy(this->nombre,nombre);

	    todoOk = 1;
	   }

	   return todoOk;

}

int employee_getNombre(Employee* this,char* nombre)
{
	int todoOk = 0;

		    if( this != NULL && nombre != NULL){

		        strcpy(nombre, this->nombre);
		        todoOk = 1;
		    }

		    return todoOk;
}

//-----------------------------------------------------------------------------

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	 int todoOk = 0;

	   if( this != NULL && horasTrabajadas > 0 ){

	    this->horasTrabajadas = horasTrabajadas;
	    todoOk = 1;
	   }

	   return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	   int todoOk = 0;

		    if( this != NULL && horasTrabajadas != NULL){

		        *horasTrabajadas = this->horasTrabajadas;
		        todoOk = 1;
		    }

		    return todoOk;
}

//--------------------------------------------------------------------------

int employee_setSueldo(Employee* this,int sueldo)
{
	 int todoOk = 0;

	   if( this != NULL && sueldo > 0 ){

	    this->sueldo = sueldo;
	    todoOk = 1;
	   }

	   return todoOk;

}

int employee_getSueldo(Employee* this,int* sueldo)
{
	   int todoOk = 0;

			    if( this != NULL && sueldo != NULL){

			        *sueldo = this->sueldo;
			        todoOk = 1;
			    }

			    return todoOk;



}

//-----------------------------------------------------------------------
