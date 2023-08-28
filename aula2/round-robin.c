#include "queue.h"

void round_robin(Queue *q, double quantum, int n)
{
  double time = 0;
  double val;
  double *times;
  double time_sum = 0;
  times = (double *)malloc(n * sizeof(double));
  int procs = 0;
  while (!empty(q))
  {
    if (front(q) > quantum)
    {
      val = dequeue(q) - quantum;
      enqueue(q, val);
      time += quantum;
    }
    else
    {
      time += dequeue(q);
      printf("Processo finalizado em %.2f ms.\n", time);
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
  Queue *q = create(procs + 1);
  enqueue(q, 53);
  enqueue(q, 17);
  enqueue(q, 68);
  enqueue(q, 24);

  round_robin(q, quantum, procs);
}
