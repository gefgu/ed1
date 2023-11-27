#ifndef __utils_c__
#define __utils_c__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define NOT_FOUND -1

/* */
void swap (int *A, int i, int j);

/* */
void print (int *A, int n, char *message);

/* */
int check (int *A, int n, int ascending);

#endif
