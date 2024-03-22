#include <stdio.h>
unsigned long long int binomialCoefficient(int n, int k) {
    unsigned long long int C[n+1][k+1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k && j <= i; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C[n][k];
}
int main() {
    int n, k;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    if (n < 0 || k < 0 || k > n) {
        printf("Invalid input. Please enter non-negative values for n and k, and k should be less than or equal to n.\n");
        return 1; 
    }
    printf("Binomial Coefficient C(%d, %d) is %llu\n", n, k, binomialCoefficient(n, k));
    return 0;
}
