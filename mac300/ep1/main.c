#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "cholesky.h"

int main ( int argc, char **argv ) {
   FILE *arq;

   double **A, *b;
   int dimensao, retorno;

   if ( argc < 2 )
      arq = stdin;
   else
      arq = fopen ( argv[1], "r" );

   dimensao = le_dimensao ( arq );

   A = cria_matriz ( arq, dimensao );

   imprime_matriz ( dimensao, A );
   printf ( "\n" );

   b = cria_b ( arq, dimensao );

   imprime_b ( dimensao, b );
   printf ( "\n" );

   retorno = cholcol ( dimensao, A );

   imprime_matriz ( dimensao, A );
   printf ( "\n" );

   forwrow ( dimensao, A, b );
   imprime_b ( dimensao, b );

   A = destroi_matriz ( dimensao, A );

   b = destroi_b ( b );

   fclose ( arq );

   return 0;
}
