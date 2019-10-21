/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "clientes.h"
#include "utn.h"
#include "pedidos.h"
#include "controller.h"

#define QTY_CLIENTES 6
#define QTY_PEDIDOS 12

int main()
{
	int contadorClientes=0;
	int contadorPedidos;
	int opcion;
	int opcionInformes;
	char menuPrincipalMensaje[] ="\n1-MENU DE OPCIONES\
            \n\n1-ALTAS CLIENTES\
            \n2-MODIFICAR DATOS DE CLIENTE\
            \n3-BAJA DE CLIENTE\
            \n4-CREAR PEDIDO DE RECOLECCION\
	 	 	\n5 PROCESAR RESIDUOS \
			\n6 IMPRIMIR CLIENTES\
			\n7 IMPRIMIR PEDIDOS CLIENTES\
			\n8 IMPRIMIR PEDIDOS PROCESADOS\
		    \n9-INFORMES\
			\n10-SALIR\n\n\
			\nIngrese opcion:";

	eClientes arrayClientes[QTY_CLIENTES] = {
			{0,"Fadeca","20358043047","buenos aires 439","Burzaco",0},
			{1,"La Zorra","20255043547","Somellera 489","Adrogue",0},
			{2,"El Rincon","20607543840","Mitre 500","Adrogue",0},
			{3,"Von Bier","30256043542","Pasco 600","Temperley",0},
			{4,"Planeta tacos","20666043547","Acasuso 764","Banfield",0},
			{5,"The Mitre","20255043547","Mitre 1236","Adrogue",0}

	};
	ePedidos arrayPedidos[QTY_PEDIDOS]={
			{0,0,500,PENDIENTE,0,0,0,0},
			{1,0,700,COMPLETADOS,300,200,200,0},
			{2,0,300,PENDIENTE,0,0,0,0},
			{3,1,800,COMPLETADOS,100,200,200,0},
			{4,2,200,COMPLETADOS,100,100,0,0},
			{5,2,500,PENDIENTE,0,0,0,0},
			{6,2,400,PENDIENTE,0,0,0,0},
			{7,2,100,PENDIENTE,0,0,0,0},
			{8,3,500,COMPLETADOS,100,200,200,0},
			{9,4,700,COMPLETADOS,100,200,200,0},
			{10,5,500,PENDIENTE,0,0,0,0},
			{11,5,600,COMPLETADOS,100,200,300,0}
	};

	/*cliente_Inicializar(arrayClientes,QTY_CLIENTES);
	pedidos_Inicializar(arrayPedidos,QTY_PEDIDOS);
	*/


	do
	{
		__fpurge(stdin);
		utn_getUnsignedInt(menuPrincipalMensaje,"\nError",1,sizeof(int),1,8,1,&opcion);



		switch(opcion)
		{
		case 1:
			printf("\n ALTAS\n");
			cliente_alta(arrayClientes,QTY_CLIENTES,&contadorClientes);
			break;
		case 2:
			printf("\nMODIFICAR\n");
			cliente_listar(arrayClientes,QTY_CLIENTES);
			cliente_modificar(arrayClientes,QTY_CLIENTES);
			break;
		case 3:
			printf("\nBAJAS\n");
			cliente_baja(arrayClientes,QTY_CLIENTES);
			break;
		case 4:
			printf("\nCREAR PEDIDO DE RECOLECCION");
			cliente_listar(arrayClientes,QTY_CLIENTES);
			pedidos_alta(arrayPedidos,QTY_PEDIDOS,&contadorPedidos);
			break;
		case 5:
			printf("PROCESAR RESIDUOS");
			pedidos_listar(arrayPedidos,QTY_PEDIDOS);
			pedidos_procesar(arrayPedidos,QTY_PEDIDOS);
			break;
		case 6:
			listarClientesPendiente(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
			break;
		case 7:
			listar_pendientes(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
			break;
		case 8:
			pedido_ImprimirArrayProcesado(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
			break;
		case 9:
			printf("\nINFORMES");
			do
				{
					utn_getUnsignedInt("\n1. Cliente con mas pedidos pendientes.\
							\n2.Cliente con mas pedidos procesados.\
							\n3.Cliente con mas pedidos\
							\n4.Cliente que mas kilos reciclo\
							\n5.Cliente que menos reciclo\
							\n6.Cantidad de clientes que reciclaron mas de 1000 kg\
							\n7.Cantidad de clientes que reciclaron menos de 100 kg\
							\n8.Pedidos completados: ID, CUIT, % de plastico reciclado\
							\n9.Cantidad de pedidos pendientes por localidad\
							\n10.Cantidad de PP reciclado promedio por cliente\
							\n11.Cantidad de kilos reciclado de cada tipo de residuo por cliente\
							\n12.Volver al menu principal\n\nSelecione una opcion: ","\nOpcion invalida",1,sizeof(int),1,12,1,&opcionInformes);

					switch(opcionInformes)
					{
					case 1:
						clienteMasPendientes(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 2:
						clienteMasPedidosCompletos(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 3:
						clienteMasPedidos(arrayClientes,arrayPedidos,QTY_CLIENTES,QTY_PEDIDOS);
						break;
					case 4:
						clienteMasReciclo(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 5:
						clienteMenosReciclo(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 6:
						 clientesConMasDeMilKg(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 7:
						clientesConMenosDeCienKg(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 8:

						break;
					case 9:

						break;
					case 10:

						break;
					case 11:

						break;
					case 12:
						break;
					default:
						printf("\n Ingrese una opcion de 1 a 12 ");
					}
				}while(opcionInformes != 12);
			break;
		case 10:
			break;
		default:
			printf("\nError. Ingresa una opcion de 1 a 9");

		}
	}while(opcion != 9);

	return 0;
}
