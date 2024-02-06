/*
C prerequisites

1. static Array (fixed size):
1.1 declaration and initialization
1.2 traversing or accessing each element


NOTES:
1. static arrays are created in STACK as part of code's activation record.
2. size of static array is decided at COMPILE TIME and cannot be changed.
3. Memory of any array is always allocated at runtime.
*/



/*
2. Dynamic Array (in heap):
2.1 declaration and initialization
2.2 traversing or accessing each element
2.3 How to increase size of a dynamic array

/* NOTES:
1. dynamic arrays are created in HEAP and pointed(controlled) by a pointer created in stack.
2. size of dynamic array can be declared at runtime(hence provides flexibility).
3. Memory of any array is always allocated at runtime.
4. size of dynamic array can be changed with a hack.
5. In heap, memory is allocated in coniguous fashion if demanded that way.
6. IMP: when heap memory is not in use anymore then release it using free(pointer) otherwise memory leak issues arise.
*/

/*
3. Memory representation of Array
Address = Base Address + i * word size
*/


#include <stdio.h>
#include <stdlib.h>

int main() {
//   1.1 declaration and initialization
// NOTE: In C, static arrays must be given a constant value for size.
    // method 1: just declaration
    int arr1[5];  // initializes with garbage values
    
    // method 2: declaration and initialization
    int arr2[5] = {2,4,5,1,4};  // 2,4,5,1,4
    
    // method 3: with less elements then size (puts 0 in uninitialized places)
    int arr3[5] = {2,4};  // 2,4,0,0,0
    
    // method 4: initialize with zero
    int arr4[5] = {0};  // 0,0,0,0,0
    
    // method 5: initialization without size (size is calculated)
    int arr5[] = {2,4,5,1,3};
   
   
//   1.2 traverse (NOTE: size is fixed)
    for(int i=0; i<5; i++){
        // printf("%d ", arr1[i]);
        // printf("%d ", arr2[i]);
        // printf("%d ", arr3[i]);
        printf("%d ", arr4[i]);
        // printf("%d ", arr5[i]);
        // printf("%d ", i[arr5]);
        // printf("%d ", *(arr5 + i));
        
    }
    printf("\n");
    
    // NOTE: some other ways of accessing array elements
    // printf("%d ", i[arr5]);
    // printf("%d ", *(arr5 + i)); // pointer points to address location arr5(base address) + i
    
    
    // 2.1 declaration and initialization
    int *arr;  // pointer in stack
    int size = 5; //non constant
    arr = (int*) malloc(size * sizeof(int));  // 5 contiguius memeory spaces are allocated and arr pointer points to its start i.e 0 index
    // NOTE: default value is 0 at all indexes (default value of int in heap is 0)
    // manual allocation of elements (works same for static array as well)
    /*
    arr[0] = 2;
    arr[1] = 4;
    arr[2] = 5;
    arr[3] = 2;
    arr[4] = 1;
    */
    
    // 2.2 traversing
    // feeding custom values (works same for static array as well)
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);   
    }
    
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);   // &arr[i] will give address
    }
    printf("\n");
    
    // 2.3 increase the size of a dynamic array
    // step 1: create a bigger size dynamic array
    int newSize = 10;
    int *newArr = (int*) malloc(newSize * sizeof(int));
    // step 2: copy contents of original array
    for(int i=0; i<size; i++){
        newArr[i] = arr[i];
    }
    // step 3: pointer exchange 
    free(arr);
    arr = newArr;
    newArr = NULL;
    
    for(int i=0; i<newSize; i++){
        printf("%d ", arr[i]);   // &arr[i] will give address
    }
    printf("\n");

    // 3. Memory representation
    for(int i = 0; i<5; i++){
        printf("Address of element at index %d: %d\n", i, &arr2[i]); 
        // note the difference is of 4bytes i.e compiler takes 4bytes to store int here
    }
    printf("\n");
    
    //TODO: not working, why ?
    for(int i = 0; i<5; i++){
        printf("%d ", (&arr2) + (i*4));
    }
    printf("\n");





    return 0;
}
