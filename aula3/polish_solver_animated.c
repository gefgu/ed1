#include "stack.h"
#include <time.h>

#define CYN "\x1B[36m"
#define RESET "\x1B[0m"

void show_expression(char *c, int pos)
{
  int i;
  printf("Expressão: ");
  for (i = 0; c[i] != '\0'; i++)
  {
    if (i == pos)
      printf(CYN "%c" RESET, c[i]);
    else
    {
      printf("%c", c[i]);
    }
  }
  printf("\n");
}

int compute_polish_expression(char *c)
{
  struct timespec second, nano = {0, 500000000};
  Stack *s = create(strlen(c)); // numeros
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

    system("clear");
    show_expression(c, i);
    printf("\n");
    print(s);
    nanosleep(&nano, &second);

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
