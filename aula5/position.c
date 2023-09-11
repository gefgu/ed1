#include "list.h"
#include <limits.h>

/* */
int position(List *l, int k)
{
  /*Terminar*/
  int val;
  if (l != NULL)
  {
    if (l->data != k)
    {
      val = position(l->next, k);
      if (val != -1)
      {
        return val + 1;
      }
      else
      {
        return -1;
      }
    }
    else
    {
      return 0;
    }
  }

  return -1;
}

/* */
int main()
{
  List *l = NULL;
  int k;
  for (k = 5; k <= 9; k++)
  {
    l = insert_back(l, k);
  }
  for (k = 4; k >= 0; k--)
  {
    l = insert_back(l, k);
  }
  printf("Lista = ");
  print(l);
  printf("\n");
  printf("Position of %d = %d\n", 9, position(l, 9));
  printf("Position of %d = %d\n", 10, position(l, 10));
  destroy(l);
  return 0;
}
