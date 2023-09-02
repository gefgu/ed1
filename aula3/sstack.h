#ifndef _sstack_h_
#define _sstack_h_
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/*Estrutura e interface para implementar
  uma pilha com array (ou vetor):*/

#define ERROR "-1"
#define STRING_MAX 50

typedef struct
{
  int peek;
  int size;
  char **array;
} Stack;

/*Interface:*/
Stack *create(int size);
void destroy(Stack *s);
void push(Stack *s, char *elem);
const char *pop(Stack *s);
const char *get_peek(Stack *s);
int empty(Stack *s);
int full(Stack *s);
void print(Stack *s);
int get_size(Stack *s);
#endif
