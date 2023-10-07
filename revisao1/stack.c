#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
} Stack;

Stack *push(Stack *l, int elem)
{
  Stack *node = (Stack *)malloc(sizeof(Stack));
  node->data = elem;
  node->prev = NULL;
  node->next = l;
  if (l != NULL)
    l->prev = node;
  return node;
}

Stack *pop(Stack *l)
{
  if (l != NULL)
  {
    Stack *node = l->next;
    if (node != NULL)
    {
      node->prev = NULL;
      free(l);
      return node;
    }
    else
    {
      free(l);
      return NULL;
    }
  }
}

int peek(Stack *l)
{
  if (!empty(l))
    return l->data;
}

int empty(Stack *l)
{
  return l == NULL;
}