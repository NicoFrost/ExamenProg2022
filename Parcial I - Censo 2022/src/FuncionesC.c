/*
 * FuncionesV.c
 *
 *  Created on: 23 may. 2022
 *      Author: Javier
 */


#include "FuncionesC.h"
/**
 * @brief
 *
 * @param lista de donde verificar existencia
 * @param tamaño de lista
 * @param legajo a verificar
 * @return -1 por lista NULL, tamaño menor 0, legajo menor a 0; 1 si existe
 */
int verifExisCensistaLegajo(eCensista* list, int len,int legajo){
	int resp = -1;
	int i;
	if(len > 0 && list != NULL && legajo > 0){ // errores de valores pasados por parametros
		for(i = 0;i < len;i++){
			if(list[i].legajoCensista > 0 && list[i].legajoCensista == legajo){
				resp = 1;
				break;
			}
		}
		if(i == len){
			resp = 0;
		}
	}

	return resp;
}
/**
 * @brief printea un censista unico
 *
 * @param lista de donde se saca los datos
 * @param posicion de la estructura
 */
void mostrarUnCensista(eCensista* list,int i){
	printf("|  %d   | %s   \t|  %d   |  %s\t|\n",list[i].legajoCensista,list[i].Nombre,list[i].edad,list[i].telefono);
}

/**
 * @brief printea una lista de todos los censistas
 *
 * @param lista donde se saca las estructuras
 * @param tamaño de la lista
 */
void printCensistas(eCensista* list,int len){

	printf("-------------------------------------------------\n");
	printf("|                   CENSISTAS                   |\n");
	printf("|-----------------------------------------------|\n");
	printf("| LEGAJO | NOMBRE\t| EDAD\t|   TELEFONO\t|\n");
	for(int i = 0;i < len;i++){
		mostrarUnCensista(list, i);
	}
	printf("-------------------------------------------------\n");
}

