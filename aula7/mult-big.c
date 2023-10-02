#include "list.h"

/* */
List* mult (List *lx, List *ly) {
  List *lz = create();
  Node *tx = lx->tail;
  /*Terminar!*/
}

/* */
int main () {
   
  int k;	

  List *lx = create ();
  int nx = 3;
  int x[] = {1,2,0};
  for (k = 0; k < nx; k++) 
    insert_back (lx, x[k]); 	  
  print_head_to_tail (lx);

  List *ly = create ();
  int ny = 1;
  int y[] = {3};
  for (k = 0; k < ny; k++) 
    insert_back (ly, y[k]); 	 
  print_head_to_tail (ly);

  List *lz = mult (lx, ly);
  print_head_to_tail (lz);

  destroy (lx);
  destroy (ly);
  destroy (lz);
  return 0;
} 
