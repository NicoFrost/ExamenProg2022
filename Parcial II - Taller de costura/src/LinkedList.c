#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this= NULL;

	this = malloc(sizeof(LinkedList));
	if(this != NULL){
		this->size = 0;
		this->pFirstNode = NULL;
	}
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* nodeAux = NULL;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this) && ll_len(this) >= 0){
		for(int i = 0;i <= nodeIndex;i++){
			if(i == 0){
				nodeAux = this->pFirstNode;
			} else {
				nodeAux = nodeAux->pNextNode;
			}
		}
	}

    return nodeAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
	Node* nodeNew = NULL;
	if( this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){
		nodeNew = malloc(sizeof(Node));
		if(nodeNew != NULL){
			nodeNew->pElement = pElement;

			if(nodeIndex == 0){
				nodeNew->pNextNode = this->pFirstNode;
				this->pFirstNode = nodeNew;
			} else {
				Node* nodeAux = getNode(this, nodeIndex-1);
				nodeNew->pNextNode = nodeAux->pNextNode;
				nodeAux->pNextNode = nodeNew;
			}

			this->size += 1;
			returnAux = 0;
		}
	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{

	int returnAux = -1;
	if(this != NULL){
		returnAux = 0;
		addNode(this,ll_len(this), pElement);
	}

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >= 0 && index <= ll_len(this)){
    	Node* nodeAux = getNode(this, index);
    	if(nodeAux != NULL){
    		returnAux = nodeAux->pElement;
    	}

    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index >= 0 && index < ll_len(this)){
    	Node* nodeAux = getNode(this, index);
    	if(nodeAux != NULL){
    		returnAux = 0;
    		nodeAux->pElement = pElement;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this) >= 0){
    	Node* nodoAEliminar = getNode(this, index);
    	Node* nodoAnterior = getNode(this, index-1);
    	if(nodoAEliminar != NULL){
			if(index == 0){
				this->pFirstNode = nodoAEliminar->pNextNode;
			}else {
				if(nodoAnterior != NULL){
					nodoAnterior->pNextNode = nodoAEliminar->pNextNode;
				}
			}
				free(nodoAEliminar);
				returnAux = 0;
				this->size--;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){
		for(int i = 0;i < ll_len(this);i++){
			ll_remove(this, i);
		}
		returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){
    	ll_clear(this);
    	free(this);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL){
    	int index;
    	for(index = 0;index < ll_len(this);index++){
    		void* elementoAComparar = ll_get(this, index);
    		if(elementoAComparar == pElement){
    			returnAux = index;
    			break;
    		}
    	}
		if(index == ll_len(this)){
			returnAux = -1;
		}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){
    	returnAux = 0;
    	if(this->pFirstNode == NULL){
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index >= 0 && index <= ll_len(this) && ll_len(this) >= 0){
    	addNode(this, index, pElement);
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* returnAux = NULL;
    if(this != NULL && index >= 0 && index <= ll_len(this) && ll_len(this) > 0){
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam = ll_len(this);
    if(this != NULL && tam >= 0){
    	void* ElementAux = NULL;
    	int index;
    	for(index = 0;index <= tam;index++){
    		ElementAux = ll_get(this, index);
    		if(ElementAux == pElement){
    			returnAux = 1;
    			break;
    		}
    	}
    	if(index == tam){
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    if(this != NULL && this2 != NULL){
    	int index;
    	int nodosIdenticos = 0;
    	void* elementAuxL1;
    	void* elementAuxL2;
    	for(index = 0;index < ll_len(this);index++){
    		elementAuxL1 = ll_get(this, index);

    		for(int j = 0;j< ll_len(this2);j++){
    			elementAuxL2 = ll_get(this2, j);
				if(elementAuxL1 == elementAuxL2){
					nodosIdenticos++;
				}
    		}
    	}
    	if(ll_len(this2) == nodosIdenticos){
    		returnAux = 1;
    	} else {
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL){
    	if((from >= 0 && from <= ll_len(this)) && (to > from && to <= ll_len(this))){
			void* pElement;
			cloneArray = ll_newLinkedList();
			for(int i = from;i <= to;i++){
				pElement = ll_get(this, i);
				ll_add(cloneArray, pElement);
			}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL){
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL){
			for(int i = 0;i <= ll_len(this);i++){
				void* elementAux = ll_get(this, i);
				ll_add(cloneArray, elementAux);
			}
    	}
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
	void* pElementA;
	void* pElementB;
	int tam = ll_len(this);
    if(this != NULL && pFunc != NULL && (order == 1 || order == 0)){
		for(int i = 0 ;i < tam-1;i++){
			for(int j = i + 1;j < tam;j++){

				pElementA=ll_get(this,i);
				pElementB=ll_get(this,j);
				if(order==1)
				{
					if(pFunc(pElementA,pElementB)>=0)
					{
						ll_set(this,i,pElementB);
						ll_set(this,j,pElementA);
					}
				}
				else
				{
					if(pFunc(pElementA,pElementB)<0)
					{
						ll_set(this,i,pElementB);
						ll_set(this,j,pElementA);
					}
				}
			}
		}
    	returnAux = 0;
    }

    return returnAux;

}

LinkedList* ll_map (LinkedList* this, void* (*pFunc)(void*)){

	void* pElement;
	void* pRetornedElemnt;
	if(this != NULL && pFunc != NULL){
		for(int i = 0;i < ll_len(this);i++){
			pElement = ll_get(this, i);
			pRetornedElemnt = pFunc(pElement);
			if(pRetornedElemnt != NULL){
				ll_set(this, i, pRetornedElemnt);
			}
		}
	}

	return this;
}

LinkedList* ll_filter (LinkedList* this, int (*pFunc)(void*)){

	LinkedList* listaFiltrada = NULL;
	int contador = 0;
	if(this != NULL && pFunc != NULL){
		LinkedList* listaFiltrada = ll_newLinkedList();

		if(listaFiltrada != NULL){
			int i;
			for(i = 0;i < ll_len(this);i++){
				void* pElement = ll_get(this, i);
				if(pFunc(pElement)){
					contador++;
					if(ll_add(listaFiltrada, pElement) == -1){
						printf("ERROR en agregar elemento. INDEX = %d\n",i);
						break;
					}
				}
			}
			return listaFiltrada;
			//razon desconocida se convierte lista en NULL pasado este punto
		}
	}

	return listaFiltrada;
}
