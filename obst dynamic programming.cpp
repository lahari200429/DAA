#include <stdio.h>
#include <limits.h>
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}
int optimalBST(int keys[], int freq[], int n) {
    int cost[n][n];
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n-1];
}

int main() {
    int keys[] = {10, 20,67,98,43,98};
    int freq[] = {3, 2, 3, 2};
    int n = sizeof(keys) / sizeof(keys[0]);
    printf("Cost of optimal BST is: %d\n", optimalBST(keys, freq, n));
    return 0;
}

