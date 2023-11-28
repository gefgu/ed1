#include "utils.h"

/* */
int perfect_square(int n)
{
  /*Terminar*/
  int l = 1;
  int r = n;
  int m;
  while (l <= r)
  {
    m = (l + r) / 2;
    if (m * m == n)
      return TRUE;
    else if (m * m < n)
      l = m + 1;
    else
      r = m - 1;
  }

  return FALSE;
}

/* */
int main()
{
  int i;
  int n = 100;
  for (i = 1; i < n; i++)
  {
    if (perfect_square(i))
    {
      printf("Número %d é um quadrado perfeito.\n", i);
    }
  }
  return 0;
}
