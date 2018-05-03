#include "gauss.h"


double extern **A, *Xprevious, *Xcurrent, *b;

void initMatrix(double **tgt, int size){
	int i, j;
	A=(double **)malloc(size*sizeof(double *));

	for(i=0; i<size; i++){
		A[i]=(double *)calloc(size, sizeof(double));
	}

	//atr. values.

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			A[i][j]=0;
		}
		A[i][i]=4;
	}

	for(i=0; i<size-1; i++)
		A[i][i+1]=-1, A[i+1][i]=-1;

	for(i=0; i<size-3; i++)
		A[i][i+3]=-1, A[i+3][i]=-1;
}
void freeMatrix(double **tgt, int size){
	int i;

	for(i=0;i<size;i++) free(tgt[i]);

	free(tgt);
}

void printMatrix(double **tgt, int size){
	int i, j;

	for(i=0;i<size;i++){
		for(j=0; j<size; j++)
			printf("%.2f ", A[i][j]);
		printf("\n");
	}
}

void initVector(int size){
	Xprevious=(double *)calloc(size, sizeof(double));
	Xcurrent=(double *)calloc(size, sizeof(double));
	b=(double *)malloc(size*sizeof(double)+1);
}
void yankVector(int size){
	int i;
	for(i=0;i<size;i++) Xprevious[i]=Xcurrent[i];
}

void b_item1( double**A, double *b, int n){
	int i, j;
	double aux = 0;

	//Values b[]
	for(i = 0; i < n; i++){
		aux = 0;
		for(j = 0; j < n; j++){
			aux += A[i][j];
		}
		b[i] = aux;
	}
}

void b_item2(double *b, int n){
	int i;
	double j;

	//Values b[]
	for(i = 1; i <= n; i++){
			j = (float)i;
			b[i] = (1/j);
	}
}

void gauss_seidel(double **A, double *b, int n, double error, int itmax){
	int k=0, i, j;
	double tmpPrevious, tmpCurrent, err = 10000;



	while(err > error && k!=itmax){
		//copy Xcurrent to Xprevious
		err = 0;

		for(i = 0;i < n;i++){
			Xprevious[i]=Xcurrent[i];
		}

		//set vector k+1 at Xcurrent
		for(i=0;i<n;i++){
			tmpPrevious = 0;
			tmpCurrent = 0;

			//set tmpPrevious
			for(j = i + 1; j < n; j++){
				tmpPrevious+=A[i][j]*Xprevious[j];
			}

			//set tmpCurrent
			for(j=1; j<i-1; j++){
				tmpCurrent+=A[i][j]*Xcurrent[j];
			}
			Xcurrent[i]=(b[i]-tmpCurrent-tmpPrevious)/A[i][i];
		}

		//calc error
		for(i = 0; i < n; i++){
			if(i == 0 && k == 0){
				err = fabs(Xcurrent[i] - Xprevious[i]);
			}

			if(err < fabs(Xcurrent[i] - Xprevious[i])){
				 err = fabs(Xcurrent[i] - Xprevious[i]);
			}

		}

		//increase iteration
/*
		for(i = 0; i < n; i++){
			printf(" %d %lf \n",i, Xcurrent[i] );
		}
*/
		k++;

	}

	//print result
	printf("---------- X = RESULT ----------\n\n");
	for(i = 0; i < n; i++){
		printf(" %lf ",Xcurrent[i]);
	}
	printf("\n");
}
