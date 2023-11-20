#include "utils.h"

/*
Não é estável
*/
void counting_sort(int *A, int n, int range)
{
  int i, j;

  /*Alocando vetores auxiliares: */
  int *T = (int *)malloc(n * sizeof(int));           /*temporário*/
  int *C = (int *)malloc((range + 1) * sizeof(int)); /*contador*/

  /*Terminar*/
  for (i = 0; i <= range; i++)
    C[i] = 0;

  for (i = 0; i < n; i++)
  {
    C[A[i]]++;
  }

  for (i = 1; i <= range; i++)
  {
    C[i] += C[i - 1];
  }

  for (i = 0; i < n; i++)
  {
    T[C[A[i]] - 1] = A[i];
    C[A[i]]--;
  }

  for (i = 0; i < n; i++)
  {
    A[i] = T[i];
  }

  /*Desalocando vetores auxiliares: */
  free(T);
  free(C);
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
    A[i] = rand() % range; /*valores aleatórios*/
  }

  start = clock();
  print(A, n, "Input");
  counting_sort(A, n, range);
  print(A, n, "Sorted");
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
