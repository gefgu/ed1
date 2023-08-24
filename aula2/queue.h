#ifndef _queue_h_
#define _queue_h_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*Estrutura e interface para implementar um fila circular:*/

#define ERROR -INT_MAX

typedef struct {
  int front;
  int back;
  int size;
  int *array;
} Queue;

/*Interface:*/
Queue *create (int size);
void destroy (Queue *q);
void enqueue (Queue *q, int elem);
int dequeue (Queue *q);
int front (Queue *q);
int empty (Queue *q);
int full (Queue *q);
void print (Queue *q);
int getsize (Queue *q);
int search (Queue *q, int e);
#endif
