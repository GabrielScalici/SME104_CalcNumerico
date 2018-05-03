#include "gauss.h"

double **A, *Xprevious, *Xcurrent, *b;

int main(int argc, char *argv[]){
	int n = 0, item = 0;
	int itmax = 0;
	double  error = 0;

	//lenght
	printf("Digite o valor de n:");
	scanf("%d", &n );

	printf("Digite o item desejado (1, 2):");
	scanf("%d", &item );

	initMatrix(A, n);
	initVector(n);

	switch (item) {
		case 1:
			//Como nao tem especificacoes sobre os valores, setando inicial
			error = 0.0000000001;
			itmax = 10000000;
			b_item1(A, b, n);
			break;
		case 2:
			error = 0.000000001;
			itmax = 1000000000;
			b_item2(b, n);
			break;
	}

	gauss_seidel(A, b, n, error, itmax);

	printf("----------- B ----------\n\n");
	int i;

	if(item == 1){
		for(i = 0; i < n; i++){
			printf("%.8lf\n", b[i]);
		}

	}else if(item == 2){
		for(i = 1; i <= n; i++){
			printf("%.8lf\n", b[i]);
		}

	}
	printf("---------- MATRIX ----------\n\n");
	printMatrix(A, n);
	freeVector(Xprevious);
	freeVector(Xcurrent);
	freeVector(b);
	freeMatrix(A, n);

	return 0;
}
