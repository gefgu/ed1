#include "queue.h"

Queue *merge(Queue *a, Queue *b)
{
  int i, size = getsize(a) + getsize(b);
  Queue *sorted = create(size);
  while (!empty(a) || !empty(b))
  {
    if (!empty(a) && !empty(b) && front(a) < front(b))
      enqueue(sorted, dequeue(a));
    else if (!empty(b))
      enqueue(sorted, dequeue(b));
    else
      enqueue(sorted, dequeue(a));
  }

  return sorted;
}

int main()
{
  int i;
  Queue *a = create(20);
  Queue *b = create(20);
  for (i = 1; i <= 20; i++)
  {
    if (i & 1)
      enqueue(a, i);
    else
      enqueue(b, i);
  }

  print(merge(a, b));
}
