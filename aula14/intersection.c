#include "utils.h"
#include "quick-sort.h"

/* */
int binary_search_recursive (int *A, int left, int right, int key) {
  /*Terminar*/	
}
 
/* */
void intersection (int *A, int m, int *B, int n) {
  /*Terminar*/	
}

/* */
int main () {
 
  int m = 7;
  int A[] = {1,4,3,2,5,8,9};
  quick_sort (A, 0, m-1); 
  print (A, m, "Sorted"); 

  int n = 5;
  int B[] = {6,3,2,7,5};
  quick_sort (B, 0, n-1); 
  print (B, n, "Sorted"); 

  intersection (A, m, B, n);
  
  return 0;
}
