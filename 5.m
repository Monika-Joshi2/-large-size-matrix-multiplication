%% Define matrix dimensions
rows = 2500;
cols = 2500;

% Create random matrices of size 100x100
matrix1 = rand(rows, cols);
matrix2 = rand(rows, cols);

% Measure execution time
start_time = tic;
result = matrix1 * matrix2;
execution_time = toc(start_time);

fprintf('Execution time: %.4f seconds\n', execution_time);