#include "queue.h"

/*Função que cria e inicializa uma fila de tamanho {size}.*/
Queue *create_queue (int size) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = 0;
  q->back = 0;
  q->size = size;
  q->array = (int *)malloc(size * sizeof(int));
  return q;
}

/*Função para enfileirar {elem} na fila {q}.*/
void enqueue (Queue *q, int elem) {
  if (full_queue(q)) {
    printf ("error: queue overflow!\n");
    exit(1);
  }	  
  q->array[q->back] = elem;
  q->back = (q->back + 1) % q->size;
}

/*Função para desenfileirar o primeiro elemento da fila {q}.*/
int dequeue (Queue *q) {
  if (empty_queue(q)) {
    printf ("error: queue underflow!\n");
    exit(1);
  }	  
  int e = q->array[q->front];
  q->front = (q->front + 1) % q->size;
  return e;
}

/*Função que retorna mas não remove o primeiro elemento de {q}.*/
int front (Queue *q) {
  if (!empty_queue(q)) 
    return q->array[q->front];	  
  else 
    return ERROR;
}

/*Função que verifica se a fila {q} está vazia (true) ou não {false}.*/
int empty_queue (Queue *q) {
  return (q->front == q->back);	
}

/*Função que verifica se a fila {q} está cheia (true) ou não {false}.*/
int full_queue (Queue *q) {
  return (q->front == ((q->back + 1) % q->size));	
}

/*Função que imprime uma fila {q}.*/
void print_queue (Queue *q) {
  int i;
  printf("Queue: (peak) ");
  for (i = q->front; i != q->back; i = (i+1) % q->size) {
    printf ("%d ", q->array[i]);	  
  }
  printf("\n");
}

/*Função que desaloca as estruturas de uma fila {q}.*/
void destroy_queue (Queue *q) {
  free (q->array);
  free (q);
}

/*Função que retorna o número de elementos alocados no array*/
int getsize_queue (Queue *q) {
  return q->size;
}

