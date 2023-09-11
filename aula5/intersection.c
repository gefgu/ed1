#include "list.h"

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
List *intersect(List *A, List *B)
{
  /*Terminar*/
  List *node = NULL;
  if (A != NULL)
  {
    if (in(B, A->data))
    {
      node = (List *)malloc(sizeof(List));
      node->data = A->data;
      node->next = intersect(A->next, B);
      return node;
    }
    else
    {
      return intersect(A->next, B);
    }
  }
}

/* */
int main()
{
  int k;
  List *A = NULL, *B = NULL;
  for (k = 0; k <= 30; k += 5)
    A = insert_back(A, k);
  for (k = 0; k <= 30; k += 3)
    B = insert_back(B, k);

  printf("Lista = ");
  print(A);
  printf("\n");

  printf("Lista = ");
  print(B);
  printf("\n");

  List *C = intersect(A, B);

  printf("Lista = ");
  print(C);
  printf("\n");

  destroy(A);
  destroy(B);
  destroy(C);
  return 0;
}