/*
13/02/24
DFS class/lab
Q1. Implement Redix sort
Q2. WAP to print sum of elements of an array (dynamic).
Q3. WAP to remove duplicate elements from an array (sorted/unsorted)

*/

// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

void sum(int size, int *arr){
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += arr[i];
    }

    printf("Sum: %d ", sum);
}

void removeDup(int size. int *arr){
    int
}

int main() {
    int size = 5;
    int *arr = (int*)malloc(size * sizeof(int));
    
    // input values from user
    for(int i=0; i<size; i++){
        printf("Enter value for index %d: ", i);
        scanf("%d", &arr[i]);
        printf("\n");
    }
    
    sum(size, arr);
    
    int temp = 
    return 0;
}
