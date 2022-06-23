#include "Controller.h"
#include "Service.h"
#include "libreriaP.h"
#include "parser.h"
#include "filters.h"
#define TAM 50

/** \brief Carga los datos desde un archivo el cual es pedido al principio.
 *
 * \param LinkedList* pLLService
 * \return int 0 si funciona correctamente.
 * 			  (-1) si la lista es NULL o si los datos no son cargados correctamente
 * 			  o no se puede abrir el archivo o no se encontro
 *
 */
int controller_loadFromText(LinkedList* pLLService)
{
	FILE* pArchivo;
	int retorno = -1;
	char path[21] = " ";
		printf("ingrese nombre del archivo separado por coma (sin su extension): ");
		scanf("%s",path);
		strcat(path,".csv");
		printf("\nleyendo archivo: %s\n",path);
	pArchivo = fopen(path,"r");
	if(pArchivo != NULL){
		retorno = parser_ServiceFromText(pArchivo, pLLService);
		if(retorno != -1){
			printf("\nDatos cargados correctamente!\n");
		}
	} else {
		printf("ERROR, no se pudo abrir achivo o no se encontro\n");
		retorno = -1;
	}
	fclose(pArchivo);
	return retorno;
}

/** \brief Listar servicio
 *
 * \param pLLService LinkedList*
 * \return int
 *
 */
int controller_listService(LinkedList* pLLService)
{

	Servicios_list(pLLService);

    return 0;
}

/**
 * \brief asigna totales a los elementos de la lista con la funcion ll_map, pasada por parametro
 * \param pLLService LinkedList
 * \return 0 si funciona correctamente -1 si la lista pasada es NULL o el mapeo sale mal
 */
int controller_assignTotal(LinkedList* pLLService){

	int retorno = -1;
	if(pLLService != NULL){
		pLLService = ll_map(pLLService,Servicios_calcularPrecioTotal);
		if(pLLService != NULL){
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * @brief crea un archivo de datos con el nombre pasado por parametro y con los datos filtrados
 * @param path nombre del nuevo archivo
 * @param pLLService linkedlist
 * @return retorna 0 si funciona correctamente
 * 					o -1 si la linkedlist es NULL
 * 					o la apertura  del archivo sale mal o el filtrado no se hace correctamente
 */
int controller_createDataFiltred(char* path,LinkedList* pLLService){
	FILE* pArchivo;
	int retorno = -1;
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
				retorno = 0;
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
 * \param pLLService LinkedList*
 * \return int retorna 0 si funciona correctamente
 * 					   -1 si la lista pasada por parametro es NULL
 * 					   	o si la lista clonada se crea mal
 * 					   	o si el ordenamiento tira un ERROR
 *
 */
int controller_sortlistServices(LinkedList* pLLService)
{
	LinkedList* sortList;
	int retorno = -1;
	if(pLLService != NULL){
		sortList = ll_clone(pLLService);
		if(sortList != NULL){
			if(ll_sort(sortList,Service_sortByDescription, 1) != -1){

				Servicios_list(sortList);
				ll_deleteLinkedList(sortList);

				retorno = 0;
			}
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los servicios en el archivo con el nombre pasado por parametro.
 *
 * \param path char* nombre del archivo
 * \param pLLService LinkedList
 * \return int retorna 0 si funciona correctamente
 * 					  -1 si la lista es NULL
 * 					   o si el ordenamiento tira ERROR(-1)
 *
 */
int controller_saveSortListServices(char* path , LinkedList* pLLService)
{

	int retorno = -1;
	FILE* pArchivo;
	if(path != NULL && pLLService != NULL){
		LinkedList* sortList = ll_clone(pLLService);
		ll_sort(sortList,Service_sortByDescription, 1);
		pArchivo = fopen(path,"w");
		if(pArchivo != NULL && sortList != NULL){
			if(GuardarTxt(pArchivo,sortList)){
				retorno = 0;
			} else {
				printf("ERROR, no se pudo escribir el archivo\n");
			}
			fclose(pArchivo);
		} else {
			printf("ERROR, no se pudo abrir el archivo\n");
		}
		ll_deleteLinkedList(sortList);
		if(sortList == NULL){
			retorno = 0;
		}
	}
	return retorno;
}


