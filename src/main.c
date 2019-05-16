#include "func.h"


int main()
{
	tcgetattr(STDIN_FILENO, &termios_default);
	sc_memoryInit();
	sc_regInit();
	index = 0;
	accumulator = 0;
	value[0] = 0;
	value[1] = 0;
	value[2] = 0;
	value[3] = 0;
	value[4] = 0;
	sc_regSet(IG, 1);
	//value[3] = 1;
	//sc_regSet(UC, 1);
	/*for(int i = 0; i < 5; i++)
		printf("%d ", value[i]);
	printf("\n ");
	//value[5] = { 0 };
	sc_regSet(IG, 1);
	sc_regGet(OV, &value[0]);
    sc_regGet(D0, &value[1]);
    sc_regGet(OM, &value[2]);
    sc_regGet(IG, &value[3]);
    sc_regGet(UC, &value[4]);
    for(int i = 0; i < 5; i++)
		printf("%d ", value[i]);
	sc_regPrint();
	pause();*/
    enum keys choose;
    //int check = 0;
    while(1) {
		print_term();
		//check = 
		//fflush(stdin);
		rk_readkey(&choose);
		//printf("%d\n", check);
		if(choose == -2)
			break;
		do_command(choose);
	}
	printf("Goodbye!!!\n\n");
//	rk_mytermrergtime(1, 0, 0, 0, 0);
    return 0;
}
