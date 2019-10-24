#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#include "pedidos.h"
#include "informes.h"
#define QTY_CLIENTES 6
#define QTY_PEDIDOS 9


int main()
{

    // --- ARRAY CLIENTES ---
    Clientes arrayClientes [QTY_CLIENTES] = {{1,"Telefonica","30112233445","CABA","Lima 1234"},
                                            {2,"DATASOFT","30445566776","CABA ","Corrientes 2547"},
                                            {3,"NESTLE","30889955219","LANUS","cucha cucha 555"},
                                            {4,"TERRABUSI","30567814235","QUILMES","rocha 784"},
                                            {5,"DIA","31545812533","AVELLANEDA","Mitre 750"},
                                            {6,"QUILMES","30514857596","QUILMES","rocha 741"}
                                            };


    // ARRAY CLIENTE INICIALIZADO
    //inicializarCliente(arrayClientes,QTY_CLIENTES);
    // --- ARRAY PEDIDOS ---
    Pedidos arrayPedidos[QTY_PEDIDOS] = {{1,1,1000,200,145,230,0,},
                                        {2,1,800,210,45,30,0,},
                                        {3,2,100,0,0,0,1,},
                                        {4,2,300,0,0,0,1,},
                                        {5,3,1500,500,150,270,0,},
                                        {6,4,750,100,50,70,0,},
                                        {7,1,200,0,0,0,1,},
                                        {8,5,30,10,5,3,0,},
                                        {9,6,456,0,0,0,1,}
    };
 /*
    int idPedido;
    int idClientes;
    float kilo;
	float HDPE;
	float LDPE;
	float PP;
	int pedido;
	int isEmpty;

	*/
    // ARRAY PEDIDO INICIALIZADO
    //inicializarPedido(arrayPedidos,QTY_PEDIDOS);



    int opcion = 0;

    // Auxiliares Clientes
    int contIdClientes;

    // Auxuliares Pedidos
    int contIdPedidos;


    while (opcion != 20)
    {
    utn_getUnsignedInt("\n\n\n1 - ALTA CLIENTE \n2 - MODIFICAR DATOS CLIENTE\n3 - BAJAR CLIENTE\n4 - CREAR PEDIDO DE RECOLECCION\n5 - PROCESAR RESIDUOS\n6 - IMPRIMIR CLIENTES\n7 - IMPRIMIR PEDIDOS PENDIENTES\n8 - IMPRIMIR PEDIDOS PROCESADOS\n9 - CLIENTE CON MAS PEDIDOS PENDIENTES\n10 - CLIENTE CON MAS PEDIDOS COMPLETADOS\n11 - CLIENTE CON MAS PEDIDOS REALIZADOS\n12- CLIENTE CON MAS DE 1000 KG\n13 - PROCENTAJE DE PEDIDOS COMPLETADOS\n20- SALIR\n\n\n",
                       "Error opcion no valida.",1,sizeof(int),1,8,3,&opcion);

        switch(opcion)
        {
        case 1: // --- ALTA CLIENTES---

        printf("\n ALTA CLIENTE \n");
        altaCliente(arrayClientes,QTY_CLIENTES,&contIdClientes);

        break;

        case 2: //--- MODIFICAR DATOS DEL CLIENTE ---

            printf("\n MODIFICAR LOS DATOS \n");
             modificarCliente(arrayClientes,QTY_CLIENTES);
             break;

        case 3: // --- BAJA DE CLIENTES

            printf("\n BAJA CLIENTE \n");
            bajaCliente(arrayClientes,QTY_CLIENTES);
            break;

        case 4: //--- LISTAMIENTO DE CLIENTES && CREAR PEDIDO DE RECOLECCION ---

            printf("\n CREAR PEDIDO DE RECOLECCION \n");
            listarClientes(arrayClientes,QTY_CLIENTES);
            altaPedido(arrayPedidos,QTY_PEDIDOS,&contIdPedidos);
            break;

        case 5: // --- LSITAR PEDIDOS PENDIENTES && PROCESAR RESIDUOS ---

            printf("\n PROCESAR RESIDUOS \n");
            listarPedido(arrayPedidos,QTY_PEDIDOS);
            ingresarPedidos(arrayPedidos,QTY_PEDIDOS);

            break;

        case 6: // --- IMPRIMIR CLIENTES && ESTADO CLIENTE ---

        printf("\n IMPRIMIR CLIENTES \n");
       imprimirClientes(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);

            break;

        case 7: // --- IMPRIMIR PEDIDOS PENDIENTES ---

        printf("\n IMPRIMIR PEDIDOS PENDIENTE \n");
        imprimirPedidosPendientes(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);

            break;

        case 8: // --- IMPRIMIR PEDIDOS PROCESADOS ---

            printf("\n IMPRIMIR PEDIDOS PROCESADOS \n");
            imprimirPedidosProcesados(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);

            break;

        case 9: // --- cliente con mas pedidos pendientes ---

        printf("\n CLIENTE CON MAS PEDIDOS PENDIENTES \n");
    clienteConMasPedidosPendientes(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);

            break;

        case 10: // --- cliente con mas pedidos completados ---

        printf("\n CLIENTE CON MAS PEDIDOS COMPLETADOS \n");
        clienteMasPedidosCompletos(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);

            break;

        case 11: //--- cliente con mas pedidos realizados ---
            printf("\n CLIENTE CON MAS PEDIDOS REALIZADOS \n");
            clienteConMasPedidosRealizados(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);

            break;

        case 12: // --- cliente con mas de 1000 kg ---
            printf("\n CLIENTE CON MAS DE 1000 KG \n");
            clientesConMasDeMilKg(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
            break;

        case 13: // --- porcentaje de pedidos completados ---
        printf("\n PROCENTAJE DE PEDIDOS COMPLETADOS \n");
        porcentajePedidosCompletados(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
        break;



        case 14:

            break;

        case 15:

            break;

        case 16:

            break;

        case 17:

            break;

        case 18:

            break;

        case 19:

            break;

        } // switch

    }// while


    return 0;
}// main
