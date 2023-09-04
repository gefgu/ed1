#ifndef _list_h_
#define _list_h_

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ERROR -INT_MAX
#define TRUE 1
#define FALSE 0

/*Structures*/

typedef struct {
  int c; /*coefficient*/
  int d; /*degree*/
} poly;

typedef struct node { 
  poly p;
  struct node *next;
} List;

/*Interface:*/
List* create ();
void print (List *l);
void destroy (List *l);
List* insert (List *l, poly p);

#endif
