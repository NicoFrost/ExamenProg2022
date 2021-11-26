/*
 * Estructuras.c
 *
 *  Created on: 25 nov. 2021
 *      Author: Javier
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Estructuras.h"
#include "LinkedList.h"

///brief Crea un nuevo libro dentro de la memoria dinamica
///params se les pasa todos los parametros que tiene una estructura eLibro

int libro_getID(eLibro* libro){
	return libro->id;
}
void libro_getTitulo(eLibro* libro,char* titulo){
	titulo = libro->titulo;
}
void libro_getAutor(eLibro* libro,char* autor){
	autor = libro->autor;
}
int libro_getPrecio(eLibro* libro){
	return libro->precio;
}
int libro_getIDeditorial(eLibro* libro){
	return libro->idEditorial;
}

void libro_setID(eLibro* libro,int id){
	libro->id = id;
}
void libro_setTitulo(eLibro* libro,char* titulo){
	strcpy(libro->titulo,titulo);
}
void libro_setAutor(eLibro* libro,char* autor){
	strcpy(libro->autor,autor);
}
void libro_setPrecio(eLibro* libro,int precio){
	libro->precio = precio;
}

void libro_setIDeditorial(eLibro* libro,int editorial){
	libro->idEditorial = editorial;
}

eLibro* set_newLibro(int id,char titulo[128],char autor[128],int precio,int idEditorial){

	eLibro* pLibro;

	pLibro = malloc(sizeof(eLibro));

	libro_setID(pLibro, id);
	libro_setTitulo(pLibro, titulo);
	libro_setAutor(pLibro, autor);
	libro_setPrecio(pLibro, precio);
	libro_setIDeditorial(pLibro, idEditorial);

	return pLibro;
}

///brief Crea una nueva editorial en memoria Dinamica
///Param char IdEditorial[]
///Param char Nombre[]

eEditorial* set_newEditorial(int IdEditorial,char nombreEditorial[50]){
	eEditorial* editorial;

	editorial = malloc(sizeof(eEditorial));

	editorial->idEditorial = IdEditorial;
	strcpy(editorial->nombre,nombreEditorial);

	return editorial;
}

void ListarLibros(LinkedList* list){

	eLibro* libro;
	printf("----------------------------------------------------\n");
	for(int i = 0;i < ll_len(list);i++){
		libro = ll_get(list, i);
		printf("%d || %s\t %s \t%d\t%d\n",libro->id,libro->titulo,libro->autor,libro->precio,libro->idEditorial);
		printf("----------------------------------------------------\n");
	}
}

void GuardarLibros(FILE* archivo,LinkedList* list){

	eLibro* libro;
	for(int i = 0;i < ll_len(list);i++){
		libro = ll_get(list,i);
		fprintf(archivo,"%d,%s,%s,%d,%d\n",libro->id,libro->titulo,libro->autor,libro->precio,libro->idEditorial);
	}

}


