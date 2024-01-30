/* 
30-1-24
DS lab/class HW
Q1. Binary Search using recursion (pending)
Q2. Bubble Sort 
Q3. Modified Bubble Sort
Q4. Insertion Sort
*/ 


#include <stdio.h>
#include<stdbool.h>  // for bool data type

// Q1. Binary search using recursion (error, pending as recursion is not clear)
int bSearch(int *arr, int low, int high, int val){
    // exit case: fail
    if(low > high) return -1;
    
    int mid = (low + high)/2;
    printf("%d--", mid);
    
    // exit case: success
    if(val == arr[mid]) return mid;
    
    // recursive steps
    if(val > arr[mid]) { bSearch(arr, mid+1, high, val); }
    if(val < arr[mid]) { bSearch(arr, low, mid-1, val); }
}

// Q2. Bubble Sort
void bubbleSort(int* arr, int len){
    // outer loop: no. of passes (n-1, observation)
    for(int i=0; i<len; i++){
        // inner loop: individual pass, compare adjacent elements and swap. 
        // (0 <= j < n-1)
        for(int j=0; j<len-1; j++){
            if(arr[j] > arr[j+1]){
                // swap operation
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Q3. Modified bubble sort
/* Modification: 
1. no. of iterations in each pass only n-i-1 as by each pass i element is sorted from last index.
2. remove redundant passes if array gets sorted already (using flag to check if swaping is done or not)
*/
void modifiedBubbleSort(int* arr, int len){
    bool flag;
    for(int i=0; i<len; i++){
        flag = false;
        for(int j=0; j<len-1-i; i++){
            if(arr[j] > arr[j+1]){
                // swap ops
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                flag = true;
            }
        }
        if(flag == false) break; // array is sorted already
    }
}

// Q4. Insertion sort (incomplete)
void insertionSort(int* arr, int len){
    for(int i=0; i<len-1; i++){
        int temp = arr[j];
        int j = i+1;
        while(j>0){
            if(temp < arr[j-1]){
                arr[j] = arr[j-1];  // shifting greater values
                j--;              
            }
            else{
                arr[j] = temp;
                break;
            }
            // TODO: how to handle the case when temp is shifted to index 0
            
        }
        
        }
    }
}




void printArray(int* arr, int len){
    for(int i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
  
    int arr[5] = {1,5,4,9,3};
    
    bubbleSort(arr, 5);
    printArray(arr, 5);
    
    modifiedBubbleSort(arr, 5);
    printArray(arr, 5);

    return 0;
}
