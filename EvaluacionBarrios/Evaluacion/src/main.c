/*
 ============================================================================
 Name        : Evaluacion.c
 Author      : Barrios
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "pedido.h"
#define QTY_CLIENTES 1000
#define QTY_PEDIDOS 100
#define PENDIENTE 1
#define COMPLETADO 0



int main(void)
{
	// array de clientes
	Cliente arrayClientes[QTY_CLIENTES];
	setClientesisEmpty(arrayClientes,QTY_CLIENTES,0);


	// array pedidos
	Recoleccion arrayPedido[QTY_PEDIDOS];
	setPedidoisEmpty(arrayPedido,QTY_PEDIDOS,0);
	setPedidopedido(arrayPedido,QTY_PEDIDOS,-1);


	//---------- Auxiliares Clientes ----------

    int idAux;
	char nombreAux[51];
	int cuitAux;
	char direccionAux[51];
	int numeroDireccionAux;
	char localidadAux[51];

	//---------- Auxiliares Pedidos----------

	float kgAux;
	int idPedidoAux;
	float HDPEAux = 0;
	float LDPEAux = 0;
	float PPAux = 0;


	int i;
	int freePlaceIndex;
    int foundIndex;
    int opcion = 0;


    //--------------------------------------------------

    	// altas hardcodeo
    setCliente(arrayClientes,1,1,2344,"COCACOLA","ALBERTI",777,"CONSTITUCION");
    setCliente(arrayClientes,2,2,3454,"PEPSI","DORREGO",3454,"TEMPERLEY");
    setCliente(arrayClientes,3,3,5654,"MANAOS","PALUMBO",234,"SOLANO");
    setCliente(arrayClientes,4,4,5654,"VILLAVICENCIO","ARIAS",988,"GLEW");




  while(opcion != 9)
    {

         printf("\n------------  ABM CLIENTES ------------");
         opcion = getInt("\n\n\n1 - ALTA CLIENTE \n2 - MODIFICAR DATOS CLIENTE\n3 - BAJAR CLIENTE\n4 - CREAR PEDIDO DE RECOLECCION\n5 - PROCESAR RESIDUOS\n6 - IMPRIMIR CLIENTES\n7 - IMPRIMIR PEDIDOS PENDIENTES\n8 - IMPRIMIR PEDIDOS PROCESADOS\n9 - SALIR\n\n\n");
         switch(opcion)
         {
            case 1: // ALTA DE CLIENTE

                freePlaceIndex = findLugarVacioCliente(arrayClientes,QTY_CLIENTES);
                if(freePlaceIndex == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                idAux = getValidInt("Ingrese el id del cliente: ","El id del cliente debe ser numerico\n", 1, QTY_CLIENTES);
                if(findClienteId(arrayClientes,QTY_CLIENTES,idAux) != -1)
                {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                cuitAux =  getValidInt("Ingrese el cuit : ","El cuit debe ser numerico\n", 1, 10000);

                getValidString("Ingrese el nombre de la empresa: ","El nombre debe estar compuesto solo por letras\n", nombreAux);

                getValidString("Ingrese la direccion: ","La direccion debe estar compuesto solo por letras\n", direccionAux);

                numeroDireccionAux = getValidInt("Ingrese el numero de calle: ","El numero de calle debe ser numerica\n", 1, 10000);

                getValidString("Ingrese la localidad: ","La localidad debe estar compuesto solo por letras\n", localidadAux);

                setCliente(arrayClientes,freePlaceIndex,idAux,cuitAux,nombreAux,direccionAux,numeroDireccionAux,localidadAux);

                break;


                   case 2: // BAJA DE CLIENTE

                idAux = getValidInt("Ingrese el id a dar de baja: ","El id debe ser numerico\n", 1, QTY_CLIENTES);
                foundIndex = findClienteId(arrayClientes,QTY_CLIENTES,idAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                arrayClientes[foundIndex].id = 0;
                break;

                 case 3: // MODIFICAR CLIENTE

                idAux = getValidInt("Ingrese el id a modificar: ","El id debe ser numerico\n", 1, QTY_CLIENTES);
                foundIndex = findClienteId(arrayClientes,QTY_CLIENTES,idAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                getValidString("Ingrese la direccion: ","La direccion debe estar compuesto solo por letras\n", direccionAux);

                numeroDireccionAux = getValidInt("Ingrese la direccion: ","La direccion debe ser numerica\n", 1, 10000);

                getValidString("Ingrese la localidad: ","la localidad debe estar compuesto solo por letras\n", localidadAux);

                setCliente(arrayClientes,foundIndex,idAux,cuitAux,nombreAux,direccionAux,numeroDireccionAux,localidadAux);

                break;


                 case 4: // CREAR PEDIDO DE RECOLECCION



                showClienteArray(arrayClientes,QTY_CLIENTES);


               // id existente:

                 idAux = getValidInt("\nIngrese el id para generar un pedido: ","El id debe ser numerico\n", 1, QTY_CLIENTES);
                foundIndex = findClienteId(arrayClientes,QTY_CLIENTES,idAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    break;
                }

                // kg pedido:

                idPedidoAux = getValidInt("Ingrese el id de pedido: ","EL id de pedido debe ser numerica\n", 1, QTY_PEDIDOS);

                 kgAux = getValidFloat("Ingrese kg total: ","El kg total debe ser numerico\n", 1, 1000);




                 arrayPedido[freePlaceIndex].idClientes = idAux;
                 arrayPedido[freePlaceIndex].idPedido = idPedidoAux;
                 arrayPedido[freePlaceIndex].kilo = kgAux;
                 arrayPedido[freePlaceIndex].pedido = PENDIENTE;
                 arrayPedido[freePlaceIndex].isEmpty = 1;

                 printf("PEDIDO PENDIENTE");

                 break;




                 case 5:

                    printf("\nIDCLIENTES - IDPEDIDOS - KILOS TOTAL -  PEDIDO (1=PENDIENTE...0=COMPLETO");
                    for(i=0;i < QTY_PEDIDOS; i++)
                    {
                    	if(arrayPedido[i].isEmpty != 0 && arrayPedido[i].isEmpty == PENDIENTE)
                    	{
                    		printf("\n %d  - %d - %.2f - %d",arrayPedido[i].idClientes,arrayPedido[i].idPedido,arrayPedido[i].kilo,arrayPedido[i].pedido);
                    	}
                    }


                 idPedidoAux = getValidInt("\nIngrese el id de pedido: ","EL id de pedido debe ser numerica\n", 1, QTY_PEDIDOS);
                  foundIndex = findPedidoId(arrayPedido,QTY_PEDIDOS,idPedidoAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    break;
                }

                HDPEAux = getValidFloat("Ingrese HDPE total: ","El HDPE total debe ser numerico\n", 1, 1000);
                LDPEAux = getValidFloat("Ingrese LDPE total: ","El LDPE total debe ser numerico\n", 1, 1000);
                PPAux = getValidFloat("Ingrese PP total: ","El PP total debe ser numerico\n", 1, 1000);


                arrayPedido[freePlaceIndex].pedido = COMPLETADO;
                arrayPedido[freePlaceIndex].HDPE = HDPEAux;
                arrayPedido[freePlaceIndex].LDPE = LDPEAux;
                arrayPedido[freePlaceIndex].PP = PPAux;

                    break;

                 case 6: // --- IMPRIMIR CLIENTES ---

                	   printf("\nIdCliente - CUIT - DIRECCION - LOCALIDAD - NOMBRE - PEDIDO(PENDIENTE = 1. COMPLETADO = 0)\n");

                	                      for(i=0;i<QTY_CLIENTES;i++)
                	                      {
                	                          if(arrayClientes[i].isEmpty == 1 && arrayPedido[i].pedido == PENDIENTE)
                	                          {

                	                              printf("%d - %d - %s - %s - %s - %d\n",arrayClientes[i].id,arrayClientes[i].cuit,arrayClientes[i].direccion,arrayClientes[i].localidad,arrayClientes[i].nombre,arrayPedido[i].pedido);

                	                          }


                	                      }

                	                    break;

                 case 7:


                     printf("\nIdCliente - CUIT - DIRECCION - CANTIDAD KG - PEDIDO(PENDIENTE = 1. COMPLETADO = 0)\n");

                     for(i=0;i<QTY_CLIENTES;i++)
                     {
                         if(arrayClientes[i].isEmpty == 1 && arrayPedido[i].pedido == PENDIENTE)
                         {

                             printf("%d - %d - %s - %.2f - %d\n",arrayClientes[i].id,arrayClientes[i].cuit,arrayClientes[i].direccion,arrayPedido[i].kilo,arrayPedido[i].pedido);

                         }


                     }
                     break;




}
    }
}
