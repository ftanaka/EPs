#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "cholesky.h"

int main ( int argc, char **argv ) {
   FILE *arq;

   double **A, *b;
   int opt, dimensao, retorno;

   if ( argc < 2 )
      arq = stdin;
   else
      arq = fopen ( argv[1], "r" );

   opt = 0;

   dimensao = le_dimensao ( arq );

   A = cria_matriz ( arq, dimensao );
   imprime_matriz ( dimensao, A );
   printf ( "\n" );

   b = cria_b ( arq, dimensao );
   imprime_b ( dimensao, b );
   printf ( "\n" );

   while ( opt != -1 ) {

      printf ( "Opcoes:\n" );
      printf ( "   1 - cholcol\n" );
      printf ( "   2 - cholrow\n" );
      printf ( "   3 - forwcol\n" );
      printf ( "   4 - forwrow\n" );
      printf ( "   0 - sair\n" );
      scanf  ( "%d", &opt );

      switch ( opt ) {

         case 1 : retorno = cholcol ( dimensao, A );
                  imprime_matriz ( dimensao, A );
                  printf ( "\n" );
                  break;
         case 2 : retorno = cholrow ( dimensao, A );
                  imprime_matriz ( dimensao, A );
                  printf ( "\n" );
                  break;
         case 3 : retorno = forwcol ( dimensao, A, b );
                  imprime_b ( dimensao, b );
                  printf ( "\n" );
                  break;
         case 4 : retorno = forwrow ( dimensao, A, b );
                  imprime_b ( dimensao, b );
                  printf ( "\n" );
                  break;
         case 0 : opt = -1;
                  break;

      }

   }

   A = destroi_matriz ( dimensao, A );
   b = destroi_b ( b );
   fclose ( arq );

   return 0;
}
