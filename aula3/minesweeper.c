#include "pstack.h"

#define TRUE 1
#define FALSE 0

/* */
typedef struct {
  int data;
  int visible;
} Cell;

/* */
int inside (int i, int j, int nrows, int ncols) {
  if ((i < 0) || (j < 0) || (i >= nrows) || (j >= ncols))
    return 0;
  return 1;
}

/* */
int ok (Cell** field, int i, int j, int nrows, int ncols) {
  if (inside (i,j,nrows,ncols) && (field[i][j].data != '*') && (field[i][j].visible == FALSE))
    return 1;
  return 0;
}

/* */
Cell** create_matrix (int nrows, int ncols) {
  int i;
  Cell **matrix = (Cell **)malloc(nrows * sizeof(Cell *));
  for (i = 0; i < nrows; i++) {
    matrix[i] = (Cell *)malloc(ncols * sizeof(Cell));
  }
  return matrix;
}

/* */
void destroy_matrix (Cell **matrix, int nrows, int ncols) {
  int i;
  for (i = 0; i < nrows; i++)
    free (matrix[i]);
  free (matrix);
}

/* */
void initialize (Cell **field, int nrows, int ncols) {
  int i, j;
  for (i = 0; i < nrows; i++) {
    for (j = 0; j < ncols; j++) {
      field[i][j].data = ' '; /*posição sem bomba.*/
      field[i][j].visible = FALSE;
    }
  }
}

/* */
int check (Cell **field, int nrows, int ncols, int mines) {
  int i, j, invisible = 0;
  for (i = 0; i < nrows; i++) 
    for (j = 0; j < ncols; j++) 
      if (field[i][j].visible == FALSE)	    
	invisible++;      
  return (invisible == mines ? 1 : 0);
}

/* */
void add_mines (Cell **field, int nrows, int ncols, int mines) {
  int i = 0;
  srand(time(NULL));
  do {
    int x = rand() % nrows;
    int y = rand() % ncols;
    if (field[x][y].data != '*') {
      field[x][y].data = '*';
      i++;
    }
  } while (i < mines);
}   

/* */
void statistics (Cell **field, int nrows, int ncols) {
  int i, j, k;
  int vx[8] = {-1, -1, -1,  0,  0, +1, +1, +1};
  int vy[8] = {-1,  0, +1, -1, +1, -1,  0, +1};
  for (i = 0; i < nrows; i++) {
    for (j = 0; j < ncols; j++) {
      if (field[i][j].data != '*') {
	int sum = 0;      
	/*Analisando os 8 vizinhos (horizontal,vertical,diagonal):*/
        for (k = 0; k < 8; k++) {
          int si = i + vx[k];
          int sj = j + vy[k];
	  if (inside(si, sj, nrows, ncols) && (field[si][sj].data == '*')) {
            sum++;		  
	  }
	}	  
	if (sum > 0) { field[i][j].data = '0' + sum; }
      }	      
    }
  }
}

/* */
void print_field (Cell **field, int nrows, int ncols, int hide) {
  int i, j;
  printf("  ");
  for (j = 0; j < ncols; j++) 
    printf("%d ", j);
  printf("\n");
  for (i = 0; i < nrows; i++) {
    printf("%d ", i);	    
    for (j = 0; j < ncols; j++) {
      if (field[i][j].visible == TRUE && (field[i][j].data == ' '))	    
	printf(". "); 
      else if (field[i][j].visible == TRUE || (hide == FALSE))	    
	printf("%c ", field[i][j].data); 
      else     
	printf("  "); 
    }
    printf("\n");
  }
}

/* */
void uncover(Cell **field, int nrows, int ncols, int x, int y) {
  int k;	
  if (!field[x][y].visible) {
    Stack *s = create (nrows*ncols); /*worst case scenario*/
    push (s, (point){x,y});
    while (!empty(s)) {
      point p = pop (s);
      /*Terminar!*/      
    }
  }	  
}	

/* */
void build (Cell **field, int nrows, int ncols, int mines) {
  initialize (field, nrows, ncols);
  add_mines (field, nrows, ncols, mines);
  statistics (field, nrows, ncols);
  //print_field (field, nrows, ncols, FALSE);
}

/* */
int main () {
  int mines = 4;	
  int nrows = 10; 
  int ncols = 10; 
  Cell **field = create_matrix (nrows, ncols);
  build (field, nrows, ncols, mines);
  print_field (field, nrows, ncols, TRUE);
  int w = FALSE, l = FALSE;
  do {
    int x, y;	  
    printf ("(x,y) : "); /*sem validação de dados!*/
    scanf ("%d %d", &x, &y);
    if (field[x][y].data == '*') {
      printf ("\n --- Game over :'( ---\n\n");
      l = TRUE;
    }
    else {
      uncover(field, nrows, ncols, x, y);	    
      if (check(field, nrows, ncols, mines)) {
        printf ("\n --- You won :) ---\n\n");
	w = TRUE;  
      }	
    }
    if (w || l) { print_field (field, nrows, ncols, FALSE); }
    else { print_field (field, nrows, ncols, TRUE); }
  } while (!w && !l);
  destroy_matrix (field, nrows, ncols);
  return 0;
}
