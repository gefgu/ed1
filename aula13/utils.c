#include "utils.h"

/* */
void swap (int *A, int i, int j) {
  int t = A[i];
  A[i] = A[j];
  A[j] = t;
}

/* */
void swap_char (char *A, int i, int j) {
  char t = A[i];
  A[i] = A[j];
  A[j] = t;
}

/* */
void swap_string (char **A, int i, int j) {
  char *t = A[i];
  A[i] = A[j];
  A[j] = t;
}

/* */
void print (int *A, int n, char *message) {
  printf("%s\n", message);
  int i;
  printf("A: {");
  for (i = 0; i < n; i++) {
    if (i == n-1)
      printf("%d", A[i]);
    else    
      printf("%d,", A[i]);
  }
  printf("}\n");
}

/* */
void print_float (double *A, int n, char *message) {
  printf("%s\n", message);
  int i;
  printf("A: {");
  for (i = 0; i < n; i++) {
    if (i == n-1)
      printf("%f", A[i]);
    else    
      printf("%f,", A[i]);
  }
  printf("}\n");
}

/* */
void print_char (char *A, int n, char *message) {
  printf("%s\n", message);
  int i;
  printf("A: {");
  for (i = 0; i < n; i++) {
    if (i == n-1)
      printf("%c", A[i]);
    else    
      printf("%c,", A[i]);
  }
  printf("}\n");
}

/* */
void partition_print (int *A, int left, int right, int rlevel) {
  int i, r;
  for (r = 0; r < rlevel; r++) { printf ("    "); }	
  printf("P: {");
  for (i = left; i <= right; i++) {
    if (i == right)
      printf("%d", A[i]);
    else    
      printf("%d,", A[i]);
  }
  printf("}\n");
}

/* */
int check (int *A, int n, int ascending) {
  int i;
  for (i = 1; i < n; i++) {
    if (ascending) {
      if (A[i-1] > A[i]) 
        return FALSE;	  
      	
    }
    else {
      if (A[i-1] < A[i]) 
        return FALSE;	  
    }    
  }
  return TRUE;  
}

/* */
int check_float (double *A, int n, int ascending) {
  int i;
  for (i = 1; i < n; i++) {
    if (ascending) {
      if (A[i-1] > A[i]) 
        return FALSE;	  
      	
    }
    else {
      if (A[i-1] < A[i]) 
        return FALSE;	  
    }    
  }
  return TRUE;  
}
