#define PENDIENTE 1
#define COMPLETADO 0

typedef struct
{
    int idPedido;
    int idClientes;
    float kilo;
	float HDPE;
	float LDPE;
	float PP;
	int pedido; // 1 PENDIENTE && 0 COMPLETADO && -1 SIN NADA
	int isEmpty; // *Activo == (1) || *Inactivo == (0)



}Pedidos;

int inicializarPedido(Pedidos array[], int size);

int buscarEmptyPedido(Pedidos array[], int size, int* posicion);

int altaPedido(Pedidos array[], int size, int* contadorID);

int listarPedido(Pedidos array[], int size);

int buscarIdPedido(Pedidos array[], int size, int valorBuscado, int* posicion);

int ingresarPedidos(Pedidos array[], int size);
