#include <stdio.h>
int binarySearch(int arr[], int size, int target) 
{
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() 
{
    int arr[] = {1, 3, 5,7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 11;
    int result = binarySearch(arr, size, target);
    if (result != -1)
        printf("Element %d is present at index %d.\n", target, result);
    else
        printf("Element %d is not present in the array.\n", target);
    return 0;
}
