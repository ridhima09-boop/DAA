#include <stdio.h>

int main() {
    int A[10][10], B[10][10], C[10][10];
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter rows and columns of A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of B: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible.");
        return 0;
    }

    printf("Enter matrix A:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            C[i][j] = 0;

            for (k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    printf("Result:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
