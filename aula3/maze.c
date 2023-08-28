#include "pstack.h"

#define n 10
#define TRUE 1
#define FALSE 0

int inside (int i, int j, int nrows, int ncols) {
  if ((i < 0) || (j < 0) || (i >= nrows) || (j >= ncols))
    return 0;
  return 1;
}

void print_maze (char maze[][n], int nrows, int ncols) {
  int i, j;
  for (i = 0; i < nrows; i++) {
    for (j = 0; j < ncols; j++) {
      if (maze[i][j] == 'v' || maze[i][j] == '$')	    
         printf("  ");	   
      else 
         printf("%c ", maze[i][j]);	    
    }	    
    printf("\n");
  }
  printf("\n\n");
}

void solve (char maze[][n], point start, point end) {
  int k;	
  print_maze (maze, n, n);
  Stack *s = create (n*n); /*worst case scenario*/
  push (s, start);
  while (!empty(s)) {
    point p = get_peek (s);
    maze[p.x][p.y] = '*';
    if ( (p.x == end.x) && (p.y == end.y) ) {
      /*saída*/	    
      break;	    
    }
    /*Terminar*/  
  }
  print_maze (maze, n, n);
  destroy (s);
}

int main () {

  //point start = {0,0};
  point start = {9,2};
  //point end = {9,9};
  point end = {6,7};

  char maze[][n] = {
      {' ','#',' ','#',' ','#','#',' ',' ',' '},
      {' ','#',' ','#',' ','#','#',' ','#',' '},
      {' ',' ',' ',' ',' ',' ',' ',' ','#',' '},
      {' ','#','#','#','#','#','#','#','#',' '},
      {' ','#','#','#','#','#','#',' ',' ',' '},
      {' ','#',' ',' ',' ',' ','#',' ','#','#'},
      {' ','#',' ','#',' ','#','#',' ','#','#'},
      {' ',' ',' ','#',' ',' ','#','#','#','#'},
      {' ','#',' ','#','#',' ','#','#','#','#'},
      {' ','#',' ','#','#',' ',' ',' ',' ',' '}};

  solve (maze, start, end);

  return 0;
}
