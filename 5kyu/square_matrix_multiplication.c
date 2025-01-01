#include <stdio.h>
#include <stdlib.h>

int **allocate_2d_array(int n)
{
    int **array = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        array[i] = (int *)malloc(n * sizeof(int));
    }

    return array;
}

// Free a dynamically allocated 2D array
void free_2d_array(int **array, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(array[i]);
    }
    
    free(array);
}

// Populate a 2D array with values
void populate_array(int **array, int n, int *values)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] = values[i * n + j]; // Use flat array indexing
        }
    }
}

int **matrix_multiplication(int **a, int **b, int n)
{
    // TODO: Return the result of A × B in the form of an n × n matrix
    // NOTE: Please use dynamic memory allocation to construct your
    // matrix as the test cases will `free` the memory from your
    // returned result afterwards

    int **c = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        c[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}

int main()
{
    int n = 2; // Size of the matrix

    // Allocate and populate matrices A and B
    int **A = allocate_2d_array(n);
    int **B = allocate_2d_array(n);

    // Define the values for A and B in a flat array
    int valuesA[4] = {1, 2, 3, 4};
    int valuesB[4] = {5, 6, 7, 8};

    // Populate matrices A and B
    populate_array(A, n, valuesA);
    populate_array(B, n, valuesB);

    // Perform matrix multiplication
    int **result = matrix_multiplication(A, B, n);

    // Print the result
    printf("Resultant Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    free_2d_array(A, n);
    free_2d_array(B, n);
    free_2d_array(result, n);

    return 0;
}
