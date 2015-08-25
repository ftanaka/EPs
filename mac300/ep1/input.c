#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

int le_dimensao ( FILE *arq ) {
   int dimensao;

   dimensao = -1;

   if ( arq != NULL ){
      fscanf ( arq, "%d", &dimensao );
      if ( dimensao <= 0 )
         fprintf ( stderr, "ERROR: invalid dimension value:le_dimensao\n" );
   } else
      fprintf ( stderr, "ERROR: can not read file.\n" );

   return dimensao;
}

double **destroi_Matriz ( int dimensao, double **matriz ) {
   int i;

   if ( matriz != NULL ) {
      for ( i = 0; i < dimensao; i++ )
         if ( matriz[i] != NULL )
            free ( matriz[i] );
      free ( matriz );
   }

   return NULL;
}

double **cria_Matriz ( FILE *arq, int dimensao ){
   int i, j, cont;
   double valor, **A;

   i = j = cont = -1;
   valor = -1;
   A   = NULL;

   if ( arq == NULL )
      fprintf ( stderr, "ERROR: can not read file: cria_Matriz.\n" );
   else {
      A = malloc ( dimensao * sizeof ( double ** ) );
      if ( A == NULL )
         fprintf ( stderr, "ERROR: malloc (1) failed: cria_Matriz\n" );
      else {
         for ( cont = 0; cont < dimensao; cont++ ) {
            A[cont] = malloc ( dimensao * sizeof ( double * ) );
            if ( A[cont] == NULL ) {
               fprintf ( stderr, "ERROR: malloc (2) failed: cria_Matriz\n" );
               A = destroi_Matriz ( dimensao, A );
            }
         }
      }

      for ( cont = 0; cont < dimensao * dimensao; cont ++ ) {
         fscanf ( arq, "%d %d %g", &i, &j, &valor );
         
         if ( i < 0 || i >= dimensao || j < 0 || j >= dimensao || valor < 0 ) {
            fprintf ( stderr, "ERROR: invalid input: cria_Matriz\n" );
            A = destroi_Matriz ( dimensao, A );
            break;
         } else
            A[i][j] = valor;
      }
   }

   return A;
}

double *destroi_b ( double *b ) {
   if ( b != NULL )
      free ( b );

   return NULL;
}

double *cria_b ( FILE *arq, int dimensao ) {
   int cont;
   double valor, *b;

   cont = -1;
   valor = -1;
   b = NULL;

   if ( arq == NULL )
      fprintf ( stderr, "ERROR: can not read file: cria_b\n" );
   else {
      b = malloc ( dimensao * sizeof ( double ) );
      if ( b == NULL ) {
         fprintf ( stderr, "ERROR: malloc failed: cria_b\n" );
         b = destroi_b ( b );
      } else {
         for ( cont = 0; cont < dimensao; cont++ ) {
            fscanf ( arq, "%g", &valor );
            b[cont] = valor;
         }
      }
   }

   return b;
}
