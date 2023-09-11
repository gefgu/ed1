#include "list.h"

/* */
void print_reverse(List *l)
{
  /*Terminar.*/
  if (l != NULL)
  {
    print_reverse(l->next);
    printf("%d ", l->data);
  }
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

  printf("Lista Revertida = ");
  print_reverse(l);
  printf("\n");

  destroy(l);
  return 0;
}
