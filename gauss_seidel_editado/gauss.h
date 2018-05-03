#ifndef GAUSS_H_
#define GAUSS_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define freeVector(x) free(x);

void initMatrix(double **tgt, int size);
void freeMatrix(double **tgt, int size);
void printMatrix(double **tgt, int size);

void b_item1( double**A, double *b, int n);
void b_item2( double *b, int n);

void yankVector(int size);
void initVector(int size);

void gauss_seidel(double **A, double *b, int n, double error, int itmax);
#endif
