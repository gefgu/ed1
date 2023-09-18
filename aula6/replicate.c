#include "list.h"

List *replicate(List *l, int k)
{
  /*Terminar!*/
  List *t;
  List *node;
  int i;
  for (t = l; t != NULL; t = t->next)
  {
    for (i = 1; i < k; i++)
    {
      node = (List *)malloc(sizeof(List));
      node->data = t->data;
      node->next = t;
      node->prev = t->prev;
      if (t->prev != NULL)
        t->prev->next = node;
      t->prev = node;
    }
  }
  while (l->prev != NULL)
    l = l->prev;
  return l;
}

int main()
{
  int i;
  int k = 3;
  int n = 4;
  List *l = create();
  for (i = n; i >= 1; i--)
  {
    l = insert_front(l, i);
  }
  print(l);
  l = replicate(l, k);
  print(l);
  destroy(l);
  return 0;
}
