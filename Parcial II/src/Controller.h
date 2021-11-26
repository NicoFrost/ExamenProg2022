/*
 * Controller.h
 *
 *  Created on: 24 nov. 2021
 *      Author: Javier
 */

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef CONTROLLER_H_
#define CONTROLLER_H_

void VerifExtencionArchivo(char* archivoExt,char* objeto);
void controller_CargarEditorial(LinkedList* lista);
void controller_CargarLibros(LinkedList* lista);
void controller_Listar(LinkedList* list);
void controller_OrdenarLista(LinkedList* list);
void controller_GuardarDatos(char* path,LinkedList* list);
void controller_Mapeado(char* path,LinkedList* list);
#endif /* CONTROLLER_H_ */
