#include <stdio.h>
#include <stdbool.h>
#define V 5

void printSolution(int path[]);
bool isSafe(int v, bool graph[V][V], int path[], int pos);
bool hamCycleUtil(bool graph[V][V], int path[], int pos);
bool hamCycle(bool graph[V][V]);

void printAllHamiltonianPaths(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }

    path[0] = 0;
    hamCycleUtil(graph, path, 1);
}

bool hamCycleUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            printSolution(path);
            return true;
        }
        else {
            return false;
        }
    }
 
    bool found = false;
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            found = hamCycleUtil(graph, path, pos + 1) || found;
            path[pos] = -1;
        }
    }

    return found;
}

bool hamCycle(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }

    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == false) {
        printf("Solution does not exist\n");
        return false;
    }

    return true;
}

void printSolution(int path[]) {
    printf("Hamiltonian Path: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);
}

bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

int main() {
	/* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
    bool graph[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};

    printf("Hamiltonian Paths:\n");
    printAllHamiltonianPaths(graph);

    return 0;
}

