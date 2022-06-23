#include "Controller.h"
#include "Service.h"
#include "libreriaP.h"
#include "parser.h"
#include "filters.h"
#define TAM 50
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pLLService)
{
	FILE* pArchivo;
	char path[21] = " ";
		printf("ingrese nombre del archivo separado por coma (sin su extension): ");
		scanf("%s",path);
		strcat(path,".csv");
		printf("leyendo archivo: %s\n",path);
	pArchivo = fopen(path,"r");
	if(pArchivo != NULL){
		parser_ServiceFromText(pArchivo, pLLService);
	}
	fclose(pArchivo);
	return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_listService(LinkedList* pLLService)
{

	Servicios_list(pLLService);

    return 1;
}

int controller_assignTotal(LinkedList* pLLService){

	pLLService = ll_map(pLLService,Servicios_calcularPrecioTotal);
	return 1;
}

int controller_createDataFiltred(char* path,LinkedList* pLLService){
	FILE* pArchivo;
	int retorno = 0;
	int filtro;

	if(path != NULL && pLLService != NULL){
		pArchivo = fopen(path,"w");
		if(pArchivo != NULL){
			do{
				printf("ingrese tipo de servicio a Filtrar (1-MINORISTA, 2-MAYORISTA, 3-EXPORTAR)EN NUMEROS:");
				scanf("%d",&filtro);
				if(filtro != 1 && filtro != 2 && filtro != 3){
					printf("WARNING, filtro no disponible seleccione de nuevo\n");
				}
			}while(filtro < 0 || filtro > 3);
			printf("Iniciando Filtrado...\n");
			LinkedList* linkfiltred;
					switch(filtro){
					case 1:
						linkfiltred = ll_filter(pLLService, filter_porMinorista);
						break;
					case 2:
						linkfiltred = ll_filter(pLLService, filter_porMayorista);
						break;
					case 3:
						linkfiltred = ll_filter(pLLService, filter_porExportar);
						break;
					}
			if(GuardarTxt(pArchivo,linkfiltred)){
				retorno = 1;
			} else {
				printf("ERROR, no se pudo escribir el archivo\n");
			}
			fclose(pArchivo);
		} else {
			printf("ERROR, no se pudo abrir el archivo\n");
		}
	}
	return retorno;

}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortlistServices(LinkedList* pLLService)
{
	LinkedList* sortList;
	if(pLLService != NULL){
		sortList = ll_clone(pLLService);
		if(sortList != NULL){

		ll_sort(sortList,Service_sortByDescription, 1);

		Servicios_list(sortList);
		ll_deleteLinkedList(sortList);
		}
	}

    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveSortListServices(char* path , LinkedList* pLLService)
{

	int retorno = 0;
	FILE* pArchivo;
	if(path != NULL && pLLService != NULL){
		LinkedList* sortList = ll_clone(pLLService);
		ll_sort(sortList,Service_sortByDescription, 1);
		pArchivo = fopen(path,"w");
		if(pArchivo != NULL && sortList != NULL){
			if(GuardarTxt(pArchivo,sortList)){
				retorno = 1;
			} else {
				printf("ERROR, no se pudo escribir el archivo\n");
			}
			fclose(pArchivo);
		} else {
			printf("ERROR, no se pudo abrir el archivo\n");
		}
		ll_deleteLinkedList(sortList);
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */


