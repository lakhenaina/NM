#include <stdio.h>
#include <math.h>

// Function to calculate factorial
int fact(int n) {
    if (n == 0 || n == 1) return 1;
    else return n * fact(n - 1);
}

int main() {
    int n, i, j;
    float val = 0, p, xp, x[10], fx[10], bd[10][10], h, s;

    // Input the number of points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Input values of x and f(x)
    printf("Enter values of x and f(x):\n");
    for (i = 0; i < n; i++) {
        scanf("%f%f", &x[i], &fx[i]);
    }

    // Input the value at which derivative is needed
    printf("Enter the value at which derivative is needed: ");
    scanf("%f", &xp);

    // Calculate step size (h)
    h = x[1] - x[0];  // Assuming uniform spacing
    s = (xp - x[n - 1]) / h;

    // Initialize backward difference table
    for (i = 0; i < n; i++) {
        bd[i][0] = fx[i]; // First column is just f(x)
    }

    // Compute backward differences
    for (j = 1; j < n; j++) {
        for (i = n - 1; i >= j; i--) {
            bd[i][j] = bd[i][j - 1] - bd[i - 1][j - 1];
        }
    }

    // Printing the backward difference table
    printf("\nBackward Difference Table:\n");
    printf("+----+--------+--------+--------+--------+\n");
    printf("| i  | x[i]   | f(x[i])| BD(1)  | BD(2)  |\n");
    printf("+----+--------+--------+--------+--------+\n");
    for (i = 0; i < n; i++) {
        printf("| %-2d | %-6.4f | %-6.4f | %-6.4f | %-6.4f |\n", i, x[i], fx[i], bd[i][1], bd[i][2]);
    }
    printf("+----+--------+--------+--------+--------+\n");

    // Compute the first derivative using backward difference formula
    val = bd[n - 1][1]; // First backward difference term
    for (i = 2; i < n; i++) {
        float term = bd[n - 1][i];
        for (j = 1; j < i; j++) {
            term *= (s + j - 1);
        }
        val += (term / fact(i));
    }

    // Divide by step size to get the derivative
    val /= h;

    // Output the first derivative value
    printf("Value of first derivative = %f\n", val);

    return 0;
}

