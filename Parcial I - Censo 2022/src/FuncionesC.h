/*
 * Funciones.h
 *
 *  Created on: 23 may. 2022
 *      Author: Javier
 */

#include <stdio.h>
#include <stdlib.h>
#include "Estructuras.h"

#ifndef FUNCIONESC_H_
#define FUNCIONESC_H_

void mostrarUnCensista(eCensista* list,int i);
void printCensistas(eCensista* list,int len);
int verifExisCensistaLegajo(eCensista* list, int len,int legajo);

#endif /* FUNCIONESV_C_ */
