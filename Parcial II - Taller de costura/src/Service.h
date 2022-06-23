/*
 * Service.h
 *
 *  Created on: 22 jun. 2022
 *      Author: Nicolas
 */

#include "LinkedList.h"
#include <stdio.h>
#ifndef SERVICE_H_
#define SERVICE_H_

struct{
	int idServicio;
	char descripcion[51]; //(del servicio)
	int tipo; //(1-MINORISTA, 2-MAYORISTA, 3-EXPORTAR)
	float precioUnitario;
	int cantidad;
	float totalServicio;
}typedef eServicios;

eServicios* Servicios_new();
eServicios* Servicios_newParametros(char* idStr,char* descripcionStr,char* tipoStr,char* precioUnitarioStr,char* cantidadStr,char* precioTotalStr);
int itocTipoPasajero(int tipoServicio,char* tipoServicioC);
void Servicios_list(LinkedList* pLLService);
void* Servicios_calcularPrecioTotal(void* this);
int Service_sortByDescription(void* Service1,void* Service2);
int Servicio_filtrarDatos(void* this);
int GuardarTxt(FILE* pFile,LinkedList* pLLService);
int itocTipoPasajero(int tipoServicio,char* tipoServicioC);
//SETTERS

int Servicios_setId(eServicios* this,int id);
int Servicios_setDescripcion(eServicios* this,char* descripcion);
int Servicios_setTipoServicio(eServicios* this,int tipoServicio);
int Servicios_setPrecioUnit(eServicios* this,float precioUnitario);
int Servicios_setCantidad(eServicios* this,int cant);
int Servicios_setPrecioTotal(eServicios* this,float precioTotal);

//GETERS
int Servicios_getId(eServicios* this,int* id);
int Servicios_getDescripcion(eServicios* this,char* descripcion);
int Servicios_getTipoServicio(eServicios* this,int* tipoPasajero);
int Servicios_getPrecioUnitario(eServicios* this,float* precioUnitario);
int Servicios_getCantidad(eServicios* this,int* cant);
int Servicios_getPrecioTotal(eServicios* this,float* precioTotal);
int Servicios_getLastId(LinkedList* lList,int* sid);
#endif /* SERVICE_H_ */
