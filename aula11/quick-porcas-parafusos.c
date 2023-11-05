#include "utils.h"

int partition(char *porcas, char *parafusos, int left, int right)
{
  // Primeiro joga o match na direita
  // Depois ordena o resto

  int i, j, pivo, flag = 1;

  pivo = parafusos[right];
  for (i = left; i <= right && flag; i++)
  {
    if (porcas[i] == pivo)
    {
      swap_char(porcas, i, right);
      flag = 0;
    }
  }

  // particiona parafusos

  i = left - 1;
  for (j = left; j <= right - 1; j++)
  {
    if (parafusos[j] < pivo)
    {
      i++;
      swap_char(parafusos, j, i);
    }
  }
  swap_char(parafusos, right, i + 1);

  // particiona porcas
  i = left - 1;
  for (j = left; j <= right - 1; j++)
  {
    if (porcas[j] < pivo)
    {
      i++;
      swap_char(porcas, j, i);
    }
  }
  swap_char(porcas, right, i + 1);

  return i + 1;
}

void quick_sort(char *porcas, char *parafusos, int left, int right)
{
  /*Terminar*/
  int p;
  if (left < right)
  {
    p = partition(porcas, parafusos, left, right);
    quick_sort(porcas, parafusos, left, p - 1);
    quick_sort(porcas, parafusos, p + 1, right);
  }
}

/* */
int main(int argc, char *argv[])
{
  int str_tam = 6;
  char porcas[7] = "@#$%^&";
  char parafusos[7] = "$%&^#@";
  printf("Porcas: %s\n", porcas);
  printf("Parafusos: %s\n", parafusos);
  printf("\n");

  quick_sort(porcas, parafusos, 0, str_tam - 1);

  printf("Porcas: %s\n", porcas);
  printf("Parafusos: %s\n", parafusos);

  return 0;
}
