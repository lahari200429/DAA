#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
    double ratio; 
};
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item2->ratio - item1->ratio);
}

void fractionalKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(items[0]), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].ratio * remainingCapacity;
            break;
        }
    }
    printf("Total value in the knapsack: %.2lf\n", totalValue);
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    fractionalKnapsack(items, n, capacity);

    return 0;
}
