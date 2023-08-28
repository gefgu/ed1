#include "stack.h"

int compute_polish_expression(char *c)
{
  Stack *s = create(strlen(c)); // operadores
  int i = 0;
  int a, b;

  while (c[i] != '\0')
  {
    /*Terminar*/
    /*Utilizar somente as operações push, pop, empty, ... (interface)*/
    if (c[i] >= '0' && c[i] <= '9')
    {
      push(s, c[i] - '0');
    }
    else if (c[i] == '+')
    {
      a = pop(s);
      b = pop(s);
      push(s, a + b);
    }
    else if (c[i] == '*')
    {
      a = pop(s);
      b = pop(s);
      push(s, a * b);
    }

    i++;
  }

  a = pop(s);
  destroy(s);
  return a;
}

int main()
{
  char *c = "9 0 1 + 2 3 * * +";
  printf("%d\n", compute_polish_expression(c));
  return 0;
}
