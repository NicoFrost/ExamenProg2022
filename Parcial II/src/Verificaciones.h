/*
 * Verificaciones.h
 *
 *  Created on: 26 nov. 2021
 *      Author: Javier
 */
#include "Estructuras.h"
#include "LinkedList.h"
#ifndef VERIFICACIONES_H_
#define VERIFICACIONES_H_

void VerifExtencionArchivo(char archivoExt[],char* objeto);
int Artistas(void* pElement1,void* pElement2);
int Identidad(void* pElement1,void* pElement2);
int fn(void* pElement);
eLibro* DescuentosLibros(LinkedList this,void* pElement);

#endif /* VERIFICACIONES_H_ */
