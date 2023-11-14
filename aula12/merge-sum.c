#include "utils.h"

/*Função para intercalar dois subvetores em um conjunto ordenado.
 *{A} é o vetor de entrada, {l} é a esquerda (de left),
 {m} é o meio (ou middle), {r} é a direita (de right),
 {O} é o vetor auxilar (de output). */
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

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort(int A[], int l, int r, int O[])
{
  /*Terminar*/
  int m;
  if (l < r)
  {
    m = (l + r) / 2;
    merge_sort(A, l, m, O);
    merge_sort(A, m + 1, r, O);
    merge(A, l, m, r, O);
  }
}

/* */
int two_sum(int A[], int n, int S)
{
  /*Terminar*/
  int left = 0, right = n - 1, value;

  while (left < right)
  {
    value = A[left] + A[right];
    if (value == S)
      return TRUE;

    if (value > S)
      right--;
    else
      left++;
  }

  return FALSE;
}

/* */
int main()
{
  clock_t start, end;
  double elapsed_time;
  int n = 5; /*quantidade de elementos*/
  int S = 4; /*soma exata*/
  int A[] = {1, -2, 1, 0, 5};
  int O[n]; /*vetor auxiliar*/
  start = clock();
  print(A, n, "Input");
  merge_sort(A, 0, n - 1, O);
  print(A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE))
  {
    printf("Error: non-ascending order!\n");
  }
  if (two_sum(A, n, S))
    printf("Existem dois inteiros que somam %d\n", S);
  else
    printf("Não existem dois inteiros que somam %d\n", S);
  return 0;
}
