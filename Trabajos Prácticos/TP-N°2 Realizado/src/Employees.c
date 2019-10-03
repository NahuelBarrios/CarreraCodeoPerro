#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "Employees.h"

/**
 * \brief Inicializa el status en un array de productos
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a estatus
 * \return -
 *
 */
void initEmployees(Employee list[], int len,int value)
{
    int i;
    for(i=0;i < len; i++)
    {
        list[i].isEmpty = value;
    }
}

/**
 * \brief Busca la primer ocurrencia de un producto mediante su codigo
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param code Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findProductByCode(Employee list[],int len,int code)
{
    int i;
    for(i=0;i < len; i++)
    {
        if(list[i].id == code && list[i].isEmpty == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findEmptyPlace(Employee list[],int len)
{
    int i;
    for(i=0;i < len; i++)
    {
        if(list[i].isEmpty == -1)
        {
            return i;
        }
    }
    return -1;
}
