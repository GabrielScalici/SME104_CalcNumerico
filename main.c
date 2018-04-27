#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
    float tol, error;
    int i, j, k, itmax, n, s1, s2;

    //Pegando a dimensao da matriz
    scanf("%d", &n);

    //Criando a matriz
    float** A = (float**) malloc (n*sizeof(float*));
    for(i = 0; i < n; i++){
      A[i] = (float*) malloc (n*sizeof(float));
    }

    //Atribuindo os valores na matriz de acordo com a especificação
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
        //Posicoes especificas
        if(i == j){
          A[i][j] = 4;
        }else if(j == i+1 && i < n-1){
          A[i][j] = -1;
        }else if(i == j+1 && j < n-1){
          A[i][j] = -1;
        }else if(j == i+3 && i < n-3){
          A[i][j] = -1;
        }else if(i == j+3 && i < n-3){
          A[i][j] = -1;
        }else{
          A[i][j] = 0; //Colocar 0 nas restantes
        }
      }
    }

    //Vetor b
    float* b = (float*) malloc(n*sizeof(float));
    //Atribuindo os valores
    for(i = 0; i < n; j++){
      int aux = 0;
      for(j = 0; j < n; j++){
        aux += A[i][j];
      }
      b[i] = aux;
    }

    //Criando vetor x
    float* x = (float*) malloc(n*sizeof(float));
    //Zerando todas as posicoes do vetor
    for(i = 0; i < n; i++){
      x[i] = 0;
    }

    //Criando vetor y (x anterior)
    float* y = (float*) malloc(n*sizeof(float));
    //Zerando todas as posicoes do vetor
    for(i = 0; i < n; i++){
      y[i] = 0;
    }

    //Pegando os valores do erro e numero maximo de iteracoes
    printf("Insira o erro(e) desejado e o número máximo de iterações: ");
    scanf("%f %d", &tol, &itmax);

    //Laco principal
    for(k = 0; k < itmax; k++){
        //Guardando x antigo
        for(i = 0; i < n; i++){
          y[i] = x[j];
        }

        for(i = 0; i < n; i++){
            s1 = 0;
            s2 = 0;

            for(j = i; j < n - 1; j++){
                s2 += A[i][j] * x[j];
            }

            for(j = 0; j < i; j++){
                s1 += A[i][j] * x[j]; //precisa usar k+1
            }

            x[i] = (b[i] - s1 - s2) / A[i][i];

            //precisa arrumar
            //error = fabs(100000000);
            error = 100000000000;

            if(error < tol)
              k = itmax; //sai do laco
        }
      }

        return 0;
    }
