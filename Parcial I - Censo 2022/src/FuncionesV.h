/*
 * Funciones.h
 *
 *  Created on: 23 may. 2022
 *      Author: Javier
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras.h"

#ifndef FUNCIONESV_H_
#define FUNCIONESV_H_

void CambioBurbuja(eVivienda* list,int i,int j);
int initVivienda(eVivienda* list, int len);
void verifRemovedAll(int* flag,int len ,eVivienda* viviendas);
void ClearViv(eVivienda* vivienda);
int findFreeSpace(eVivienda* list,int cantidad);
void MostrarUnaVivienda(eVivienda* list,int i);
void setCalle(char calle[]);
void setTipoVivienda(eVivienda* vivienda);
int setVivData(eVivienda* vivienda,eCensista* list);
int modVivienda(eVivienda* vivienda);
int addVivienda(eVivienda* list, int len, int id, char calle[],int cantidadPersona,int cantidadHabitaciones,int tipoVivienda,int legajo);
int findViviendaByLegajo(eVivienda* list, int len,int id);
int	sortViviendasByCalle(eVivienda* list, int len);
int printVivienda(eVivienda* list, int length);
int removeVivienda(eVivienda* list, int len, int i);
void modVivData(int sid,eVivienda vivienda,eVivienda* list,int len);

#endif /* FUNCIONESV_H_ */
