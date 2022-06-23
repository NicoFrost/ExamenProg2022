#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Service.h"
#include "parser.h"

#define TAM 50
/** \brief Parsea los datoss de los servicios desde el archivo enviado por parametro
 *
 * \param pLLService LinkedList* linkedlist en donde dejar resultados
 * \return int 0 en caso de que funcione correctamente
 * 			   -1 si los datos no se pueden escanear correctamente
 *
 */
int parser_ServiceFromText(FILE* pFile , LinkedList* pLLService)
{
	char fid[20];
	char fdescripcion[TAM];
	char ftipoServicio[TAM];
	char fprecioUnitario[TAM];
	char fcantidad[TAM];
	char fprecioTotal[TAM];
	int retorno;
	eServicios* servicioAux;

	//Lectura Fantasma
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",fid,fdescripcion,ftipoServicio,fprecioUnitario,fcantidad,fprecioTotal);


	do{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",fid,fdescripcion,ftipoServicio,fprecioUnitario,fcantidad,fprecioTotal);
		servicioAux = Servicios_newParametros(fid, fdescripcion, ftipoServicio, fprecioUnitario, fcantidad, fprecioTotal);
		retorno = ll_add(pLLService, servicioAux);
		if(retorno != 0){
			break;
		}
	}while(!feof(pFile));
	return retorno;
}
