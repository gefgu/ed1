#include "queue.h"
#include <unistd.h>

#define RED "\x1B[31m"
#define RESET "\x1B[0m"

void show(Queue *q, int m, int passo_atual)
{
  system("clear");

  printf("O último passo é a eliminação:\n\n");
  printf("Fila - ");
  print(q);
  printf("\nPassos restantes para a eliminação: %d\n", m - passo_atual);
  sleep(1);
}

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
    show(q, m, passos);
    ultimo = dequeue(q);
    passos++;
    if (passos < m)
      enqueue(q, ultimo);
    else
    {
      passos = 0;
      printf(RED "\nO %d foi eliminado\n" RESET, ultimo);
      sleep(1);
    }
  }

  return ultimo;
}

int main()
{
  josephus(5, 3);
}
