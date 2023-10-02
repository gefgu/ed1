#include "list.h"

int palindrome(List *l)
{
  Node *h = l->head;
  Node *t = l->tail;

  while (h != NULL && t != NULL)
  {
    if (h->data != t->data)
      return 0;

    h = h->next;
    t = t->prev;
  }

  return 1;
}

int main()
{

  List *l = create();

  insert_front(l, 1);
  insert_front(l, 2);
  insert_front(l, 2);
  insert_front(l, 1);
  print_head_to_tail(l);

  printf("Palindrome: %d\n", palindrome(l));

  remove_front(l);

  printf("Palindrome: %d\n", palindrome(l));

  destroy(l);

  return 0;
}
