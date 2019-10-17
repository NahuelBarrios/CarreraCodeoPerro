#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pedido.h"

/**
 * \brief Inicializa el status en un array de libros
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setPedidoisEmpty(Recoleccion Array[],int arrayLenght,int value)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        Array[i].isEmpty = value;
    }
}


/**
 * \brief Inicializa el status en un array de libros
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setPedidopedido(Recoleccion Array[],int arrayLenght,int value)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        Array[i].pedido = value;
    }
}


void setPedido(Recoleccion Array[],int freePlaceIndex, int idClienteAux,int idPedidoAux,float kilosAux,int estadoAux)
{

    Array[freePlaceIndex].idClientes = idClienteAux;
    Array[freePlaceIndex].idPedido = idPedidoAux;
    Array[freePlaceIndex].kilo = kilosAux;
    Array[freePlaceIndex].pedido = estadoAux;
    Array[freePlaceIndex].isEmpty = 1;
}


/**
 * \brief Busca la primer ocurrencia de un libro mediante su codigo
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param code Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findPedidoId(Recoleccion Array[],int arrayLenght,int code)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(Array[i].idPedido == code && Array[i].isEmpty == 1)
        {
            return i;
        }
    }
    return -1;
}
