#include "myBigChars.h"

int bc_printA(char *str)
{
	printf("\E(0%s\E(B", str);
	return 0;
}

int bc_box(int x1, int y1, int x2, int y2)
{
	int x, y;
	int i;
	int size_x = x1 + x2 - 1;
	int size_y = y1 + y2 - 1;
	
	mt_getscreensize(&x, &y);
	if ((x1 < 1) || (y1 < 1) || (x2 <= 0) || (y2 <= 0) || (size_x > x) 
	  || (size_y > y))
		return -1;
	mt_gotoXY(x1, y1);
	bc_printA(TL);
	for (i = y1 + 1; i < size_y; i++)
		bc_printA(HOR);
	bc_printA(TR);
	for (i = x1 + 1; i < size_x; i++) {
		mt_gotoXY(i, y1);
		bc_printA(VERT);
		mt_gotoXY(i, size_y);
		bc_printA(VERT);
	}
	mt_gotoXY(size_x, y1);
	bc_printA(BL);
	for (i = y1 + 1; i < size_y; i++)
		bc_printA(HOR);
	bc_printA(BR);
	return 0;
}

int bc_printbigchar(int *a, int x, int y, enum colors c1, enum colors c2)
{
	int xs, ys;
	int index, bit;
	int i, j;
	char row[9];
	
	mt_getscreensize(&xs, &ys);
	if ((x < 1) || (y < 1) || (x + 8 > xs) || (y + 8 > ys))
		return -1;
	row[8] = '\0';
	mt_ssetfgcolor(c1);
	mt_ssetbgcolor(c2);
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			index = i >> 2;
			bit = (a[index] >> ((i % 4) * 8 + j)) & 1;
			if (bit == 0)
				row[j] = ' ';
			else
				row[j] = REC;
		}
		mt_gotoXY(x + i, y);
		bc_printA(row);
	}
	mt_ssetfgcolor(white);
	mt_ssetbgcolor(black);
	return 0;
}

int bc_setbigcharpos (int *big, int x, int y, int value)
{
	int index;
	//printf("\n%d %d %d", x, y, value);
	if ((x < 1) || (y < 1) || (x > 8) || (y > 8) || ((value != 0) && (value != 1)) )
		return -1;
		
	if (x > 4) {
		x -= 5;
		index = 1;
	}else {
		x -= 1;
		index = 0;
	}
	int k = x * 8 + y;
	
	value = value << (k - 1);
	//printf(" %d %d [%d] %d\n\n", k, value, index, big[index] );
	//big[index] &= value;// (~big[index] || big[index]) && value;
	//printf("\n%d\n\n", big[index]);
	
	if (value != 0)
		big[index] |= value;
	else 
		big[index] &= ~((value + 1) << (k - 1));
	printf("\n%d\n\n", big[index]);
	return 0;
} 
	