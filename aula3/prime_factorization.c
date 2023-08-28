#include "stack.h"

int *sieve(int n)
{
  int *primos = (int *)malloc(sizeof(int) * n);
  int phi = 1, i, j;
  int eh_primo;
  primos[0] = 2;
  for (i = 3; phi < n; i++)
  {
    eh_primo = 1;
    for (j = 0; j < phi && primos[j] * primos[j] < i && eh_primo; j++)
    {
      if (i % primos[j] == 0)
        eh_primo = 0;
    }

    if (eh_primo)
      primos[phi++] = i;
  }

  return primos;
}

void prime_factorization(int n)
{
  int *primos = sieve(20);
  int i;
  Stack *s = create(100);

  for (i = 0; i < 20 && n > 1; i++)
  {
    while (n % primos[i] == 0)
    {
      push(s, primos[i]);
      n /= primos[i];
    }
  }

  print(s);
  destroy(s);
  free(primos);
}

int main()
{
  int n = 3960;
  prime_factorization(n);
  return 0;
}
