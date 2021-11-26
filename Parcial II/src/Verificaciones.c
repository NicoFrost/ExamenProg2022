#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Verificaciones.h"
#include "Estructuras.h"

void VerifExtencionArchivo(char archivoExt[],char* objeto){
	char archivo[50];
	char extencion[20] = ".csv";


	printf("ingrese el NOMBRE(SIN EXTENCION) del Archivo csv de %s\n",objeto);
	scanf("%s",archivo);
	while(strchr(archivo,'.') != NULL){
		printf("ERROR: se ingreso una extencion\n");
		printf("ingrese el NOMBRE(SIN EXTENCION) Archivo csv\n");
		scanf("%s",archivo);
	}
	strcat(archivo,extencion);

	strcpy(archivoExt,archivo);
}

int Artistas(void* pElement1,void* pElement2){

	eLibro* libroA;
	eLibro* libroB;
	int retorno;

	libroA = pElement1;
	libroB = pElement2;

	if(strcmpi(libroA->autor,libroB->autor) > 0){
		retorno = 1;
	} else {
		if(strcmpi(libroA->autor,libroB->autor) < 0){
			retorno = -1;
		}
	}


	return retorno;
}

//func
///brief
///param
///param
///param
///return retorno (1) cuando el pElement1 >


int Identidad(void* pElement1,void* pElement2){

	eLibro* libroA;
	eLibro* libroB;
	int retorno;


	libroA = pElement1;
	libroB = pElement2;

	if(libroA->id > libroB->id){
		retorno = 1;
	} else {
		if(libroA->id < libroB->id){
			retorno = -1;
		}
	}

	return retorno;
}

//func fn(void* pElement);
///brief valida si el elemento ingresado es de la editorial MINOTAURO (4)
///param pElement
///return retorna (-1) ERROR: pElement NULL (0) idEditorial del pElement != 4 (1) idEditorial del pElement == 4

int fn(void* pElement){

	int retorno = -1;

	if(pElement != NULL){
		eLibro* libroTemp = pElement;


		if(libroTemp->idEditorial == 4){
			retorno = 1;
		} else {
			retorno = 0;
		}
	}

	return retorno;
}

eLibro* DescuentosLibros(LinkedList this,void* pElement){
/*
  este modo se realizarán descuentos a los precios según se detalla:
 	 * PLANETA: 20% (si el monto es mayor o igual a $300)
 	 * SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)
 */
	eLibro* libroEnDescuento;
	int precioDesc;

	libroEnDescuento = pElement;

	if(libro_getIDeditorial(libroEnDescuento) == 1 && libro_getPrecio(libroEnDescuento) >= 300){
		precioDesc = libro_getPrecio(libroEnDescuento) * .10;
		libro_setPrecio(libroEnDescuento, precioDesc);
	} else {
		if(libro_getIDeditorial(libroEnDescuento) == 2 && libro_getPrecio(libroEnDescuento) <= 200){
			precioDesc = libro_getPrecio(libroEnDescuento) * .10;
			libro_setPrecio(libroEnDescuento, precioDesc);
		}
	}


	return libroEnDescuento;

}

