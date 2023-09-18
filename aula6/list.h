#ifndef _list_h_
#define _list_h_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ERROR -INT_MAX

/*Structure*/
typedef struct node { 
  int data;
  struct node *next;
  struct node *prev;
} List;

/*Interface:*/
List* create ();
List* insert_front (List *l, int elem);
List* insert_back (List *l, int elem);
List* remove_queue (List *l, int elem);
void print (List *l);
void destroy (List *l);
List* search (List *l, int k);

#endif
