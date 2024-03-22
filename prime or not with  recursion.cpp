#include <stdio.h>
int isPrime(int n, int i) {
    if (n <= 2)
        return (n == 2) ? 1 : 0;
    if (n % i == 0)
        return 0;
    if (i * i > n)
        return 1;
    return isPrime(n, i + 1);
}
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n <= 1)
        printf("%d is not a prime number.\n", n);
    else {
        if (isPrime(n, 2))
            printf("%d is a prime number.\n", n);
        else
            printf("%d is not a prime number.\n", n);
    }
    return 0;
}
