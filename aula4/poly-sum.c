#include "plist.h"

List* poly_sum (List *pA, List *pB) {
  /*Terminar!*/	
}

int main () {

  List *pA = create ();
  pA = insert (pA, (poly){2, 0});
  pA = insert (pA, (poly){4, 1});
  pA = insert (pA, (poly){5, 2});
  pA = insert (pA, (poly){7, 5});
  print (pA);

  List *pB = create ();
  pB = insert (pB, (poly){-5, 0});
  pB = insert (pB, (poly){-4, 1});
  pB = insert (pB, (poly){5, 2});
  pB = insert (pB, (poly){3, 6});
  print (pB);

  List *pC = poly_sum (pA, pB);
  print (pC);

  destroy (pA);
  destroy (pB);
  destroy (pC);
}
