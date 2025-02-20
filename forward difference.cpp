#include<stdio.h>

// Function to calculate factorial
int fact(int n) {
    if (n == 1) return 1;
    else return (n * fact(n - 1));
}

int main() {
    int n, i, j, k;
    float val = 0, xp, x[10], fx[10], fd[10], h, s, term1, term2, prev;

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

    // Initialize the forward differences array
    for (i = 0; i < n; i++) {
        fd[i] = fx[i];
    }

    // Printing the initial table with x, f(x), and forward differences
    printf("\nInitial Table of x, f(x), and Forward Differences:\n");
    printf("+----+--------+--------+----------------------+\n");
    printf("| i  | x[i]   | f(x[i])| Forward Differences  |\n");
    printf("+----+--------+--------+----------------------+\n");
    for (i = 0; i < n; i++) {
        printf("| %-2d | %-6.4f | %-6.4f | %-19.4f |\n", i, x[i], fx[i], fd[i]);
    }
    printf("+----+--------+--------+----------------------+\n");

    // Forward difference calculation
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            fd[j] = fd[j + 1] - fd[j];
        }
    }

    // Printing the table after forward differences
    printf("\nTable after calculating forward differences:\n");
    printf("+----+--------+--------+----------------------+\n");
    printf("| i  | x[i]   | f(x[i])| Forward Differences  |\n");
    printf("+----+--------+--------+----------------------+\n");
    for (i = 0; i < n; i++) {
        printf("| %-2d | %-6.4f | %-6.4f | %-19.4f |\n", i, x[i], fx[i], fd[i]);
    }
    printf("+----+--------+--------+----------------------+\n");

    // Start calculating the value of the first derivative using forward differences
    val = fd[0]; // First forward difference at i=0

    prev = 1; // Initialize prev before using it
    for (i = 1; i < n; i++) {
        term1 = 1;
        for (k = 2; k <= i; k++) {
            term1 = term1 * (s - k + 2);
        }

        term2 = (s - i + 1) * prev;
        prev = term1 + term2;
        val = val + (fd[i] * (term1 + term2)) / fact(i);
    }

    val = val / h;  // Final derivative value

    // Output the value of the first derivative
    printf("\nValue of first Derivative at x = %.4f: %.6f\n", xp, val);

    return 0;
}

