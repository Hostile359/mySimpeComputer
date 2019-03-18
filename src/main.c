#include "mySimpleComputer.h"

void print_log(int result);
void sc_memoryPrint();
void sc_regPrint();

int main()
{
    system("clear");

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
