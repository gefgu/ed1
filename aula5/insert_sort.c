#include "list.h"
#include <time.h>

List *insert_sort(List *l, int k)
{
  List *node = NULL;

  if (l != NULL)
  {
    if (l->data > k)
    {
      node = (List *)malloc(sizeof(List));
      node->data = k;
      node->next = l;
      return node;
    }
    else
    {
      l->next = insert_sort(l->next, k);
    }
  }
  else
  { // primeiro da lista
    node = (List *)malloc(sizeof(List));
    node->data = k;
    node->next = l;
    return node;
  }
  return l;
}

/* */
int main()
{
  srand(time(NULL));
  List *l = NULL;
  int k, n;
  for (k = 0; k <= 10; k++)
  {
    n = rand() % 50;
    l = insert_sort(l, n);
    printf("Lista = ");
    print(l);
    printf("- Após inserir o número %d \n", n);
  }

  destroy(l);
  return 0;
}
