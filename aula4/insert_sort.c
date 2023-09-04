#include "list.h"
#include <time.h>

/* */
List *insert_sort(List *l, int k)
{
  List *t = l;
  List *node = (List *)malloc(sizeof(List));
  node->data = k;
  node->next = NULL;
  if (t == NULL)
  {
    return node;
  }
  if (t->next == NULL || t->data > k)
  {
    if (t->data < k)
    {
      t->next = node;
      return t;
    }
    else
    {
      node->next = t;
      return node;
    }
  }
  while (t->next != NULL && t->next->data < k)
  {
    t = t->next;
  }

  node->next = t->next;
  t->next = node;

  return l;
}

/* */
int main()
{
  srand(time(NULL));
  int i, n;
  List *A = create();
  for (i = 0; i < 10; i++)
  {
    n = rand() % 50;
    printf("Num %d - ", n);
    A = insert_sort(A, n);
    print(A);
  }

  destroy(A);

  return 0;
}
