#include "utils.h"

/*Função para intercalar*/
int merge(int A[], int l, int m, int r, int O[], int rlevel)
{
  /*Terminar*/
  int i = l, j = m + 1, k = l;
  int inv = 0;
  while ((i <= m) && (j <= r))
  {
    if (A[i] <= A[j])
    {
      O[k++] = A[i++];
    }
    else
    {
      printf("(%d, %d) ", A[i], A[j]);
      inv++;
      O[k++] = A[j++];
    }
  }

  while (i <= m)
  {
    if (i < m)
    {
      printf("(%d, %d) ", A[m], A[i]);
      inv++;
    }
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
  return inv;
}

/*Função principal do algoritmo Merge-Sort adaptada.*/
int merge_sort(int A[], int l, int r, int O[], int rlevel)
{
  int i;
  if (l < r)
  {
    int m = (l + r) / 2;
    int invA = merge_sort(A, l, m, O, rlevel + 1);
    int invB = merge_sort(A, m + 1, r, O, rlevel + 1);
    int invC = merge(A, l, m, r, O, rlevel + 1);
    return invA + invB + invC;
  }
  else
    return 0;
}

/* */
int main()
{
  clock_t start, end;
  double elapsed_time;
  int n = 6; /*quantidade de elementos*/
  int A[] = {2, 4, 1, 3, 5, 2};
  int O[n]; /*vetor auxiliar*/
  start = clock();
  // print (A, n, "Input");
  printf("# de inversoes: %d\n", merge_sort(A, 0, n - 1, O, 0));
  // print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE))
  {
    printf("Error: non-ascending order!\n");
  }
  return 0;
}
