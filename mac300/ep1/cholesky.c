#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "cholesky.h"

int cholcol ( int n, double **A ) {
   int i, j, k;

   for ( j = 0; j < n; j++ ) {
      for ( k = 0; k < j; k++ )
         A[j][j] = A[j][j] - pow ( A[j][k], 2 );

      if ( A[j][j] <= 0 ) /* matriz A nao e definida positiva */
         return -1;

      A[j][j] = sqrt ( A[j][j] );

      for ( i = j + 1; i < n; i++ ) {

         for ( k = 0; k < j; k++ )
            A[i][j] = A[i][j] - A[i][k] * A[j][k];

         A[i][j] = A[i][j] / A[j][j];
      }
   }

   return 0;
}

int cholrow ( int n, double **A ) {
   int i, j, k;
   double s;

   for ( i = 0; i < n; i++ ) {
      for ( j = 0; j < n; j++ ) {

         for ( k = 0, s = 0; k < j; k++ )
            s += A[i][k] * A[j][k];

         if ( i == j )
            A[i][j] = sqrt ( A[i][j] - s );
         else
            A[i][j] = ( A[i][j] - s ) / A[j][j];
      }
   }

   return 0;
}
