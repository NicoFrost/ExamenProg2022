/*
 * filters.c
 *
 *  Created on: 23 jun. 2022
 *      Author: Nicolas
 */
#include "filters.h"
#include "Service.h"

/**
 * funcion filtradora por minorista
 * @param this elemento a filtrar
 * @return 1 si el filtro es verdadero
 * 		   0 si el elemento pasado es NULL o si el filtro es falso
 *
 */
int filter_porMinorista(void* this){
	int retorno = 0;
	int tipo;
	if(this != NULL){
		Servicios_getTipoServicio(this, &tipo);
		if(tipo == 1){
			retorno = 1;
		}
	}

	return retorno;
}

/**
 * funcion filtradora por mayorista
 * @param this elemento a filtrar
 * @return 1 si el filtro es verdadero
 * 		   0 si el elemento pasado es NULL o si el filtro es falso
 *
 */
int filter_porMayorista(void* this){
	int retorno = 0;
	int tipo;
	if(this != NULL){
		Servicios_getTipoServicio(this, &tipo);
		if(tipo == 2){
			retorno = 1;
		}
	}

	return retorno;
}

/**
 * funcion filtradora por exportar
 * @param this elemento a filtrar
 * @return 1 si el filtro es verdadero
 * 		   0 si el elemento pasado es NULL o si el filtro es falso
 *
 */
int filter_porExportar(void* this){
	int retorno = 0;
	int tipo;
	if(this != NULL){
		Servicios_getTipoServicio(this, &tipo);
		if(tipo == 3){
			retorno = 1;
		}
	}

	return retorno;
}
