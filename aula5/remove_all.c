#include "list.h"

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
  for (k = 0; k <= 9; k++)
  {
    l = insert_back(l, k);
  }
  printf("Lista = ");
  print(l);
  printf("\n");

  l = remove_all(l, 5);
  printf("Lista = ");
  print(l);
  printf("\n");

  l = remove_all(l, 3);
  printf("Lista = ");
  print(l);
  printf("\n");

  l = remove_all(l, 0);
  printf("Lista = ");
  print(l);
  printf("\n");

  destroy(l);
  return 0;
}
