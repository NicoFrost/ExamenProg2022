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
	int option;
	do{
		option = MenuGeneral(0, "1.Cargar Archivo\n", "2.Imprimir lista\n", "3.Asignar totales\n", "4.Filtrar por tipo\n", "5.Mostrar servicios\n", "6.Guardar servicios\n", "", "", '7');
		switch(option) {
		case 1:
			controller_loadFromText(pLLService);
			break;
		case 2:
			controller_listService(pLLService);
			break;
		case 3:
			controller_assignTotal(pLLService);
			break;
		case 4:
			controller_createDataFiltred("dataFiltred.csv",pLLService);
			break;
		case 5:
			controller_sortlistServices(pLLService);
			break;
		case 6:
			controller_saveSortListServices("dataSorterd.csv",pLLService);
			break;
		}
	}while(option != 7);
	return 0;
}
