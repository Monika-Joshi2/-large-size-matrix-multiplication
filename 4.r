# Function to multiply two matrices
multiplyMatrices <- function(matrix1, matrix2) {
  result <- matrix(0, nrow = nrow(matrix1), ncol = ncol(matrix2))
  
  if (ncol(matrix1) != nrow(matrix2)) {
    cat("Matrices cannot be multiplied due to incompatible dimensions.\n")
    return(NULL)
  }
  
  for (i in 1:nrow(matrix1)) {
    for (j in 1:ncol(matrix2)) {
      for (k in 1:ncol(matrix1)) {
        result[i, j] <- result[i, j] + matrix1[i, k] * matrix2[k, j]
      }
    }
  }
  
  return(result)
}

# Taking input for matrix dimensions
rows1 <- as.integer(readline("Enter the number of rows for matrix 1: "))
cols1 <- as.integer(readline("Enter the number of columns for matrix 1: "))
rows2 <- as.integer(readline("Enter the number of rows for matrix 2: "))
cols2 <- as.integer(readline("Enter the number of columns for matrix 2: "))

# Creating matrices with random values (for demonstration)
set.seed(123)  # Setting seed for reproducibility
matrix1 <- matrix(sample(0:9, rows1 * cols1, replace = TRUE), nrow = rows1, ncol = cols1)
matrix2 <- matrix(sample(0:9, rows2 * cols2, replace = TRUE), nrow = rows2, ncol = cols2)

# Perform matrix multiplication
start_time <- Sys.time()

result <- multiplyMatrices(matrix1, matrix2)

end_time <- Sys.time()
duration_seconds <- as.numeric(end_time - start_time, units = "secs")

if (!is.null(result)) {
  cat("Execution time:", duration_seconds, "seconds\n")
}
