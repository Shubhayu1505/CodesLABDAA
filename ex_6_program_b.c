#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x, y;
} Point;

// Function to find the orientation of the ordered triplet (p, q, r)
// Returns 0 if collinear, 1 if clockwise, 2 if counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or counterclockwise
}

// Comparison function for sorting points
int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return p1->x - p2->x;
}

// Function to find the convex hull using Graham's Scan
void convexHull(Point points[], int n) {
    if (n < 3) {
        printf("Convex hull cannot be formed with less than 3 points.\n");
        return;
    }

    // Step 1: Sort the points by x coordinate
    qsort(points, n, sizeof(Point), compare);

    // Step 2: Create an empty stack
    Point stack[n];
    int top = -1;

    // Step 3: Build the lower hull
    for (int i = 0; i < n; i++) {
        while (top >= 2 && orientation(stack[top - 1], stack[top], points[i]) != 2) {
            top--;
        }
        stack[++top] = points[i];
    }

    // Step 4: Build the upper hull
    int t = top + 1;
    for (int i = n - 2; i >= 0; i--) {
        while (top >= t && orientation(stack[top - 1], stack[top], points[i]) != 2) {
            top--;
        }
        stack[++top] = points[i];
    }

    // Step 5: Print the points of the convex hull
    printf("Convex Hull:\n");
    for (int i = 0; i <= top; i++) {
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
    }
}

int main() {
    int n;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point points[n];
    printf("Enter the points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    convexHull(points, n);

    return 0;
}
