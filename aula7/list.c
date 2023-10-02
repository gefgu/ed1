#include "list.h"

/**/
List *create()
{
  List *l = (List *)malloc(sizeof(List));
  l->head = NULL;
  l->tail = NULL;
  return l;
}

/**/
void insert_front(List *l, int elem)
{
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = elem;
  n->prev = NULL;
  if (l->head != NULL)
  {
    n->next = l->head;
    l->head->prev = n;
  }
  else
  {
    n->next = NULL;
    l->tail = n;
  }
  l->head = n;
}

/**/
void insert_back(List *l, int elem)
{
  /*Terminar!*/
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = elem;
  n->next = NULL;
  if (l->tail != NULL)
  {
    l->tail->next = n;
    n->prev = l->tail;
  }
  else
  {
    n->prev = NULL;
    l->head = n;
  }
  l->tail = n;
}

/**/
void remove_front(List *l)
{
  if (l->head != NULL)
  {
    Node *n = l->head->next;
    free(l->head);
    if (n != NULL)
      n->prev = NULL;
    else
      l->tail = NULL;
    l->head = n;
  }
}

/**/
void remove_back(List *l)
{
  if (l->tail != NULL)
  {
    Node *p = l->tail->prev;
    /*Terminar!*/
    free(l->tail);
    if (p != NULL)
    {
      p->next = NULL;
    }
    else
    {
      l->head = NULL;
    }
    l->tail = p;
  }
}

/**/
Node *search(List *l, int k)
{
  if (l != NULL)
  {
    Node *n = l->head;
    while (n != NULL)
    {
      if (n->data == k)
        return n;
      n = n->next;
    }
  }
  return NULL;
}

/**/
void remove_k(List *l, int k)
{
  if (l != NULL)
  {
    if (l->head != NULL)
    {
      Node *h = l->head; /*head pointer*/
      Node *t = l->tail; /*tail pointer*/
      /*Terminar!*/
      while (h != NULL && h->data != k)
        h = h->next;

      if (h != NULL) // é igual a k
      {
        if (h->prev != NULL)
          h->prev->next = h->next;
        else
          l->head = h->next;
        if (h->next != NULL)
          h->next->prev = h->prev;
        else
          l->tail = h->prev;
        free(h);
      }
    }
  }
}

/**/
void print_head_to_tail(List *l)
{
  Node *t;
  /*Terminar!*/
  t = l->head;
  while (t != NULL)
  {
    printf("%d ", t->data);
    t = t->next;
  }
  printf("\n");
}

/**/
void print_tail_to_head(List *l)
{
  Node *t;
  /*Terminar!*/
  t = l->tail;
  while (t != NULL)
  {
    printf("%d ", t->data);
    t = t->prev;
  }
  printf("\n");
}

/**/
int middle(List *l)
{
  /*Terminar*/
}

/**/
void destroy(List *l)
{
  if (l != NULL)
  {
    Node *h = l->head;
    while (h != NULL)
    {
      Node *t = h->next;
      free(h);
      h = t;
    }
  }
}

void enqueue(List *l, int elem)
{
  insert_back(l, elem);
}

int dequeue(List *l)
{
  remove_front(l);
}

int front(List *l)
{
  if (l->head != NULL)
    return l->head->data;
  return ERROR;
}

int empty_queue(List *l)
{
  return l->head == l->tail && l->head == NULL; // redundante
}

void push(List *l, int elem)
{
  insert_front(l, elem);
}

int pop(List *l)
{
  if (l->head != NULL)
  {
    int val = l->head->data;
    remove_front(l);
    return val;
  }
}

int peek(List *l)
{
  if (l->head != NULL)
    return l->head->data;
}

int empty_stack(List *l)
{
  return empty_queue(l);
}