#include <stdio.h>
#include <stdbool.h>
#define N 4
#define INF 9999

int cost[N][N] = {
    {7, 9, 6, 4},
    {12, 8, 19, 6},
    {10, 15, 3, 7},
    {8, 6, 5, 4}
};
int minCost = INF;

bool assigned[N] = {false};

void branchAndBound(int worker, int totalCost) {
    if (worker == N) {
        if (totalCost < minCost) {
            minCost = totalCost;
        }
        return;
    }
    
    for (int job = 0; job < N; job++) {
        if (!assigned[job]) {
            assigned[job] = true;
            branchAndBound(worker + 1, totalCost + cost[worker][job]);
            assigned[job] = false;
        }
    }
}

int main() {
    branchAndBound(0, 0);
    printf("Minimum cost: %d\n", minCost);
    return 0;
}
