#include "utils.h"

/*Função para intercalar*/
void merge (int A[], int l, int m, int r) {
  /*Terminar*/	
}

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort (int A[], int l, int r) {
  if (l < r) {
    int m = (l + r)/2;
    merge_sort (A, l, m);
    merge_sort (A, m+1, r); 
    merge (A, l, m, r);
  }
}

/* */
int main ( ) {
  clock_t start, end;
  double elapsed_time;
  int n = 8; /*quantidade de elementos*/
  int A[] = {5, 2, 7, 4, 8, 1, 9, 8};
  start = clock();
  print (A, n, "Input");
  merge_sort (A, 0, n-1);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  return 0;
}

