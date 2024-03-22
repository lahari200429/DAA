#include <stdio.h>
#include <stdbool.h>
#define N 8
int solutionCount = 0; 
void printSolution(int board[N][N]) {
    solutionCount++;
    printf("Solution %d:\n", solutionCount);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    return true;
}

bool solveNQueensUtil(int board[N][N], int col) {
    if (col >= N) {
        printSolution(board);
        if (solutionCount >= 8) { 
            return true;
        }
        return false; 
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueensUtil(board, col + 1)) {
                return true;
            }

            board[i][col] = 0; 
        }
    }

    return false;
}

bool solveNQueens() {
    int board[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0} };

    if (solveNQueensUtil(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }

    return true;
}

int main() {
    solveNQueens();
    return 0;
}

