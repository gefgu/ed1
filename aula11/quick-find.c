#include "utils.h"

int partition_random (int A[], int left, int right) {
  /*Terminar*/
  int i, j, pivo;
  int rand_choice = left + rand() % (right - left + 1);
  swap(A, right, rand_choice);
  pivo = A[right];
  i = left-1;
  for(j = left; j <= right-1; j++) {
    if(A[j] < pivo) {
      i++;
      swap(A, j, i);
    }
  }
  swap(A, right, i+1);
  return i+1;
}

/* */
int quick_find (int *A, int left, int right, int k) {
  /*Terminar*/
  int p;	
  if (left < right) {
    p = partition_random(A, left, right);
    if(p == (k-1)) {
      return A[k-1];
    }
    else if(p >= k) { 
      quick_find(A, left, p-1, k);
    } else {
      quick_find(A, p+1, right, k);
    }
  }	
  return A[k-1];
}

/* */
int main () {
  int n = 8;
  int A[] = {7, 1, 3, 10, 17, 2, 21, 9};
  print (A, n, "Input");
  printf("Value: %d\n", quick_find (A, 0, n-1, 3));
  print (A, n, "Partial sorted");
  return 0;
}
