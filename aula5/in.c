#include "list.h"
#include <limits.h>

/* */
int in(List *l, int k)
{
  /*Terminar.*/
  if (l != NULL)
  {
    if (l->data == k)
      return 1;
    return in(l->next, k);
  }
  return 0;
}

/* */
int main()
{
  List *l = NULL;
  int k;
  for (k = 0; k <= 5; k++)
  {
    l = insert_back(l, k);
  }
  printf("Lista = ");
  print(l);
  printf("\n");
  printf("In = %d\n", in(l, 3));
  printf("In = %d\n", in(l, 6));
  destroy(l);
  return 0;
}
