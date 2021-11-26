/*
 * parsers.c
 *
 *  Created on: 24 nov. 2021
 *      Author: Javier
 */

#include "LinkedList.h"
#include "Controller.h"
#include "Estructuras.h"

#define TAM 120

int parser_CargaEditorial(FILE* pArchivo , LinkedList* pListaE){

 	char parIDEditorial[TAM];
 	char parNombre[TAM];
 	int IdEditorial;
 	int primeraPas = 0;
 	eEditorial* editorial;

	while(!feof(pArchivo)){
 		fscanf(pArchivo,"%[^,],%[^\n]\n",parIDEditorial,parNombre);
 		if(primeraPas != 0){
 			IdEditorial = atoi(parIDEditorial);

 			editorial = set_newEditorial(IdEditorial, parNombre);
 			ll_add(pListaE, editorial);
 		} else {
 			if(!(strcmp(parIDEditorial,"idEditorial") == 0 && strcmp(parNombre,"nombre") == 0)){
				printf("Archivo con formato erroneo o sin indice de formato FAVOR DE REVISAR\nFormato requerido: (idEditorial,nombre)");
				break;
			} else {
				primeraPas = 1;
			}
 		}
	}

	if(primeraPas == 1){
		printf("\nCarga Exitosa!,Listo para trabajar\n");
	}


	return 1;
}

int parser_CargaLibros(FILE* pArchivo , LinkedList* pListaL){

	char parID[TAM];
 	char parTitulo[TAM];
 	char parAutor[TAM];
 	char parPrecio[TAM];
 	char parIDEditorial[TAM];
 	int id,precio,idEditorial,primeraPas = 0;

 	eLibro* libro;
	while(!feof(pArchivo)){
 		fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",parID,parTitulo,parAutor,parPrecio,parIDEditorial);
		if(primeraPas != 0){
 			id =  atoi(parID);
 			precio = atoi(parPrecio);
 			idEditorial = atoi(parIDEditorial);

			libro = set_newLibro(id,parTitulo,parAutor,precio,idEditorial);
 			ll_add(pListaL,libro);
		} else {
			if(!(strcmp(parID,"id") == 0 && strcmp(parTitulo,"titulo") == 0 && strcmp(parAutor,"autor") == 0 && strcmp(parPrecio,"precio") == 0 && strcmp(parIDEditorial,"idEditorial") == 0)){
				printf("Archivo con formato erroneo o sin indice de formato FAVOR DE REVISAR\nFormato requerido: (id,titulo,autor,precio,idEditorial)");
				break;
			} else {
				primeraPas = 1;
			}
		}
 	}

	if(primeraPas == 1){
		printf("\nCarga Exitosa!,Listo para trabajar\n");
	}

	return 1;
}
