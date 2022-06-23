#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Service.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los servicios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pLLService LinkedList*
 * \return int
 *
 */
#define TAM 50
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
