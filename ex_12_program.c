#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 256

// Naive String Matching Algorithm
void naiveStringMatch(char *text, char *pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);

    for (int i = 0; i <= textLen - patternLen; i++) {
        int j = 0;
        
        // Check for match
        while (j < patternLen && text[i + j] == pattern[j]) {
            j++;
        }

        if (j == patternLen) {
            printf("Naive: Pattern found at index %d\n", i);
        }
    }
}

// KMP String Matching Algorithm
void computeLPSArray(char *pattern, int m, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPStringMatch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    int lps[m];
    computeLPSArray(pattern, m, lps);

    int i = 0, j = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("KMP: Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

// Rabin-Karp Algorithm
#define d 256

void rabinKarp(char *text, char *pattern, int q) {
    int m = strlen(pattern);
    int n = strlen(text);
    int p = 0, t = 0, h = 1;

    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j = 0;
            while (j < m && text[i + j] == pattern[j]) {
                j++;
            }
            if (j == m) {
                printf("Rabin-Karp: Pattern found at index %d\n", i);
            }
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
}

// Boyer-Moore Algorithm
void badCharacterHeuristic(char *pattern, int m, int *badChar) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        badChar[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        badChar[(int)pattern[i]] = i;
    }
}

void boyerMoore(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int badChar[ALPHABET_SIZE];

    badCharacterHeuristic(pattern, m, badChar);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            printf("Boyer-Moore: Pattern found at index %d\n", s);
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } else {
            s += (j - badChar[text[s + j]] > 1) ? j - badChar[text[s + j]] : 1;
        }
    }
}

// Main function
int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABAB";
    int q = 101;  // Prime number for Rabin-Karp hash

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    int choice;
    printf("Choose an algorithm:\n");
    printf("1. Naive\n2. KMP\n3. Rabin-Karp\n4. Boyer-Moore\n");
    printf("Enter choice (1/2/3/4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            naiveStringMatch(text, pattern);
            break;
        case 2:
            KMPStringMatch(text, pattern);
            break;
        case 3:
            rabinKarp(text, pattern, q);
            break;
        case 4:
            boyerMoore(text, pattern);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
