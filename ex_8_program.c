#include <stdio.h>
#include <string.h>

#define MAX 100

int LCS(char *X, char *Y, int m, int n) {
    int dp[m + 1][n + 1];

    // Build the LCS table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    // The length of the LCS is in dp[m][n]
    return dp[m][n];
}

// Function to print the LCS
void printLCS(char *X, char *Y, int m, int n) {
    int dp[m + 1][n + 1];

    // Build the LCS table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    // Backtrack to find the LCS string
    int index = dp[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';  // Null-terminate the LCS string

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Print the LCS string
    printf("LCS: %s\n", lcs);
}

int main() {
    char X[MAX], Y[MAX];

    // Input the two sequences (strings)
    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    // Find the length of LCS
    printf("Length of LCS: %d\n", LCS(X, Y, m, n));

    // Print the LCS string
    printLCS(X, Y, m, n);

    return 0;
}
