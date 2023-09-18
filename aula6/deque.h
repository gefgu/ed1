#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 18

typedef struct {
  int x;
  int y;
} Point;

typedef struct deck {
  Point p;
  struct deck *next;
  struct deck *prev;
} Deque;

/*Cria um deck vazio.*/
Deque* create_deque ();

/*Adiciona um item na cabeça da lista.*/
Deque* insert_front (Deque *q, Point p, char field[][SIZE]);  

/*Adiciona um item na cauda da lista.*/
Deque* insert_back (Deque *q, Point p, char field[][SIZE]);  

/*Remove um item da cabeça da lista.*/
Deque* delete_front (Deque *q, char field[][SIZE]);          

/*Remove um item da cauda da lista.*/
Deque* delete_back (Deque *q, char field[][SIZE]);           

/*Retorna sem remover o item na cabeça da lista.*/
Point get_front (Deque *q);                                 

/*Retorna sem remover o item na cauda da lista.*/
Point get_back (Deque *q);                                  

