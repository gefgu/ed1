#include "queue.h"
#include <unistd.h>

void show(Queue *q, Queue *t, Queue *reversed)
{
  system("clear");
  printf("Fila Original - ");
  print(q);
  printf("\nFila Auxiliar - ");
  print(t);
  printf("\nReversa - ");
  print(reversed);
  sleep(1);
}

Queue *reverse(Queue *q)
{
  int size = getsize(q);
  Queue *r = create(size);
  Queue *t = create(size);
  int i;

  while (!empty(q))
  {
    while (!empty(r))
    {
      enqueue(t, dequeue(r));
      show(q, t, r);
    }

    enqueue(r, dequeue(q));
    show(q, t, r);
    while (!empty(t))
    {
      enqueue(r, dequeue(t));
      show(q, t, r);
    }
  }

  return r;
}

int main()
{
  int i;
  Queue *a = create(10);
  for (i = 1; i < 5; i++)
  {
    enqueue(a, i);
  }

  print(a);
  printf("\n");
  Queue *reversed = reverse(a);
  print(reversed);
  destroy(a);
  destroy(reversed);
}
