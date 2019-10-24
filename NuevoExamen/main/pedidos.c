#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#include "pedidos.h"
#include "informes.h"

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array fantasma Array of fantasma
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int inicializarPedido(Pedidos array[], int size)
{
        int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}


/** \brief Busca el primer lugar vacio en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int buscarEmptyPedido(Pedidos array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}



//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int altaPedido(Pedidos array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(buscarEmptyPedido(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if( (utn_getUnsignedInt("\n:Ingrese ID de cliente: ","\nError",1,sizeof(int),1,size,2,&array[posicion].idClientes) == 0))
            {


            (*contadorID)++;
            array[posicion].idPedido = *contadorID;
            array[posicion].isEmpty = 0;
            array[posicion].pedido = PENDIENTE;
            utn_getFloat("\n:Ingrese cantidad de kilos totales: ","\nError",1,sizeof(float),1,10000,2,&array[posicion].kilo);


            printf("\n ID Cliente: %d\nID Pedido: %d\nEstado del Pedido: %d\nCant Kilos Totales: %.2f "
                   , array[posicion].idClientes,array[posicion].idPedido,array[posicion].pedido,array[posicion].kilo);
            }

            else
            {
                printf("\n ID INCORRECTO \n");

            }
            retorno=0;
        }
    }
    return retorno;
}


//Listar
/** \brief Lista los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int listarPedido(Pedidos array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n---------------------------- \nID Cliente: %d\nID Pedido: %d\nCant Kilos Totales: %.2f "
                   , array[i].idClientes,array[i].idPedido,array[i].kilo);

                   if(array[i].pedido == 0 )
                   {
                       printf("\nEl Pedido esta PENDIENTE\n");

                   }

                   else{
                    printf("\nEl Pedido esta COMPLETADO\n");
                   }
        }
        retorno=0;
    }
    return retorno;
}


int buscarIdPedido(Pedidos array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPedido == valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int ingresarPedidos(Pedidos array[], int size)
{
    int retorno=-1;
    int i;
    int id;

    if(array!=NULL && size>0)
    {
    	utn_getUnsignedInt("\nID de pedido: ","\nError",1,sizeof(int),1,size,3,&id);
    	if(buscarIdPedido(array,size,id,&i)==-1)
    	{
    		printf("No existe el ID del pedido");
    	}
    	else
    	{
    		if(array[i].pedido==0)
    		 {
    			utn_getFloat("\nCantidad de kilos de HDPE:\n ","\nError",1,sizeof(float),1,10000,1,&array[i].HDPE);
    			utn_getFloat("\nCantidad de kilos de LPDE:\n ","\nError",1,sizeof(float),1,10000,1,&array[i].LDPE);
    			utn_getFloat("\nCantidad de kilos de PP:\n ","\nError",1,sizeof(float),1,10000,1,&array[i].PP);


    			array[i].pedido=COMPLETADO;
    		    printf("\n ID: %d\tCantidad de kilos: %.2f\nCantidad de kilosHDPE: %.2f\nCantidad de kilosLDPE: %.2f\nCantidad de kilosPP: %.2f\nEstado: Completado",
						array[i].idPedido,array[i].kilo,array[i].HDPE,array[i].LDPE,array[i].PP);

    		 }

    		else
    		{
    			printf("El pedido ya fue procesado");
    		}
    	}

    }


    return retorno;
}
