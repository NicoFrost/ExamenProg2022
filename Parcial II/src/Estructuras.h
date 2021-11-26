/*
 * Estructuras.h
 *
 *  Created on: 24 nov. 2021
 *      Author: Javier
 */
#include "LinkedList.h"
#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_

typedef struct {
	int id;
	char titulo[128];
	char autor[128];
	int precio;
	int idEditorial;
} eLibro;

typedef struct {
	int idEditorial;
	char nombre[50];
} eEditorial;

int libro_getID(eLibro* libro);
void libro_getTitulo(eLibro* libro,char* titulo);
void libro_getAutor(eLibro* libro,char* autor);
int libro_getPrecio(eLibro* libro);
int libro_getIDeditorial(eLibro* libro);

void libro_setID(eLibro* libro,int id);
void libro_setTitulo(eLibro* libro,char* titulo);
void libro_setAutor(eLibro* libro,char* autor);
void libro_setPrecio(eLibro* libro,int precio);
void libro_setIDeditorial(eLibro* libro,int editorial);

eLibro* set_newLibro(int id,char titulo[50],char autor[50],int precio,int idEditorial);
eEditorial* set_newEditorial(int IdEditorial,char nombreEditorial[50]);
void ListarLibros(LinkedList* list);
void GuardarLibros(FILE* archivo,LinkedList* list);


#endif /* ESTRUCTURAS_H_ */
