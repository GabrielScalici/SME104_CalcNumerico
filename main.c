#include<stdio.h>
#include<math.h>


int main(void){

    float ae, max, t, s, e;
    int i, j, r, mxit, n;

    //Pegando a dimensao da matriz
    scanf("%d", &n);

    //Criando a matriz
    float** x = (float**) malloc (n*sizeof(float*));
    for(i = 0; i < n; i++){
      x[i] = (float*) malloc (n*sizeof(float));
    }

    //Atribuindo os valores na matriz de acordo com a especificação
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
        //Posicoes especificas
        if(i == j){
          x[i][j] = 4;
        }else if(j == i+1 && i <= n-1){
          x[i][j] = -1;
        }else if(i == j+1 && j <= n-1){
          x[i][j] = -1;
        }else if(j == i+3 && i <= n-3){
          x[i][j] = -1;
        }else if(i == j+3 && i <= n-3){
          x[i][j] = -1;
        }else{
          x[i][j] = 0; //Colocar 0 nas restantes
        }
      }
    }

    //Vetor b
    float* b = (float*) malloc(n*sizeof(float));
    //Atribuindo os valores
    for(i = 0; i < n; j++){
      int aux = 0;
      for(j = 0; j < n; j++){
        aux += x[i][j];
      }
      b[i] = aux;
    }

    //Criando vetor x
    float* b = (float*) malloc(n*sizeof(float));
    //Zerando todas as posicoes do vetor
    for(i = 0; i < n; i++){
      b[i] = 0;
    }


    //Pegando os valores do erro e numero maximo de iteracoes
    printf("Insira o erro(e) desejado e o número máximo de iterações: ");
    scanf("%f %d",&ae,&mxit);


    printf("Iteration\tx[1]\tx[2]\n");
    for(r = 1; r <= mxit; r++){
        max=0;

        for(i = 0; i < n; i++){
            s2=0;

            for(j = 0; j < n ; j++){
              if(j != i){
                s2 += x[i][j] * x[j];
              }
            }

            t = ( x[i][n] - s2) / x[i][i];
            // b - s1 - s2 / diag

            e = fabs(b[i] - t);
            b[i] = t;
        }


        printf(" %5d\t",r);
        for(i=0;i<n;i++)
        printf(" %9.4f\t",a[i]);
        printf("\n");

        if(max<ae){
            printf(" Converses in %3d iteration\n", r);
            for(i=0;i<n;i++)
              printf("a[%3d]=%7.4f\n", i+1,a[i]);
            return 0;
        }

        }
    }
