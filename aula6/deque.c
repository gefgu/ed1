#include "deque.h"

/* */
Deque *create_deque()
{
  return NULL;
}

/* */
Point get_front(Deque *d)
{
  if (d != NULL)
  {
    return d->p;
  }
}

/* */
Point get_back(Deque *d)
{
  if (d != NULL)
  {
    Deque *aux = d;
    while (aux->next != NULL)
    {
      aux = aux->next;
    }
    return aux->p;
  }
}

/* */
Deque *insert_front(Deque *d, Point p, char field[][SIZE])
{
  /*Terminar!*/
  Deque *node = (Deque *)malloc(sizeof(Deque));
  field[p.x][p.y] = '*';
  node->p = p;
  node->prev = NULL;
  node->next = d;
  if (d != NULL)
    node->prev = d;
  return node;
}

/* */
Deque *insert_back(Deque *d, Point p, char field[][SIZE])
{
  /*Terminar!*/

  Deque *t = d;
  field[p.x][p.y] = '*';
  Deque *node = (Deque *)malloc(sizeof(Deque));
  node->p = p;
  node->prev = NULL;
  node->next = NULL;
  if (d == NULL)
    return node;

  while (t->next != NULL)
  {
    t = t->next;
  }

  node->prev = t;
  t->next = node;

  return d;
}

/* */
Deque *delete_front(Deque *d, char field[][SIZE])
{
  /*Terminar!*/
  Deque *t = d;
  if (d == NULL)
    return d;
  d = d->next;
  d->prev = NULL;
  field[t->p.x][t->p.y] = ' ';
  free(t);
  return d;
}

/* */
Deque *delete_back(Deque *d, char field[][SIZE])
{
  /*Terminar!*/
  Deque *t = d;
  if (t == NULL)
    return d;

  while (t->next != NULL)
    t = t->next;

  t->prev->next = NULL;
  field[t->p.x][t->p.y] = ' ';
  free(t);
  return d;
}
