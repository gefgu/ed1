#include "graph.h"

/* */
void free_list (No *l) {
  while (l != NULL) {
    No *t = l->next; 
    free (l); 
    l = t; 
  }
}

/* */
Graph* create (int V) {
  Graph *G = (Graph *)malloc(sizeof(Graph));
  G->E = 0;
  G->V = V;
  G->list = (No **)malloc(G->V * sizeof(No *));
  int i;
  /*Uma lista de adjacência por vértice:*/ 
  for (i = 0; i < G->V; i++) 
    G->list[i] = NULL; 
  return G;
}

/* */
void destroy (Graph *G) {
  int i;	
  for (i = 0; i < G->V; i++) 
    free_list (G->list[i]);	   
  free (G->list);
  free (G);
}

/* */
void print (Graph *G) {
  int i;	
  for (i = 0; i < G->V; i++) {
    No *v = G->list[i];
    No *tmp = v;
    printf("%d -> ", i);
    for (tmp = v; tmp != NULL; tmp = tmp->next) {
      printf ("%d ", tmp->id);     
    }
    printf("\n");
  }	
}

/* Escrever o código para adicionar a aresta {u,v} em {G} */
void _add_edge (int u, int v, Graph *G) {
  /*Terminar!*/	
}

/*Adiciona arestas {u,v} e {v,u} (grafo não direcionado) */
void add_edge (int u, int v, Graph *G) {
  _add_edge (u, v, G);
  _add_edge (v, u, G);
  G->E++;
}


