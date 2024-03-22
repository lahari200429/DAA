#include <stdio.h>
void generateFactors(int n, int i) {
    if (i > n)
        return;

    if (n % i == 0)
        printf("%d ", i);

    generateFactors(n, i + 1);
}
int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("Factors of %d are: ", n);
    generateFactors(n, 1);
    return 0;
}
