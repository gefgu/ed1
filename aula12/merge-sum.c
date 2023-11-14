#include "utils.h"

/* */
void merge_sort (int A[], int l, int r, int O[], int rlevel) {
  /*Terminar*/	
}

/* */
int two_sum (int A[], int n, int S) {
  /*Terminar*/	
}

/* */
int main ( ) {
  clock_t start, end;
  double elapsed_time;
  int n = 5; /*quantidade de elementos*/
  int S = 4; /*soma exata*/
  int A[] = {1, -2, 1, 0, 5};
  int O[n];  /*vetor auxiliar*/
  start = clock();
  print (A, n, "Input");
  merge_sort (A, 0, n-1, O, 0);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  if (two_sum (A, n, S))
    printf ("Existem dois inteiros que somam %d\n", S);
  else
    printf ("Não existem dois inteiros que somam %d\n", S);
  return 0;
}

