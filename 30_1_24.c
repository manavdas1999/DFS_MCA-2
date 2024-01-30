

#include<stdio.h>

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





int main(){
    
    int myArray[5] = {1,2,5,4,8};
    
    
    
    printf("%d", bSearch(myArray, 0, 4, 2));
    
    return 0;
}
