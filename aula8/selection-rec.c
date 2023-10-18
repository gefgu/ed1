#include "utils.h"

/* reverse - coloca maior na ponta direita */
void selection_sort_recursive(int *A, int n)
{
  /*Terminar*/
  if (n < 2)
    return;

  int i, aux, maior = 0;
  for (i = 1; i < n; i++)
  {
    if (A[i] > A[maior])
    {
      maior = i;
    }
  }
  i--;
  aux = A[maior];
  A[maior] = A[i];
  A[i] = aux;

  selection_sort_recursive(A, n - 1);
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
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++)
  {
    A[i] = rand() % (n + 1); /*valores aleatórios*/
  }

  start = clock();
  // print (A, n, "Input");
  selection_sort_recursive(A, n);
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
