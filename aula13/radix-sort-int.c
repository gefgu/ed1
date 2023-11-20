#include "utils.h"

int get_digit(int number, int digit_number)
{
  int i;
  for (i = 0; i < digit_number; i++)
    number /= 10;

  return number % 10;
}

/* */
void counting_sort(int *A, int n, int digit, int digit_range)
{
  int i, j;

  /*Alocando vetores auxiliares: */
  int *T = (int *)malloc(n * sizeof(int));                 /*temporário*/
  int *C = (int *)malloc((digit_range + 1) * sizeof(int)); /*contador*/

  /*Terminar*/
  for (i = 0; i <= digit_range; i++)
    C[i] = 0;

  for (i = 0; i < n; i++)
  {
    j = get_digit(A[i], digit);
    C[j]++;
  }

  for (i = 1; i <= digit_range; i++)
    C[i] += C[i - 1];

  for (i = n - 1; i >= 0; i--)
  {
    j = get_digit(A[i], digit);
    T[C[j] - 1] = A[i];
    C[j]--;
  }

  for (i = 0; i < n; i++)
    A[i] = T[i];

  /*Desalocando vetores auxiliares: */
  free(T);
  free(C);
}

int n_digits(int num)
{
  int i;
  for (i = 0; num > 0; i++)
    num /= 10;
  return i;
}

/* */
void radix_sort(int *A, int n, int range)
{
  int max_digit = 0, digit, i;
  int digit_range = 9; /*números de 0 a 9 (para inteiros)*/
  for (i = 0; i < n; i++)
  {
    digit = n_digits(A[i]);
    if (digit > max_digit)
      max_digit = digit;
  }

  for (i = 0; i < max_digit; i++)
    counting_sort(A, n, i, digit_range);
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
  int range = 100; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++)
  {
    A[i] = rand() % range; /*valores aleatórios*/
  }

  start = clock();
  print(A, n, "Input");
  radix_sort(A, n, range);
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
