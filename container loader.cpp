#include <stdio.h>
#include <stdlib.h>
#define MAX_CONTAINERS 100
struct Container {
    int id;
    int weight;
};
void sortContainers(struct Container containers[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (containers[j].weight > containers[j+1].weight) {
                struct Container temp = containers[j];
                containers[j] = containers[j+1];
                containers[j+1] = temp;
            }
        }
    }
}
void loadContainers(struct Container containers[], int n, int shipCapacity) {
    int totalWeight = 0;
    int loadedContainers = 0;

    printf("Loading containers...\n");

    for (int i = 0; i < n; i++) {
        if (totalWeight + containers[i].weight <= shipCapacity) {
            totalWeight += containers[i].weight;
            loadedContainers++;
            printf("Container %d (weight: %d) loaded onto the ship.\n", containers[i].id, containers[i].weight);
        } else {
            break; 
        }
    }

    printf("Total containers loaded: %d\n", loadedContainers);
    printf("Total weight loaded: %d\n", totalWeight);
}

int main() {
    struct Container containers[MAX_CONTAINERS];
    int n, shipCapacity;

    printf("Enter the number of containers: ");
    scanf("%d", &n);

    printf("Enter the ship's capacity: ");
    scanf("%d", &shipCapacity);
    printf("Enter the weights of the containers:\n");
    for (int i = 0; i < n; i++) {
        containers[i].id = i + 1;
        scanf("%d", &containers[i].weight);
    }
    sortContainers(containers, n);
    loadContainers(containers, n, shipCapacity);
    return 0;
}
