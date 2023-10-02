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

/* */
List *mult(List *lx, List *ly)
{
  List *lz = create();
  Node *tx = lx->tail;
  List *aux;
  Node *ty;
  int mult, sobra = 0, casas = 0, i;
  /*Terminar!*/
  while (tx != NULL)
  {
    aux = create();
    ty = ly->tail;
    sobra = 0;
    for (i = 0; i < casas; i++)
      insert_front(aux, 0);

    while (ty != NULL)
    {
      mult = (ty->data * tx->data) + sobra;
      sobra = mult / 10;
      insert_front(aux, mult % 10);
      ty = ty->prev;
    }
    while (sobra > 0)
    {
      insert_front(aux, sobra % 10);
      sobra /= 10;
    }

    tx = tx->prev;
    casas++;
    lz = add(lz, aux);
    destroy(aux);
  }

  return lz;
}

/* */
int main()
{

  int k;

  List *lx = create();
  int nx = 3;
  int x[] = {1, 2, 0};
  for (k = 0; k < nx; k++)
    insert_back(lx, x[k]);
  print_head_to_tail(lx);

  List *ly = create();
  int ny = 1;
  int y[] = {3};
  for (k = 0; k < ny; k++)
    insert_back(ly, y[k]);
  print_head_to_tail(ly);

  List *lz = mult(lx, ly);
  print_head_to_tail(lz);

  destroy(lx);
  destroy(ly);
  destroy(lz);
  return 0;
}
