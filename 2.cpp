#include <iostream>
#include <ctime>

using namespace std;

void multiplyMatrices(long long **a, long long **b, long long **result, int row1, int col1, int row2, int col2) {
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < col1; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter the number of rows for matrix 1: ";
    cin >> rows1;
    cout << "Enter the number of columns for matrix 1: ";
    cin >> cols1;
    cout << "Enter the number of rows for matrix 2: ";
    cin >> rows2;
    cout << "Enter the number of columns for matrix 2: ";
    cin >> cols2;

    if (cols1 != rows2) {
        cout << "Matrices cannot be multiplied due to incompatible dimensions." << endl;
        return 0;
    }

    long long **matrix1 = new long long *[rows1];
    long long **matrix2 = new long long *[rows2];
    long long **resultMatrix = new long long *[rows1];

    for (int i = 0; i < rows1; ++i) {
        matrix1[i] = new long long[cols1];
    }

    for (int i = 0; i < rows2; ++i) {
        matrix2[i] = new long long[cols2];
    }

    for (int i = 0; i < rows1; ++i) {
        resultMatrix[i] = new long long[cols2];
    }

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            matrix1[i][j] = rand() % 10; 
        }
    }

    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            matrix2[i][j] = rand() % 10; 
        }
    }

    clock_t start_time = clock();

    multiplyMatrices(matrix1, matrix2, resultMatrix, rows1, cols1, rows2, cols2);

    clock_t end_time = clock();
    double duration_seconds = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Execution time: " << duration_seconds << " seconds" << endl;

  
    for (int i = 0; i < rows1; ++i) {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for (int i = 0; i < rows2; ++i) {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    for (int i = 0; i < rows1; ++i) {
        delete[] resultMatrix[i];
    }
    delete[] resultMatrix;

    return 0;
}
