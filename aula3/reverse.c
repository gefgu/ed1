#include "stack.h"
#include "queue.h"

/* */
void reverse (Queue *q) {
  /*Terminar*/	
}

/* */
int main () {
  int i, n = 10;
  Queue *q = create_queue (n+1);
  for (i = 0; i < n; i++) 
    enqueue (q, i);
  print_queue(q);  
  reverse (q);
  print_queue(q);  
  destroy_queue (q);
  return 0;
}
