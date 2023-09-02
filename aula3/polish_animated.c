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

void show_stack(Stack *s)
{
  int i;
  printf("Stack (peek): ");
  for (i = s->peek - 1; i >= 0; i--)
  {
    printf("%c ", s->array[i]);
  }
  printf("\n");
}

void show_notation(char *c)
{
  int i;
  printf("Notation: ");
  for (i = 0; c[i] != '\0'; i++)
  {
    printf("%c ", c[i]);
  }
  printf("\n");
}

void reversed_polish_notation(char *c)
{
  struct timespec second, nano = {0, 400000000};
  Stack *s = create(strlen(c)); // operadores
  char *notation = (char *)malloc(strlen(c) * sizeof(char));
  int i = 0, n = 0;

  while (c[i] != '\0')
  {
    /*Terminar*/
    /*Utilizar somente as operações push, pop, empty, ... (interface)*/
    if (c[i] >= '0' && c[i] <= '9')
    {
      notation[n++] = c[i];
    }
    else if (c[i] == ')')
    {
      notation[n++] = pop(s);
    }
    else if (c[i] == '+' || c[i] == '*')
    {
      push(s, c[i]);
    }

    system("clear");
    show_expression(c, i);
    printf("\n");
    show_stack(s);
    printf("\n");
    show_notation(notation);
    nanosleep(&nano, &second);
    i++;
  }
  printf("\n");
  destroy(s);
}

int main()
{
  char *c = "( 9 + ( ( 0 + 1 ) * ( 2 * 3 ) ) )";
  reversed_polish_notation(c);
  return 0;
}
