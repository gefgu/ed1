#include "graph.h"

/*Função principal.*/
int main () {

   /*Número de vértices*/	
   int V = 5; 

   /*Construindo o grafo mostrado na lista de exercícios:*/
   Graph *G = create (V);

   /*Inserção de arestas (ligações):*/
   add_edge (0, 4, G); 
   add_edge (0, 1, G);
   add_edge (1, 2, G);
   add_edge (1, 3, G);
   add_edge (1, 4, G);
   add_edge (2, 3, G);
   add_edge (3, 4, G);

   print (G);

   printf("# vertices = %d, # arestas = %d\n", G->V, G->E);

   destroy (G);      

   return 0;
}

