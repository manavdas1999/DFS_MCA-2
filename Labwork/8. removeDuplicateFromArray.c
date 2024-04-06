/*
8. Write A C Program to Remove Duplicate Elements from An Array
*/

#include <stdio.h>
#include <stdlib.h>

// Function to remove duplicate elements from the array
int* removeDuplicates(int arr[], int n, int* newSize) {
    // Create a boolean array to mark visited elements
    int* visited = (int*)malloc(n *   sizeof(int));
    if (visited == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Count the number of distinct elements
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            arr[count++] = arr[i];
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    visited[j] = 1;
                }
            }
        }
    }

    // Update the new size of the array
    *newSize = count;

    // Reallocate memory for the array
    arr = (int*)realloc(arr, count * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }

    // Free memory allocated for the visited array
    free(visited);

    return arr;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Remove duplicate elements from the array
    int newSize;
    arr = removeDuplicates(arr, n, &newSize);

    // Print the array after removing duplicates
    printf("Array after removing duplicates:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
