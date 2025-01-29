#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item in the knapsack
struct Item {
    int value;
    int weight;
    float ratio;
};

// Comparison function to sort items based on value/weight ratio in descending order
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    if (item1->ratio < item2->ratio)
        return 1;
    else if (item1->ratio > item2->ratio)
        return -1;
    return 0;
}

// Greedy function to solve knapsack problem
float knapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);

    int totalWeight = 0;
    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - totalWeight;
            totalValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    struct Item items[n];

    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    float maxValue = knapsack(items, n, capacity);
    printf("Maximum value that can be obtained: %.2f\n", maxValue);

    return 0;
}
