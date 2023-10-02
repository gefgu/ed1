#include "list.h"

int main()
{

  List *queue = create();

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  print_head_to_tail(queue);
  dequeue(queue);
  print_head_to_tail(queue);
  printf("%d \n", front(queue));
  dequeue(queue);
  printf("%d \n", empty_queue(queue));
  dequeue(queue);
  printf("%d \n", empty_queue(queue));

  return 0;
}