/*
 * Practica.h
 *
 *  Created on: 19 sep. 2019
 *      Author: alumno
 */

#ifndef GETS_H_
#define GETS_H_

int ObtenerResultado(char msj[]);

int getInt(char msj[]);

void getString(char mensaje[],char input[]);

int esNumerico (char str[]);

int esSoloLetras(char str[]);

void getString(char msj[], char input[]);

int getStringLetras(char msj[],char input[]);

int getStringNumeros(char msj[],int *input);


#endif /* GETS_H_ */
