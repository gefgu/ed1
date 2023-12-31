#include <string.h>
#include <math.h>
#include "utils.h"

/* */
void sort(char **A, int n)
{
  /*Terminar*/
  int i, j;
  char *key;
  for (i = 0; i < n - 1; i++)
  {
    key = A[i + 1];
    // key é menor que A[j]
    for (j = i + 1; j > 0 && strcmp(key, A[j - 1]) < 0; j--)
    {
      A[j] = A[j - 1];
    }
    A[j] = key;
  }
}

/* */
int get_number_of_lines(FILE *f)
{
  int n = 0;
  if (f == NULL)
    return n;
  while (!feof(f))
  {
    char c;
    fscanf(f, "%c", &c);
    if (c == '\n')
      n++;
  }
  rewind(f);
  return (n - 1);
}

/* */
int main(int argc, char *argv[])
{
  FILE *f = fopen("palavras.txt", "r");
  int n = get_number_of_lines(f);
  char **words = (char **)malloc(n * sizeof(char *));
  int i;
  for (i = 0; i < n; i++)
    words[i] = (char *)malloc(256 * sizeof(char));
  i = 0;
  while (!feof(f))
  {
    fscanf(f, "%s", words[i]);
    i++;
  }
  sort(words, n);
  for (i = 0; i < n; i++)
    printf("%s\n", words[i]);
  for (i = 0; i < n; i++)
    free(words[i]);
  free(words);
  fclose(f);
  return 0;
}
