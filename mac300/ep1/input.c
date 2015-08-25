#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

int le_dimensao ( FILE *arq ) {
   int dimensao;

   dimensao = -1;

   if ( arq != NULL )
      fscanf ( arq, "%d", &dimensao );
   else
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

double **cria_Matriz ( FILE *arq, int dimensao );

double *destroi_b ( double *b );

double *cria_b ( FILE *arq, int dimensao );
