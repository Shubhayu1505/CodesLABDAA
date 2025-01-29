#include <stdio.h>
#include <stdlib.h>

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

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return (i + 1); // Return the partition index
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], size = 0, choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Remove Element\n");
        printf("3. Sort using Quick Sort\n");
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
                quickSort(arr, 0, size - 1);
                printf("Array sorted using Quick Sort.\n");
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
