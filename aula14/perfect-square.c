#include "utils.h"

/* */
int perfect_square (int n) {
  /*Terminar*/	
} 

/* */
int main () {
  int i;
  int n = 100;
  for (i = 1; i < n; i++) {
    if (perfect_square(i)) {
      printf("Número %d é um quadrado perfeito.\n", i);
    }
  }  
  return 0;
}
