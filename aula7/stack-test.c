#include "list.h"

int main()
{

  List *stack = create();

  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  print_head_to_tail(stack);
  pop(stack);
  print_head_to_tail(stack);
  printf("%d \n", peek(stack));
  pop(stack);
  printf("%d \n", empty_stack(stack));
  pop(stack);
  printf("%d \n", empty_stack(stack));

  return 0;
}