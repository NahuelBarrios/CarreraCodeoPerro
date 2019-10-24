typedef struct
{
	int id;
	char nombre[51];
	char cuit[51];
	char localidad[51];
	char direccion[51];
	int isEmpty; // *Activo == (1) || *Inactivo == (0)

}Clientes;


int inicializarCliente(Clientes array[], int size);

int buscarEmptyCliente(Clientes array[], int size, int* posicion);

int altaCliente(Clientes array[], int size, int* contadorID);

int buscarIdCliente(Clientes array[], int size, int valorBuscado, int* posicion);

int modificarCliente(Clientes array[], int sizeArray);

int listarClientes(Clientes array[], int size);

int bajaCliente(Clientes array[], int sizeArray);
