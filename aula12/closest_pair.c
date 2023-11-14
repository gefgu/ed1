#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "utils.h"

/* */
double brute_force (Points P[], int l, int m, int r) {
  /*Terminar*/	
}

/* */
double closest_pair (Points P[], int l, int r) {
  /*Terminar*/	
}

/* */
int main() {

  //int n = 6;
  //Points P[] ={{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
  //Solution: 1.41421

  int n = 5;
  Points P[] ={{0,2}, {6,67}, {43,71}, {39,107}, {189,140}};
  //Solution: 36.2215

  Points O[n];
  printf("The minimum distance is: %f\n", closest_pair (P, 0, n-1));

  return 0;
}

