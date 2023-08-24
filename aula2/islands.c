#include "pqueue.h"

int inside (int i, int j, int n) {
  if ((i < 0) || (j < 0) || (i >= n) || (j >= n))
    return 0;
  return 1;    
}

void print_matrix (char M[][10], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%c ", M[i][j]);
    }
    printf("\n");
  }   
}

void conquer (char M[][10], int i, int j, int n, int nlabel) {
  Queue *q = create((n*n)+1); /*supondo pior caso*/
  enqueue (q, (point){i,j});
  M[i][j] = ' ';
  while (!empty(q)) {
    point p = dequeue (q);
    /*Terminar*/
  }
  destroy (q); 
}

int count_islands (char M[][10], int n) {
  int i, j, sum = 0;	
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (M[i][j] == '*') {
	sum++;
        conquer (M, i, j, n, sum);     
      }	      
    }	     
  }
  return sum;
}

int main () {

  int n = 10;

  char M[][10] = 
    { {'*',' ','*',' ',' ',' ','*','*','*','*'}, 
      {' ',' ','*',' ','*',' ','*',' ',' ',' '},	    
      {'*','*','*','*',' ',' ','*',' ',' ',' '},
      {'*',' ',' ','*',' ',' ',' ',' ',' ',' '},
      {'*','*','*','*',' ',' ',' ','*','*','*'},
      {' ','*',' ','*',' ',' ','*','*','*','*'},
      {' ',' ',' ',' ',' ','*','*','*',' ',' '},
      {' ',' ',' ','*',' ',' ','*','*','*',' '},
      {'*',' ','*',' ','*',' ',' ','*',' ',' '},
      {'*','*','*','*',' ',' ',' ','*','*','*'} 
    } ;

  print_matrix (M, n);
  printf("Número de ilhas: %d\n", count_islands (M, n));
  print_matrix (M, n);
  return 0; 
}
