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
      for ( j = 0; j <= i; j++ ) {
         for ( k = 0; k < j; k++ )
            A[i][j] = A[i][j] - A[i][k] * A[j][k];

         if ( i == j ) {
            if ( A[i][i] <= 0 ) /* matriz A nao e definida positiva */
               return -1;
            else
               A[i][i] = sqrt ( A[i][i] );
         } else
            A[i][j] = A[i][j] / A[j][j];
      }
   }

   return 0;
}

int forwrow ( int n, double **A, double *b ) {
   int i, j;

   for ( i = 0; i < n; i++ ) {
      for ( j = 0; j < i; j++ )
         b[i] = b[i] - A[i][j] * b[j];
      if ( A[i][i] == 0 ) /* matriz A e singular */
         return -1;
      b[i] = b[i] / A[i][i];
   }

   return 0;
}

int forwcol ( int n, double **A, double *b ) {
   int i, j;

   for ( j = 0; j < n; j++ ) {
      if ( A[j][j] == 0 ) /* matriz A e singular */
         return -1;
      b[j] = b[j] / A[j][j];
      for ( i = j + 1; i < n; i++ )
         b[i] = b[i] - A[i][j] * b[j];
   }

   return 0;
}

int backrow ( int n, double **A, double *b, int trans ) {
   int i, j;

   if ( trans == 1 ) {
      /* matriz triangular inferior == matriz triangular superior transposta */
      for ( i = n - 1; i >= 0; i-- ) {
         if ( A[i][i] == 0 ) /* matriz A e singular */
            return -1;

         b[i] = b[i] / A[i][i];

         for ( j = i - 1; j >= 0; j-- )
            b[j] = b[j] - A[i][j] * b[i];
      }
      return 0;
   } else {
      /* matriz triangular superior */
      for ( i = n - 1; i >= 0; i-- ) {
         for ( j = n - 1; j > i; j-- )
            b[i] = b[i] - A[i][j] * b[j];

         if ( A[i][i] == 0 ) /* matriz A e singular */
            return -1;

         b[i] = b[i] / A[i][i];
      }
      return 0;
   }
}

int backcol ( int n, double **A, double *b, int trans ) {
   int i, j;

   if ( trans == 0 ) {
      /* matriz triangular superior */
      for ( j = n - 1; j >= 0; j-- ) {
         if ( A[j][j] == 0 ) /* matriz A e singular */
            return -1;

         b[j] = b[j] / A[j][j];

         for ( i = 0; i < j; i++ )
            b[i] = b[i] - A[i][j] * b[j];
      }
      return 0;
   } else {
      /* matriz triangular inferior */
      for ( j = n - 1; j >= 0; j-- ) {
         for ( i = j + 1; i < n; i++ )
            b[j] = b[j] - A[i][j] * b[i];

         if ( A[j][j] == 0 ) /* matriz A e singular */
            return -1;

         b[j] = b[j] / A[j][j];
      }
      return 0;
   }
}
