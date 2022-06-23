/*
 ============================================================================
 Name        : Parcial.c
 Author      : nicolas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "libreriaP.h"
#include "Controller.h"
#include "LinkedList.h"

int main(void) {
	LinkedList* pLLService = ll_newLinkedList();
	setbuf(stdout,NULL);
	int option,flagLoaded = 0;
	do{
		option = MenuGeneral(0, "1.Cargar Archivo\n", "2.Imprimir lista\n", "3.Asignar totales\n", "4.Filtrar por tipo\n", "5.Mostrar servicios\n", "6.Guardar servicios\n", "", "", '7');
		switch(option) {
		case 1:
			if(flagLoaded == 1){
				ll_deleteLinkedList(pLLService);
				pLLService = ll_newLinkedList();
			}
			if(controller_loadFromText(pLLService) != -1){
				flagLoaded = 1;
			}
			break;
		case 2:
			if(flagLoaded){
				if(controller_listService(pLLService) == -1){
					printf("ERROR al listar\n");
				}
			} else {
				printf("Debe cargar un archivo valido\n");
			}
			break;
		case 3:
			if(flagLoaded){
				if(controller_assignTotal(pLLService) == -1){
					printf("ERROR al asignar totales");
				}
			} else {
				printf("Debe cargar un archivo valido\n");
			}
			break;
		case 4:
			if(flagLoaded){
				if(controller_createDataFiltred("dataFiltred.csv",pLLService) == -1){
					printf("ERROR, al crear Datos filtrados\n");
				}
			} else {
				printf("Debe cargar un archivo valido\n");
			}
			break;
		case 5:
			if(flagLoaded){
				if(controller_sortlistServices(pLLService) == -1){
					printf("ERROR al intententar ordemar lista\n");
				}
			} else {
				printf("Debe cargar un archivo valido\n");
			}
			break;
		case 6:
			if(flagLoaded){
				if(controller_saveSortListServices("dataSorterd.csv",pLLService) == -1){
					printf("ERROR, al intentar guardar lista ordenada");
				}
			} else {
				printf("Debe cargar un archivo valido\n");
			}
			break;
		default:
			if(option != 7){
				printf("Fuera de rango del menu intente de nuevo");
			}
		}

	}while(option != 7);
	return 0;
}
