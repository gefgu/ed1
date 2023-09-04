#include "list.h"

/* */
int size(List *l) {
    int size;
    List *t = l;
    for(size = 0; t != NULL; t = t->next, size++);
    return size;
}

/* */
int main () {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2) 
    A = insert (A, k);
  print (A);
  printf("Size: %d\n", size(A));

  return 0;
}
