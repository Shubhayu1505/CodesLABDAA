#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function to print the board
void printBoard(int board[MAX][MAX], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
// This function checks the column and both diagonals for conflicts
bool isSafe(int board[MAX][MAX], int row, int col, int N) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to solve the N Queen problem using backtracking
bool solveNQueens(int board[MAX][MAX], int row, int N) {
    // If all queens are placed
    if (row >= N) {
        return true;
    }

    // Consider this row and try placing the queen in all columns one by one
    for (int col = 0; col < N; col++) {
        // Check if it's safe to place the queen in board[row][col]
        if (isSafe(board, row, col, N)) {
            // Place the queen
            board[row][col] = 1;

            // Recursively place the queen in the next row
            if (solveNQueens(board, row + 1, N)) {
                return true;
            }

            // If placing queen in board[row][col] doesn't lead to a solution, backtrack
            board[row][col] = 0; // Remove queen (backtrack)
        }
    }

    // If the queen cannot be placed in any column in this row, return false
    return false;
}

int main() {
    int N;

    printf("Enter the number of queens (N): ");
    scanf("%d", &N);

    int board[MAX][MAX] = {0};

    if (solveNQueens(board, 0, N)) {
        printf("Solution to the N-Queens problem:\n");
        printBoard(board, N);
    } else {
        printf("Solution does not exist\n");
    }

    return 0;
}
