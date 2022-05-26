/*
 * libreria.c
 *
 *  Created on: 9 set. 2021
 *      Author: Javier
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "libreriaP.h"


/**
 * @brief crea un menu con los mensajes de ingresados por parametro
 *
 * @param 0 en caso de que no sea un submenu;1 en caso de que sea un submenu
 * @param mensaje 1
 * @param mensaje 2
 * @param mensaje 3
 * @param mensaje 4
 * @param mensaje 5
 * @param mensaje 6
 * @return tira la opcion que ingreso el usuario; -1 si ingresa una letra adicionalmente tira un aviso
 * @attention tiene que usarse con un switch de lo retornado para que ande correctmente
 */
int MenuGeneral(int submenu,char mensaje1[], char mensaje2[], char mensaje3[], char mensaje4[], char mensaje5[], char mensaje6[]){

	char ingreso[10];
	int respuesta,i;

	printf("\nIngrese una opción (en números)...\n");
	printf("%s", mensaje1);
	printf("%s", mensaje2);
	printf("%s", mensaje3);
	printf("%s", mensaje4);
	printf("%s", mensaje5);
	printf("%s", mensaje6);
	if(submenu){
		printf("o ingrese 0 para regresar\n");
	} else {
		printf("o ingrese 0 para SALIR\n");
	}
	setbuf(stdin, NULL);
	scanf("%s", ingreso);

	for(i = 0;i < strlen(ingreso);i++){
		if(!(isdigit(ingreso[i]))){
			break;
		}
	}
	if(i == strlen(ingreso)){
		respuesta = atoi(ingreso);
	} else {
		printf("ERROR, solo se aceptan números\n");
		respuesta = -1;
	}

	return respuesta;
}

/**
 * @brief ingreso de entero + unas verificaciones opcionales
 * @attention FUNCION EN DESARROLLO
 * @param mensaje mostrado antes de pedir el numero
 * @param 1 o 0 si se quiere o no una verificacion
 * @return numero ingresado ya verificado
 */
int IngresarEntero(char mensaje[],int verif)
{
    int numero;
	char respuesta;

    do{
		printf("%s",mensaje);
	    setbuf(stdin,NULL);
		scanf("%d",&numero );
		respuesta = 's';

		if(verif){
			printf("el valor de %d esta correcto? (S/N/C)", numero);
		    setbuf(stdin,NULL);
			scanf("%c",&respuesta);
			respuesta = tolower(respuesta);
			if(respuesta == 'c'){
				numero = 0;
				respuesta = 's';
			}

		}
    }while(respuesta != 's');
	return numero;
}

/**
 * @brief ingreso de flotante + unas verificaciones opcionales
 * @attention FUNCION EN DESARROLLO
 * @param mensaje mostrado antes de pedir el numero
 * @param 1 o 0 si se quiere o no una verificacion
 * @return numero ingresado ya verificado
 */
float IngresarFlotante(char mensaje[],int verif)
{
    float numero;
    char respuesta;
    do{
		printf("%s",mensaje);
		setbuf(stdin,NULL);
		scanf("%f",&numero );

		if(verif){
			printf("el valor de %.2f esta correcto? (S/N/C)", numero);
			setbuf(stdin,NULL);
			scanf("%c",&respuesta);
			respuesta = tolower(respuesta);
			if(respuesta == 'c'){
				numero = 0;
				respuesta = 's';
			}
		}
    }while(respuesta != 's');
	return numero;
}


//void setString(char cadena[],char mensaje[],int tam)
//{
//    char auxiliar[tam];
//    printf("%s", mensaje);
//    setbuf(stdin,NULL);
//    scanf("%s", auxiliar);
//    strcpy(cadena, auxiliar);
//}

//recordatorio de como es las funciones para inicializar toda la estructura, NO ES UNA FUNCION
void InicializarArray(int array[],int cantidad){

	for(int i = 0;i<cantidad;i++){
		array[i] = -1;
	}

}

//recordatorio de como es las funciones para buscr espacio vacios en todas las estructuras, NO ES UNA FUNCION
int BuscarEspacio(int array[],int cantidad){

	int i;
	for(i = 0;i < cantidad;i++){
		if(array[i] == -1){
			break;
		}
	}
	return i;
}

//FUNCION NO TERMINADA
int isStrAlpha(char string[]){

	int r = 0;
	int contador = 0;

	for(int i = 0;i < strlen(string);i++){
		if(isalpha(string[i])){
			contador++;
		}
	}
	if(contador == strlen(string)){
		r = 1;
	}
	return r;
}

//void verifRemovedAll(int* flag,int len ,eVivienda* viviendas){
//	int contRemovedAll = 0;
//
//	for(int i = 0;i < len;i++){
//		if(viviendas[i].idViviendas == -1){
//			verifRemovedAll++;
//		}
//	}
//	if(contRemovedAll == len){
//		*flag = 0;
//		contRemovedAll = 0;
//	}
//
//}
