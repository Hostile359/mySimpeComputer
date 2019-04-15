#pragma once

#include "myTerm.h"

#define REC 'a'
#define BR "j"
#define BL "m"
#define TR "k"
#define TL "l"
#define VERT "x"
#define HOR "q"

enum BigChar {
	plus_top = 4279769112,
	plus_bot = 404232447,
	one_top = 404626456,
	one_bot = 4279769112
};

int bc_printA (char *str);
int bc_box (int x1, int y1, int x2, int y2);
int bc_printbigchar(int *a, int x, int y, enum colors c1, enum colors c2);
int bc_setbigcharpos (int *big, int x, int y, int value);
int bc_getbigcharpos (int *big, int x, int y, int *value);
int bc_bigcharwrite (int fd, int *big, int count);
int bc_charread (int fd, int *big, int need_count, int *count);
