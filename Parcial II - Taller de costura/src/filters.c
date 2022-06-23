/*
 * filters.c
 *
 *  Created on: 23 jun. 2022
 *      Author: Nicolas
 */
#include "filters.h"
#include "Service.h"

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
