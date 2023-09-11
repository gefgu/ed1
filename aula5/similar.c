#include "list.h"

/* */
int similar(List *A, List *B)
{
  /*Terminar*/
  int igual;
  if (A != NULL && B != NULL)
  {
    igual = (A->data == B->data);
    if (!igual)
      return 0;
    return igual && similar(A->next, B->next); // caso contrário
  }
  else if (A != NULL || B != NULL)
    return 0; // um deles é nulo e o outro não
  return 1;   // fim
}

/* */
int main()
{
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2)
    A = insert_back(A, k);
  for (k = 10; k >= 0; k -= 2)
    B = insert_back(B, k);

  printf("Lista A = ");
  print(A);
  printf("\n");

  printf("Lista B = ");
  print(B);
  printf("\n");

  printf("%d\n", similar(A, B));
  destroy(A);
  destroy(B);
  return 0;
}