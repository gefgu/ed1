#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int inicio;
  int fim;
} reuniao;

int trivial(reuniao *reunioes, int numero_de_reunioes)
{
  int i, j;

  for (i = 0; i < numero_de_reunioes; i++)
  {
    for (j = i + 1; j < numero_de_reunioes; j++)
    {
      int condicao_nao_pode_iniciar = reunioes[i].inicio < reunioes[j].fim && reunioes[i].inicio >= reunioes[j].inicio;
      int condicao_nao_pode_acabar = reunioes[i].fim > reunioes[j].inicio && reunioes[i].fim <= reunioes[j].fim;
      if (condicao_nao_pode_iniciar || condicao_nao_pode_acabar)
      {
        return 0;
      }
    }
  }

  return 1;
}

void merge_reunioes(reuniao *reunioes, int left, int mid, int right, reuniao *O)
{
  int i = left;
  int j = mid + 1;
  int k = left;
  while (i <= mid && j <= right)
  {
    if (reunioes[i].inicio <= reunioes[j].inicio)
      O[k++] = reunioes[i++];
    else
      O[k++] = reunioes[j++];
  }

  while (i <= mid)
    O[k++] = reunioes[i++];

  while (j <= right)
    O[k++] = reunioes[j++];

  for (i = left; i <= right; i++)
    reunioes[i] = O[i];
}

void merge_sort_reunioes(reuniao *reunioes, int left, int right, reuniao *O)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    merge_sort_reunioes(reunioes, left, mid, O);
    merge_sort_reunioes(reunioes, mid + 1, right, O);
    merge_reunioes(reunioes, left, mid, right, O);
  }
}

int elegante(reuniao *reunioes, int numero_de_reunioes, reuniao *O)
{
  merge_sort_reunioes(reunioes, 0, numero_de_reunioes - 1, O);

  int i;
  for (i = 0; i < numero_de_reunioes - 1; i++)
  {
    if (reunioes[i].fim > reunioes[i + 1].inicio)
      return 0;
  }

  return 1;
}

int main()
{
  /* Exemplo 1 */

  reuniao R[3] = {{15, 20}, {0, 30}, {5, 10}};
  reuniao O[3];

  int resposta_trivial = trivial(R, 3);
  int resposta_elegante = elegante(R, 3, O);

  /* Exemplo 2 */

  // reuniao R[2] = {{7, 10}, {2, 4}};
  // reuniao O[2];

  // int resposta_trivial = trivial(R, 2);
  // int resposta_elegante = elegante(R, 2, O);

  /* Printa Resultados */

  printf(resposta_trivial ? "True\n" : "False\n");
  printf(resposta_elegante ? "True\n" : "False\n");

  return 0;
}
