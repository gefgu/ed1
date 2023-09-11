#include "list.h"

/* */
List *copy(List *l)
{
  List *node = NULL;
  if (l != NULL)
  {
    node = (List *)malloc(sizeof(List));
    node->data = l->data;
    node->next = copy(l->next);
  }
  return node;
}

/* */
int main()
{
  int k;
  List *A = NULL;
  for (k = 10; k >= 0; k -= 2)
    A = insert_back(A, k);

  printf("Lista = ");
  print(A);
  printf("\n");

  List *B = copy(A);
  printf("Lista Copiada = ");
  print(B);
  printf("\n");
  destroy(A);
  printf("Lista Copiada após destruição de A = ");
  print(B);
  printf("\n");
  return 0;
}