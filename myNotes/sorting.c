
#include <stdio.h>

// 1. Bubble Sort (Heavy elements go dowm(end), light elements come up(start))
/*
STEP 1: start at index 0
STEP 2: compare consecutive elements
        if a[i] > a[i+1] -> swap(a[i], a[i+1])
STEP 3: move forward i++
STEP 4: Repeat step 1-3 for n-1 passes
*/

/*
Nature:
1. Max comparisons: 1+2+3.. +n-1 = n(n-1)/2 => O(n2)
2. Max Swaps: 1+2+3.. +n-1 = n(n-1)/2 => O(n2)
3. Adaptive : (not natively) modifications can be done to make it adaptive.
4. Stable: order of duplicates remain same, hence Stable
5. Space consumption: only 1 extra (isSwapped) is required.

6. K passes => K sorted elements, hence useful intermediate results.
BEST CASE (already sorted) => 0(n) (after modifications)
WORST CASE (reverse sorted) => 0(n2)
*/

void bubbleSort(int *arr, int n){
    int isSwapped= 0; //false // modification
    // Pass Loop => n-1 times
    for(int i=0; i<n-1; i++){
        for(int j=0; j<(n-1)-i; j++){
            if(arr[j] > arr[j+1]){
                // swapping
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                isSwapped = 1;
            }
        }
        if(isSwapped == 0) {
            //if no swaps were made in a pass then it is already sorted
            break;
        }
    }
}

// 2. Insertion sort (insert unsorted elements to its correct position in the sorted part)
/*
STEP 0: Assume the left extreme i.e a[0] (or right) of the array is already sorted.
STEP 1: start from index 1 i.e j = 1; store temp = a[j]
STEP 2: compare the elements behind j
            if a[j-1] > temp -> a[j] = a[j-1] and j--
STEP 3: repeat STEP 2 until a[j-1] <= temp or j <= 0;
STEP 4: put a[j] = temp
*/

/*
NATURE:
1. Max comparisions: 1 + 2 + 3...+ n-1 => n(n-1)/2 => 0(n2)
2. Max Swaps: 1 + 2 + 3...+ n-1 => n(n-1)/2 => 0(n2)
3. Adaptive: natively adaptive
4. Stable: no change in order of duplicates
5. Extra Space: only 1 extra (temp)

6. No Useful intermediate results.

BEST CASE (already sorted) => 0(n)
WORST CASE (reverse sorted) => 0(n2)
*/

void insertionSort(int *arr, int n){
    
    // n-1 passes
    for(int i=0; i<n-1; i++){
        int j = i+1;
        int temp = arr[j];
        while(arr[j-1] > temp && j > 0){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
}


void printArray(int *arr, int n){
    for(int i = 0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[5] = {8,5,4,4,10};
    
    // bubbleSort(arr, 5);
    insertionSort(arr, 5);
    
    printArray(arr, 5);
    
    return 0;
}
