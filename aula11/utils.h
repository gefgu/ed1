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
void swap_char (char *A, int i, int j);

/* */
void swap_string (char **A, int i, int j);

/* */
void print (int *A, int n, char *message);

/* */
void print_char (char *A, int n, char *message);

/* */
void partition_print (int *A, int left, int right, int rlevel);

/* */
int check (int *A, int n, int ascending);

#endif
