#include "list.h"

/* */
List *merge(List *A, List *B)
{
  /*Terminar*/
  List *a = A;
  List *b = B;
  List *merged = create();
  while (a != NULL || b != NULL)
  {
    if (a == NULL || b->data <= a->data)
    {
      merged = insert_back(merged, b->data);
      b = b->next;
    }
    else if (b == NULL || a->data < b->data)
    {
      merged = insert_back(merged, a->data);
      a = a->next;
    }
  }
  return merged;
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
  destroy(A);
  destroy(B);
  destroy(C);
  return 0;
}
