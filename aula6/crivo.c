#include <math.h>
#include "list.h"

void crivo(int n)
{
  int i, sq = sqrt(n);
  List *l = create();
  /*Terminar!*/
  for (i = 2; i <= n; i++)
  {
    l = insert_back(l, i);
  }

  List *t;
  for (t = l; t != NULL; t = t->next)
  {
    if (t->data <= sq)
    {
      for (i = t->data + t->data; i <= n; i += t->data)
      {
        l = remove_queue(l, i);
      }
    }
  }

  print(l);

  destroy(l);
}

int main()
{
  int n = 30;
  crivo(n);
  return 0;
}
