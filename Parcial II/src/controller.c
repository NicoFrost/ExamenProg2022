/*
 * Controller.c
 *
 *  Created on: 24 nov. 2021
 *      Author: Javier
 */

#include <string.h>
#include "Controller.h"
#include "Estructuras.h"
#include "LinkedList.h"
#include "parser.h"
#include "Verificaciones.h"


void controller_CargarEditorial(LinkedList* lista){

	FILE* archivoEditoriales;
	char pathEditoriales[20];

	VerifExtencionArchivo(pathEditoriales,"editoriales");

	archivoEditoriales = fopen(pathEditoriales,"r");
	if(archivoEditoriales != NULL){
		parser_CargaEditorial(archivoEditoriales, lista);
	} else {
		printf("Editoriales:Archivo/Ruta %s no encontrado",pathEditoriales);
	}
	fclose(archivoEditoriales);
}

void controller_CargarLibros(LinkedList* lista){

	FILE* archivoLibro;
	char pathLibros[20];

	VerifExtencionArchivo(pathLibros,"libros");

	archivoLibro = fopen(pathLibros,"r");
	if(archivoLibro != NULL){
		parser_CargaLibros(archivoLibro, lista);
	} else {
		printf("Libros: Archivo/Ruta %s no encontrado",pathLibros);
	}
	fclose(archivoLibro);

}

void controller_Listar(LinkedList* list){

	ListarLibros(list);

}

void controller_OrdenarLista(LinkedList* list){

	ll_sort(list,Artistas, 1);
	controller_Listar(list);
	ll_sort(list,Identidad, 1);
}

void controller_GuardarDatos(char* path,LinkedList* list){

	FILE* archivo;
	LinkedList* listaFiltrada;

	listaFiltrada = ll_filter(list,fn);
	archivo = fopen(path,"w");
	if(archivo != NULL){
		GuardarLibros(archivo,listaFiltrada);
		fclose(archivo);
	}

}

void controller_Mapeado(char* path,LinkedList* list){

	FILE* archivo;
	LinkedList* listaMapeada;

	archivo = fopen(path,"w");
	if(archivo != NULL){
		listaMapeada = ll_map(list,DescuentosLibros);
		GuardarLibros(archivo, listaMapeada);
		fclose(archivo);
	}

}
