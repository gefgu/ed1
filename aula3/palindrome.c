#include "stack.h"

int palindrome(char *c)
{
  int len = strlen(c);
  Stack *s = create(len);
  int i, flag = 1;

  for (i = 0; i < len / 2; i++)
  {
    push(s, c[i]);
  }

  for (i = (len + 1) / 2; i < len && flag; i++)
  {
    if (c[i] != pop(s))
      flag = 0;
  }

  destroy(s);
  return flag;
}

int main()
{
  char *c = "radar";
  // char *c = "asa";
  // char *c = "renner";
  // char *c = "gustavo";
  printf("%d\n", palindrome(c));
  return 0;
}
