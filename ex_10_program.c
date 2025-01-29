#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;  // Number of cities
int dist[MAX][MAX];  // Distance matrix

// Function to calculate the total distance of a tour
int calculateTourDistance(int tour[]) {
    int totalDist = 0;
    for (int i = 0; i < n - 1; i++) {
        totalDist += dist[tour[i]][tour[i + 1]];
    }
    totalDist += dist[tour[n - 1]][tour[0]];  // Returning to the starting city
    return totalDist;
}

// Function to generate all permutations of the cities and find the shortest route
void findShortestRoute(int tour[], int start, int end) {
    if (start == end) {
        // Calculate the distance of the current permutation
        int currentDist = calculateTourDistance(tour);
        static int minDist = INT_MAX;
        static int bestTour[MAX];
        
        // If the current distance is shorter, update the best tour
        if (currentDist < minDist) {
            minDist = currentDist;
            for (int i = 0; i < n; i++) {
                bestTour[i] = tour[i];
            }
        }
    } else {
        for (int i = start; i <= end; i++) {
            // Swap elements
            int temp = tour[start];
            tour[start] = tour[i];
            tour[i] = temp;
            
            // Recursively generate permutations
            findShortestRoute(tour, start + 1, end);
            
            // Swap back (backtrack)
            temp = tour[start];
            tour[start] = tour[i];
            tour[i] = temp;
        }
    }
    
    // Print the best tour
    if (start == 0) {
        printf("Shortest route: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", tour[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix (0 for same city distances):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    int tour[MAX];
    for (int i = 0; i < n; i++) {
        tour[i] = i;  // Initialize tour with cities in order
    }

    findShortestRoute(tour, 0, n - 1);

    return 0;
}
