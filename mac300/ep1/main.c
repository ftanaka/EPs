#include <stdio.h>
#include <stdlib.h>

#include "input.h"

int main ( int argc, char **argv ) {
   FILE *arq;

   double **A, *b;
   int dimensao;

   if ( argc < 2 )
      arq = stdin;
   else
      arq = fopen ( argv[1], "r" );

   dimensao = le_dimensao ( arq );

   A = cria_Matriz ( arq, dimensao );

   imprime_Matriz ( dimensao, A );

   b = cria_b ( arq, dimensao );

   imprime_b ( dimensao, b );

   A = destroi_Matriz ( dimensao, A );

   b = destroi_b ( b );

   fclose ( arq );

   return 0;
}
