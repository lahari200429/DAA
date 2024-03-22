#include <stdio.h>
#define MAX_SIZE 100
void displayList(int list[], int size) {
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}
void insertNumber(int list[], int *size, int number, int position) {
    if (position < 0 || position > *size || *size >= MAX_SIZE) {
        printf("Error: Invalid position or list is full, cannot insert.\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        list[i] = list[i - 1];
    }
    list[position] = number;
    (*size)++;
}
int main() {
    int list[MAX_SIZE] = {10, 20, 40}; 
    int size = 3; 
    printf("List before insertion:\n");
    displayList(list, size);
    int numberToInsert = 30;
    int positionToInsert = 2;
    insertNumber(list, &size, numberToInsert, positionToInsert);
    printf("\nList after insertion of %d at position %d:\n", numberToInsert, positionToInsert);
    displayList(list, size);
    return 0;
}
