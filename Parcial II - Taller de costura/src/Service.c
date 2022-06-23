/*
 * Service.c
 *
 *  Created on: 22 jun. 2022
 *      Author: Nicolas
 */
#include "Service.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "libreriaP.h"
#include "filters.h"
#define TAM 50

/**
 * @brief crea en memoria dinamica un Servicio y lo setea vacio para luego ser llenado por otra funcion
 * @return Servicio vacio
 */
eServicios* Servicios_new(){

    eServicios* nuevoServicio = NULL;
    nuevoServicio= (eServicios*) malloc(sizeof(eServicios));

    if(nuevoServicio != NULL)
    {
    	nuevoServicio->idServicio=0;
        strcpy(nuevoServicio->descripcion, " ");
        nuevoServicio->tipo = 0;
        nuevoServicio->precioUnitario=0;
        nuevoServicio->cantidad = 0;
        nuevoServicio->totalServicio=0;
    }

    return nuevoServicio;
}


/**
 * @brief usa funcion Servicios_new() para crear un servicio y luego lo rellena con datos pasados por parametros
 * @param idStr id como string
 * @param descripcionStr descripcion del producto
 * @param tipoStr tipo de servicio pasado como string (contertidos a texto)
 * @param precioUnitarioStr precio unitario pasado como string
 * @param cantidadStr cantidad pasado como string
 * @param precioTotalStr precio total pasado como string
 * @return servicio lleno con datos aportados por parametros
 */
eServicios* Servicios_newParametros(char* idStr,char* descripcionStr,char* tipoStr,char* precioUnitarioStr,char* cantidadStr,char* precioTotalStr){

	eServicios* pnuevoServicio = Servicios_new();

	if(pnuevoServicio != NULL){

		int idInt = atoi(idStr);
		int tipoServicioInt = atoi(tipoStr);
		float precioUnitarioFlt = atof(precioUnitarioStr);
		int cantidadInt = atoi(cantidadStr);
		float precioTotalFlt = atof(precioTotalStr);

		if(strcmp(tipoStr,"MINORISTA") == 0){
			tipoServicioInt = 1;
		} else {
			if(strcmp(tipoStr,"MAYORISTA") == 0){
				tipoServicioInt = 2;

			} else {
				if(strcmp(tipoStr,"EXPORTAR") == 0){
					tipoServicioInt = 3;
				}
			}
		}

	    if(!(
	    		Servicios_setId(pnuevoServicio, idInt)
			&&	Servicios_setDescripcion(pnuevoServicio, descripcionStr)
			&&	Servicios_setTipoServicio(pnuevoServicio, tipoServicioInt)
			&&	Servicios_setCantidad(pnuevoServicio, cantidadInt)
			&&	Servicios_setPrecioUnit(pnuevoServicio, precioUnitarioFlt)
			&&	Servicios_setPrecioTotal(pnuevoServicio, precioTotalFlt)
	    ))
	    {
	    	printf("ERROR,Uno o varios datos no se puedieron procesar\n");
	    	printf("DATOS ENVIADOS: %d %s %d %.2f %d %.2f\n",idInt,descripcionStr,tipoServicioInt,precioUnitarioFlt,cantidadInt,precioTotalFlt);
	    }
	}

   	return pnuevoServicio;
}

/**
 * @brief obtiene datos y muestra 1 servcicio por pantalla
 * @param pServicio servicio a mostrar
 * @param pLLService LinkedList
 */
void Servicios_OneServicios(eServicios* pServicio,LinkedList* pLLService){
	int id,tipoAux,cantidad;
	float precioUnitario,precioTotal;
	char descripcion[TAM],tipoServicio[TAM];

	if(
			Servicios_getId(pServicio, &id)
		&&	Servicios_getDescripcion(pServicio, descripcion)
		&&	Servicios_getTipoServicio(pServicio, &tipoAux)
		&&	Servicios_getCantidad(pServicio, &cantidad)
		&&	Servicios_getPrecioUnitario(pServicio, &precioUnitario)
		&&	Servicios_getPrecioTotal(pServicio, &precioTotal)
    ){

		itocTipoPasajero(tipoAux, tipoServicio);

		printf("|| %5d | %-25s\t | %-12s\t | %9.2f\t | %9d\t | %12.2f\t ||\n",id,descripcion,tipoServicio,precioUnitario,cantidad,precioTotal);
//	} else {
//		int aux = ll_indexOf(pLLService, pServicio);
//		printf("ERROR, al traer uno o varios datos desdde Linkedlist INDEX = %d",aux);
	}
}
/**
 * @brief muestra una lista de todos los servicios
 * @param pLLService LinkedList
 */
void Servicios_list(LinkedList* pLLService){
	char res;
	int corte = 250;
	eServicios* servicioAux = NULL;
	printf("_|=======================================================================================================|_\n");
	printf("||  ID   |          Descripcion          |     Tipo      |  Precio Unit  |    Cantidad   | Precio Total  ||\n");
	printf("||-------+-------------------------------+---------------+---------------+---------------+---------------||\n");
	for(int i = 0;i < ll_len(pLLService);i++){
		servicioAux = ll_get(pLLService, i);
		Servicios_OneServicios(servicioAux, pLLService);
		if(i == corte-1 && i != 1000-1){
			printf("\nPresione V para continuar\n");
			setbuf(stdin,NULL);
			scanf("%c",&res);
			corte = corte + 125;
		}
	}
	printf("===========================================================================================================\n");
}

/**
 * @brief se usa para obtener datos de los elementos pasados por parametros y luego los compara
 * @param Service1 elemento 1
 * @param Service2 elemento 2
 * @return si es verdadera la comparacion devuelve 1
 * 		   si es falsa la compararacion devuelve 0
 */
int Service_sortByDescription(void* Service1,void* Service2){
	int retorno;

	if(Service1 != NULL && Service2 != NULL){
		char description1[TAM];
		char description2[TAM];

		Servicios_getDescripcion(Service1, description1);
		Servicios_getDescripcion(Service2, description2);

		if(description1 != NULL && description2 != NULL){
			retorno = strcmp(description1,description2);
		}
	}

	return retorno;
}
/**
 * @brief funcion para guardar linkedlist en archivo pasado
 * @param pFile puntero a archivo
 * @param lList puntero a linkedlist
 * @return retorna 1 si se guarda bien sino 0 si no se guardaron correctamente
 */
int GuardarTxt(FILE* pFile,LinkedList* pLLService){
	int retorno = 0;
	if(pFile != NULL && pLLService != NULL){
		eServicios* pServicioAux;
		int id;
		char descripcion[TAM];
		float precioUnitario,precioTotal;
		int tipoServicio,cantidad;

		int len,cantidadEscrita;
		len = ll_len(pLLService);

		if(len > 0){
			fprintf(pFile,"id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio\n");

			for(int i = 0 ;i < len;i++){
				pServicioAux = ll_get(pLLService, i);
				if(pServicioAux != NULL){
					Servicios_getId(pServicioAux, &id);
					Servicios_getDescripcion(pServicioAux, descripcion);
					Servicios_getTipoServicio(pServicioAux, &tipoServicio);
					Servicios_getPrecioUnitario(pServicioAux, &precioUnitario);
					Servicios_getCantidad(pServicioAux, &cantidad);
					Servicios_getPrecioTotal(pServicioAux, &precioTotal);

					cantidadEscrita = fprintf(pFile,"%d,%s,%d,%.2f,%d,%.2f\n",id,descripcion,tipoServicio,precioUnitario,cantidad,precioTotal);
					if(cantidadEscrita != 0){
						retorno = 1;
					}
				}
			}
		}
	}

	return retorno;
}

/**
 * @brief se usa para poder convertir tipo de servicio en numero a su contraparte en cadena de texto
 * @param tipoServicio numero referenciando a uno de sus modos en texto
 * @param tipoServicioC cadena de texto a la que referencia el numero con el que se guarda en la estructura
 * @return retorna siempre 1
 */
int itocTipoPasajero(int tipoServicio,char* tipoServicioC){

	if(tipoServicio == 1){
		strcpy(tipoServicioC,"MINORISTA");
	} else {
		if(tipoServicio == 2){
			strcpy(tipoServicioC,"MAYORISTA");
		} else {
			if(tipoServicio == 3){
				strcpy(tipoServicioC,"EXPORTAR");
			}
		}
	}
	return 1;
}

/**
 * @brief calcula precio total del elemento pasado por parametro
 * @param this elemento para calcularle el precio total
 */
void* Servicios_calcularPrecioTotal(void* this){

	if(this != NULL){
		int cantidad;
		float precioUnit,precioTot;
		Servicios_getCantidad(this, &cantidad);
		Servicios_getPrecioUnitario(this, &precioUnit);

		precioTot = cantidad * precioUnit;

		Servicios_setPrecioTotal(this, precioTot);
	}

	return this;
}


//SETTERS
/**
 * @brief setea un id en el servicio
 * @param this servicio
 * @param id numero de id
 * @return devuele 1 si se hizo bien 0 si hubo un error
 */
int Servicios_setId(eServicios* this,int id){

	int retorno = 0;

	if(this != NULL && id > 0){
		this->idServicio = id;
		retorno = 1;
	}

	return retorno;
}

/**
 * @brief setea una descripcion en el servicio
 * @param this servicio
 * @param nombre cadena de texto de nombre
 * @return devuele 1 si se hizo bien 0 si hubo un error
 */
int Servicios_setDescripcion(eServicios* this,char* descripcion){
	int retorno = 0;

	if(this != NULL ){
		strcpy(this->descripcion,descripcion);
		retorno = 1;
	}

	return retorno;
}


/**
 * @brief setea un tipo de servicio en el servicio
 * @param this servicio
 * @param tipoServicio numero de tipo de servicio
 * @return devuele 1 si se hizo bien 0 si hubo un error
 */
int Servicios_setTipoServicio(eServicios* this,int tipoServicio){
	int retorno = 0;

	if(this != NULL && tipoServicio > 0 && tipoServicio <= 3){
		this->tipo = tipoServicio;
		retorno = 1;
	}

	return retorno;
}

/**
 * @brief setea un precio Unitario en el servicio
 * @param this servicio
 * @param precio numero flotante
 * @return devuele 1 si se hizo bien 0 si hubo un error
 */
int Servicios_setPrecioUnit(eServicios* this,float precioUnitario){
	int retorno = 0;

	if(this != NULL && precioUnitario > 0){
		this->precioUnitario = precioUnitario;
		retorno = 1;
	}

	return retorno;
}

/**
 * @brief setea una cantidad en el servicio
 * @param this servicio
 * @param precio numero flotante
 * @return devuele 1 si se hizo bien 0 si hubo un error
 */
int Servicios_setCantidad(eServicios* this,int cant){
	int retorno = 0;

	if(this != NULL && cant > 0){
		this->cantidad = cant;
		retorno = 1;
	}

	return retorno;
}

/**
 * @brief setea un precio Total en el servicio
 * @param this servicio
 * @param precio numero flotante
 * @return devuele 1 si se hizo bien 0 si hubo un error
 */

int Servicios_setPrecioTotal(eServicios* this,float precioTotal){
	int retorno = 0;

	if(this != NULL && precioTotal >= 0){
		this->totalServicio = precioTotal;
		retorno = 1;
	}

	return retorno;
}


//GETERS

/**
 * @brief obtiene el id y lo pasa por parametro
 * @param this
 * @param id
 * @return retorna 1 si devuelve bien y 0 si hay un error
 */
int Servicios_getId(eServicios* this,int* id){
	int retorno = 0;
	if(this != NULL && id > 0){
		*id = this->idServicio;
		retorno = 1;
	}
		return retorno;
}
/**
 * @brief obtiene el nombre y lo pasa por parametro
 * @param this
 * @param nombre
 * @return retorna 1 si devuelve bien y 0 si hay un error
 */

int Servicios_getDescripcion(eServicios* this,char* descripcion){
	int retorno = 0;
	if(this != NULL && descripcion != NULL){
		strcpy(descripcion,this->descripcion);
		retorno = 1;
	}


	return retorno;
}

/**
 * @brief obtiene el tipo de servicio (en numero) y lo pasa por parametro
 * @param this
 * @param tipo de servicio (en numero)
 * @return retorna 1 si devuelve bien y 0 si hay un error
 */
int Servicios_getTipoServicio(eServicios* this,int* tipoPasajero){
	int retorno = 0;
	if(this != NULL && tipoPasajero != NULL){
		*tipoPasajero = this->tipo;
		retorno = 1;
	}
		return retorno;
}


/**
 * @brief obtiene el precio y lo pasa por parametro
 * @param this
 * @param precio en flotante
 * @return retorna 1 si devuelve bien y 0 si hay un error
 */
int Servicios_getPrecioUnitario(eServicios* this,float* precioUnitario){
	int retorno = 0;
	if(this != NULL && precioUnitario != NULL){
		*precioUnitario = this->precioUnitario;
		retorno = 1;
	}

	return retorno;
}

/**
 * @brief obtiene el precio y lo pasa por parametro
 * @param this
 * @param precio en flotante
 * @return retorna 1 si devuelve bien y 0 si hay un error
 */
int Servicios_getCantidad(eServicios* this,int* cant){
	int retorno = 0;
	if(this != NULL && cant != NULL){
		*cant = this->cantidad;
		retorno = 1;
	}

	return retorno;
}

/**
 * @brief obtiene el precio y lo pasa por parametro
 * @param this
 * @param precio en flotante
 * @return retorna 1 si devuelve bien y 0 si hay un error
 */
int Servicios_getPrecioTotal(eServicios* this,float* precioTotal){
	int retorno = 0;
	if(this != NULL && precioTotal != NULL){
		*precioTotal = this->totalServicio;
		retorno = 1;
	}

	return retorno;
}

/**
 * @brief obtiene el obtiene ultimo ID registrado
 * @param this
 * @param id id buscado
 * @return retorna 1 si devuelve bien y 0 si hay un error
 */
int Servicios_getLastId(LinkedList* lList,int* sid){

	int retorno = 0;
	if(lList != NULL && sid != NULL){
		int len = ll_len(lList);
		int idMax = 0;
		int serviceId;
		eServicios* service;

		for(int i = 0;i < len;i++){
			service = ll_get(lList, i);
			Servicios_getId(service, &serviceId);
			if(serviceId > idMax){
				idMax = serviceId;
			}
		}
		*sid = idMax + 1;
		retorno = 1;
	}
	return retorno;
}
