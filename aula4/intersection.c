#include "list.h"

/* */
List *intersect(List *A, List *B)
{
  /*Terminar*/
  List *a = A;
  List *intersection = create();
  for (; a != NULL; a = a->next)
  {
    if (search(B, a->data) != NULL)
    {
      intersection = insert(intersection, a->data);
    }
  }
  return intersection;
}

/* */
int main()
{
  int k;
  List *A = NULL, *B = NULL;
  for (k = 16; k >= 6; k -= 2)
    A = insert(A, k);
  for (k = 20; k >= 0; k -= 2)
    B = insert(B, k);
  print(A);
  print(B);
  List *C = intersect(A, B);
  print(C);
  destroy(A);
  destroy(B);
  destroy(C);
  return 0;
}
