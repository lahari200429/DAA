#include <stdio.h>
#include <stdbool.h>
bool isPrime(int num, int i) {
    if (num <= 2) {
        return (num == 2) ? true : false;
    }
    if (num % i == 0) {
        return false;
    }
    if (i * i > num) {
        return true;
    }
    return isPrime(num, i + 1);
}
void printPrimes(int n, int i) {
    if (i <= n) {
        if (isPrime(i, 2)) {
            printf("%d ", i);
        }
        printPrimes(n, i + 1);
    }
}
int main() {
    int limit;
    printf("Enter the limit to find prime numbers: ");
    scanf("%d", &limit);
    printf("Prime numbers up to %d are: ", limit);
    printPrimes(limit, 2);
    printf("\n");
    return 0;
}
