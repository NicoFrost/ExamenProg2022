/*
 * utn.c
 *
 *  Created on: 24 may. 2022
 *      Author: Javier
 */

#include "utn.h"


/**
 * @brief verifica que los string no sean nulos, ni que tengan numeros entre las letras
 *
 * @param string cadena de caracteres a verificar
 * @return -1 error por nulo;
 * 			0 hay numeros en la cadena;
 * 			1 no hay numeros en la cadena;
 *
 */
int verifStr(char string[]){
	int r = -1;
	int i;
	int len = strlen(string);

	if(string != NULL){
		for(i = 0;i < len;i++){
			if(!(isalpha(string[i]))){
				r = 0;
				break;
			}
		}
	}

	if(len == i){
		r = 1;
	}

	return r;
}

/**
 * @brief pide a usuario un ingreso y devuelve por referncia el string
 *
 *
 * @param string que se devuelve
 * @param mensaje que se muestra antes de pedir string
 */
void setString(char string[],char mensaje[]){
	do{
		printf("%s: ",mensaje);
		fflush(stdin);
		gets(string);
		if(!(verifStr(string))){
			printf("ERROR, numeros ingresados, solo letras por favor\n");
		}
	}while(!(verifStr(string)));
}

/**
 * @brief muestra un mensaje, pide un flotante verifica contra letras
 *
 * @param mensaje mensaje que se muestra antes de pedir el flotante
 *
 * @return flotante
 */
float setFlotante(char mensaje[]){
	float flotante;
	do{
		printf("%s: ",mensaje);
		setbuf(stdin,NULL);
		scanf("%f",&flotante);
		if(!(isalpha(flotante))){
			printf("ERROR, ha ingresado una letra en el numero");
		}
	}while(flotante < 0);

	return flotante;
}

/**
 * @brief muestra un mensaje, pide un entero verifica contra letras
 *
 * @param mensaje mensaje que se muestra antes de pedir el entero
 * @return entero
 */
int setEntero(char mensaje[]){


	char entero[10];
	int i,resultado;
	int flag = 1;
	int len;
	do{
		printf("%s: ",mensaje);
		setbuf(stdin,NULL);
		scanf("%s",entero);
		len = strlen(entero);
		for(i = 0;i < len;i++){
			if(!(isdigit(entero[i]))){
				break;
			}
		}
		if(i == len){
			flag = 0;
		} else {
			i = 0;
			printf("ERROR, solo se aceptan numeros no letras\n");
		}
	}while(flag);
	resultado = atoi(entero);

	return resultado;
}
