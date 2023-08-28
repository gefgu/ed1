#include "queue.h"

int pfault(int requests[], int nreq, int nslots)
{
  int faults = 0;
  Queue *q = create(nslots + 1);
  int i, j;
  int alreadyHere = 0;

  if (nreq > 0)
  {
    enqueue(q, requests[0]);
    faults++;
  }

  for (i = 1; i < nreq; i++)
  {
    alreadyHere = search(q, requests[i]);

    if (!alreadyHere)
    {
      if (full(q))
        dequeue(q);
      enqueue(q, requests[i]);
      faults++;
    }
  }

  destroy(q);

  return faults;
}

int main()
{
  int requests[6] = {1, 3, 0, 3, 5, 6};
  int nreq = 6;
  int nslots = 3;
  printf("%d\n", pfault(requests, nreq, nslots));
}
