#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplyMatrices(long long **a, long long **b, long long **result, long long row1, long long col1, long long row2, long long col2) {
    if (col1 != row2) {
        printf("Matrices cannot be multiplied due to incompatible dimensions.\n");
        return;
    }

    for (long long i = 0; i < row1; i++) {
        for (long long j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (long long k = 0; k < col1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void generateRandomMatrix(long long **matrix, long long rows, long long cols) {
    for (long long i = 0; i < rows; i++) {
        for (long long j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // Generate random numbers between 0 and 9
        }
    }
}

int main() {
    long long row1, col1, row2, col2;

    printf("Enter the number of rows for matrix 1: ");
    scanf("%lld", &row1);
    printf("Enter the number of columns for matrix 1: ");
    scanf("%lld", &col1);
    printf("Enter the number of rows for matrix 2: ");
    scanf("%lld", &row2);
    printf("Enter the number of columns for matrix 2: ");
    scanf("%lld", &col2);

    if (col1 != row2) {
        printf("Matrices cannot be multiplied due to incompatible dimensions.\n");
        return 0;
    }

    srand(time(0)); // Seed for random number generation

    long long **matrix1 = (long long **)malloc(row1 * sizeof(long long *));
    long long **matrix2 = (long long **)malloc(row2 * sizeof(long long *));
    long long **resultMatrix = (long long **)malloc(row1 * sizeof(long long *));

    for (long long i = 0; i < row1; i++) {
        matrix1[i] = (long long *)malloc(col1 * sizeof(long long));
    }

    for (long long i = 0; i < row2; i++) {
        matrix2[i] = (long long *)malloc(col2 * sizeof(long long));
    }

    for (long long i = 0; i < row1; i++) {
        resultMatrix[i] = (long long *)malloc(col2 * sizeof(long long));
    }

    generateRandomMatrix(matrix1, row1, col1);
    generateRandomMatrix(matrix2, row2, col2);

    clock_t start_time = clock();

    multiplyMatrices(matrix1, matrix2, resultMatrix, row1, col1, row2, col2);

    clock_t end_time = clock();
    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\nExecution time: %.6f seconds\n", execution_time);

    for (long long i = 0; i < row1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (long long i = 0; i < row2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    for (long long i = 0; i < row1; i++) {
        free(resultMatrix[i]);
    }
    free(resultMatrix);

    return 0;
}
