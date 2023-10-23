#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* */
typedef struct
{
  char nome[256];
  int idade;
} Cadastro;

/* */
void print(Cadastro *A, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("Pessoa: %s, idade: %d\n", A[i].nome, A[i].idade);
  }
}

/* */
void swap(Cadastro *A, int i, int j)
{
  Cadastro tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
}

/* */
void selection_sort(Cadastro *A, int n)
{
  /*Terminar*/
  int i, j, smallest;
  for (i = 0; i < n - 1; i++)
  {
    smallest = i;
    for (j = i + 1; j < n; j++)
    {
      // A[j].nome é menor que A[smallest].nome
      if (strcmp(A[j].nome, A[smallest].nome) < 0)
      {
        smallest = j;
      }
    }
    swap(A, i, smallest);
  }
}

/* */
void insertion_sort(Cadastro *A, int n)
{
  /*Terminar*/
  int i, j;
  Cadastro key;
  for (i = 0; i < n - 1; i++)
  {
    key = A[i + 1];

    // key.nome é menor que A[j-1].nome
    for (j = i + 1; j > 0 && strcmp(key.nome, A[j - 1].nome) < 0; j--)
    {
      A[j] = A[j - 1];
    }
    A[j] = key;
  }
}

/* */
int main(int argc, char *argv[])
{

  int i;
  int n = 5;
  Cadastro *A = (Cadastro *)malloc(n * sizeof(Cadastro));

  strcpy(A[0].nome, "João da Silva");
  A[0].idade = 1980;

  strcpy(A[1].nome, "Maria de Souza");
  A[1].idade = 1935;

  strcpy(A[2].nome, "Zumira dos Santos");
  A[2].idade = 1970;

  strcpy(A[3].nome, "João da Silva");
  A[3].idade = 2020;

  strcpy(A[4].nome, "Ana Pereira");
  A[4].idade = 2005;

  printf("Entrada: \n");
  print(A, n);
  printf("\n");

  // selection_sort (A, n);
  insertion_sort(A, n);

  printf("Ordenação: \n");
  print(A, n);
  printf("\n");

  free(A);
  return 0;
}
