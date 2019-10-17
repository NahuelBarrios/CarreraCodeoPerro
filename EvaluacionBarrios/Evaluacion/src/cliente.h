
#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
	int id;
	char nombre[51];
	int cuit;
	char direccion[51];
	int numeroDireccion;
	char localidad[51];
	int isEmpty; // *Activo == (1) || *Inactivo == (0)

}Cliente;

void setClientesisEmpty(Cliente Array[],int arrayLenght,int value);

int findClienteId(Cliente Array[],int arrayLenght,int code);

int findLugarVacioCliente(Cliente Array[],int arrayLenght);

void setCliente(Cliente Array[],int freePlaceIndex, int idAux,int cuitAux,char nombreAux[],char direccionAux[], int numeroCalleAux,char localidad[]);

void showClienteArray(Cliente Array[],int arrayLenght);


#endif /* CLIENTE_H_ */
