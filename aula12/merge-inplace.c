#include "utils.h"

/*Função intercalar*/
void merge(int A[], int l, int m, int r)
{
  /*Terminar*/

  /* EX 3 */

  // 1)
  // Quando avança no lado direito, pode não deixar aquele cara ordenada.
  // É o que acontece nos testes. Tem canos em que não é ordenado corretamente.
  // int i = 0, j = m+1;
  // while((i <= m) && (j <= r)) {
  //   if(A[i] <= A[j])
  //     i++;
  //   else {
  //     swap(A, i, j);
  //     i++;
  //     j++;
  //   }
  // }

  // 2)
  // Parece que sempre funciona.
  // Tem o custo dos swaps.
  // Funciona deixando o lado esquerdo com os menores
  // E o direito com os maiores
  int i = 0, j = m + 1;
  while ((i <= m) && (j <= r))
  {
    if (A[i] <= A[j])
      i++;
    else
    {
      swap(A, i, j);
      i++;
    }
  }

  /* EX 4 */
  // Pega o primeiro elemento da direita
  // E encaixa ele no resto do array
  // usando algo parecido como o insertion sort.
  // Depois faz para todos os elementos
  // Do lado direito
  // while (m <= r)
  // {
  //   int c = A[m], i;
  //   for (i = m - 1; (i >= 1) && (A[i] > c); i--)
  //   {
  //     A[i + 1] = A[i];
  //   }
  //   A[i + 1] = c;
  //   m++;
  // }
}

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort(int A[], int l, int r)
{
  if (l < r)
  {
    int m = (l + r) / 2;
    merge_sort(A, l, m);
    merge_sort(A, m + 1, r);
    merge(A, l, m, r);
  }
}

/* */
int main()
{
  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));
  int n = 10, i; /*quantidade de elementos*/
  int *A = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
  {
    A[i] = rand() % (n + 1); /*valores aleatórios*/
    // A[i] = i;   /*valores em ordem crescente*/
    // A[i] = n-i; /*valores em ordem descrescente*/
    // A[i] = 0;   /*valores iguais*/
  }
  start = clock();
  print(A, n, "Input");
  merge_sort(A, 0, n - 1);
  print(A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE))
  {
    printf("Error: non-ascending order!\n");
  }
  return 0;
}
