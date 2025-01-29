#include <stdio.h>
#include <stdlib.h>

void insertMatrix(int matrix[][100], int *rows, int *cols) {
    printf("Enter number of rows and columns: ");
    scanf("%d%d", rows, cols);
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[][100], int rows, int cols) {
    printf("Matrix: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[][100], int B[][100], int result[][100], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[][100], int B[][100], int result[][100], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassenMultiply(int A[][100], int B[][100], int C[][100], int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int A11[100][100], A12[100][100], A21[100][100], A22[100][100];
    int B11[100][100], B12[100][100], B21[100][100], B22[100][100];
    int M1[100][100], M2[100][100], M3[100][100], M4[100][100];
    int M5[100][100], M6[100][100], M7[100][100];
    int temp1[100][100], temp2[100][100];

    // Divide A into four sub-matrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    addMatrices(A11, A22, temp1, newSize);
    addMatrices(B11, B22, temp2, newSize);
    strassenMultiply(temp1, temp2, M1, newSize);

    // M2 = (A21 + A22) * B11
    addMatrices(A21, A22, temp1, newSize);
    strassenMultiply(temp1, B11, M2, newSize);

    // M3 = A11 * (B12 - B22)
    subtractMatrices(B12, B22, temp2, newSize);
    strassenMultiply(A11, temp2, M3, newSize);

    // M4 = A22 * (B21 - B11)
    subtractMatrices(B21, B11, temp2, newSize);
    strassenMultiply(A22, temp2, M4, newSize);

    // M5 = (A11 + A12) * B22
    addMatrices(A11, A12, temp1, newSize);
    strassenMultiply(temp1, B22, M5, newSize);

    // M6 = (A21 - A11) * (B11 + B12)
    subtractMatrices(A21, A11, temp1, newSize);
    addMatrices(B11, B12, temp2, newSize);
    strassenMultiply(temp1, temp2, M6, newSize);

    // M7 = (A12 - A22) * (B21 + B22)
    subtractMatrices(A12, A22, temp1, newSize);
    addMatrices(B21, B22, temp2, newSize);
    strassenMultiply(temp1, temp2, M7, newSize);

    // C11 = M1 + M4 - M5 + M7
    addMatrices(M1, M4, temp1, newSize);
    subtractMatrices(M5, M7, temp2, newSize);
    addMatrices(temp1, temp2, C, newSize);

    // C12 = M3 + M5
    addMatrices(M3, M5, C + newSize, newSize);

    // C21 = M2 + M4
    addMatrices(M2, M4, C + newSize * size, newSize);

    // C22 = M1 - M2 + M3 + M6
    addMatrices(M1, M2, temp1, newSize);
    addMatrices(M3, M6, temp2, newSize);
    subtractMatrices(temp1, temp2, C + newSize * size + newSize, newSize);
}

int main() {
    int A[100][100], B[100][100], C[100][100], rowsA, colsA, rowsB, colsB, choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Matrix A\n");
        printf("2. Insert Matrix B\n");
        printf("3. Perform Strassen's Matrix Multiplication\n");
        printf("4. Display Matrix A\n");
        printf("5. Display Matrix B\n");
        printf("6. Display Resulting Matrix\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertMatrix(A, &rowsA, &colsA);
                break;
            case 2:
                insertMatrix(B, &rowsB, &colsB);
                break;
            case 3:
                if (rowsA == colsA && rowsB == colsB && rowsA == rowsB) {
                    strassenMultiply(A, B, C, rowsA);
                    printf("Strassen's Matrix Multiplication is completed.\n");
                } else {
                    printf("Matrix dimensions are not compatible for multiplication.\n");
                }
                break;
            case 4:
                displayMatrix(A, rowsA, colsA);
                break;
            case 5:
                displayMatrix(B, rowsB, colsB);
                break;
            case 6:
                displayMatrix(C, rowsA, colsA);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
