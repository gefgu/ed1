#include "queue.h"
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  int i, n = 10, val;
  /*Use somente as operações definidas em queue.h*/
  /*Não use para resolver esse exercício o operador -> aqui!*/
  /*Terminar*/
  Queue *pares = create(n);
  Queue *impares = create(n);

  i = 1; // evita queue overflow
  while (i < n)
  {
    val = rand() % 100;
    if (val % 2 == 1)
      enqueue(impares, val);
    else
      enqueue(pares, val);

    i++;
  }
  printf("Pares ");
  print(pares);
  printf("Impares ");
  print(impares);

  return 0;
}
