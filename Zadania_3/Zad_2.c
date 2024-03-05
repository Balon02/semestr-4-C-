#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, i, j;
    double **matrix;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    matrix = (double **)malloc(rows * sizeof(double *));
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(cols * sizeof(double));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    srand(time(NULL));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    printf("\nMatrix content:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    char keepopen[999];
    scanf("%s", keepopen);

    return 0;
}