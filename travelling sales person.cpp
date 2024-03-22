#include <stdio.h>
#include <limits.h>
#define V 4 
int min(int a, int b) {
    return (a < b) ? a : b;
}
int tsp(int graph[][V], int mask, int pos, int dp[][V]) {
    if (mask == (1 << V) - 1) {
        return graph[pos][0]; 
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    int ans = INT_MAX;
    for (int city = 0; city < V; city++) {
        if (!(mask & (1 << city)) && graph[pos][city]) {
            int newAns = graph[pos][city] + tsp(graph, mask | (1 << city), city, dp);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}
void initialize(int dp[][V]) {
    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = -1;
        }
    }
}
int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int dp[1 << V][V];
    initialize(dp);
    int minCost = tsp(graph, 1, 0, dp); 
    printf("Minimum cost of TSP: %d\n", minCost);
    return 0;
}
