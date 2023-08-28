#ifndef _stack_h_
#define _stack_h_
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/*Estrutura e interface para implementar 
  uma pilha com array (ou vetor):*/

#define ERROR -INT_MAX

typedef struct {
  int peek;
  int size;
  int *array;
} Stack;

/*Interface:*/
Stack *create (int size);
void destroy (Stack *s);
void push (Stack *s, int elem);
int pop (Stack *s);
int get_peek (Stack *s);
int empty (Stack *s);
int full (Stack *s);
void print (Stack *s);
int get_size (Stack *s);
#endif
