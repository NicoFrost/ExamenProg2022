#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

int controller_loadFromText(LinkedList* pLLService);
int controller_listService(LinkedList* pLLService);
int controller_assignTotal(LinkedList* pLLService);
int controller_createDataFiltred(char* path,LinkedList* pLLService);
int controller_sortlistServices(LinkedList* pLLService);
int controller_saveSortListServices(char* path , LinkedList* pLLService);


