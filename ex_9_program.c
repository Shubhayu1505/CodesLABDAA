#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8

void printBoard(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }
    return 1;
}

void shuffle(int arr[]) {
    for (int i = N - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int solveNQueens(int board[N][N], int col) {
    if (col >= N) {
        return 1;
    }
    int rows[N];
    for (int i = 0; i < N; i++) {
        rows[i] = i;
    }
    shuffle(rows);
    for (int i = 0; i < N; i++) {
        int row = rows[i];
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            if (solveNQueens(board, col + 1)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[N][N];
    int boardInt[N][N] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 'O';
        }
    }
    if (solveNQueens(boardInt, 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (boardInt[i][j] == 1) {
                    board[i][j] = 'X';
                }
            }
        }
        printBoard(board);
    } else {
        printf("Solution does not exist.\n");
    }
    return 0;
}
