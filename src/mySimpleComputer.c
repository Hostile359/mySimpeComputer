#include "mySimpleComputer.h"

int commands[NC] = { 10, 11, 20, 21, 30, 31, 32, 33, 40, 41, 42,
	43, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,
	67, 68, 69, 70, 71, 72, 73, 74, 75, 76 };

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
	if (adress >= N || adress < 0) {
		sc_regSet(OM, 1);
		return ERROR;
	}
	else
		arr[adress] = value;
		
	return OK;
}

int sc_memoryGet(int adress, int *value)
{
	if (adress >= N || adress < 0) {
		sc_regSet(OM, 1);
		return ERROR;
	}
	else
		*value = arr[adress];
		
	return OK;
}


int sc_memorySave(char *filename)
{
	FILE *file = fopen(filename, "wb");
	
	if (!file) {
		printf("File not open!\n");
		return ERROR;
	}
	
	fwrite(arr, sizeof(int), N, file);
	fclose(file);
	return OK;
}

int sc_memoryLoad(char *filename)
{
	FILE *file = fopen(filename, "rb");
	
	if (!file) {
		printf("File not open!\n");
		return ERROR;
	}
	
	fread(arr, sizeof(int), N, file);
	fclose(file);
	return OK;
}

int sc_regInit(void)
{
	flag = 0;
	return OK;
}

int sc_regSet(int registr, int value)
{
	if (registr < 0 || registr > 4)
		return ERROR;
		
	if(value == 1) {
		value <<= registr;
		flag |= value;
	}else if (value == 0) {
		value = 1;
		value <<= registr;
		value = ~value;
		flag &= value;
	}else
		return ERROR;
		
	return OK;
}

int sc_regGet(int registr, int *value)
{
	if (registr < 0 || registr > 4)
		return ERROR;
	
	*value = flag >> registr;
	
	return OK;
}

int sc_commandEncode(int command, int operand, int *value)
{
	if (*value >> 14 != 0)
		return ERROR;
	int i;
	for (i = 0; i < NC; i++) {
		if (command == commands[i])	break;
	}
	
	if (i == NC) {
		sc_regSet(UC, 1);
		return ERROR;	
	}
	
	command <<= 7;
	command |= operand;
	*value = command;
	
	return OK;
}

int sc_commandDecode(int *command, int *operand, int value)
{
	if (value >> 14 != 0)
		return ERROR;
		
	int temp_command, i;
	temp_command = (value >> 7) & 127;
	
	for (i = 0; i < NC; i++) {
		if (temp_command == commands[i]) break;
	}
	
	if (i == NC) {
		sc_regSet(UC, 1);
		return ERROR;
	}
	
	*command = temp_command;
	*operand = value & 127;

	return OK;	
}
