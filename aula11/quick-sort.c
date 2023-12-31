#include "utils.h"

/* TEMPOS - Aleatória*/
// 10: 0.00
// 100: 0.00
// 1000: 0.00
// 10000: 0.01
// 100000: 0.04
// 200000: 0.05

/* TEMPOS - Crescente*/
// 10: 0.00
// 100: 0.00
// 1000: 0.00
// 10000: 0.25
// 100000: 25.09

/* TEMPOS - Decrescente*/
// 10: 0.00
// 100: 0.00
// 1000: 0.00
// 10000: 0.17
// 100000: 16.98

/* TEMPOS - Iguais*/
// 10: 0.00
// 100: 0.00
// 1000: 0.00
// 10000: 0.13
// 100000: 9.16

/* */
int partition(int A[], int left, int right)
{
  /*Terminar*/
  int i, j, pivo;
  pivo = A[right];
  i = left - 1;
  for (j = left; j <= right - 1; j++)
  {
    if (A[j] < pivo)
    {
      i++;
      swap(A, j, i);
    }
  }
  swap(A, right, i + 1);
  return i + 1;
}

/* */
void quick_sort(int *A, int left, int right)
{
  /*Terminar*/
  int p;
  if (left < right)
  {
    p = partition(A, left, right);
    quick_sort(A, left, p - 1);
    quick_sort(A, p + 1, right);
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
    // A[i] = rand() % (n + 1); /*valores aleatórios*/
    // A[i] = i; /*ordem crescente*/
    // A[i] = n - i; /*ordem descrente*/
    A[i] = 0; /*iguais*/
  }

  start = clock();
  // print (A, n, "Input");
  quick_sort(A, 0, n - 1);
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
