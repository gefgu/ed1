#include "list.h"

int max(int a, int b)
{
  if (a >= b)
    return a;
  return b;
}

int max_itr(List *l)
{
  if (l != NULL)
  {
    int max = l->data;
    List *t = l->next;
    while (t != NULL)
    {
      if (t->data > max)
        max = t->data;
      t = t->next;
    }
    return max;
  }
  return ERROR;
}

int max_rec(List *l)
{
  if (l == NULL)
    printf("EMPTY LIST\n");
  else if (l->next == NULL)
    return l->data;

  return max(l->data, max_rec(l->next));
}

int main()
{
  List *l = create();
  l = insert_back(l, 5);
  l = insert_back(l, 6);
  l = insert_back(l, 7);
  l = insert_back(l, 0);
  l = insert_back(l, 9);
  l = insert_back(l, -2);
  l = insert_back(l, 3);
  l = insert_back(l, 2);
  l = insert_back(l, 1);
  l = insert_back(l, 0);

  print(l);
  printf("\nInterativo: %d\n", max_itr(l));
  printf("Recursive: %d\n", max_rec(l));

  return 0;
}