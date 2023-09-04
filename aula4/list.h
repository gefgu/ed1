#ifndef _list_h_
#define _list_h_

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ERROR -INT_MAX
#define TRUE 1
#define FALSE 0

/*Structure*/
typedef struct node { 
  int data;
  struct node *next;
} List;

/*Interface:*/
List* create ();
void print (List *l);
void destroy (List *l);
List* insert (List *l, int elem);
List* insert_back (List *l, int elem);
List* removek (List *l, int elem);
List* search (List *l, int k);

#endif
