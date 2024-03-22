#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool solution[MAX_SIZE]; 
int arr[MAX_SIZE]; 
int n; 
int targetSum; 

void printSubset() {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if (solution[i]) {
            printf("%d ", arr[i]);
        }
    }
    printf("}\n");
}

void subsetSum(int index, int sum, int remainingSum) {
    if (sum == targetSum) {
        printSubset();
        return;
    }
    if (index == n || sum > targetSum || sum + remainingSum < targetSum)
        return;

    
    solution[index] = true;
    subsetSum(index + 1, sum + arr[index], remainingSum - arr[index]);

    solution[index] = false;
    subsetSum(index + 1, sum, remainingSum - arr[index]);
}

void findSubsets() {
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    if (totalSum < targetSum) {
        printf("No subset with given sum exists.\n");
        return;
    }

    subsetSum(0, 0, totalSum);
}

int main() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Subsets with sum equal to %d are:\n", targetSum);
    findSubsets();

    return 0;
}

