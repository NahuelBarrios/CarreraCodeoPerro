/*
 * controller.c
 *
 *  Created on: 16 oct. 2019
 *      Author: sergio
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "pedidos.h"
#include "utn.h"


int listarClientesPendiente(eClientes list[], int len, ePedidos list2[], int len2)
{
	int i;
	int auxPos;
	int contadorPendientes = 0;
	int retorno = -1;

	if(list != NULL && len>0 && list2 != NULL && len2 >0)
	{
		printf("\nID: -- Nombre de la Empresa:  -- cuit:  -- Direccion:	--	Localidad:  -- Pendientes: \n");
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				continue;
			}
			else
			{
				for(auxPos=0;auxPos<len2;auxPos++)
				{
					if(list[i].idClientes == list2[auxPos].idClientes
							&& list2[auxPos].isEmpty==0
							&& list2[auxPos].estado==PENDIENTE)
					{
						contadorPendientes++;
					}
				}
				list2[i].idClientes = list[i].idClientes;

				printf("\n\n%4d		%-20s		%-10s		%-10s		%-25s		%4d",list[i].idClientes,
																		list[i].nombreEmpresa,
																		list[i].cuit,
																		list[i].direccion,
																		list[i].localidad,
																		contadorPendientes);
				contadorPendientes = 0;

			}
		}
		retorno = 0;
	}
	return retorno;
}

int listar_pendientes(eClientes list[], int size, ePedidos list2[], int size2)
{
    int retorno=-1;
    int posicion,i;

    if(list2!=NULL && size2>0)
    {

		for(i=0;i<size2;i++)
    	    {
    			if(list2[i].isEmpty==0 && list2[i].estado == 0)
    	          {
    				for(posicion=0;posicion<size;posicion++)
    				{
    					if(list2[i].idClientes == list[posicion].idClientes
    							&& list[posicion].isEmpty == 0)
    					{
    						printf( "\n ID: %d\t Cuit: %s\tDireccion: %s\t Kilos: %.2f\t Estado: Pendiente",
									list2[i].idPedidos,
    								list[posicion].cuit,
 									list[posicion].direccion,
									list2[i].kilos);
    					}
    				}
    	          }
    	    }
    	retorno=0;
    }
    return retorno;
}

int pedido_ImprimirArrayProcesado(eClientes list[], int len, ePedidos list2[], int len2)
{
	int retorno=-1;
	int posicion;
	int i;

	    if(list2!=NULL && len2>0)
	    {
	    	__fpurge(stdin);
	    	for(i=0;i<len2;i++)
	    	    {
	    			if(list2[i].isEmpty==0 && list2[i].estado == 1)
	    	          {
	    				for(posicion=0;posicion<len;posicion++)
	    				{
	    					if(list[i].idClientes == list[posicion].idClientes
	    							&& list[posicion].isEmpty == 0)
	    					{
	    						printf( "\n ID: %d \n Cuit: %s\t Direccion: %s\t Kilos de HDPE: %.2f\t Kilos de LDPE: %.2f\tKilos de PP: %.2f\tEstado: Completado",
										list2[i].idPedidos,
	    								list[posicion].cuit,
	 									list[posicion].direccion,
										list2[i].HDPE,
										list2[i].LPDE,
										list2[i].PP);

	    					}
	    				}
	    	          }
	    	    }
	    	retorno=0;
	    }
	    return retorno;
}


int clienteMasPendientes(eClientes list[], int len, ePedidos list2[], int len2)
{
	int retorno=-1;
	int pedidosPend = 0;
	int pedidosPendMax = 0;
	int posicion;
	int i;
	int posPendMax;
	int flag = 0;

	    if(list!=NULL && len>0)
	    {
	    	for(i=0;i<len;i++)
	    	    {
	    			if(list[i].isEmpty==1)
	    	          {
	    	            continue;
	    	          }
	                else if(list[i].isEmpty==0 && list[i].idClientes > 0)
	    	            {
	    	            	for(posicion=0;posicion<len2;posicion++)
	    	            	{
	    	            		if(list[i].idClientes == list2[posicion].idClientes
	    	            			&& list2[posicion].isEmpty==0
									&& list2[posicion].estado==0)
	    	            		{
	    	            			pedidosPend++;
	    	            		}
	    	            	}

	    	            	if(flag==0)
	    	            	{
	    	            		pedidosPendMax = pedidosPend;
	    	            		posPendMax = i;
	    	            		flag++;
	    	            	}

	    	            	if(pedidosPend>pedidosPendMax)
	    	            	{
	    	            		pedidosPendMax = pedidosPend;
	    	            		posPendMax = i;
	    	            	}

	    	            	pedidosPend=0;

	    	            }

	    	        }

	    	printf("\nCliente con mas pedidos pendientes: %s"
	    			"\nCantide de pedidos pendientes: %d",
	    			list[posPendMax].nombreEmpresa,
					pedidosPendMax);
	        retorno=0;
	    }
	    return retorno;
}

int clienteMasPedidosCompletos(eClientes list[], int len, ePedidos list2[], int len2)
{
	int retorno=-1;
	int pedidosCompletados = 0;
	int pedidosCompletMax = 0;
	int posicion;
	int i;
	int posCompletMax;
	int flag = 0;

	    if(list!=NULL && len>0)
	    {
	    	for(i=0;i<len;i++)
	    	    {
	    			if(list[i].isEmpty==1)
	    	          {
	    	            continue;
	    	          }
	                else if(list[i].isEmpty==0 && list[i].idClientes > 0)
	    	            {
	    	            	for(posicion=0;posicion<len2;posicion++)
	    	            	{
	    	            		if(list[i].idClientes == list2[posicion].idClientes
	    	            			&& list2[posicion].isEmpty==0
									&& list2[posicion].estado==1)
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

	    	printf("\nCliente con mas pedidos pendientes: %s"
	    			"\nCantide de pedidos pendientes: %d",
	    			list[posCompletMax].nombreEmpresa,
					pedidosCompletMax);
	        retorno=0;
	    }
	    return retorno;
}

int clienteMasPedidos(eClientes list[],ePedidos list2[], int len, int len2)
{
    int retorno=-1;
    int pedidos = 0;
    int pedidosMax = 0;
    int posicion;
    int i;
    int posMax;
    int flag = 0;

    if(list!=NULL && len>0)
    {
    	for(i=0;i<len;i++)
    	    {
    			if(list[i].isEmpty==1)
    	          {
    	            continue;
    	          }
                else if(list[i].isEmpty==0 && list[i].idClientes > 0)
    	            {
    	            	for(posicion=0;posicion<len2;posicion++)
    	            	{
    	            		if(list[i].idClientes == list2[posicion].idClientes
    	            			&& list2[posicion].isEmpty==0
								&& (list2[posicion].estado==1 || list2[posicion].estado==0))
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

    	printf("\nCliente con mas pedidos: %s"
    			"\nCantide de pedidos: %d",
    			list[posMax].nombreEmpresa,
				pedidosMax);
        retorno=0;
    }
    return retorno;
}

int clienteMasReciclo(eClientes list[], int len, ePedidos list2[], int len2)
{
    int retorno=-1;
    int kilosRecic = 0;
    int kilosRecicMax = 0;
    int posicion;
    int i;
    int posMax;
    int flag = 0;

    if(list!=NULL && len>0)
    {
    	for(i=0;i<len;i++)
    	    {
    			if(list[i].isEmpty==1)
    	          {
    	            continue;
    	          }
                else if(list[i].isEmpty==0 && list[i].idClientes > 0)
    	            {
    	            	for(posicion=0;posicion<len2;posicion++)
    	            	{
    	            		if(list[i].idClientes == list2[posicion].idClientes
    	            			&& list2[posicion].isEmpty==0
								&& list2[posicion].estado==1)
    	            		{
    	            			kilosRecic=0;
    	            			kilosRecic = kilosRecic + list2[posicion].HDPE
    	            									+ list2[posicion].LPDE
														+ list2[posicion].PP;
    	            		}
    	            	}

    	            	if(flag==0)
    	            	{
    	            		kilosRecicMax = kilosRecic;
    	            		posMax = i;
    	            		flag++;
    	            	}

    	            	if(kilosRecic>kilosRecicMax)
    	            	{
    	            		kilosRecicMax = kilosRecic;
    	            		posMax = i;
    	            	}

    	            }

    	        }

    	printf("\nCliente que mas reciclo: %s"
    			"\nCantidad de kilos: %d",
    			list[posMax].nombreEmpresa,
				kilosRecicMax);
        retorno=0;
    }
    return retorno;
}

int clienteMenosReciclo(eClientes list[], int len, ePedidos list2[], int len2)
{
    int retorno=-1;
    int kilosRecic = 0;
    int kilosRecicMin = 0;
    int posicion;
    int i;
    int posMin;
    int flag = 0;

    if(list!=NULL && len>0)
    {
    	for(i=0;i<len;i++)
    	    {
    			if(list[i].isEmpty==1)
    	          {
    	            continue;
    	          }
                else if(list[i].isEmpty==0 && list[i].idClientes > 0)
    	            {
    	            	for(posicion=0;posicion<len2;posicion++)
    	            	{
    	            		if(list[i].idClientes == list2[posicion].idClientes
    	            			&& list2[posicion].isEmpty==0
								&& list2[posicion].estado==1)
    	            		{
    	            			kilosRecic = 0;
    	            			kilosRecic = kilosRecic + list2[posicion].HDPE
    	            									+ list2[posicion].LPDE
														+ list2[posicion].PP;
    	            		}
    	            	}

    	            	if(flag==0)
    	            	{
    	            		kilosRecicMin = kilosRecic;
    	            		posMin = i;
    	            		flag++;
    	            	}

    	            	if(kilosRecic<kilosRecicMin)
    	            	{
    	            		kilosRecicMin = kilosRecic;
    	            		posMin = i;
    	            	}


    	            }

    	        }

    	printf("\nCliente que menos reciclo: %s"
    			"\nCantidad de kilos: %d",
    			list[posMin].nombreEmpresa,
				kilosRecicMin);
        retorno=0;
    }
    return retorno;
}

int clientesConMasDeMilKg(eClientes list[], int len, ePedidos list2[], int len2)
{
    int retorno=-1;
    int kilosRecic = 0;
    int cantCliente = 0;
    int posicion,i;

    if(list!=NULL && len>0)
    {
    	for(i=0;i<len;i++)
    	    {
    			if(list[i].isEmpty==1)
    	          {
    	            continue;
    	          }
                else if(list[i].isEmpty==0 && list[i].idClientes > 0)
    	            {
    	            	for(posicion=0;posicion<len2;posicion++)
    	            	{
    	            		if(list[i].idClientes == list2[posicion].idClientes
    	            			&& list2[posicion].isEmpty==0
								&& list2[posicion].estado==1)
    	            		{
    	            			kilosRecic=0;
    	            			kilosRecic = kilosRecic + list2[posicion].HDPE
    	            									+ list2[posicion].LPDE
														+ list2[posicion].PP;
    	            		}
    	            	}

    	            	if(kilosRecic>1000)
    	            	{
    	            		cantCliente++;
    	            	}

    	            }

    	        }

    	printf("\nCantidad de clientes que reciclaron mas de 1000: %d",cantCliente);
        retorno=0;
    }
    return retorno;
}


int clientesConMenosDeCienKg(eClientes list[], int len, ePedidos list2[], int len2)
{
    int retorno=-1;
    int kilosRecic=0;
    int cantCliente = 0;
    int posicion;
    int i;

    if(list!=NULL && len>0)
    {
    	for(i=0;i<len;i++)
    	    {
    			if(list[i].isEmpty==1)
    	          {
    	            continue;
    	          }
                else if(list[i].isEmpty==0 && list[i].idClientes > 0)
    	            {
    	            	for(posicion=0;posicion<len2;posicion++)
    	            	{
    	            		if(list[i].idClientes == list2[posicion].idClientes
    	            			&& list2[posicion].isEmpty==0
								&& list2[posicion].estado==1)
    	            		{
    	            			kilosRecic = 0;
    	            			kilosRecic = kilosRecic + list2[posicion].HDPE
    	            									+ list2[posicion].LPDE
														+ list2[posicion].PP;
    	            		}
    	            	}

    	            	if(kilosRecic<100 && list2[posicion].idClientes>0)
    	            	{
    	            		cantCliente++;
    	            		kilosRecic=100;
    	            	}

    	            }

    	        }

    	printf("\nCantidad de clientes que reciclaron menos de 100: %d",cantCliente);
        retorno=0;
    }
    return retorno;
}

