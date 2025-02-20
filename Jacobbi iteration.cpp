#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j;
    float sum, error, E[10], a[10][10], b[10], new_x[10], old_x[10];

    // Input system dimensions
    printf("Enter dimensions of the system of equations: ");
    scanf("%d", &n);

    // Input coefficients matrix
    printf("Enter coefficients row-wise:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Input RHS vector
    printf("Enter RHS vector:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    // Input accuracy limit
    printf("Enter accuracy limit: ");
    scanf("%f", &error);

    // Initialize old_x to 0
    for (i = 0; i < n; i++) {
        old_x[i] = 0;
    }

    // Iterative calculation
    while (1) {
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum -= a[i][j] * old_x[j];
                }
            }
            new_x[i] = sum / a[i][i];
            E[i] = fabs((new_x[i] - old_x[i]) / fabs(new_x[i]));
        }

        // Check for convergence
        for (i = 0; i < n; i++) {
    if (E[i] > error) {
        for (j = 0; j < n; j++)
            old_x[j] = new_x[j];
        break;
    }
}

        if(i==n) 
            break;
        else 
        continue;
    }


    // Output the solution
    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %6.2f\n", i + 1, new_x[i]);
    }

    return 0;
}

