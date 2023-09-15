#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RED "\x1B[31m"
#define RESET "\x1B[0m"

#define TRUE 1
#define FALSE 0

/* */
void print(int sudoku[][9], int n)
{
  int r, c, v;
  for (r = 0; r < n; r++)
  {
    for (c = 0; c < n; c++)
    {
      if (sudoku[r][c] == 0)
        printf("  ");
      else
        printf("%d ", sudoku[r][c]);
    }
    printf("\n");
  }
}

void print_styled(int original_sudoku[0][9], int sudoku[][9], int n)
{
  int r, c, v;
  for (r = 0; r < n; r++)
  {
    for (c = 0; c < n; c++)
    {
      if (sudoku[r][c] == 0)
        printf("  ");
      else if (original_sudoku[r][c] == 0)
      {
        printf(RED "%d " RESET, sudoku[r][c]);
      }
      else
        printf("%d ", sudoku[r][c]);
    }
    printf("\n");
  }
}

/* */
void print_failed(int sudoku[][9], int n, int i, int j)
{
  int r, c, v;
  for (r = 0; r < n; r++)
  {
    for (c = 0; c < n; c++)
    {
      if ((r == i) && (c == j))
        printf("* ");
      else if (sudoku[r][c] == 0)
        printf("  ");
      else
        printf("%d ", sudoku[r][c]);
    }
    printf("\n");
  }
}

/* */
int check_row(int sudoku[][9], int r, int n, int v)
{
  int k = 0;
  for (k = 0; k < n; k++)
    if (sudoku[r][k] == v)
      return FALSE;
  return TRUE;
}

/* */
int check_col(int sudoku[][9], int c, int n, int v)
{
  int k = 0;
  for (k = 0; k < n; k++)
    if (sudoku[k][c] == v)
      return FALSE;
  return TRUE;
}

/* */
int check_square(int sudoku[][9], int r, int c, int n, int v)
{
  int i, j = 0;
  int square_r = r / 3;
  int square_c = c / 3;
  for (i = 3 * square_r; i < 3 * (square_r + 1); i++)
    for (j = 3 * square_c; j < 3 * (square_c + 1); j++)
      if (sudoku[i][j] == v)
        return FALSE;
  return TRUE;
}

/* */
int check(int sudoku[][9], int r, int c, int n, int v)
{
  // printf("row %d, col: %d, square: %d\n", check_row(sudoku, r, n, v), check_col(sudoku, c, n, v), check_square(sudoku, r, c, n, v));
  return check_row(sudoku, r, n, v) &&
         check_col(sudoku, c, n, v) &&
         check_square(sudoku, r, c, n, v);
}

/* */
int solve(int original_sudoku[0][9], int sudoku[][9], int n)
{
  struct timespec second, nano = {0, 30000000};
  int r, c, v;
  int i;
  for (r = 0; r < n; r++)
  {
    for (c = 0; c < n; c++)
    {
      if (sudoku[r][c] == 0)
      {
        /*Terminar*/
        for (i = 1; i <= 9; i++)
        {
          if (check(sudoku, r, c, n, i))
          {
            sudoku[r][c] = i;
            system("clear");
            print_styled(original_sudoku, sudoku, n);
            nanosleep(&nano, &second);
            if (solve(original_sudoku, sudoku, n))
              return TRUE;
          }
        }
        sudoku[r][c] = 0;
        return FALSE;
      }
    }
  }
  return TRUE; /*caso base*/
}

/* */
int main()
{

  int n = 9;

  /*int sudoku[9][9] =
      {{5, 3, 0, 0, 7, 0, 0, 0, 0},
       {6, 0, 0, 1, 9, 5, 0, 0, 0},
       {0, 9, 8, 0, 0, 0, 0, 6, 0},
       {8, 0, 0, 0, 6, 0, 0, 0, 3},
       {4, 0, 0, 8, 0, 3, 0, 0, 1},
       {7, 0, 0, 0, 2, 0, 0, 0, 6},
       {0, 6, 0, 0, 0, 0, 2, 8, 0},
       {0, 0, 0, 4, 1, 9, 0, 0, 5},
       {0, 0, 0, 0, 8, 0, 0, 7, 9}};*/

  /*int sudoku[9][9] =
      {{0, 0, 0, 3, 9, 7, 2, 1, 0},
       {3, 0, 7, 4, 1, 8, 6, 0, 9},
       {8, 9, 0, 2, 5, 0, 0, 7, 0},
       {1, 0, 0, 0, 4, 0, 8, 2, 0},
       {2, 8, 4, 1, 0, 0, 0, 9, 0},
       {9, 0, 0, 0, 8, 0, 4, 6, 1},
       {4, 1, 0, 6, 3, 9, 0, 8, 7},
       {5, 0, 9, 8, 7, 4, 1, 0, 2},
       {0, 3, 8, 5, 2, 1, 0, 0, 0}};*/

  int sudoku[9][9] =
      {{0, 0, 0, 4, 3, 0, 6, 0, 5},
       {4, 0, 0, 0, 0, 6, 0, 0, 0},
       {0, 2, 0, 0, 0, 0, 0, 4, 0},
       {0, 0, 3, 0, 4, 0, 0, 0, 8},
       {0, 5, 4, 0, 0, 0, 9, 1, 0},
       {9, 0, 0, 0, 5, 0, 7, 0, 0},
       {0, 7, 0, 0, 0, 0, 0, 6, 0},
       {0, 0, 0, 5, 0, 0, 0, 0, 1},
       {3, 0, 6, 0, 2, 9, 0, 0, 0}};

  /*int sudoku[9][9] =
     {{0,0,0,3,0,7,0,0,8},
      {0,2,0,0,0,8,6,0,0},
      {0,0,1,0,0,6,0,0,0},
      {0,7,6,9,0,0,0,0,5},
      {0,0,4,0,0,0,7,0,0},
      {9,0,0,0,0,2,4,6,0},
      {0,0,0,6,0,0,5,0,0},
      {0,0,9,8,0,0,0,3,0},
      {7,0,0,5,0,1,0,0,0}};*/

  int original_sudoku[9][9];
  int i, j;
  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
      original_sudoku[i][j] = sudoku[i][j];
    }
  }

  printf("Jogo:\n");
  print(sudoku, n);
  printf("\n");

  solve(original_sudoku, sudoku, n);

  printf("Solução:\n");
  print(sudoku, n);
  printf("\n");

  return 0;
}
