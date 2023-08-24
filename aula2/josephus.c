#include "queue.h"

// n pessoas e m é o passo da morte
int josephus(int n, int m)
{
  int passos = 0;
  int ultimo;
  Queue *q = create(n + 1);
  int i;
  for (i = 1; i <= n; i++)
    enqueue(q, i);

  while (!empty(q))
  {
    ultimo = dequeue(q);
    passos++;
    if (passos < m)
      enqueue(q, ultimo);
    else
      passos = 0;
  }

  return ultimo;
}

int main()
{
  printf("%d\n", josephus(5, 3));
}
