#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#include "pedidos.h"
#include "informes.h"
#define QTY_CLIENTES 6
#define QTY_PEDIDOS 9


//Listar
/** \brief Lista los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/

int imprimirClientes(Clientes array[], int size, Pedidos arrayTwo[], int sizeTwo)
{
	int i, j;
	int contPend = 0;
	int retorno = -1;

	if(array != NULL && size>0 && arrayTwo != NULL && sizeTwo >0)
	{
		for(i = 0 ;i < size; i++)
		{
			if(array[i].isEmpty == 1)
			{
				continue;
			}
			else
			{
				for(j = 0;j < sizeTwo;j++)
				{
					if(array[i].id == arrayTwo[j].idClientes && arrayTwo[j].isEmpty==0 && arrayTwo[j].pedido==1) // Pendiente
					{
						contPend++;
					}
				}
				arrayTwo[i].idClientes = array[i].id;

				printf("\n-------------------------------------------\nID: %d\nNOMBRE EMPRESA: %s\nCUIT: %s\nDIRECCION: %s\nLOCADIDAD: %s\nESTADO: PENDIENTE = 1. COMPLETADO = 0: %d\n",
         array[i].id,array[i].nombre,array[i].cuit,array[i].direccion,array[i].localidad,contPend);

				contPend = 0;

			}
		}
		retorno = 0;
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

int imprimirPedidosPendientes(Clientes array[], int size, Pedidos arrayTwo[], int sizeTwo)
{
    int retorno=-1;
    int j,i;

    if(arrayTwo!=NULL && sizeTwo>0)
    {

		for(i=0;i<sizeTwo;i++)
    	    {
    			if(arrayTwo[i].isEmpty==0 && arrayTwo[i].pedido == 0)
    	          {
    				for(j=0;j<size;j++)
    				{
    					if(arrayTwo[i].idClientes == array[j].id && array[j].isEmpty == 0)
    					{
    						printf( "\n -------------------------------\nID: %d\nCuit: %s\nDireccion: %s\n Kilos a recolecctar: %.2f\n Estado: %d",
									arrayTwo[i].idPedido,array[j].cuit,array[j].direccion,arrayTwo[i].kilo, arrayTwo[i].pedido);

    					}
    				}
    	          }
    	    }
    	retorno=0;
    }
    return retorno;
}



int imprimirPedidosProcesados(Clientes array[], int size, Pedidos arrayTwo[], int sizeTwo)
{
	int retorno=-1;
	int j;
	int i;

	    if(arrayTwo!=NULL && sizeTwo>0)
	    {

	    	for(i=0;i<sizeTwo;i++)
	    	    {
	    			if(arrayTwo[i].isEmpty==0 && arrayTwo[i].pedido == 1)
	    	          {
	    				for(j=0;j<size;j++)
	    				{
	    					if(array[i].id == array[j].id && array[j].isEmpty == 0)
	    					{
	    						printf( "\n--------------------- \nID: %d \n Cuit: %s\n Direccion: %s\n Kilos de HDPE: %.2f\n Kilos de LDPE: %.2f\nKilos de PP: %.2f\nEstado: Completado",arrayTwo[i].idPedido,array[j].cuit,array[j].direccion,arrayTwo[i].HDPE,arrayTwo[i].LDPE,arrayTwo[i].PP);

	    					}
	    				}
	    	          }
	    	    }
	    	retorno=0;
	    }
	    return retorno;
}


//-----------------------------------------------------------------------------------------------------


int clienteConMasPedidosPendientes(Clientes array[], int size, Pedidos arrayTwo[], int sizeTwo)
{


	int retorno=-1;
	int pedPendientes = 0;
	int pedPendMaximo = 0;
	int j;
	int i;
	int posicionPendienteMaximo;
	int Aux = 0;

	    if(array!=NULL && size>0)
	    {
	    	for(i=0;i<size;i++)
	    	    {
	    			if(array[i].isEmpty==1)
	    	          {
	    	            continue;
	    	          }
	                else if(array[i].isEmpty==0 && array[i].id > 0)
	    	            {
	    	            	for(j=0;j<sizeTwo;j++)
	    	            	{
	    	            		if(array[i].id == arrayTwo[j].idClientes && arrayTwo[j].isEmpty==0 && arrayTwo[j].pedido==1)
	    	            		{
	    	            			pedPendientes++;
	    	            		}
	    	            	}

	    	            	if(Aux==0)
	    	            	{
	    	            		pedPendMaximo = pedPendientes;
	    	            		posicionPendienteMaximo = i;
	    	            		Aux++;
	    	            	}

	    	            	if(pedPendientes>pedPendMaximo)
	    	            	{
	    	            		pedPendMaximo = pedPendientes;
	    	            		posicionPendienteMaximo = i;
	    	            	}

	    	            	pedPendientes=0;

	    	            }

	    	        }

	    	printf("\n------------------------------\nCLIENTE CON MAS PEDIDOS PENDIENTES: %s\nCANTIDAD DE PEDIDOS PENDIENTES: %d",array[posicionPendienteMaximo].nombre,pedPendMaximo);
	        retorno=0;
	    }
	    return retorno;
}



int clienteMasPedidosCompletos(Clientes array[], int size, Pedidos arrayTwo[], int sizeTwo)
{
	int retorno=-1;
	int pedidosCompletados = 0;
	int pedidosCompletMax = 0;
	int i,j;
	int posCompletMax;
	int flag = 0;

	    if(array!=NULL && size>0)
	    {
	    	for(i=0;i<size;i++)
	    	    {
	    			if(array[i].isEmpty==1)
	    	          {
	    	            continue;
	    	          }
	                else if(array[i].isEmpty==0 && array[i].id >= 0)
	    	            {
	    	            	for(j=0;j<sizeTwo;j++)
	    	            	{
	    	            		if(array[i].id == arrayTwo[j].idClientes && arrayTwo[j].isEmpty==0 && arrayTwo[j].pedido==0)
	    	            		{
	    	            			pedidosCompletados++;
	    	            		}
	    	            	}

	    	            	if(flag==0)
	    	            	{
	    	            		pedidosCompletMax = pedidosCompletados;
	    	            		posCompletMax = i;
	    	            		flag++;
	    	            	}

	    	            	if(pedidosCompletados>pedidosCompletMax)
	    	            	{
	    	            		pedidosCompletMax = pedidosCompletados;
	    	            		posCompletMax = i;
	    	            	}

	    	            	pedidosCompletados=0;

	    	            }

	    	        }

	    	printf("\n---------------------------\nCLIENTE CON MAS PEDIDOS COMPLETOS: %s\nCANTIDAD DE PEDIDOS COMPLETOS: %d",array[posCompletMax].nombre,pedidosCompletMax);

	        retorno=0;
	    }
	    return retorno;
}



int clienteConMasPedidosRealizados(Clientes array[],int size,Pedidos arrayTwo[] ,int sizeTwo)
{
    int retorno=-1;
    int pedidos = 0;
    int pedidosMax = 0;
    int j;
    int i;
    int posMax;
    int flag = 0;

    if(array!=NULL && size>0)
    {
    	for(i=0;i<size;i++)
    	    {
    			if(array[i].isEmpty==1)
    	          {
    	            continue;
    	          }
                else if(array[i].isEmpty==0 && array[i].id > 0)
    	            {
    	            	for(j=0;j<sizeTwo;j++)
    	            	{
    	            		if(array[i].id == arrayTwo[j].idClientes && arrayTwo[j].isEmpty == 0 && (arrayTwo[j].pedido == 1 || arrayTwo[j].pedido == 0))
    	            		{
    	            			pedidos++;
    	            		}
    	            	}

    	            	if(flag==0)
    	            	{
    	            		pedidosMax = pedidos;
    	            		posMax = i;
    	            		flag++;
    	            	}

    	            	if(pedidos>pedidosMax)
    	            	{
    	            		pedidosMax = pedidos;
    	            		posMax = i;
    	            	}

    	            	pedidos=0;

    	            }

    	        }

    	printf("\n------------------------------------\nCLIENTE CON MAS PEDIDO REALIZADO: %s\nCANTIDAD DE PEDIDOS: %d",array[posMax].nombre,pedidosMax);

        retorno=0;
    }
    return retorno;
}


int clientesConMasDeMilKg(Clientes array[], int size, Pedidos arrayTwo[], int sizeTwo)
{
    int retorno=-1;
    int kilosRecic = 0;
    int cantCliente = 0;
    int j,i;

    if(array!=NULL && size>0)
    {
    	for(i=0;i<size;i++)
    	    {
    			if(array[i].isEmpty==1)
    	          {
    	            continue;
    	          }
                else if(array[i].isEmpty==0 && array[i].id >= 0)
    	            {
    	            	for(j=0;j<sizeTwo;j++)
    	            	{
    	            		if(array[i].id == arrayTwo[j].idClientes && arrayTwo[j].isEmpty == 0 && arrayTwo[j].pedido == 0)//Completado
    	            		{
    	            			kilosRecic=0;
    	            			kilosRecic = kilosRecic + arrayTwo[j].HDPE + arrayTwo[j].LDPE + arrayTwo[j].PP;
    	            		}
    	            	}

    	            	if(kilosRecic>1000)
    	            	{
    	            		cantCliente++;
    	            	}

    	            }

    	        }

    	printf("\n----------------------------------------\nCANTIDAD DE CLIENTES QUE RECICLARON MAS DE 1000 KG: %d",cantCliente);
        retorno=0;
    }
    return retorno;
}





int porcentajePedidosCompletados(Clientes array[], int size, Pedidos arrayTwo[], int sizeTwo)
{
    int retorno=-1;
    int j;
    int i;
    float porcentaje;
    int acumulador;

    if(arrayTwo!=NULL && sizeTwo>0)
    {
    	for(i=0;i<sizeTwo;i++)
    	    {
    			if(arrayTwo[i].isEmpty==0 && arrayTwo[i].pedido == 0)
    	          {
    				for(j=0;j<size;j++)
    				{
    					if(arrayTwo[i].idClientes == array[j].id && array[j].isEmpty == 0 && array[j].id >= 0)
    					{

    						acumulador = 0;
    						porcentaje = 0;

							acumulador = arrayTwo[i].HDPE + arrayTwo[i].LDPE + arrayTwo[i].PP;
							porcentaje = acumulador / arrayTwo[i].kilo;
							porcentaje = porcentaje * 100;

							printf("\n------------------------------------------\nID PEDIDO: %d\nCUIT: %s\n PORCENTAJE DE RESIDUOS RECICLADOS: %.2f",arrayTwo[i].idPedido,array[j].cuit,porcentaje);

    					}
    				}
    	          }


    	    }
    	        retorno=0;
    }
    return retorno;
}
