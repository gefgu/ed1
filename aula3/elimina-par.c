#include "stack.h"

int main()
{
  int tam = 6;
  Stack *s = create(tam);
  Stack *t = create(tam);
  srand(time(NULL));
  int i;
  for (i = 0; i < tam; i++)
  {
    push(s, rand() % 10);
  }
  print(s);
  /*TERMINAR*/

  int val;
  while (!empty(s))
  {
    val = pop(s);
    if (val & 1)
    {
      push(t, val);
    }
  }

  while (!empty(t))
  {
    push(s, pop(t));
  }

  print(s);

  destroy(s);
}
