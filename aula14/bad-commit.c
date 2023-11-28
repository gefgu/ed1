#include "utils.h"

/* */
int bad_commit(int *A, int n)
{
  /*Terminar*/
  int l = 0;
  int r = n - 1;
  int m;

  while (l <= r)
  {
    m = (l + r) / 2;
    if (A[m] == 0)
      l = m + 1;
    else
      r = m - 1;
  }

  return l;
}

/* */
int main()
{
  int i;
  int n = 7;
  int A[] = {0, 0, 0, 0, 0, 0, 1};
  printf("Bad commit: %d\n", bad_commit(A, n));
  return 0;
}
