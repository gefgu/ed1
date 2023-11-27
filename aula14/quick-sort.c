#include "quick-sort.h"

/* */
int partition (int A[], int left, int right) {
  int pivot = A[right];
  int i = left - 1;
  int j;
  for (j = left; j < right; j++) {
    if (A[j] <= pivot) {
      i += 1;
      swap (A, i, j);
    }
  }
  swap (A, i+1, right);
  return i+1;
}

/* */
void quick_sort (int *A, int left, int right) {
  if (left < right) {
    int pivot = partition (A, left, right);
    quick_sort (A, left, pivot-1);
    quick_sort (A, pivot+1, right); 
  }
}
