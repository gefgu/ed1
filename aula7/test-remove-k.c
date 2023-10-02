#include "list.h"

int main()
{

   List *l = create();

   int i;
   for (i = 0; i <= 5; i++)
   {
      insert_back(l, i);
   }
   printf("Lista após inserções: \n");
   print_head_to_tail(l);
   print_tail_to_head(l);
   printf("--------------------- \n");

   int elimacoes[] = {5, 2, 0, 1, 4};
   for (i = 0; i < 5; i++)
   {
      printf("Eliminando: %d\n", elimacoes[i]);
      remove_k(l, elimacoes[i]);
      print_head_to_tail(l);
      print_tail_to_head(l);
      printf("--------------------- \n");
   }

   destroy(l);

   return 0;
}
