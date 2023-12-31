import numpy as np
import random
import time

rows1 = int(input("Enter the number of rows for matrix 1: "))
cols1 = int(input("Enter the number of columns for matrix 1: "))
rows2 = int(input("Enter the number of rows for matrix 2: "))
cols2 = int(input("Enter the number of columns for matrix 2: "))

if cols1 != rows2:
    print("Matrices cannot be multiplied due to incompatible dimensions.")
else:
    matrix1 = np.random.randint(0, 10, (rows1, cols1))
    matrix2 = np.random.randint(0, 10, (rows2, cols2))

    start_time = time.time()

    result = np.dot(matrix1, matrix2)

    end_time = time.time()
    duration_seconds = end_time - start_time

    print("Execution time: {:.6f} seconds".format(duration_seconds))
