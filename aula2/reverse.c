#include "queue.h"

Queue *reverse(Queue *q)
{
  int size = getsize(q);
  Queue *r = create(size);
  Queue *t = create(size);
  int i;

  for (i = 0; i < size - 1; i++)
  {
    while (!empty(r))
      enqueue(t, dequeue(r));

    enqueue(r, dequeue(q));
    while (!empty(t))
      enqueue(r, dequeue(t));
  }

  return r;
}

int main()
{
  int i;
  Queue *a = create(20);
  for (i = 1; i < 20; i++)
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
