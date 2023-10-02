#include "list.h"
#include <time.h>
#define RED "\x1B[31m"
#define RESET "\x1B[0m"

int max(int a, int b)
{
  if (a > b)
    return a;
  return b;
}

int get_size(List *l)
{
  int size = 0;
  Node *t = l->head;
  while (t != NULL)
  {
    t = t->next;
    size++;
  }
  return size;
}

void print_style(List *lx, List *ly, List *lz, int sobra)
{
  struct timespec second, nano = {0, 750000000};
  system("clear");
  int i;
  int size_x = get_size(lx);
  int size_y = get_size(ly);
  int size_z = get_size(lz);
  int size = max(size_x, size_y);
  size = max(size_z, size);

  for (i = 0; i < size - size_x; i++)
    printf("  ");
  print_head_to_tail(lx);
  printf("+ ");
  for (i = 0; i < size - size_y - 1; i++)
    printf("  ");
  print_head_to_tail(ly);
  for (i = 0; i < size; i++)
    printf("--");
  printf("\n\n");
  for (i = 0; i < size - size_z; i++)
    printf("  ");
  print_head_to_tail(lz);
  printf("Sobra: %d\n", sobra);

  nanosleep(&nano, &second);
}

List *add(List *lx, List *ly)
{
  List *lz = create();
  Node *tx = lx->tail;
  Node *ty = ly->tail;
  int sobra = 0, soma;
  /*Terminar!*/
  while (tx != NULL || ty != NULL)
  {
    soma = sobra;
    if (tx != NULL)
    {
      soma += tx->data;
      tx = tx->prev;
    }
    if (ty != NULL)
    {
      soma += ty->data;
      ty = ty->prev;
    }
    sobra = soma / 10;
    insert_front(lz, soma % 10);
    print_style(lx, ly, lz, sobra);
  }

  if (sobra)
  {
    insert_front(lz, sobra);
    sobra = 0;
  }
  print_style(lx, ly, lz, sobra);

  return lz;
}

int main()
{

  int k;

  List *lx = create();
  int nx = 4;
  int x[] = {9, 9, 9, 9};
  for (k = 0; k < nx; k++)
    insert_back(lx, x[k]);
  print_head_to_tail(lx);

  List *ly = create();
  int ny = 7;
  int y[] = {9, 9, 9, 9, 9, 9, 9};
  for (k = 0; k < ny; k++)
    insert_back(ly, y[k]);
  print_head_to_tail(ly);

  List *lz = add(ly, lx);
  // print_head_to_tail(lz);

  destroy(lx);
  destroy(ly);
  destroy(lz);
  return 0;
}
