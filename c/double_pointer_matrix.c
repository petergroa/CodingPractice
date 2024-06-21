/*
 * nxm matrix utilizing double pointers
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <assert.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "usage: bla bla\n");
    exit(1);
  }

  char *command;
  int nMatrixes;
  int *dims[2];
  int ***matrixes;
  int argvIndex = 2;

  sscanf(argv[1], "%s %i", command, &nMatrixes);
  fprintf(stdout, "%s %i", command, nMatrixes);

  // Allocate memory
  matrixes = malloc(nMatrixes*sizeof(*matrixes));
  for (int i = 0 ; i < nMatrixes; i++) {
    if (argvIndex >= argc) {
      fprintf(stderr, "Not enough arguments\n");
      exit(2);
    }

    // Scan matrix dimensions
    sscanf(argv[argvIndex], "%i %i", &dims[i][0], &dims[i][1]);
    argvIndex++;

    // Alloc memory to use
    matrixes[i] = malloc(dims[i][0]*sizeof(int*));
    for (int row = 0 ; argvIndex < argc && row < dims[i][0] ; row++) {
      if (argvIndex >= argc) {
        fprintf(stderr, "Not enough arguments\n");
        exit(2);
      }

      // Alloc cells memory
      matrixes[i][row] = (int*)malloc(dims[i][1]*sizeof(int));
      // This is going to be a complex while
      char *eon, *start = argv[argvIndex];
      long value;
      for (int col = 0 ; i < dims[i][1] ; col++) {
        matrixes[i][row][col] = strtol(start, &eon, 10);
        assert(matrixes[i][row][col] <= INT_MAX);
        assert(matrixes[i][row][col] >= INT_MIN);

        // In case of error
        if (eon != start || errno == EINVAL || errno == ERANGE ) {
          fprintf(stderr, "Incomplete matrix #%i - %i,%i\n", i, row, col);
          exit(3);
        }
        start = eon;
        errno = 0;
      }
      argvIndex++;
    }
  }

  for (int i = 0 ; i < nMatrixes ; i++) {
    for (int row = 0 ; row < dims[i][0] ; row++) {
      for (int col = 0 ; col < dims[i][1] ; col++) {
        fprintf(stdout, "%i ", matrixes[i][row][col]);
      }
      fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n\n");
  }

  // Free memory
  // Free matrixes
  for (int i = 0 ; i < nMatrixes; i++) {
    for(int j = 0; j < dims[i][0]; j++) {
      free(matrixes[i][j]);
    }
    free(matrixes[i]);
    free(dims[i]);
  }
  free(matrixes);
}
