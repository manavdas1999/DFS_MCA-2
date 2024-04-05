/*
Matrix ADT
Write A C Program to Perform Following Operation on Matrix 
1.	Addition Of Two Matrix.
2.	Subtraction Of Two Matrix.
3.	Multiplication Of Two Matrix.
4.	Transpose Of Two Matrix.
5.	Diagonal Sum of Two Matrix (row and col must be same.
6.	Check If Matrix Is Identity Or not.
7.	Exit.

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int rows;
    int cols;
    int **data;
}Matrix;

// Function to create a matrix with specified dimensions
Matrix* createMatrix(int rows, int cols) {
    Matrix *matrix = (Matrix*)malloc(sizeof(Matrix));
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    matrix->rows = rows;
    matrix->cols = cols;

    // Allocate memory for the matrix data
    matrix->data = (int**)malloc(rows * sizeof(int*));
    if (matrix->data == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int*)malloc(cols * sizeof(int));
        if (matrix->data[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }

    return matrix;
}

void initializeMatrix(Matrix *matrix) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("\nElement [%d][%d]: ", i, j);
            scanf("%d", &matrix->data[i][j]);
        }
    }
}

void display(Matrix *mat){
    for(int i=0; i<mat->rows; i++){
        for(int j=0; j<mat->cols; j++){
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Matrix* addMatrix(Matrix *m1, Matrix *m2){
    if((m1->rows != m2->rows)  || (m1->cols != m2->cols) ){
        printf("\nMatrices should have same dimensions for addition\n");
        return NULL;
    }
    Matrix *m3 = createMatrix(m1->rows, m1->cols);
    for(int i=0; i<m1->rows; i++){
        for(int j=0; j<m1->cols; j++){
            m3->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
    return m3;
}

Matrix* subtractMatrix(Matrix *m1, Matrix *m2){
    if((m1->rows != m2->rows)  || (m1->cols != m2->cols) ){
        printf("\nMatrices should have same dimensions for subraction\n");
        return NULL;
    }
    Matrix *m3 = createMatrix(m1->rows, m1->cols);
    for(int i=0; i<m1->rows; i++){
        for(int j=0; j<m1->cols; j++){
            m3->data[i][j] = m1->data[i][j] - m2->data[i][j];
        }
    }
    return m3;
}

Matrix* multiplyMatrix(Matrix *m1, Matrix *m2){
    if(m1->cols != m2->rows ){
        printf("\nNumber of columns in first matrix should be equal to number of rows in second matrix for multiplication\n");
        return NULL;
    }
    Matrix *m3 = createMatrix(m1->rows, m2->cols);
    for(int i=0; i<m1->rows; i++){
        for(int j=0; j<m2->cols; j++){
            m3->data[i][j] = 0;
            for (int k = 0; k < m1->cols; k++) {
                m3->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    return m3;
}

Matrix* transposeMatrix(Matrix *matrix) {
    Matrix *result = createMatrix(matrix->cols, matrix->rows);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->data[j][i] = matrix->data[i][j];
        }
    }
    return result;
}

int diagonalSum(Matrix *m){
    int sum = 0;
    if(m->rows != m->cols){
        printf("\nMatrix should be square i.e rows = cols.\n");
    }
    else{
        for(int i=0; i<m->rows; i++){
            sum += m->data[i][i];
        }
    }
    return sum;
}

int isIdentityMatrix(Matrix *m){
    if(m->rows != m->cols){
        printf("\nMatrix should be square i.e rows = cols.\n");
        return 0;
    }
    for(int i=0; i<m->rows; i++){
        for(int j=0; j<m->cols; j++){
            if(i==j){
                if(m->data[i][j] != 1) return 0;
            }
            else{
                if(m->data[i][j] != 0) return 0;
            }
        }
    }
    return 1;
}



int main() {
    Matrix *m1 = createMatrix(3,3);
    Matrix *m2 = createMatrix(3,3);
    
    printf("Matrix 1: \n");
    initializeMatrix(m1);
    display(m1);
    printf("is identity matrix? %d\n", isIdentityMatrix(m1));
    
    printf("Matrix 2: \n");
    initializeMatrix(m2);
    
    Matrix *sumResult = addMatrix(m1,m2);
    Matrix *diffResult = subtractMatrix(m1,m2);
    Matrix *mulResult = multiplyMatrix(m1,m2);
    
    printf("Sum of matrix1 and matrix2: \n");
    display(sumResult);
    printf("Difference of matrix1 and matrix2: \n");
    display(diffResult);
    printf("Multiply of matrix1 and matrix2: \n");
    display(mulResult);
    
    printf("Diagonal sum of matrix1: %d\n", diagonalSum(m1));
    printf("Diagonal sum of matrix2: %d\n", diagonalSum(m2));
    
    Matrix *transpose1 = transposeMatrix(m1);
    Matrix *transpose2 = transposeMatrix(m2);
    
    printf("Transpose of Matrix 1: \n");
    display(transpose1);
    printf("Transpose of Matrix 2: \n");
    display(transpose2);
    

    return 0;
}
