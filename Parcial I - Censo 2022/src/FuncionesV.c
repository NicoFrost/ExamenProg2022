/*
 * FuncionesV.c
 *
 *  Created on: 23 may. 2022
 *      Author: Javier
 */


#include "FuncionesV.h"
#include "FuncionesC.h"
#include "Estructuras.h"
#include "utn.h"
#include "libreriaP.h"


/**
 * @brief funcion para acortar codigo a la hora de hacer el cambio de valores por burbujeo.
 * @attention tenga en cuenta que esta funcion esta pensada para funcionar dentro de 2 for's
 * @param list de eViviendas que se quiere reacomodar
 * @param contador i
 * @param contador j
 */
void CambioBurbuja(eVivienda* list,int i,int j){
	char strAux[51];
	int iAux;


	iAux = list[i].idViviendas;
	list[i].idViviendas = list[j].idViviendas;
	list[j].idViviendas = iAux;

	strcpy(strAux,list[i].calle);
	strcpy(list[i].calle,list[j].calle);
	strcpy(list[j].calle,strAux);

	iAux = list[i].cantidadPersonas;
	list[i].cantidadPersonas = list[j].cantidadPersonas;
	list[j].cantidadPersonas = iAux;

	iAux = list[i].cantidadHabitaciones;
	list[i].cantidadHabitaciones = list[j].cantidadHabitaciones;
	list[j].cantidadHabitaciones = iAux;

	iAux = list[i].tipoVivienda;
	list[i].tipoVivienda = list[j].tipoVivienda;
	list[j].tipoVivienda = iAux;

	iAux = list[i].legajoCensista;
	list[i].legajoCensista = list[j].legajoCensista;
	list[j].legajoCensista = iAux;

}

/**
 * @brief inicializa los ID de todos los espacios de (list)
 *
 * @param lista a ser inicializada
 * @param tamaño de la lista a ser inicializada
 * @return 0 si se inicializo bien; -1 si la lista pasada es nula
 */
int initVivienda(eVivienda* list, int len){

	int r = -1;
	if(len > 0 && list != NULL ){
		for(int i = 0; i < len;i++){
			list[i].idViviendas = -1;
		}
		r = 0;
	}
	return r;
}

/**
 * @brief verifica si en la lista de viviendas quedan datos activos
 *
 * @param flag que refleje el resultado de esta funcion
 * @param tamaño de la lista
 * @param lista que se quiere verificar
 */
void verifRemovedAll(int* flag,int len ,eVivienda* viviendas){
	int contRemovedAll = 0;

	for(int i = 0;i < len;i++){
		if(viviendas[i].idViviendas == -1){
			contRemovedAll++;
		}
	}
	if(contRemovedAll == len){
		*flag = 0;
		contRemovedAll = 0;
	}

}


/**
 * @brief borrado completo de estructura (vivienda) para hacer un ingreso limpio para la proxima vez
 * @attention esta funcion solo se usa con la estructura ingresoViv
 * @param vivienda a ser borrada completamente
 */
void ClearViv(eVivienda* vivienda){
	vivienda->idViviendas = -1;
	strcpy(vivienda->calle,"");
	vivienda->cantidadPersonas = -1;
	vivienda->cantidadHabitaciones = -1;
	vivienda->tipoVivienda = -1;
	vivienda->legajoCensista = -1;
}

/**
 * @brief encuentra espacio vacio en la lista mandada por param 1
 *
 * @param lista que se quiere revisar
 * @param tamaño de la lista a revisar
 * @return referencia de donde se encuentra el espacio vacio
 */
int findFreeSpace(eVivienda* list,int cantidad){
	int i;
	for(i = 0;i < cantidad;i++){
		if(list[i].idViviendas == -1){
			break;
		} else {
			if(i == cantidad){
				i = -1;
			}
		}
	}
	return i;
}

/**
 * @brief printea en pantalla una sola vivienda
 *
 * @param lista de donde se va a sacar los datos
 * @param indicador de posicion de donde esta el dato a mostrar
 */
void MostrarUnaVivienda(eVivienda* list,int i){

	char tipoVivienda[20] = "";

	if(!(list[i].idViviendas == -1)){
		switch (list[i].tipoVivienda){
		case 1:
			strcpy(tipoVivienda,"CASA");
			break;
		case 2:
			strcpy(tipoVivienda,"DEPARTAMENTO");
			break;
		case 3:
			strcpy(tipoVivienda,"CASILLA");
			break;
		case 4:
			strcpy(tipoVivienda,"RANCHO");
		}

		printf("| %5d ",list[i].idViviendas);
		printf("| %-21s ",list[i].calle);
		printf("| %11d ",list[i].cantidadPersonas);
		printf("%10s"," ");
		printf("| %11d ",list[i].cantidadHabitaciones);
		printf("%10s"," ");
		printf("| %15s ",tipoVivienda);
		printf("%6s"," ");
		printf("| %11d ",list[i].legajoCensista);
		printf("%10s"," ");
		printf("|\n");
	}


}

/**
 * @brief encargada de pedir el nombre de la calle y la altura de la vivienda
 *
 * @param string que se quiere dejar lo ingresado por el usuario
 */
void setCalle(char* calle){
	char nombreCalle[25],alturaS[10];
	int altura;

	printf("Ingrese SOLO NOMBRE de la calle de la vivienda: ");
	fflush(stdin);
	gets(nombreCalle);

	altura = setEntero("Ingrese la altura de la calle de la vivienda");

	itoa(altura,alturaS,10);

	strcat(nombreCalle," ");
	strcat(nombreCalle,alturaS);
	strcpy(calle,nombreCalle);

}

/**
 * @brief encargada de pedir el tipo de vivienda con sus respectivas verificaciones
 *
 * @param vivienda en la que se quiere posicionar el dato
 */
void setTipoVivienda(eVivienda* vivienda){

	int tipo;
	int flag = 1;

	do{
		tipo = setEntero("Tipo de vivienda (1-CASA/2-DEPARTAMENTO/3-CASILLA/4-RANCHO)");
		if(tipo == 1 || tipo == 2 || tipo == 3 || tipo == 4){
			flag = 0;
		} else {
			printf("Está intentando poner un tipo de vivienda inexistente, intente de nuevo\n");
		}
	}while(flag);
	vivienda->tipoVivienda = tipo;
}

/**
 * @brief se le pasa por parametro una vivienda para ingresarlo
 * @attention para una alta comun y no harcodeada, se suele usar en compania de la funcion (addViviendas).
 * @param estructura temporal para poder guardar temporalmente los datos
 * @param lista de censistas a mostrar
 * @return 0 siempre
 */
int setVivData(eVivienda* vivienda,eCensista* censistas){

	int verifLegajo = 1;
	int legajo;

	printCensistas(censistas, 3);
	do{
		legajo = setEntero("Ingrese Legajo del censista");
		verifLegajo = verifExisCensistaLegajo(censistas,3, legajo);
		if(verifLegajo){
			vivienda->legajoCensista = legajo;
		} else {
			printf("ERROR, Censista no encontrado\n");
		}
	}while(verifLegajo != 1);

	setCalle(vivienda->calle);

	vivienda->cantidadPersonas = setEntero("Cantidad de personas en la vivienda");

	vivienda->cantidadHabitaciones = setEntero("Cantidad de habitaciones en la vivienda");

	setTipoVivienda(vivienda);

	return 0;
}

/**
 * @brief funcion encargada de dar unicamente de insertar datos en el punto indicado
 * @attention para una alta comun y no harcodeada, se suele usar en compania de la funcion (setVivData).
 * @param lista que se quiere ingresar dato
 * @param tamaño de la lista usada
 * @param id
 * @param calle
 * @param cantidadPersona
 * @param cantidadHabitaciones
 * @param tipoVivienda
 * @param legajo
 * @return -1 error en ingreso por lista NULL o por tamaño menor a 0 o porque no hay mas espacio en la lista; 1 la vivienda se agrego correctamente
 */
int addVivienda(eVivienda* list, int len, int id, char calle[],int cantidadPersona,int cantidadHabitaciones,int tipoVivienda,int legajo){
	int r = -1;
	int i = findFreeSpace(list, len);

	if(i != -1 && len > 0 && list != NULL){
		list[i].idViviendas = id;
		strcpy(list[i].calle,calle);
		list[i].cantidadHabitaciones = cantidadHabitaciones;
		list[i].cantidadPersonas = cantidadPersona;
		list[i].tipoVivienda = tipoVivienda;
		list[i].legajoCensista = legajo;
		r = 1;
	}

	return r;
}

/**
 * @brief encuentra viviendas segun su legajo
 *
 * @param lista en la que se quiere buscar
 * @param tamaño de la lista
 * @param legajo a encontrar
 * @return posicion de la vivienda encontrada en la lista dada; -1 si no encontro la vivienda con ese legajo
 */
int findViviendaByLegajo(eVivienda* list, int len,int legajo){
	int i = -1;

	if(len > 0 && list != NULL && legajo > 0){
		for(i = 0;i < len;i++){
			if(list[i].idViviendas >= len && list[i].idViviendas == legajo){
				break;
			}
		}
		if(i == len){
			i = -1;
		}
	}

	return i;
}

/**
 * @brief ordena las viviendas por calles
 * @attention en caso de calles iguales ordena por cantidad de personas en forma (de menor a mayor)
 *
 * @param lista a ordenar
 * @param tamaño de lista
 * @return -1 error en ordenamiento por lista NULL o tamaño menor a 0; 0 ordenamiento correcto
 */
int	sortViviendasByCalle(eVivienda* list, int len){
	int r = -1;

	if(list != NULL && len > 0){
		for(int i = 0;i < len-1;i++){
			if(list[i].idViviendas != -1){
				for(int j = i+1;j < len;j++){
					if(list[j].idViviendas != -1){

						if(strcmp(list[i].calle,list[j].calle) > 0){
							CambioBurbuja(list, i, j);
						} else {
							if(strcmp(list[i].calle,list[j].calle) == 0 && list[i].cantidadPersonas > list[j].cantidadPersonas){
									CambioBurbuja(list, i, j);
							}
						}
					}
				}
			}
		}
		r = 0;
	}
	return r;
}

/**
 * @brief muestra una lista armada previamente con todas las viviendas activas
 *
 * @param lista a ser mostrada
 * @param tamaño de la lista
 * @return 0 en cualquier caso
 */
int printVivienda(eVivienda* list, int len){

	printf("---------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|  ID\t|\t   CALLE   \t|    CANT PERSONAS\t|    CANT HABITACIONES\t|    TIPO VIVIENDA\t|     LEGAJO CENSISTA\t|\n");
	printf("|-------------------------------------------------------------------------------------------------------------------------------|\n");
	for(int i = 0;i < len;i++){
		MostrarUnaVivienda(list, i);
	}
	printf("---------------------------------------------------------------------------------------------------------------------------------\n");

	return 0;
}

/**
 * @brief hace una baja logica (idVivienda = -1)
 *
 * @param lista a utilizar
 * @param tamaño de la lista
 * @param posicion de vivienda a dar de baja
 * @return 0 si se borro; posicion si no se pudo borrar
 */
int removeVivienda(eVivienda* list, int len, int i){

	char respuesta;

	if(i != -1){
		MostrarUnaVivienda(list,i);
		do{
			printf("\nEsta seguro que quiere eliminar este vivienda? (Y/N): ");
			setbuf(stdin,NULL);
			scanf("%c",&respuesta);
		}while(!(respuesta == 'y' || respuesta == 'n'));
		if(respuesta == 'y'){
			 list[i].idViviendas = -1;
			i = 0;
		}
	}

	return i;
}

/**
 * @brief modificador de vivienda temporal, modifica la calle, cantidad de personas,
 * @brief cantidad de habitaciones y tipo de vivienda
 * @param vivienda
 * @return -1 error; 0 ok
 */
int modVivienda(eVivienda* vivienda){

	int option;
	int respuesta = 0;

	do{
		option = MenuGeneral(1, "1.Calle\n", "2.Cantidad de Personas\n", "3.Cantidad de Habitaciones\n", "4.Tipo de vivienda\n", "5.Terminar modificaciones\n", "");
		switch(option){
			case 1:
				setCalle(vivienda->calle);
				break;
			case 2:
				vivienda->cantidadPersonas = setEntero("Cantidad de personas en la vivienda");
				break;
			case 3:
				vivienda->cantidadHabitaciones = setEntero("Cantidad de habitaciones en la vivienda");
				break;
			case 4:
				setTipoVivienda(vivienda);
				break;
			case 5:
				respuesta = 1;
				option = 0;
				break;
			default:
				if(option != -1){
					printf("ERROR, numero fuera de rango de menu\n");

				}
		}
	}while(option != 0);

	return respuesta;
}

/**
 * @brief ingresa valores a la lista dada a partir de una estructura temporal (vivienda)
 *
 * @param posicion de la estructura a modificar en el array
 * @param estructura temporal
 * @param lista a donde quieres modificar datos
 * @param tamaño de la lista
 */
void modVivData(int sid,eVivienda vivienda,eVivienda* list,int len){

	if(strcmp(vivienda.calle,"") != 0){
		strcpy(list[sid].calle,vivienda.calle);
	}
	if(vivienda.cantidadHabitaciones != -1){
		list[sid].cantidadHabitaciones = vivienda.cantidadHabitaciones;

	}
	if(vivienda.cantidadPersonas != -1){
		list[sid].cantidadPersonas = vivienda.cantidadPersonas;
	}
	if(vivienda.tipoVivienda != -1){
		list[sid].tipoVivienda = vivienda.tipoVivienda;
	}

}
