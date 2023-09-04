#include "list.h"

/* */
List *merge(List *A, List *B)
{
  /*Terminar*/
  List *start = NULL;
  List *t = NULL;
  if (A->data >= B->data)
  {
    start = B;
    B = B->next;
  }
  else
  {
    start = A;
    A = A->next;
  }
  t = start;

  while (A != NULL || B != NULL)
  {
    if (A == NULL || B->data <= A->data)
    {
      t->next = B;
      B = B->next;
      t = t->next;
    }
    else if (B == NULL || A->data < B->data)
    {
      t->next = A;
      A = A->next;
      t = t->next;
    }
  }

  return start;
}

/* */
int main()
{
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2)
    A = insert(A, k);
  for (k = 19; k >= 0; k -= 2)
    B = insert(B, k);
  print(A);
  print(B);
  List *C = merge(A, B);
  print(C);
  destroy(C);
  return 0;
}
