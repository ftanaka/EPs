#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int le_dimensao ( FILE *arq );

double **destroi_Matriz ( FILE *arq, int dimensao, double **matriz );

double **cria_Matriz ( FILE *arq, int dimensao );

double **destroi_b ( FILE *arq, double *b );

double **cria_b ( FILE *arq, int dimensao );
