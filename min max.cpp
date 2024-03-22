#include <stdio.h>
void findMinMax(int arr[], int size, int index, int *min, int *max) {
    if (index == size) {
        return;
    }
    if (arr[index] < *min) {
        *min = arr[index]; 
    }
    if (arr[index] > *max) {
        *max = arr[index]; 
    }
    findMinMax(arr, size, index + 1, min, max);
}
int main() {
    int arr[] = {3,6,8,9,87,34,2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0]; 
    int max = arr[0];
    printf("enter the numbers:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    findMinMax(arr, size, 0, &min, &max);
    printf("Minimum value in the list: %d\n", min);
    printf("Maximum value in the list: %d\n", max);
    return 0;
}
