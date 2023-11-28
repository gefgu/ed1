#include "utils.h"
#include "quick-sort.h"

/* */
int binary_search_recursive(int *A, int left, int right, int key)
{
  /*Terminar*/
  if (left > right)
    return -1;
  int m = (left + right) / 2;

  if (A[m] == key)
    return m;
  else if (key < A[m])
    return binary_search_recursive(A, left, m - 1, key);
  else
    return binary_search_recursive(A, m + 1, right, key);
}

/* */
void intersection(int *A, int m, int *B, int n)
{
  /*Terminar*/
  int i;

  for (i = 0; i < m; i++)
    if (binary_search_recursive(B, 0, n - 1, A[i]) != -1)
      printf("%d ", A[i]);
  printf("\n");
}

/* */
int main()
{

  int m = 7;
  int A[] = {1, 4, 3, 2, 5, 8, 9};
  quick_sort(A, 0, m - 1);
  print(A, m, "Sorted");

  int n = 5;
  int B[] = {6, 3, 2, 7, 5};
  quick_sort(B, 0, n - 1);
  print(B, n, "Sorted");

  intersection(A, m, B, n);

  return 0;
}
