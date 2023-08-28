#ifndef _dqueue_h_
#define _dqueue_h_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*Estrutura e interface para implementar um fila circular:*/

#define ERROR -INT_MAX

typedef struct
{
  int front;
  int back;
  int size;
  double *array;
} Queue;

/*Interface:*/
Queue *create(int size);
void destroy(Queue *q);
void enqueue(Queue *q, double elem);
double dequeue(Queue *q);
double front(Queue *q);
int empty(Queue *q);
int full(Queue *q);
void print(Queue *q);
int getsize(Queue *q);
int search(Queue *q, double e);
#endif
