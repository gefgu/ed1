#include "pqueue.h"
#include <time.h>
#include <unistd.h>

#define N 10

int inside(int i, int j, int n)
{
  if ((i < 0) || (j < 0) || (i >= n) || (j >= n))
    return 0;
  return 1;
}

void print_matrix(char M[][N], int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%c ", M[i][j]);
    }
    printf("\n");
  }
}

void show(char M[][N], int n)
{
  system("clear");
  print_matrix(M, n);
  sleep(1);
}

void conquer(char M[][N], int i, int j, int n, int nlabel)
{
  show(M, n);
  Queue *q = create((n * n) + 1); /*supondo pior caso*/
  enqueue(q, (point){i, j});
  int k, l;
  int x, y, flag;
  M[i][j] = '0' + nlabel;
  show(M, n);
  while (!empty(q))
  {
    point p = dequeue(q);
    flag = (M[p.x][p.y] != '*');
    M[p.x][p.y] = '0' + nlabel;
    if (!flag)
      show(M, n);
    // box around
    for (k = 0; k < 3; k++)
    {
      for (l = 0; l < 3; l++)
      {
        x = p.x - 1 + k;
        y = p.y - 1 + l;
        if (inside(x, y, N) && M[x][y] == '*')
        {
          enqueue(q, (point){x, y});
          M[x][y] = '0' + nlabel;
          show(M, n);
        }
      }
    }
  }
  destroy(q);
}

int count_islands(char M[][N], int n)
{
  int i, j, sum = 0;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (M[i][j] == '*')
      {
        sum++;
        conquer(M, i, j, n, sum);
      }
    }
  }
  return sum;
}

int main()
{

  int n = N;

  char M[][N] =
      {{'*', ' ', '*', ' ', ' ', ' ', '*', '*', '*', '*'},
       {' ', ' ', '*', ' ', '*', ' ', '*', ' ', ' ', ' '},
       {'*', '*', '*', '*', ' ', ' ', '*', ' ', ' ', ' '},
       {'*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' '},
       {'*', '*', '*', '*', ' ', ' ', ' ', '*', '*', '*'},
       {' ', '*', ' ', '*', ' ', ' ', '*', '*', '*', '*'},
       {' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' '},
       {' ', ' ', ' ', '*', ' ', ' ', '*', '*', '*', ' '},
       {'*', ' ', '*', ' ', '*', ' ', ' ', '*', ' ', ' '},
       {'*', '*', '*', '*', ' ', ' ', ' ', '*', '*', '*'}};

  print_matrix(M, n);
  int islands = count_islands(M, n);
  system("clear");
  printf("Número de ilhas: %d\n", islands);
  print_matrix(M, n);
  return 0;
}
