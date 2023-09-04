#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct _no {
   int id; /*Identificador armazenado no nó. */
   struct _no *next; /*Próximo nó na lista encadeada. */
} No;

/*Estrutura de Grafo por lista de adjacências: */
typedef struct {
   int E; /*Quantidade de arestas.*/
   int V; /*Quantidade de vértices.*/
   No **list; /*Listas de adjacências (uma por vértice).*/
} Graph;

/*Cria um grafo com {V} listas de adjacência.*/
Graph* create (int V);

/*Libera memória de um grafo representado por lista de adjacências.*/
void destroy (Graph *G);

/*Imprime um grafo representado por lista de adjacências.*/
void print (Graph *G);

/*Insere uma ligação entre os vértices {u,v} e {v,u} em {G}.*/
void add_edge (int u, int v, Graph *G);
