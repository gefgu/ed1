#include "list.h"

/* */
int similar(List *A, List *B)
{
  /*Terminar*/
  int igual;
  if (A != NULL && B != NULL)
  {
    igual = (A->data == B->data);
    return igual && similar(A->next, B->next);
  }
  return 0; // Um é nulo e o outro não
}

/* */
int main()
{
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2)
    A = insert(A, k);
  for (k = 10; k >= 2; k -= 2)
    B = insert(B, k);
  print(A);
  print(B);
  printf("%d\n", similar(A, B));
  destroy(A);
  destroy(B);
  return 0;
}