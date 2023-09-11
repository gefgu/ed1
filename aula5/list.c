#include "list.h"

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
  if (l != NULL)
  {
    if (l->data == k)
    {
      if (l->next != NULL)
      {
        l->data = l->next->data;
        l->next = l->next->next;
      }
      else
      {
        l = NULL;
        free(l);
      }
    }
    else
    {
      removek(l->next, k);
    }
  }
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
