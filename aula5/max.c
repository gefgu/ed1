#include "list.h"

int _max(int a, int b)
{
  if (a >= b)
  {
    return a;
  }
  return b;
}

/* */
int max(List *l)
{
  /*Terminar.*/
  if (l != NULL)
  {
    return _max(l->data, max(l->next));
  }
  return 0;
}

/* */
int main()
{
  srand(time(NULL));
  List *l = NULL;
  int k;
  for (k = 0; k <= 9; k++)
  {
    l = insert_back(l, rand() % 50);
  }
  printf("Lista = ");
  print(l);
  printf("\n");
  printf("Max = %d\n", max(l));
  destroy(l);
  return 0;
}
