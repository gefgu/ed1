#include "dqueue.h"

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
      printf("Processo %d, finalizado em %.2lf ms.\n", _id, time);
      times[procs++] = time;

      time_sum += time;
    }
  }
  printf("Tempo médio de espera: %.2lf ms.\n", time_sum / n);
}

int main(int argc, char *argv[])
{
  double quantum;
  int procs, i;
  double x, y;
  sscanf(argv[1], "%lf", &quantum);
  sscanf(argv[2], "%d", &procs);

  Queue *q = create(procs + 1);
  Queue *ids = create(procs + 1);
  for (i = 0; i < argc - 3; i += 2)
  {
    sscanf(argv[i + 3], "%lf", &x);
    sscanf(argv[i + 4], "%lf", &y);
    enqueue(ids, x);
    enqueue(q, y);
  }

  round_robin(q, ids, quantum, procs);
}
