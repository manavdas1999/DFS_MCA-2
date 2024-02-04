/*
31/1/24
DFS class/Lab
Q1. Find the second largest element from a given array.
*/
#include <stdio.h>

int secondLargest(int* arr, int len){
    // STEP1: find largest
    int largest = arr[0]; 
    for(int i=1; i<len; i++){
        if(largest < arr[i]){
            largest = arr[i];
        }
    }
    printf("%d", largest);
    
    // STEP2: find next largest
    int nextLargest = arr[0];
    for(int i=1; i<len; i++){
        if(nextLargest < arr[i] && arr[i] != largest){
            nextLargest = arr[i];
        }
    }
    return nextLargest;
}


int main() {
    int* arr[5] = {3,5,1,6,7};
    int c = secondLargest(arr, 5);
    printf("%d", c);
    return 0;
}
