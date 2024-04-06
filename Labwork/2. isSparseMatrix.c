/*
2. Write A C Program to Check Whether a Matrix Is Sparse or Not.
*/

#include <stdio.h>
#define MAX_SIZE 10

// Function to check whether a matrix is sparse or not
int isSparse(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int countNonZero = 0;
    // Count non-zero elements in the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                countNonZero++;
            }
        }
    }
    // If the count of non-zero elements is less than or equal to half of total elements,
    // the matrix is considered sparse
    if (countNonZero <= (rows * cols) / 2) {
        return 1; // Sparse matrix
    } else {
        return 0; // Not a sparse matrix
    }
}

void display(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main() {
    int rows, cols;
    int matrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("\nElement matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    display(matrix, rows, cols);

    // Check if the matrix is sparse
    if (isSparse(matrix, rows, cols)) {
        printf("The matrix is sparse.\n");
    } else {
        printf("The matrix is not sparse.\n");
    }

    return 0;
}
