#include "mySimpleComputer.h"
#include "myBigChars.h"
#include "myReadkey.h"

#include <math.h>
#include <signal.h>
#include <sys/time.h>

int index;
int value[5];
int accumulator;
struct termios termios_default;
struct itimerval nval, oval;

void print_term();
void print_big(int a);
int *get_big(int a);
void do_command(enum keys k);
void inst_counter();
void _reset();
int ALU (int command, int operand);
void CU ();
