#include "list.h"

/* */
int similar(List *A, List *B)
{
  /*Terminar*/
  List *a = A;
  List *b = B;
  int flag = 1;
  while ((a != NULL && b != NULL) && flag)
  {
    if (a->data != b->data)
      flag = 0;
    a = a->next;
    b = b->next;
  }
  return flag && a == NULL && b == NULL;
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
