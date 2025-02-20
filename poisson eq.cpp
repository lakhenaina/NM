#include <stdio.h>
#include <math.h>

#define g(x, y) (2 * (x) * (x) * (y) * (y))

int main() {
    int n, i, j, k;
    float sum, error, E[100], a[100][100], b[100], new_x[100], old_x[100];
    float tl, tr, tu, tb, h;

    // Input parameters
    printf("Enter the dimension of the plate (n): ");
    scanf("%d", &n);
    printf("Enter the grid spacing (h): ");
    scanf("%f", &h);
    printf("Enter temperatures at left, right, bottom, and upper parts of the plate:\n");
    printf("Left (tl): ");
    scanf("%f", &tl);
    printf("Right (tr): ");
    scanf("%f", &tr);
    printf("Bottom (tb): ");
    scanf("%f", &tb);
    printf("Top (tu): ");
    scanf("%f", &tu);

    // Initialize coefficient matrix a and vector b
    int size = (n - 1) * (n - 1); // Number of interior points
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            a[i][j] = 0;
        }
        b[i] = 0;
    }

    // Fill coefficient matrix and RHS vector
    k = 0;
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            a[k][k] = -4; // Diagonal element
            if (k > 0 && (k % (n - 1)) != 0) a[k][k - 1] = 1;       // Left neighbor
            if (k < size - 1 && ((k + 1) % (n - 1)) != 0) a[k][k + 1] = 1; // Right neighbor
            if (k >= (n - 1)) a[k][k - (n - 1)] = 1;               // Top neighbor
            if (k < size - (n - 1)) a[k][k + (n - 1)] = 1;         // Bottom neighbor

            // Compute the corresponding b[k] value
            b[k] = h * h * g(i * h, j * h);
            if (i == 1) b[k] -= tb;  // Bottom boundary
            if (i == n - 1) b[k] -= tu; // Top boundary
            if (j == 1) b[k] -= tl;  // Left boundary
            if (j == n - 1) b[k] -= tr; // Right boundary

            k++;
        }
    }

    // Input accuracy limit
    printf("Enter accuracy limit: ");
    scanf("%f", &error);

    // Initialize new_x and old_x
    for (i = 0; i < size; i++) {
        new_x[i] = 0;
    }

    // Gauss-Seidel Iteration
    while (1) {
        int converged = 1;

        for (i = 0; i < size; i++) {
            sum = b[i];
            for (j = 0; j < size; j++) {
                if (i != j) sum -= a[i][j] * new_x[j];
            }
            old_x[i] = new_x[i];
            new_x[i] = sum / a[i][i];
            E[i] = fabs(new_x[i] - old_x[i]) / fabs(new_x[i]);

            if (E[i] > error) {
                converged = 0;
            }
        }

        if (converged) break;
    }

    // Print the solution
    printf("Solution:\n");
    k = 0;
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            printf("x(%d,%d) = %.4f\n", i, j, new_x[k++]);
        }
    }

    return 0;
}

