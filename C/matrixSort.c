#include <stdio.h>
#include <stdlib.h>


double** allocate_2d_array(int rows, int columns) {
  double** matrix = (double**)malloc(rows * sizeof(double*));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (double*)malloc(columns * sizeof(double));
  }
  return matrix;
}

void free_2d_array(double** matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

void print_matrix(double** matrix, int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("| %.4f ", matrix[i][j]);
    }
    printf("|\n");
  }
}

void sort_by_column(double** matrix, int rows, int columns, int column) {
  for (int i = 0; i < rows; i++) {
    for (int j = i + 1; j < rows; j++) {
      if (matrix[i][column] > matrix[j][column]) {
        double* temp = matrix[i];
        matrix[i] = matrix[j];
        matrix[j] = temp;
      }
    }
  }
}

int main() {
  int rows = 4, columns = 3;
  double** matrix = allocate_2d_array(rows, columns);

  matrix[0][0] = 1.0;
  matrix[0][1] = 3.0;
  matrix[0][2] = 5.0;
  matrix[1][0] = 3.0;
  matrix[1][1] = 4.0;
  matrix[1][2] = 3.0;
  matrix[2][0] = 4.0;
  matrix[2][1] = 7.0;
  matrix[2][2] = 1.0;
  matrix[3][0] = 3.0;
  matrix[3][1] = 1.0;
  matrix[3][2] = 3.0;

  printf("Before sorting:\n");
  print_matrix(matrix, rows, columns);

  sort_by_column(matrix, rows, columns, 0);
  printf("After sorting with first column selection:\n");
  print_matrix(matrix, rows, columns);

  sort_by_column(matrix, rows, columns, 2);
  printf("After sorting with second column selection:\n");
  print_matrix(matrix, rows, columns);

  free_2d_array(matrix, rows);
  return 0;
}
