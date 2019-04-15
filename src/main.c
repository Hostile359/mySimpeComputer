#include "mySimpleComputer.h"
#include "myBigChars.h"

void print_log(int result);
void sc_memoryPrint();
void sc_regPrint();
void print_term();

int main()
{
	/*printf("Choose lab: ");
	int a;
	scanf("%d", &a);
	
	if (a == 1) {

		int result = 0, value = 0, command = 0, operand = 0;

		printf("Инициализация массива\n\n");
		sc_memoryInit();
		sc_memoryPrint();

		printf("Инициализация регистра\n\n");
		sc_regInit();
		sc_regPrint();


		printf("Установка значения в заданной ячейке\n");
		printf("118 в 3\n");
		result = sc_memorySet(3, 118);
		print_log(result);
		sc_memoryPrint();
		sc_regPrint();
		sc_regInit();
		printf("14 в 1\n");
		result = sc_memorySet(1, 14);
		print_log(result);
		sc_memoryPrint();
		sc_regPrint();


		printf("\nОчистка регистра\n\n");
		sc_regInit();
		sc_regPrint();


		printf("Чтение значения из заданной ячейки\n");
		printf("Из 3\n");
		result = sc_memoryGet(3, &value);
		print_log(result);
		sc_memoryPrint();
		sc_regPrint();
		printf("Value: %d\n\n", value);

		printf("Очистка регистра\n\n");
		sc_regInit();
		sc_regPrint();


		printf("Запись в файл(\"resources/output.bin\")\n");
		result = sc_memorySave("resources/output.bin");
		print_log(result);


		printf("Очистка памяти\n\n");
		sc_memoryInit();
		sc_memoryPrint();


		printf("Чтение из файла(\"resources/input.bin\")\n");
		result = sc_memoryLoad("resources/output.bin");
		print_log(result);
		sc_memoryPrint();


		printf("Запись в регистр(1, 1)\n");
		result = sc_regSet(1, 1);
		print_log(result);
		sc_regPrint();


		printf("Чтение из регистра (1)\n");
		result = sc_regGet(1, &value);
		print_log(result);
		printf("Значение: %d\n\n", value);

		printf("Очистка регистра\n\n");
		sc_regInit();
		sc_regPrint();


		printf("Кодирование(0x20, 0x13)\n");
		result = sc_commandEncode(0x20, 0x13, &value);
		print_log(result);
		printf("Число: %d\n\n", value);


		printf("Декодирование\n");
		result = sc_commandDecode(&command, &operand, value);
		print_log(result);
		printf("Число: %d\tКоманда: 0x%x\tОперанд: 0x%x\n\n", value, command, operand);
	}else {
		print_term();
		while (a != 0) {
			printf("   1-Отчистить терминал, 2-перенести курсор, 3-вывести размер экрана, 4-поменять цвет символов, 5-поменять фон,6-вывести терминал заново\n\n");
			scanf("%d", &a);
			if (a == 1)
				mt_clrscr();
			else if(a == 2) {
				printf("введите x и y: ");
				int x,y;
				scanf("%d", &x);
				scanf("%d", &y);
				mt_gotoXY(x, y);
			}else if(a == 3) {
				int rows, cols;
				mt_getscreensize(&rows, &cols);
				printf("  Строки: %d, Столбцы: %d\n\n", rows, cols);
			}else if(a == 4 || a == 5) {
				printf("Выберите цвет: \n");
				printf("0-Black, 1-Red, 2-Green, 3-Yellow, 4-Blue, 5-Purple, 6-Cyan, 7-White\n");
				int col;
				scanf("%d", &col);
				if (a == 4)
					mt_ssetfgcolor(col);
				else
					mt_ssetbgcolor(col);
			}else if(a == 6)
				print_term();
		}
	}*/
	system ("clear");
	//mt_gotoXY(2, 5);
	//printf("Успешно!\n\n");
	/*int x = 1, y = 1;
	//bc_box(x, y, 6, 8);
	int n[2];
	n[1] = 471999010;
	n[0] = 572662300;
	bc_printbigchar(n, x, y, red, green);
	int check = bc_setbigcharpos (n, 8, 6, 0);
	if (check == 0) {
		x = 15;
		bc_printbigchar(n, x, y, red, green);
    }
    int v;
    bc_getbigcharpos (n, 1, 1, &v);
    printf("\n\n %d \n", v);*/
    print_term();
    return 0;
}

void print_log(int result)
{
    if (result == OK)
        printf("Успешно!\n\n");
    else if (result == ERROR)
        printf("Ошибка!\n\n");
    else
        printf("Неверное значение!\n\n");

    return;
}

void sc_memoryPrint()
{
    printf("Память: ");

    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);

    printf("\n\n\n");

    return;
}

void sc_regPrint()
{
    printf("Регистр флагов: %d\n\n", flag);
}

void print_term()
{
	sc_memoryInit();
	sc_regInit();
	bc_box(1, 1, 12, 63);//ячейки
	mt_gotoXY(1, 27);
	printf("Memory");
	mt_gotoXY(2, 2);
    for (int i = 0; i < 10; i++)
    {
		mt_gotoXY(i + 2, 2);
        for (int j = 0; j < 10; j++)
        {
            printf(" +%.4d", arr[i * 10 + j]);
        }
        //printf("\n");
    }
    //printf("\n");
	
	bc_box(1, 64, 3, 22);//правая таб 1
	mt_gotoXY(1, 69);
    printf("accumulator");
    mt_gotoXY(2, 70);
    printf("+9999");
    
    bc_box(4, 64, 3, 22);//правая таб 2
    mt_gotoXY(4, 66);
    printf("instructionCounter");
    mt_gotoXY(5, 70);
    printf("+0000");
    
    bc_box(7, 64, 3, 22);//правая таб 3
    mt_gotoXY(7, 69);
    printf("Operation");
    mt_gotoXY(8, 70);
    printf("+00 : 00");
    
	bc_box(10, 64, 3, 22);//правая таб 4
	mt_gotoXY(10, 69);
    printf("Flags");
    mt_gotoXY(11, 70);
    printf("O E V M");
    //printf("%x", flag);
    
    int bc[2];
	bc_box(13, 1, 10, 52);//big char
	bc[0] = plus_top;
	bc[1] = plus_bot;
    mt_gotoXY(14, 2);
    bc_printbigchar(bc, 14, 3, red, green);
    bc[0] = one_top;
	bc[1] = one_bot;
 
    bc_printbigchar(bc, 14, 13, red, green);

    bc_printbigchar(bc, 14, 23, red, green);

    bc_printbigchar(bc, 14, 33, red, green);
    
    bc_printbigchar(bc, 14, 43, red, green);
    
    bc_box(13, 53, 10, 33);//таблица keys
    mt_gotoXY(13, 55);
    printf("Keys:");
    mt_gotoXY(14, 54);
    printf("l  - load");
    mt_gotoXY(15, 54);
    printf("s  - save");
    mt_gotoXY(16, 54);
    printf("r  - run");
    mt_gotoXY(17, 54);
    printf("t  - step");
    mt_gotoXY(18, 54);
    printf("i  - reset");
    mt_gotoXY(19, 54);
    printf("F5 - accumulator");
    mt_gotoXY(20, 54);
    printf("F6 - instructionCounter");
    
    mt_gotoXY(24, 1);
    printf("Input\\Output:\n\n\n");
}
 
