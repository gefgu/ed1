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
Queue *create_queue (int size);
void destroy_queue (Queue *q);
void enqueue (Queue *q, int elem);
int dequeue (Queue *q);
int front (Queue *q);
int empty_queue (Queue *q);
int full_queue (Queue *q);
void print_queue (Queue *q);
int getsize_queue (Queue *q);
#endif
