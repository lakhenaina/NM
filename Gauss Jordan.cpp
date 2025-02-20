#include<stdio.h>
#include<conio.h>
#include<math.h>

int main() {
    int n, i, k, j, p, q;
    float pivot, term, a[10][10];

    printf("Enter dimensions of the system of equations: ");
    scanf("%d", &n);

    printf("Enter coefficients of the augmented matrix:\n");
    for(i = 0; i < n; i++) { // Corrected the loop condition here
        for(j = 0; j < n + 1; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    for(k = 0; k < n; k++) {
        pivot = a[k][k];
        for(p = 0; p < n + 1; p++) {
            a[k][p] = a[k][p] / pivot;
        }
        for(i = 0; i < n; i++) {
            term = a[i][k];
            if(k != i) {
                for(j = 0; j < n + 1; j++) {
                    a[i][j] = a[i][j] - a[k][j] * term;
                }
            }
        }
    }

    printf("Solution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %f\t", i + 1, a[i][n]); // Updated indexing for solution output
    }

    getch();
    return 0;
}

