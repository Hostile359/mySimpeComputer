#include "mySimpleComputer.h"

void check_err(int check)
{
	if (check == ERROR)
		printf("ERROR: array out of order\n");
}

int main()
{
	int check;
	check = sc_memoryInit();
	check_err(check);
		
	int index, val;
	printf("Enter index: ");
	scanf("%d", &index);
	
	printf("Enter number: ");
	scanf("%d", &val);
	
	check = sc_memorySet(index, val);
	check_err(check);
	
	check = sc_memoryGet(0, &val);
	check_err(check);
	
	printf("%d \n", val);
	
	return 0;
}
	
