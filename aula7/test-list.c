#include "list.h"

int main () {

   List *l = create ();
   
   insert_front (l, 2);   
   print_head_to_tail (l); 
   print_tail_to_head (l); 

   insert_back (l, 3);   
   print_head_to_tail (l); 
   print_tail_to_head (l);

   insert_front (l, 4);   
   print_head_to_tail (l); 
   print_tail_to_head (l);

   insert_back (l, 1);  
   print_head_to_tail (l); 
   print_tail_to_head (l); 

   printf("Middle element: %d\n", middle(l));

   remove_front (l);
   print_head_to_tail (l); 
   print_tail_to_head (l); 

   remove_back (l);
   print_head_to_tail (l); 
   print_tail_to_head (l); 

   remove_front (l);
   print_head_to_tail (l); 
   print_tail_to_head (l); 

   remove_back (l);
   print_head_to_tail (l); 
   print_tail_to_head (l); 

   destroy (l);

   return 0;
} 
