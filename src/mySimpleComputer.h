#include <stdio.h>
#include <stdlib.h>

enum{
	OK = 1,
	ERROR = -1,
	N = 100
};

int arr[N];

int sc_memoryInit();

int sc_memorySet(int adress, int value);

int sc_memoryGet(int adress, int *value);

int sc_memorySave(char *filename);

int sc_memoryLoad(char * filename);

int sc_regInit(void);

int sc_regSet(int registr, int value);

int sc_regGet(int registr, int *value);

int sc_commandEncode(int command, int operand, int *value);

int sc_commandDecode(int *command, int *operand, int value);
