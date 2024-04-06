/*
3. Write A C Program to Covert Sparse Matrix Into 3-Triplet Representation
*/
#include <stdio.h>

#define MAX_SIZE 10
#define MAX_TERMS 100

// Structure to represent a triplet (row, column, value)
typedef struct {
    int row;
    int col;
    int value;
} Triplet;

// Function to convert a sparse matrix into 3-triplet representation
int convertToTriplets(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, Triplet triplets[]) {
    int count = 0; // Initialize count of non-zero elements
    // Traverse the matrix and store non-zero elements as triplets
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                triplets[count].row = i;
                triplets[count].col = j;
                triplets[count].value = matrix[i][j];
                count++; // Increment count for each non-zero element
            }
        }
    }
    return count; // Return the total count of non-zero elements (number of triplets)
}

int main() {
    int rows, cols;
    int matrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Input matrix elements
    printf("\nEnter the elements of the matrix:");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("\nElement matrix[%d][%d]: ", i,j);
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }
    
    // printing Matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");

    Triplet triplets[MAX_TERMS];
    int count = convertToTriplets(matrix, rows, cols, triplets);

    // Print the 3-triplet representation of the sparse matrix
    printf("3-Triplet Representation of the Sparse Matrix:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t\t%d\n", triplets[i].row, triplets[i].col, triplets[i].value);
    }

    return 0;
}
