#include "list.h"
#include <time.h>

/* */
void print_reverse(List *l)
{
  List *t = l;
  List *reversed = create();
  while (t != NULL)
  {
    reversed = insert(reversed, t->data);
    t = t->next;
  }

  print(reversed);
}

/* */
int main()
{
  srand(time(NULL));
  int i, n;
  List *A = create();
  for (i = 0; i < 10; i++)
  {
    n = rand() % 50;
    A = insert(A, n);
  }
  print(A);
  print_reverse(A);

  destroy(A);

  return 0;
}
