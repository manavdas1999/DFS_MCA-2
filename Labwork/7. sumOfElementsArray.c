/*
7. Write A C To Dynamically Allocate an Array and Calculate Sum of Its Elements.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int sum = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("\nElement array[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    
    // printing array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Calculate sum of array elements
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Print the sum
    printf("Sum of array elements: %d\n", sum);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
