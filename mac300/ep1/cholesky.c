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

   for ( i = 0; i < n; i++ ) {
      for ( j = 0; j < i; j++ ) {
         for( k = 0; k < i; k++ )
            A[i][j] = A[i][j] - A[i][k] * A[j][k];
         A[i][i] = A[i][i] - pow ( A[i][j], 2 );
      }

      if ( A[i][i] <= 0 ) /* matriz A nao e definida positiva */
         return -1;

      A[i][i] = sqrt ( A[i][i] );
   }

   return 0;
}
