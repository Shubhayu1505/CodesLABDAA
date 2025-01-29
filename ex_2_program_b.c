#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Add this header for strcmp

void insertElement(int arr[], int *size, int element) {
    arr[*size] = element;
    (*size)++;
}

void removeElement(int arr[], int *size, int element) {
    int i, found = 0;
    for (i = 0; i < *size; i++) {
        if (arr[i] == element) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            break;
        }
    }
    if (!found) {
        printf("Element not found!\n");
    }
}

int binarySearch(int arr[], int size, int element) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == element) {
            return mid;
        }
        if (arr[mid] < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], size = 0, choice, element, index;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Remove Element\n");
        printf("3. Search using Binary Search\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insertElement(arr, &size, element);
                break;
            case 2:
                printf("Enter element to remove: ");
                scanf("%d", &element);
                removeElement(arr, &size, element);
                break;
            case 3:
                // Ensure the array is sorted before binary search
                printf("Enter element to search for: ");
                scanf("%d", &element);
                qsort(arr, size, sizeof(int), (int (*)(const void *, const void *))strcmp);
                index = binarySearch(arr, size, element);
                if (index != -1) {
                    printf("Element found at index %d.\n", index);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 4:
                printArray(arr, size);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
