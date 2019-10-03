
#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>


int Calculadora ()
{
    int opcion;
    float numero1 = 0;
    float numero2 = 0;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    int facorial1;
    int factorial2;


    do
    {
        printf("Bienvenidos a la calculadora de Nahuel Barrios abajo se le mostrara el menu. \n");
        printf("1. Ingrese el 1er operando:\n");
        printf("2. Ingrese el 2do operando:\n");
        printf("3. Calcular todas las operaciones:\n");
        printf("4. Mostrar los resultados: \n");
        printf("5. Salir\n");
        printf("El primer operando es: %.2f\n",numero1);
        printf("El segundo operando es: %.2f\n",numero2);
        printf("Seleccione una opcion:");
        scanf("%d",&opcion);

        switch(opcion)
    {
    case 1:
        printf("Ingrese el primer numero:\n");
       scanf("%f",&numero1);
        break;

    case 2:
       printf("Ingrese el segundo numero:\n");
       scanf("%f",&numero2);
        break;

    case 3:

    suma = Sumar(numero1, numero2);

    resta = Restar(numero1, numero2);

    if(numero2 != 0)
    {
    	division = Dividir(numero1, numero2);


    }

    multiplicacion = Multiplicar(numero1, numero2);

    facorial1 = FactorialA(numero1);

    factorial2 = FactorialB(numero2);

    break;

    case 4:
        printf("El resultado de la suma es: %.2f\n",suma);

        printf("El resultado de la resta es: %.2f\n",resta);

        if(numero2 != 0)
        {
        	printf("El resultado de la division es: %.2f\n",division);

        }

        else {

        	printf("No se puede dividir por 0\n");
        }

        printf("El resultado de la multiplicacion es: %.2f\n",multiplicacion);

        printf("El resultado del 1er factorial es: %d\n",facorial1);

        printf("El resultado del 2do factorial es: %d\n",factorial2);

        break;

        case 5:
        Salir();
        break;


    }

        }  while(opcion != 5);



return 0;
}

float Sumar (float numero1, float numero2)
{
    float resultado;

    resultado = numero1 + numero2;

    return resultado;


}


float Restar (float numero1,float numero2)
{
    float resultado;

    resultado = numero1 - numero2;

    return resultado;


}

float Dividir (float numero1,float numero2)
{
    float resultado;


    	  resultado = numero1 / numero2;


    return resultado;


}


float Multiplicar (float numero1, float numero2)
{
    float resultado;

    resultado = numero1 * numero2;

    return resultado;


}


int FactorialA (int numero1)
{
    int factorial = 1;
    int i;

    for(i = 1; i <= numero1;i++)
    {
        factorial = factorial * i;
    }

    return factorial;
}

int FactorialB (int numero2)
{
    int factorial = 1;
    int i;

    for(i = 1; i <= numero2;i++)
    {
        factorial = factorial * i;
    }

    return factorial;
}

char Salir ()
{
    printf("Gracias, vuelva pronto\n");

    return 0;

}



