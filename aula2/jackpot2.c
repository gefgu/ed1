#include "queue.h"
#include <time.h>
#include <unistd.h>

int max(int a, int b)
{
  return a > b ? a : b;
}

void show(Queue *queues[], Queue *b_queues[], Queue *a_queues[])
{
  printf("\t \t     Jackpot\n");
  printf("------------------------------------------------\n");
  printf("\t %d \t|\t %d \t |\t %d\n", front(b_queues[0]), front(b_queues[1]), front(b_queues[2]));
  printf("\n");
  printf("\t %d \t|\t %d \t |\t %d\n", front(queues[0]), front(queues[1]), front(queues[2]));
  printf("\n");
  printf("\t %d \t|\t %d \t |\t %d\n", front(a_queues[0]), front(a_queues[1]), front(a_queues[2]));
  printf("------------------------------------------------\n");
}

void jackpot(int n, int r)
{
  /*Terminar*/
  int i, j, val, aleatorios[3], maior;
  Queue *b_queues[3];
  Queue *queues[3];
  Queue *a_queues[3];
  for (i = 0; i < 3; i++)
  {
    queues[0] = create(r + 1);
    queues[1] = create(r + 1);
    queues[2] = create(r + 1);
  }
  for (i = 0; i < 3; i++)
  {
    b_queues[0] = create(r + 1);
    b_queues[1] = create(r + 1);
    b_queues[2] = create(r + 1);
  }
  for (i = 0; i < 3; i++)
  {
    a_queues[0] = create(r + 1);
    a_queues[1] = create(r + 1);
    a_queues[2] = create(r + 1);
  }

  for (i = 0; i < 10; i++)
    for (j = 0; j < 3; j++)
    {
      enqueue(b_queues[j], (i + 10 - 1) % 10);
      enqueue(queues[j], i);
      enqueue(a_queues[j], (i + 1) % 10);
    }

  do
  {
    for (i = 0; i < 3; i++)
      aleatorios[i] = (rand() % 10) + 1;

    maior = max(aleatorios[0], max(aleatorios[1], aleatorios[2]));

    for (j = 0; j < maior; j++)
    {
      for (i = 0; i < 3; i++)
      {
        if (j < aleatorios[i])
        {
          val = dequeue(b_queues[i]);
          enqueue(b_queues[i], val);

          val = dequeue(queues[i]);
          enqueue(queues[i], val);

          val = dequeue(a_queues[i]);
          enqueue(a_queues[i], val);
        }
      }

      system("clear");
      show(queues, b_queues, a_queues);
      sleep(1);
    }

    system("clear");

    printf("Não foi dessa vez!\n");
    sleep(1);
    system("clear");
    show(queues, b_queues, a_queues);
    sleep(2);

  } while (front(queues[0]) != front(queues[1]) || front(queues[1]) != front(queues[2]) != 7);

  printf(" -> Ganhou\n");
}

int main()
{
  srand(time(NULL));
  int n = 3;  /*número de carretéis*/
  int r = 10; /*sequência de números em cada carretel*/
  jackpot(n, r);
}
