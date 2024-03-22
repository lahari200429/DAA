#include <stdio.h>
void printPattern(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printPattern(n);
    return 0;
}
