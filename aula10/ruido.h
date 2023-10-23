#ifndef __imagem_h__
#define __imagem_h__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Definição de uma imagem.*/
typedef struct {
  int nrows;  /*Número de linhas da imagem.*/
  int ncols;  /*Número de colunas da imagem.*/
  int **m;    /*Matriz de pixels.*/
} Image;  

Image* create (int nlin, int ncol);

void destroy (Image *img);

Image* process (Image *img, int wsize);

#endif
