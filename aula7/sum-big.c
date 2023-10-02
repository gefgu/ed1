#include "list.h"

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
  }

  if (sobra)
    insert_front(lz, sobra);

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

  List *lz = add(lx, ly);
  print_head_to_tail(lz);

  destroy(lx);
  destroy(ly);
  destroy(lz);
  return 0;
}
