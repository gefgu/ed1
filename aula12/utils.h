#ifndef __utils_c__
#define __utils_c__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

/* */
typedef struct point {
  int x, y;
} Points;

void swap (int *A, int i, int j);
void swap_char (char *A, int i, int j);
void swap_string (char **A, int i, int j);
void print (int *A, int n, char *message);
void print_char (char *A, int n, char *message);
void partition_print (int *A, int left, int right, int rlevel);
int check (int *A, int n, int ascending);
void print_points (Points P[], int n);
double min (double a, double b);
double eucledian_distance (Points p1, Points p2);
double find_minimum_distance (Points P[], int l, int r);

#endif
