/* 
29-1-24
DS lab HW
Q1. Create a menu driven program to perform following operations
1. Traverse
2. Insert
3. Delete
4. Linear Search (single occurance, multiple occurance)
5. Binary Search
6. Exit
*/ 


#include<stdio.h>
#include <stdlib.h>

// global array
int arr[10] = {1,2,3,4,5};
int length=5;  // 0 for custom array

// function to take values from user
void makeArray(){
    printf("Enter size of array (1-10): ");
    scanf("%d", &length);

    for(int i=0; i<length; i++){
        printf("\nEnter value at index %d: ",i);
        scanf("%d", &arr[i]);
    }
}

// function to traverse array
void traverse(){
    for(int i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function to insert into array
int insert(int loc, int val){
    
    if(loc < 0 || loc > length){
        printf("Invalid index\n");
        return -1;
    }
    
    for(int i=length+1; i>loc; i--){
        arr[i] = arr[i-1];
    }
    arr[loc] = val;
    length++;
    
    return 0;
}

// function to Delete from array (index based delete)
// TODO: value based delete
int deleteItem(int loc){
    if(loc <0 || loc >=length){
        printf("Invalid index\n");
        return -1;
    }
    
    int temp = arr[loc];
    for(int i=loc; i<length-1; i++){
        arr[i] = arr[i+1];
    }
    length--;
    
    return temp;
}

// function to perform linear search (return first occurance)
int lsearch(int val){
    for(int i=0; i<length; i++){
        if(val == arr[i]) return i;
    }
    return -1;
}

// function to find count of occurances using linear search
int count(int val){
    int count = 0;
    for(int i=0; i<length; i++){
        if(val == arr[i]) count++;
    }
    return count;
}

// function to search an element using binary search
// NOTE: array must be sorted
int binarySearch(int val){
    int low = 0, high=length, mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid] == val) return mid;
        if(arr[mid] > val) high = mid-1;
        if(arr[mid] < val) low = mid+1;
    }
    return -1;
}


// function for menu
void showMenu(){
    int choice;
    printf("Array operations menu\n");
    printf("1. Create your own array.\n");
    printf("2. Traverse\n");
    printf("3. Insert\n");
    printf("4. Delete\n");
    printf("5. Linear Search (first occurance)\n");
    printf("6. Count (multiple occurance)\n");
    printf("7. Binary Search (ONLY IF SORTED ARRAY!)\n");
    printf("8. Exit\n");
    
    printf("\nYour choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1: makeArray(); break;
        case 2: traverse(); break;
        case 3: {
            int loc,val;
            printf("\nEnter insert index:");
            scanf("%d", &loc);
            printf("\nEnter value to insert:");
            scanf("%d", &val);
            insert(loc, val); break;
        }
        case 4: {
            int loc;
            printf("\nEnter delete index:");
            scanf("%d", &loc);
            deleteItem(loc); 
            break;
        }
        case 5: {
            int val;
            printf("\nEnter value to search:");
            scanf("%d", &val);
            printf("Index of searched item: %d\n", lsearch(val)); 
            break;
        } 
        case 6: {
            int val;
            printf("\nEnter value to count:");
            scanf("%d", &val);
            printf("Count of given value: %d\n", count(val)); 
            break;
        } 
        case 7:{
            int val;
            printf("\nEnter value to search:");
            scanf("%d", &val);
            printf("Index of searched item: %d\n", binarySearch(val)); 
            break;
        } 
        case 8: exit(1);
        default: printf("Invalid option!"); break;
    }
}


int main(){
    // // makeArray();
    // traverse();
    // insert(2,10);
    // traverse();
    // delete(6);
    // traverse();
    // printf("%d\n", lsearch(1));
    // printf("%d\n", count(11));
    // // printf("%d\n", bsearch(3));
    while(1){
        showMenu();
    }

    return 0;
}