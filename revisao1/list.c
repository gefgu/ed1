// AULA 5

#include "list.h"

List *create()
{
  return NULL;
}

/* */
List *insert_back(List *l, int k)
{
  if (l == NULL)
  {
    l = (Node *)malloc(sizeof(Node));
    l->data = k;
    l->next = NULL;
  }
  else
  {
    l->next = insert_back(l->next, k);
  }
  return l;
}

/* */
List *removek(List *l, int k)
{
  /*Terminar*/
  List *n;
  if (l != NULL)
  {
    n = l->next;

    // Caso seja na cabeça
    if (l->data == k)
    {
      free(l);
      return n;
    }
    else if (n != NULL && n->data == k)
    {
      l->next = n->next;
      free(n);
    }
    else
    {
      removek(l->next, k);
    }
  }
  return l;
}

List *remove_all(List *l, int k)
{
  /*Terminar*/
  List *n;
  if (l != NULL)
  {
    n = l->next;

    // Caso seja na cabeça
    if (l->data == k)
    {
      free(l);
      n = remove_all(n, k);
      return n;
    }
    else if (n != NULL && n->data == k)
    {
      l->next = n->next;
      free(n);
      l->next = remove_all(l->next, k);
    }
    else
    {
      remove_all(l->next, k);
    }
  }
  return l;
}

/* */
void print(List *l)
{
  if (l != NULL)
  {
    printf("%d ", l->data);
    print(l->next);
  }
}

/* */
void destroy(List *l)
{
  /*Terminar*/
  if (l != NULL)
  {
    destroy(l->next);
    free(l);
  }
}