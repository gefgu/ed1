#include "queue.h"
#include <time.h>

void jackpot(int n, int r)
{
  /*Terminar*/
  int i, j, val, aleatorio;
  Queue *queues[3];
  queues[0] = create(r + 1);
  queues[1] = create(r + 1);
  queues[2] = create(r + 1);

  for (i = 1; i <= 10; i++)
    for (j = 0; j < 3; j++)
      enqueue(queues[j], i);

  do
  {
    for (i = 0; i < 3; i++)
    {
      aleatorio = rand() % 10;
      for (j = 0; j < aleatorio; j++)
      {
        val = dequeue(queues[i]);
        enqueue(queues[i], val);
      }
    }

    printf("\n%d %d %d", front(queues[0]), front(queues[1]), front(queues[2]));
  } while (front(queues[0]) != front(queues[1]) || front(queues[1]) != front(queues[2]));

  printf(" -> Ganhou\n");
}

int main()
{
  srand(time(NULL));
  int n = 3;  /*número de carretéis*/
  int r = 10; /*sequência de números em cada carretel*/
  jackpot(n, r);
}
