#include "utils.h"

/* */
int is_maximal(int A[], int l, int r)
{
  int i;
  for (i = l; i < r; i++)
    if (A[i] > A[i + 1])
      return FALSE;
  return TRUE;
}

void merge(int A[], int l, int m, int r, int O[])
{
  /*Terminar*/
  int i = l, j = m + 1, k = l;
  while ((i <= m) && (j <= r))
  {
    if (A[i] <= A[j])
      O[k++] = A[i++];
    else
      O[k++] = A[j++];
  }

  while (i <= m)
  {
    O[k++] = A[i++];
  }

  while (j <= r)
  {
    O[k++] = A[j++];
  }

  for (i = l; i <= r; i++)
  {
    A[i] = O[i];
  }
}

int merge_sort(int A[], int l, int r, int O[], int rlevel)
{
  /*Terminar*/
  // if (l < r)
  if (!is_maximal(A, l, r))
  {
    int m = (l + r) / 2;
    int rec1 = merge_sort(A, l, m, O, rlevel + 1);
    int rec2 = merge_sort(A, m + 1, r, O, rlevel + 1);
    merge(A, l, m, r, O);
    return 1 + rec1 + rec2;
  }
  return 1;
}

/* */
int main()
{
  clock_t start, end;
  double elapsed_time;
  int n = 13; /*quantidade de elementos*/
  int A[] = {1, 2, 3, 4, 2, 4, 6, 4, 5, 6, 7, 8, 9};
  int O[n]; /*vetor auxiliar*/
  start = clock();
  print(A, n, "Input");
  printf("Numero de chamadas recursivas: %d\n", merge_sort(A, 0, n - 1, O, 0));
  print(A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE))
  {
    printf("Error: non-ascending order!\n");
  }
  return 0;
}
