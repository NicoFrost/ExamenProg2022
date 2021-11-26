/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include "Controller.h"
#include "LinkedList.h"

int main(void) {
	setbuf(stdout,NULL);
	LinkedList* myListL;
	LinkedList* myListE;

	myListE = ll_newLinkedList();
	myListL = ll_newLinkedList();
	int option;
	do{
		option = MenuGeneral("1.Cargar archivo de libros\n", "2.Cargar archivo de editores\n", "3.Ordenar Lista de libros\n", "4.Listar libros\n", "5.listado de libros de la editorial MINOTAURO\n", "6.Generar Archivo mapeado.csv con los descuentos\n" , "", "", 0);
		switch(option){
			case 1:

				controller_CargarLibros(myListL);
				break;
			case 2:
				controller_CargarEditorial(myListE);
				break;
			case 3:
				controller_OrdenarLista(myListL);
				break;
			case 4:
				controller_Listar(myListL);
				break;
			case 5:
				controller_GuardarDatos("LibrosFiltrados.csv",myListL);
				break;
			case 6:
				controller_Mapeado("mapedo.csv",myListL);
				break;
				//6. Generar el archivo de salida “mapeado.csv” luego de aplicar la función map.
		}
	}while(option != 0);
	return 0;

}
