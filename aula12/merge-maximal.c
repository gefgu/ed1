#include "utils.h"

/* */
int is_maximal (int A[], int l, int r) {
  int i;
  for (i = l; i < r; i++)
    if (A[i] > A[i+1]) 
      return FALSE;
  return TRUE;
}

int merge_sort (int A[], int l, int r, int O[], int rlevel) {
  /*Terminar*/	
}

/* */
int main ( ) {
  clock_t start, end;
  double elapsed_time;
  int n = 13; /*quantidade de elementos*/
  int A[] = {1, 2, 3, 4, 2, 4, 6, 4, 5, 6, 7, 8, 9};
  int O[n];  /*vetor auxiliar*/
  start = clock();
  print (A, n, "Input");
  printf("Numero de chamadas recursivas: %d\n", merge_sort (A, 0, n-1, O, 0));
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  return 0;
}

