#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "cholesky.h"

int cholcol ( int n, double **A ) {
   int i, j, k;

   for ( j = 0; j < n; j++ ) {

      for ( k = 0; k < j; k++ )
         for ( i = j; i < n; i++ )
            A[i][j] = A[i][j] - A[i][k] * A[j][k]; 

      if ( A[j][j] <= 0 ) /* matriz A nao e definida positiva */
         return -1;

      A[j][j] = sqrt ( A[j][j] );

      for ( i = j + 1; i < n; i++ )
         A[i][j] = A[i][j] / A[j][j];
   }

   return 0;
}

int cholrow ( int n, double **A ) {
   int i, j, k;

   for ( i = 0; i < n; i++ ) {

      for ( k = 0; k < i; k++ )
         for ( j = i; j < n; j++ )
            A[i][j] = A[i][j] - A[k][i] * A[k][j];

      if ( A[i][i] <= 0 )
         return -1;

      A[i][i] = sqrt ( A[i][i] );

      for ( j = i + 1; i < n; i++ )
         A[i][j] = A[i][j] / A[i][i];

   }

   return 0;
}
