#include "list.h"

/**/
List *create()
{
  List *l = (List *)malloc(sizeof(List));
  l->head = NULL;
  l->tail = NULL;
  return l;
}

/**/
void insert_front(List *l, double elem)
{
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = elem;
  n->prev = NULL;
  if (l->head != NULL)
  {
    n->next = l->head;
    l->head->prev = n;
  }
  else
  {
    n->next = NULL;
    l->tail = n;
  }
  l->head = n;
}
