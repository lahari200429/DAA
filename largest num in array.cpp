#include <stdio.h>
int findLargest(int arr[], int size) {
    if (size == 1)
        return arr[0];
    int largestInRest = findLargest(arr + 1, size - 1);
	   return (arr[0] > largestInRest) ? arr[0] : largestInRest;
}
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int largest = findLargest(arr, size);
    printf("The largest element in the array is: %d\n", largest);
    return 0;
}
