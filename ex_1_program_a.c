#include <stdio.h>

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

void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
        printf("3. Sort using Insertion Sort\n");
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
                insertionSort(arr, size);
                printf("Array sorted using Insertion Sort.\n");
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
