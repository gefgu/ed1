#include "queue.h"
#include <unistd.h>

void show(Queue *a, Queue *b, Queue *sorted)
{
  system("clear");
  printf("Fila A - ");
  print(a);
  printf("\nFila B - ");
  print(b);
  printf("\nSorted - ");
  print(sorted);
  sleep(1);
}

Queue *merge(Queue *a, Queue *b)
{
  int i, size = getsize(a) + getsize(b);
  Queue *sorted = create(size + 1);
  show(a, b, sorted);
  while (!empty(a) || !empty(b))
  {
    if (!empty(a) && !empty(b) && front(a) < front(b))
      enqueue(sorted, dequeue(a));
    else if (!empty(b))
      enqueue(sorted, dequeue(b));
    else
      enqueue(sorted, dequeue(a));
    show(a, b, sorted);
  }

  return sorted;
}

int main()
{
  int i;
  Queue *a = create(10);
  Queue *b = create(10);
  for (i = 1; i <= 10; i++)
  {
    if (i & 1)
      enqueue(a, i);
    else
      enqueue(b, i);
  }

  Queue *sorted = merge(a, b);

  show(a, b, sorted);
  destroy(a);
  destroy(b);
  destroy(sorted);
}
