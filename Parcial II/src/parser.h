/*
 * parser.h
 *
 *  Created on: 8 nov. 2021
 *      Author: Javier
 */

#include "Controller.h"
#ifndef PARSER_H_
#define PARSER_H_

int parser_CargaEditorial(FILE* pArchivo , LinkedList* pListaE);

int parser_CargaLibros(FILE* pArchivo , LinkedList* pListaL);

//int parser_GuardarEditorial(FILE* pArchivo , LinkedList* pLista);

//int parser_GuardarLibros(FILE* pArchivo , LinkedList* pLista);


#endif /* PARSER_H_ */
