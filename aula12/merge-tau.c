#include "utils.h"

void recuo(int rlevel)
{
  int i;
  for (i = 0; i < rlevel * 2; i++)
    printf(" ");
}

/* */
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
      recuo(rlevel + 1);
      printf("(%d, %d)\n", A[i], A[j]);
      inv++;
      O[k++] = A[j++];
    }
  }

  while (i <= m)
  {
    if (i < m)
    {
      recuo(rlevel + 1);
      printf("(%d, %d)\n", A[m], A[i]);
      inv++;
    }
    O[k++] = A[i++];
  }

  while (j <= r)
  {
    O[k++] = A[j++];
  }

  recuo(rlevel);
  printf("Intercalando = {");

  for (i = l; i <= r; i++)
  {
    A[i] = O[i];
    printf("%d", O[i]);
    if (i < r)
    {
      printf(", ");
    }
  }
  printf("}\n");
  return inv;
}

int abs(int a)
{
  if (a < 0)
    return -a;

  return a;
}

/*Função principal do algoritmo Merge-Sort adaptada.*/
int merge_sort(int A1[], int A2[], int l, int r, int O[], int rlevel)
{
  int i;
  for (i = 0; i < rlevel * 2; i++)
    printf(" ");
  int m = (l + r) / 2;
  printf("Merge-Sort (%d, %d, %d)\n", l, m, r);
  if (l < r)
  {

    int invA = merge_sort(A1, A2, l, m, O, rlevel + 1);
    int invB = merge_sort(A1, A2, m + 1, r, O, rlevel + 1);
    int invC = abs(merge(A1, l, m, r, O, rlevel + 1) - merge(A2, l, m, r, O, rlevel + 1));
    return invA + invB + invC;
  }
  else
    return 0;
}

/* */
int mapping(int A1[], int A2[], int O[], int n)
{
  /*Terminar*/
  int l = 0, r = n - 1;

  return merge_sort(A1, A2, l, r, O, 0);
}

/* */
int main()
{

  // int n = 7; /*quantidade de elementos*/
  // int A1[] = {0, 3, 1, 6, 2, 5, 4};
  // int A2[] = {1, 0, 3, 6, 4, 2, 5};
  // Solucao = 4

  // int n = 5;
  // int A1[] = {0, 4, 3, 1, 2};
  // int A2[] = {1, 4, 2, 3, 0};
  // Solucao = 2

  int n = 12;
  int A1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  int A2[] = {0, 1, 2, 4, 3, 6, 5, 7, 9, 8, 10, 11};
  // Solucao = 3

  int O[n]; /*vetor auxiliar*/

  printf("Kendall tau distance: %d\n", mapping(A1, A2, O, n));

  return 0;
}
