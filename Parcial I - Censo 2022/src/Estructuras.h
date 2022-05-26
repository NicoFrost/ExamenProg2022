/*
 * Estructuras.h
 *
 *  Created on: 23 may. 2022
 *      Author: Javier
 */

#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_

typedef struct {
	int idViviendas;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
} eVivienda;

typedef struct {
		int legajoCensista;
		char Nombre[25];
		int edad;
		char telefono[25];
} eCensista;







#endif /* ESTRUCTURAS_H_ */
