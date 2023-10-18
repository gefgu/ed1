#ifndef __utils_c__
#define __utils_c__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

/* */
void swap (int *A, int i, int j);

/* */
void swap_string (char **A, int i, int j);

/* */
void print (int *A, int n, char *message);

/* */
int check (int *A, int n, int ascending);

#endif
