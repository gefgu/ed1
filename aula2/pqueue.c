#include "pqueue.h"

/*Função que cria e inicializa uma fila de tamanho {size}.*/
Queue *create (int size) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = 0;
  q->back = 0;
  q->size = size;
  q->array = (point *)malloc(size * sizeof(point));
  return q;
}

/*Função para enfileirar {elem} na fila {q}.*/
void enqueue (Queue *q, point elem) {
  if (full(q)) {
    printf ("error: queue overflow!\n");
    exit(1);
  }	 
  q->array[q->back] = elem;
  q->back = (q->back + 1) % q->size;
}

/*Função para desenfileirar o primeiro elemento da fila {q}.*/
point dequeue (Queue *q) {
  if (empty(q)) {
    printf ("error: queue underflow!\n");
    exit(1);
  }	  
  point e = q->array[q->front];
  q->front = (q->front + 1) % q->size;
  return e;
}

/*Função que retorna mas não remove o primeiro elemento de {q}.*/
point front (Queue *q) {
  if (!empty(q)) 
    return q->array[q->front];	  
}

/*Função que verifica se a fila {q} está vazia (true) ou não {false}.*/
int empty (Queue *q) {
  return (q->front == q->back);	
}

/*Função que verifica se a fila {q} está cheia (true) ou não {false}.*/
int full (Queue *q) {
  return (q->front == ((q->back + 1) % q->size));	
}

/*Função que desaloca as estruturas de uma fila {q}.*/
void destroy (Queue *q) {
  free (q->array);
  free (q);
}

/*Função que retorna o número de elementos alocados no array*/
int getsize (Queue *q) {
  return q->size;
}
