#include "utils.h"

/* */
int merge (int A[], int l, int m, int r, int O[], int rlevel) {
  /*Terminar*/
}

/* */
int merge_sort (int A[], int l, int r, int O[], int rlevel) {
  /*Terminar*/
}

/* */
void mapping (int A1[], int A2[], int n) {
  /*Terminar*/
}

/* */
int main ( ) {
  
  //int n = 7; /*quantidade de elementos*/
  //int A1[] = {0,3,1,6,2,5,4};
  //int A2[] = {1,0,3,6,4,2,5};
  //Solucao = 4
   
  int n = 5;
  int A1[] = {0, 4, 3, 1, 2};
  int A2[] = {1, 4, 2, 3, 0};
  //Solucao = 7
   
  //int n = 12;
  //int A1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  //int A2[] = {0, 1, 2, 4, 3, 6, 5, 7, 9, 8, 10, 11};
  //Solucao = 3
  
  int O[n];  /*vetor auxiliar*/

  mapping (A1, A2, n);

  printf ("Kendall tau distance: %d\n", merge_sort (A2, 0, n-1, O, 0));

  return 0;
}

