#include "sstack.h"
#define TAG_MAX 50

int compare(const char *a, const char *b)
{
  int i, len = strlen(a);
  int lenb = strlen(b);

  /*
  for (i = 0; i < len; i++)
    printf("%c", a[i]);
  printf("\n");
  for (i = 0; i < lenb; i++)
    printf("%c", b[i]);
  printf("\n");
 */

  if (len != lenb)
    return 0;
  for (i = 0; i < len; i++)
    if (a[i] != b[i])
      return 0;

  return 1;
}

int html(FILE *file)
{
  char c;
  char current_tag[STRING_MAX];
  Stack *s = create(TAG_MAX);
  int open = 0;
  int closing = 0;
  int i, n = 0;

  while (fscanf(file, "%c", &c) == 1)
  {
    if (c == '<')
      open = 1;
    else if (c == '/')
      closing = 1;
    else if (c == '>')
    {
      current_tag[n++] = '\0';

      if (open)
      {
        if (!closing)
        {
          push(s, current_tag);
        }
        else if (compare(pop(s), current_tag) == 0) // não fecha o último
          return 0;
      }

      open = 0;
      closing = 0;
      n = 0;

      // clean
      for (i = 0; i < STRING_MAX; i++)
        current_tag[i] = 0;
    }
    else if (open)
      current_tag[n++] = c;
    // printf("%c", c);
  }

  return 1;
}

/* */
int main()
{
  FILE *file;

  file = fopen("test.html", "r");
  printf("%d\n", html(file));
  fclose(file);

  return 0;
}
