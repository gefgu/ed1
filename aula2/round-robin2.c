#include "queue.h"

void round_robin(Queue *q, Queue *ids, double quantum, int n)
{
  double time = 0;
  double val;
  double *times;
  double time_sum = 0;
  times = (double *)malloc(n * sizeof(double));
  int procs = 0;
  int _id;
  while (!empty(q))
  {
    if (front(q) > quantum)
    {
      val = dequeue(q) - quantum;
      enqueue(q, val);
      time += quantum;
      enqueue(ids, dequeue(ids));
    }
    else
    {
      time += dequeue(q);
      _id = dequeue(ids);
      printf("Processo %d, finalizado em %.2f ms.\n", _id, time);
      times[procs++] = time;

      time_sum += time;
    }
  }
  printf("Tempo médio de espera: %.2f ms.\n", time_sum / n);
}

int main()
{
  double quantum = 20.0;
  int procs = 4;
  int i;
  Queue *q = create(procs + 1);
  Queue *ids = create(procs + 1);
  enqueue(q, 53);
  enqueue(q, 17);
  enqueue(q, 68);
  enqueue(q, 24);
  for (i = 1; i <= procs; i++)
  {
    enqueue(ids, i);
  }

  round_robin(q, ids, quantum, procs);
}
