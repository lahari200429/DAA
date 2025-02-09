#include <stdio.h>
#define N 2
void multiply(int A[N][N], int B[N][N], int C[N][N]) {
    int M1, M2, M3, M4, M5, M6, M7;
    M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    M2 = (A[1][0] + A[1][1]) * B[0][0];
    M3 = A[0][0] * (B[0][1] - B[1][1]);
    M4 = A[1][1] * (B[1][0] - B[0][0]);
    M5 = (A[0][0] + A[0][1]) * B[1][1];
    M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
}
void display(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int A[N][N] = {{1, 2}, {3, 4}};
    int B[N][N] = {{6, 8}, {9, 8}};
    int C[N][N] = {{0, 0}, {0, 0}};
    multiply(A, B, C);
    printf("Matrix A:\n");
    display(A);
    printf("\nMatrix B:\n");
    display(B);
    printf("\nResultant Matrix C:\n");
    display(C);
    return 0;
}
