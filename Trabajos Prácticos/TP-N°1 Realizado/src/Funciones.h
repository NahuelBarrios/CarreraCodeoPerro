/*
 * Trabajo_practico.h
 *
 *  Created on: 31 ago. 2019
 *      Author: alumno
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>

int Calculadora ();
/*
 * "Calculadora": Es donde esta alojado casi todo el programa. Su uso es para
 * 	que el main sea mas limpio y bonito.
 */

float Sumar(float numero1,float numero2);
float Restar(float numero1, float numero2);
float Dividir(float numero1, float numero2);
float Multiplicar(float numero1, float numero2);
int FactorialA(int numero1);
int FactorialB(int numero2);
/*
 * Funciones Sumar,Restar,Dividir,Multiplicar,FactorialA,FactorialB. Su uso es
	realizar las operaciones en la funcion Calculadora.
 */

char Salir();
/*
 * Funcion Char. Su uso es para brindar el mensaje de la opcion 5 de la
 * calculadora, la salida.
 */


#endif /* FUNCIONES_H_ */
