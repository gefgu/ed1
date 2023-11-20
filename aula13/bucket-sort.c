#include "utils.h"
#include "list.h"

void insertion_sort(double *A, int n)
{
  int i, j;
  float key;

  for (i = 0; i < n - 1; i++)
  {
    key = A[i + 1];
    for (j = i + 1; j > 0 && key < A[j - 1]; j--)
    {
      A[j] = A[j - 1];
    }
    A[j] = key;
  }
}

void bucket_sort(double *A, int n)
{
  int i, j, k, m = 0;

  List **B = (List **)malloc(sizeof(List *) * n);
  double *T = (double *)malloc(sizeof(double) * n);

  for (i = 0; i < n; i++)
    B[i] = create();

  for (i = 0; i < n; i++)
    insert_front(B[(int)(n * A[i])], A[i]);

  for (i = 0; i < n; i++)
  {
    Node *node;
    j = 0;
    for (node = B[i]->head; node != NULL; node = node->next, j++)
      T[j] = node->data;

    insertion_sort(T, j);
    for (k = 0; k < j; k++)
      A[m++] = T[k];
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
  double *A = (double *)malloc(n * sizeof(double));

  for (i = 0; i < n; i++)
  {
    A[i] = (double)rand() / RAND_MAX; /*valores aleatórios*/
  }

  start = clock();
  print_float(A, n, "Input");
  bucket_sort(A, n);
  print_float(A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check_float(A, n, TRUE))
  {
    printf("Error: non-ascending order!\n");
  }
  free(A);
  return 0;
}
