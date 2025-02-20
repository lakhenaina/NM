#include <stdio.h>

// Function to calculate factorial
int fact(int n) {
    if (n == 0 || n == 1) return 1;
    else return (n * fact(n - 1));
}

int main() {
    int n, i, j, k;
    float val = 0, xp, x[10], fx[10], bd[10], h, s, term1, term2, prev;

    // Input the number of points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Input values of x and f(x)
    printf("Enter values of x and f(x):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] f(x[%d]): ", i, i);
        scanf("%f %f", &x[i], &fx[i]);
    }

    // Input the value at which derivative is needed
    printf("Enter the value at which derivative is needed: ");
    scanf("%f", &xp);

    // Calculate step size (h) and s (scaled value of xp)
    h = x[1] - x[0];  // assuming uniform spacing
    s = (xp - x[0]) / h;

    // Initialize the backward differences array
    for (i = 0; i < n; i++) {
        bd[i] = fx[i]; 
    }

    // Printing the initial table with x, f(x) and divided differences
    printf("\nInitial Table of x, f(x), and Divided Differences:\n");
    printf("+----+--------+--------+----------------------+\n");
    printf("| i  | x[i]   | f(x[i])| Divided Differences  |\n");
    printf("+----+--------+--------+----------------------+\n");

    for (i = 0; i < n; i++) {
        printf("| %-2d | %-6.4f | %-6.4f | %-19.4f |\n", i, x[i], fx[i], bd[i]);
    }
    printf("+----+--------+--------+----------------------+\n");

    // Backward divided differences calculation
    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            bd[j] = bd[j + 1] - bd[j];
        }

        // Print divided differences at each step
        printf("\nAfter iteration %d:\n", n - i);
        printf("+----+--------+--------+----------------------+\n");
        printf("| i  | x[i]   | f(x[i])| Divided Differences  |\n");
        printf("+----+--------+--------+----------------------+\n");

        for (j = 0; j < i; j++) {
            printf("| %-2d | %-6.4f | %-6.4f | %-19.4f |\n", j, x[j], fx[j], bd[j]);
        }
        printf("+----+--------+--------+----------------------+\n");
    }

    // Calculate the value of the first derivative
    val = bd[0];  // The first divided difference at i=0
    prev = 1;     // Initialize prev before using it

    // Compute the remaining terms for the derivative
    for (i = 1; i < n; i++) {
        term1 = 1;
        for (k = 2; k <= i; k++) {
            term1 *= (s - k + 2);
        }

        term2 = (s - i + 1) * prev;
        prev = (term1 + term2);
        val += (bd[i] * (term1 + term2)) / fact(i);
    }

    val = val / h;  // Final derivative value

    // Output the first derivative value
    printf("\nValue of first Derivative at x = %.4f: %.6f\n", xp, val);

    return 0;
}

