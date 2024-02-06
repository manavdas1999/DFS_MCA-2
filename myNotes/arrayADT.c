/*
Array ADT
*/


#include <stdio.h>
#include <stdlib.h>

struct Array{
    // Method 1: Pointer approach
    int *a;
    // Method 2: static array
    // int a[10];
    int size; //max size (declared at initialization)
    int length; // current number of elements
};

void initialize(struct Array *arr, int size){
    arr->size = size;
    arr->length = 0;
    arr->a = (int*)malloc(arr->size * sizeof(int));
}

void append(struct Array *arr, int x){
    if(arr->length >= arr->size) printf("\n Array overflow: cannot append.");
    else{
        arr->a[arr->length] = x;
        arr->length++;
    }
}

void insert(struct Array *arr, int index, int x){
    if(arr->length >= arr->size){
        printf("\n Array overflow: cannot append.");
    }
    else if(index > arr->length-1 || index < 0) printf("\n Invalid index.");
    else{
        for(int i=arr->length-1; i>=index; i--){
            arr->a[i+1] = arr->a[i];
        }
        arr->a[index] = x;
        arr->length++;
    }
}

void deleteElement(struct Array *arr, int index){
    if(arr->length == 0) printf("\n Array Underflow: Array is empty.");
    else if(index > arr->length-1 || index < 0) printf("\n Invalid index.");
    else{
        for(int i = index; i<arr->length-1; i++){
            arr->a[i] = arr->a[i+1];
        }
        arr->length--;
    }
}

int getElement(struct Array *arr, int index){
    if(index > 0 && index < arr->length){
        return arr->a[index];
    }
    else return -1;
}

void setElement(struct Array *arr, int index, int x){
    if(index > 0 && index < arr->length){
         arr->a[index] = x;
    }
}

int max(struct Array *arr){
    int max = arr->a[0];
    for(int i=1;i<arr->length;i++){
        if(max < arr->a[i]) max = arr->a[i];
    }
    return max;
}

int min(struct Array *arr){
    int min = arr->a[0];
    for(int i=1;i<arr->length;i++){
        if(min > arr->a[i]) min = arr->a[i];
    }
    return min;
}

void reverse(struct Array *arr){
    int low = 0;
    int high = arr->length-1;
    while(low < high){
        // swapping 
        int temp = arr->a[low];
        arr->a[low] = arr->a[high];
        arr->a[high] = temp;
        
        low++;
        high--;
    }
}

int linearSearch(struct Array *arr, int element){
    for(int i = 0; i<arr->length; i++){
        if(arr->a[i] == element) return i;
    }
    return -1;
}

// works only for sorted array
int binerySearch(struct Array *arr, int element){
    int low = 0;
    int high = arr->length-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr->a[mid] == element) return mid;
        else if(arr->a[mid] < element) high = mid-1;
        else if(arr->a[mid] > element) low = mid+1;
    }
    return -1;
}

int sum(struct Array *arr){
    int sum=0;
    for(int i=0; i<arr->length;i++){
        sum = sum + arr->a[i];
    }
    return sum;
}

void display(struct Array *arr){
    printf("\n");
    for(int i=0; i<arr->length; i++){
        printf("%d ", arr->a[i]);
    }
    
}

// left rotate (Left shift with rotation)
void lRotate(struct Array *arr){
    int temp = arr->a[0];
    for(int i=0; i<arr->length-1; i++){
        arr->a[i] = arr->a[i+1];
    }
    arr->a[arr->length-1] = temp;
}
// right rotate (right shift with rotation)
void rRotate(struct Array *arr){
    int temp = arr->a[arr->length-1];
    for(int i=arr->length-1; i>0; i--){
        arr->a[i] = arr->a[i-1];
    }
    arr->a[0] = temp;
}

int isSorted(struct Array *arr){
    for(int i=0; i<arr->length-1;i++){
        if(arr->a[i] > arr->a[i+1]) return -1;
    }
    return 0;
}

int main() {
    
    struct Array myArr;
    initialize(&myArr, 10);
    
    append(&myArr, 2);
    append(&myArr, 4);
    append(&myArr, 1);
    append(&myArr, 5);
    append(&myArr, 2);
    
    // printf("%d", myArr.length);
    
    insert(&myArr, 3, 10);
    deleteElement(&myArr, 3);
    
    display(&myArr);
    
    printf("\n%d", getElement(&myArr, 3));
    
    setElement(&myArr, 3, 30);
    
    printf("\n%d", getElement(&myArr, 3));
    
    display(&myArr);
    
    printf("\n%d", max(&myArr));
    printf("\n%d", min(&myArr));
    
    reverse(&myArr);
    display(&myArr);
    
    printf("\n%d", linearSearch(&myArr, 30));
    
    printf("\n%d", sum(&myArr));
    
    rRotate(&myArr);
    display(&myArr);
    
    printf("\n%d", isSorted(&myArr));

    return 0;
}
