#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"

/**
 * \brief Inicializa el status en un array de libros
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setClientesisEmpty(Cliente Array[],int arrayLenght,int value)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        Array[i].isEmpty = value;
    }
}



/**
 * \brief Busca la primer ocurrencia de un libro mediante su codigo
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param code Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findClienteId(Cliente Array[],int arrayLenght,int code)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(Array[i].id == code && Array[i].isEmpty == 1)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findLugarVacioCliente(Cliente Array[],int arrayLenght)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(Array[i].isEmpty == 0)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Carga los valores del libro
 * \param bookArray Es el array de libros
 * \param freePlaceIndex Indica la posicion a setear
 * \param codeAux Codigo del libro
 * \param titleAux Titulo del libro
 * \param authorIdAux Id del autor
 * \param stockIdAux Cantidad de ejemplaes disponibles
 * \return -
 *
 */
void setCliente(Cliente Array[],int freePlaceIndex, int idAux,int cuitAux,char nombreAux[],char direccionAux[], int numeroCalleAux,char localidadAux[])
{

    Array[freePlaceIndex].id = idAux;
    Array[freePlaceIndex].cuit = cuitAux;
    strcpy(Array[freePlaceIndex].nombre,nombreAux);
    strcpy(Array[freePlaceIndex].direccion,direccionAux);
    Array[freePlaceIndex].numeroDireccion = numeroCalleAux;
    strcpy(Array[freePlaceIndex].localidad,localidadAux);
    Array[freePlaceIndex].isEmpty = 1;
}

/**
 * \brief Muestra los libros activos por pantalla
 * \param bookArray Es el array de libros
 * \param arrayLenght Indica la logitud del array
 * \return -
*/
void showClienteArray(Cliente Array[],int arrayLenght)
{
    int i;
    printf("\n| ID - CUIT - NOMBRE - DIRECCION - NRO CALLE - LOCALIDAD");
    for(i=0;i < arrayLenght; i++)
    {
        if(Array[i].isEmpty != 0)
        {
            printf("\n %d  - %d - %s - %s - %d - %s",Array[i].id,Array[i].cuit,Array[i].nombre,Array[i].direccion,Array[i].numeroDireccion,Array[i].localidad);
        }
    }

}


