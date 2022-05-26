/*
 * utn.h
 *
 *  Created on: 24 may. 2022
 *      Author: Javier
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Estructuras.h"

#ifndef UTN_H_
#define UTN_H_

int verifStr(char string[]);
void setString(char* string,char mensaje[]);
float setFlotante(char mensaje[]);
int setEntero(char mensaje[]);

#endif /* UTN_H_ */
