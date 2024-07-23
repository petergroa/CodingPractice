/*
 * nxm matrix utilizing double pointers
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(const int *dims, int **matrix) {
  for (int row = 0 ; row < dims[0] ; row++) {
    for (int col = 0 ; col < dims[1] ; col++) {
      fprintf(stdout, "%i ", matrix[row][col]);
    }
    fprintf(stdout, "\n");
  }
}

void sumMatrix(const int *dimsA, int **matrixA, const int *dimsB, int **matrixB, int **result) {
  if (dimsA[0] != dimsB[0] || dimsA[1] != dimsB[1]) {
    fprintf(stderr, "Error! Dims not matching");
    return;
  }

  for(int row = 0; row < dimsA[0]; row++) {
    for(int col = 0; col < dimsA[1]; col++) {
      result[row][col] = matrixA[row][col] + matrixB[row][col];
    }
  }
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  const int dimsA[] = {4, 4};
  const int dimsB[] = {4, 4};

  int **matrixA = new int*[dimsA[0]];
  for (int row = 0 ; row < dimsA[0] ; row++) {
    matrixA[row] = (int*)malloc(dimsA[1]*sizeof(int));
    for (int col = 0 ; col < dimsA[1] ; col++) {
      matrixA[row][col] = rand()%11;
    }
  }
  printMatrix(dimsA, matrixA);

  fprintf(stdout, "\n\n");
  int **matrixB = new int*[dimsB[0]];
  for (int row = 0 ; row < dimsB[0] ; row++) {
    matrixB[row] = (int*)malloc(dimsB[1]*sizeof(int));
    for (int col = 0 ; col < dimsB[1] ; col++) {
      matrixB[row][col] = rand()%11;
    }
  }
  printMatrix(dimsB, matrixB);

  fprintf(stdout, "\n\n");
  int **sum = new int*[dimsA[0]];
  for(int row = 0; row < dimsA[0]; row++) sum[row] = (int*)malloc(dimsA[1]*sizeof(int));
  sumMatrix(dimsA, matrixA, dimsB, matrixB, sum);
  printMatrix(dimsA, sum);

  for (int row = 0; row < dimsA[0]; row++) free(matrixA[row]);
  for (int row = 0; row < dimsB[0]; row++) free(matrixB[row]);
//  for (int row = 0; row < dimsA[0]; row++) free(sum[row]);
  return(0);
}
