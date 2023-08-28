#include "stack.h"
#include <time.h>

#define SIZE 10

void game(Stack *stack_player_a, Stack *stack_player_b)
{
  int a, b, val, i;
  while (!empty(stack_player_a) && !empty(stack_player_b))
  {
    a = pop(stack_player_a);
    b = pop(stack_player_b);
    if (a > b)
    {
      val = a - b;
      for (i = 0; i < val && !empty(stack_player_a); i++)
        push(stack_player_b, pop(stack_player_a));
    }
    else if (a < b)
    {
      val = b - a;
      for (i = 0; i < val && !empty(stack_player_b); i++)
        push(stack_player_a, pop(stack_player_b));
    }
  }

  if (empty(stack_player_a))
    printf("O jogador A ganhou!!!\n");
  else
    printf("O jogador B ganhou!!!\n");
}

int main()
{
  srand(time(NULL));
  Stack *stack_player_a = create(SIZE * 2); // 2 * para caber tudo em um só no pior caso
  Stack *stack_player_b = create(SIZE * 2);
  int i;

  for (i = 0; i < SIZE; i++)
    push(stack_player_a, rand() % 30);

  for (i = 0; i < SIZE; i++)
    push(stack_player_b, rand() % 30);

  game(stack_player_a, stack_player_b);

  return 0;
}
