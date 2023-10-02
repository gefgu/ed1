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
} Node;

typedef struct {
  Node *head;
  Node *tail;
} List;

/*Interface:*/
List* create ();
void insert_front (List *l, int elem);
void insert_back (List *l, int elem);
void remove_front (List *l);
void remove_back (List *l);
void remove_k (List *l, int k);
void print_head_to_tail (List *l);
void print_tail_to_head (List *l);
int middle (List *l);
void destroy (List *l);
Node* search (List *l, int k);

/*Queue:*/
void enqueue (List *l, int elem);
int dequeue (List *l);
int front (List *l);
int empty_queue (List *l);

/*Stack:*/
void push (List *l, int elem);
int pop (List *l);
int peek (List *l);
int empty_stack (List *l);

#endif
