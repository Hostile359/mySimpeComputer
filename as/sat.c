#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100];
char sa_file[50];
char o_file[50];
int arr[100];

int lex(int i)
{
	char *tok;
	tok = strtok(str, " ");
	//printf("%d\n", atoi(tok));
	if (atoi(tok) != i)
		return -1;

	tok = strtok(NULL, " ");
	if (strcmp(tok, "READ") == 0)
			arr[i] = 0x10;
	else if (strcmp(tok, "WRITE") == 0)
			arr[i] = 0x11;
	else
		return -1;

	printf("%s\n", tok);
	tok = strtok(NULL, " ");
	printf("%d\n", atoi(tok));
	tok = strtok(NULL, " ");
	printf("%s\n", tok);
	
	tok = strtok(NULL, " ");
	if (tok == NULL)
		printf("EOF\n");
	return 0;
}
int main(int argc, const char *argv[]) 
{
	if(argc != 3) {
		printf("Wrong number of arguments\n");
		return 0;
	}
	strcpy(sa_file, argv[1]);
	strcpy(o_file, argv[2]);
	FILE *f;
	f = fopen(sa_file, "r");
	int i = 0;
	if(f != NULL) {
		//for (int i = 0; i < MAX_VAR_COUNT; i++) 
			//vars[i].name[0] = '\0';
		for (int j = 0; j < 100; j++)
			arr[j] = 0;
		while(fgets(str, 100, f) != NULL) {
			if(lex(i) == -1) {
				printf("Syntax error: %d str\n", i);
				break;
			}
			i++;
		}
	} else
		printf("Could't open file!\n");
	fclose(f);
	for (int i = 0; i < 100; i++)
        printf("%x ", arr[i]);

    printf("\n\n\n");
	return 0;
}
