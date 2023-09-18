#include "list.h"

List* create_circular (List *head) {
  /*Terminar!*/	
  List* last;
  if(head == NULL) return head;
  for(last = head; last->next != NULL; last = last->next) {}
  head->prev = last;
  last->next = head;
}

int is_circular (List *l) {
  /*Terminar!*/	
  int front = 0;
  int back = 0;
  List* t;

  for(t = l->next; t != NULL && !front; t = t->next) {
    if(t == l)
      front = 1;
  }

  for(t = l->prev; t != NULL && !back; t = t->prev) {
    if(t == l)
      back = 1;
  }


  return front && back;
}

int main () {
  int i;	
  int n = 4;	
  List *l = create ();
  for (i = n; i >= 0; i--) {
    l = insert_front (l, i);
  }
  print (l);
  printf("Is circular: %d\n", is_circular(l));
  l = create_circular(l);
  printf("Is circular: %d\n", is_circular(l));
  return 0;
} 
