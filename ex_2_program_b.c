#include <stdio.h>

// Function to perform binary search (array must be sorted)
int binarySearch(int arr[], int size, int element) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == element)
            return mid; // Element found
        
        if (arr[mid] < element)
            left = mid + 1; // Search in right half
        else
            right = mid - 1; // Search in left half
    }
    return -1; // Element not found
}

// Function to sort the array using Bubble Sort (for simplicity)
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], size, choice, element, index;

    // Taking input for array size and elements
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    printf("Enter the elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting the array before performing Binary Search
    bubbleSort(arr, size);
    printArray(arr, size);

    // Searching menu loop
    while (1) {
        printf("\nMenu:\n");
        printf("1. Search using Binary Search\n");
        printf("2. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search for: ");
                scanf("%d", &element);
                index = binarySearch(arr, size, element);
                if (index != -1) {
                    printf("Element found at index %d.\n", index);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 2:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
