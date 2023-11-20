#include "utils.h"

/* */
void counting_sort(FILE *f, int range)
{
  int i, j, total = 0;
  int *C = (int *)malloc((range + 1) * sizeof(int)); /*contador*/
  /*Terminar*/
  /*Imprimir no final desta função as frequências das letras!*/
  for (i = 0; i <= range; i++)
  {
    C[i] = 0;
  }

  char c;

  while (!feof(f))
  {
    fscanf(f, "%c", &c);
    if (isalpha(c))
    {
      C[tolower(c) - 'a']++;
    }
  }

  float sum = 0;

  for (i = 0; i <= range; i++)
  {
    sum += C[i];
  }

  printf("Letra \t Contagem \t Frequência\n");
  for (i = 0; i <= range; i++)
  {
    printf("%c \t %d \t \t %.4f \n", 'a' + i, C[i], (float)C[i] / sum);
  }
}

/* */
int main(int argc, char *argv[])
{

  if (argc < 2)
  {
    printf("run: %s file.txt\n", argv[0]);
    exit(1);
  }

  FILE *f = fopen(argv[1], "r");

  int range = 25; /*número de letras do alfabeto (a-z)*/

  counting_sort(f, range);

  fclose(f);

  return 0;
}
