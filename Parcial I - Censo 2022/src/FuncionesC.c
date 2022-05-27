/*
 * FuncionesV.c
 *
 *  Created on: 23 may. 2022
 *      Author: Javier
 */


#include "FuncionesC.h"
#include "FuncionesV.h"
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
/*
 * 100-Ana 34 años tel:1203-2345
	idVivienda calle habitantes habitaciones tipo vivienda
	20000 Salta 23 4 2 CASA
	20001 Salta 27 2 1 DEPARTAMENTO
 */
	printf("-------------------------------------------------\n");
	printf("|                   CENSISTAS                   |\n");
	printf("|-----------------------------------------------|\n");
	printf("| LEGAJO | NOMBRE\t| EDAD\t|   TELEFONO\t|\n");
	for(int i = 0;i < len;i++){
		mostrarUnCensista(list, i);
	}
	printf("-------------------------------------------------\n");
}


// lo haria modificando la estructura y agregando un nuevo valor que diga cuantas viviendas tiene cada uno

void mostrarInforme(eCensista* listC,int lenC,eVivienda* listV,int lenV){

	int contadorViviendas;

	for(int i = 0;i < lenC;i++){
		printf("%d-%s %d años tel:%s\n",listC[i].legajoCensista,listC[i].Nombre,listC[i].edad,listC[i].telefono);
		printf("---------------------------------------------------------------------------------------------------------------------------------\n");
		printf("|  ID\t|\t   CALLE   \t|    CANT PERSONAS\t|    CANT HABITACIONES\t|    TIPO VIVIENDA\t|     LEGAJO CENSISTA\t|\n");
		for(int j = 0;j < lenV;j++){
			if(listV[j].legajoCensista == listC[i].legajoCensista){
				contadorViviendas++;
				MostrarUnaVivienda(listV, j);
			}
		}
		printf("---------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n");
	}
}

