#include "plist.h"

/* */
List* create () {
  return NULL;	
}

/* */
List* insert (List *l, poly p) {
  List *node = (List *)malloc(sizeof(List));
  node->p = p;
  node->next = l;
  return node;
}

/* */
void print (List *l) {
  List *t;
  printf ("Poly: ");
  for (t = l; t != NULL; t = t->next) {
    if (t->p.c != 0) {	  
      printf ("%d^%d", t->p.c, t->p.d);
      if ((t->next != NULL) && (t->next->p.c > 0)) { printf ("+"); }
    }  
  }  
  printf("\n");
}

/* */
void destroy (List *l) {
  if (l != NULL) {	
    List *t = l->next; 
    free (l); 
    l = t;    
  }  
}
