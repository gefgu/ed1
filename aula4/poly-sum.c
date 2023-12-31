#include "plist.h"

List *poly_sum(List *pA, List *pB)
{
  /*Terminar!*/
  List *sum = create();
  List *poly_ordered = create();
  while (pA != NULL || pB != NULL)
  {
    if (pA->p.d > pB->p.d)
    {
      sum = insert(sum, (poly){pA->p.c, pA->p.d});
      pA = pA->next;
    }
    else if (pB->p.d > pA->p.d)
    {
      sum = insert(sum, (poly){pB->p.c, pB->p.d});
      pB = pB->next;
    }
    else
    { // equal
      sum = insert(sum, (poly){pA->p.c + pB->p.c, pA->p.d});
      pA = pA->next;
      pB = pB->next;
    }
  }

  while (sum != NULL)
  {
    poly_ordered = insert(poly_ordered, sum->p);
    sum = sum->next;
  }

  return poly_ordered;
}

int main()
{

  List *pA = create();
  pA = insert(pA, (poly){2, 0});
  pA = insert(pA, (poly){4, 1});
  pA = insert(pA, (poly){5, 2});
  pA = insert(pA, (poly){7, 5});
  print(pA);

  List *pB = create();
  pB = insert(pB, (poly){-5, 0});
  pB = insert(pB, (poly){-4, 1});
  pB = insert(pB, (poly){5, 2});
  pB = insert(pB, (poly){3, 6});
  print(pB);

  List *pC = poly_sum(pA, pB);
  print(pC);

  destroy(pA);
  destroy(pB);
  destroy(pC);
}
