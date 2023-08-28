#include "stack.h"

int parser(char *c)
{
  Stack *s = create(strlen(c));
  int i = 0;
  int flag = 1;
  while (c[i] != '\0' && flag)
  {
    /*Terminar*/
    /*Utilizar somente as operações push, pop, empty, ... (interface)*/
    if (c[i] == '(' || c[i] == '[')
    {
      push(s, c[i]);
    }
    else if (c[i] == ')')
    {
      if (empty(s) || get_peek(s) == '[')
        flag = 0;
      else
        pop(s);
    }
    else if (c[i] == ']')
    {
      if (empty(s) || get_peek(s) == ')')
        flag = 0;
      else
        pop(s);
    }

    i++;
  }

  flag = flag && empty(s);

  return flag;
}

int main()
{
  char *c = "( ( ) [ ( ) ] )"; // V
  // char *c = "( [ ) ]"; // F
  // char *c = "( ) [ ]"; // V
  // char *c = "( [ ]"; // F
  // char *c = ") ("; // F
  if (parser(c))
    printf("true  (bem formada)\n");
  else
    printf("false (mal formada)\n");
  return 0;
}
