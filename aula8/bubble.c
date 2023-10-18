#include "utils.h"

/* TEMPOS */
// 10: 0.00
// 100: 0.00
// 1000: 0.01
// 10000: 0.25
// 100000: 25.99
// 200000: 105.46

/* */
void bubble_sort(int *A, int n)
{
  /*Terminar*/
  int i, j, aux;
  for (i = n; i > 0; i--)
  {
    for (j = 0; j < i; j++)
    {
      if (A[j] > A[j + 1])
      {
        aux = A[j + 1];
        A[j + 1] = A[j];
        A[j] = aux;
      }
    }
  }
}

/* */
int main(int argc, char *argv[])
{

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  if (argc < 2)
  {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }

  int i;
  int n = atoi(argv[1]);
  ;
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++)
  {
    A[i] = rand() % (n + 1); /*valores aleatórios*/
  }

  start = clock();
  // print (A, n, "Input");
  bubble_sort(A, n);
  // print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE))
  {
    printf("Error: non-ascending order!\n");
  }
  free(A);
  return 0;
}
