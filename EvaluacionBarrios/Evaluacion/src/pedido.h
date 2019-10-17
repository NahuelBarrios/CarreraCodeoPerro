#ifndef PEDIDO_H_
#define PEDIDO_H_

#define PENDIENTE 1
#define COMPLETADO 0

typedef struct
{
    int idPedido;
    int idClientes;
	int tipoPlastico;
    float kilo;
	float HDPE;
	float LDPE;
	float PP;
	int pedido; // 1 PENDIENTE && 0 COMPLETADO && -1 SIN NADA
	int isEmpty; // *Activo == (1) || *Inactivo == (0)



}Recoleccion;

void setPedidoisEmpty(Recoleccion Array[],int arrayLenght,int value);

int findPedidoId(Recoleccion Array[],int arrayLenght,int code);

void setPedidopedido(Recoleccion Array[],int arrayLenght,int value);



#endif /* PEDIDO_H_ */
