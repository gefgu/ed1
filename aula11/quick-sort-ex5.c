#include "utils.h"



/* */
int partition (int A[], int left, int right) {
  /*Terminar*/
  int i, j, pivo;
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
int quick_sort (int *A, int left, int right, int level) {
  /*Terminar*/
  int p, i, calls=1;	
  for(i = 0; i < level * 4; i++)
    printf(" ");
  printf("quick-sort (%d, %d)\n", left, right);
  if (left < right) {
    p = partition(A, left, right);
    for(i = 0; i < (level+1) * 4; i++) 
        printf(" ");
    printf("P: {");
    for(i = left; i < right; i++) {
        printf("%d", A[i]);
        if(i < right -1)
            printf(", ");
    }
    printf("}\n");
    calls += quick_sort(A, left, p-1, level+1);
    calls += quick_sort(A, p+1, right, level+1);
  }
  return calls;
}

/* */
int main (int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  if (argc < 2) {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }

  int i;
  int n = atoi(argv[1]);;
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios*/
    //A[i] = i; /*ordem crescente*/
    //A[i] = n-i; /*ordem descrente*/
    //A[i] = 0; /*iguais*/
  }  

  start = clock();
  //print (A, n, "Input");
  printf("Number of recursive calls: %d\n", quick_sort (A, 0, n-1, 0));
  //print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

