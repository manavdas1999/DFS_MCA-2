/*
5. Write A C Program to Perform Count Sort on An Unsorted Array
*/
#include <stdio.h>
#include <stdlib.h>

// Function to perform Count Sort
void countSort(int arr[], int n) {
    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create a count array to store the count of each element
    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Store the count of each element in the count array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Update the count array to store the actual position of each element
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted elements
    int temp[n];
    for (int i = n - 1; i >= 0; i--) {
        temp[--count[arr[i]]] = arr[i];
    }

    // Copy the sorted elements from the temporary array to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("\nElement array[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nBefore Count Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Perform Count Sort
    countSort(arr, n);

    // Print the sorted array
    printf("\nAfter Count Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
