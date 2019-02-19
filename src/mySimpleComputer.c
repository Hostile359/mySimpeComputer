#include "mySimpleComputer.h"

int sc_memoryInit()
{
	for (int i = 0; i < N; i++){
		if (&arr[i] == NULL) return ERROR;
		arr[i] = 0;
	}
	return OK;
}

int sc_memorySet(int adress, int value)
{
	if (adress >= N || adress < 0)
		return ERROR;
	else
		arr[adress] = value;
		
	return OK;
}

int sc_memoryGet(int adress, int *value)
{
	if (adress >= N || adress < 0)
		return ERROR;
	else
		*value = arr[adress];
		
	return OK;
}

