#include "list.h"

int main () {
  List *l = create ();
  l = insert_back (l, 1);
  l = insert_back (l, 2);
  l = insert_back (l, 4);
  print (l);
  destroy (l);
  return 0;
} 
