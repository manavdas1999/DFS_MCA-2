
/*
02/02/24
DFS class/lab
Q1. Check whether a given matrix is sparse or not.
Q2. Convert a given sparse matrix into coordinate set/3-row triplet representation.
*/

/*
Points of struggle:
1. how to pass and return matrix to/from a function in c.
*/

#include <stdio.h>

void printMatrix(int n, int arr[][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

int isSparseMatrix(int n, int arr[][n]){
    int countZero = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 0) countZero++;
        }
    }
    
    return (countZero > (n*n)/2) ? 1 : 0;
}

int elementCount(int n, int arr[][n]){
    int count =0;
    for(int i=0; i<n*n; i++){
        if(arr[i%n][i/5] != 0) count++; 
    }
    return count;
}

int main() {
    int arr[5][5] = {{5,0,8,0,0}, {0,0,0,9,0}, {0,2,0,0,6}, {0,0,0,1,0}, {0,0,7,0,0}};
    
    printMatrix(5, arr);
    printf("is given matrix is Sparse matrix? %s", isSparseMatrix(5, arr) ? "true" : "false");

    int nonZeroCount = elementCount(5, arr);
    printf("Count of Non zero elements: %d", nonZeroCount);

    return 0;
}
