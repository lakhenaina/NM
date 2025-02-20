#include <stdio.h>
#include <math.h>

int fact(int n) {
    if (n == 0 || n == 1) return 1;
    else return n * fact(n - 1);
}

int main() {
    int n, i, j;
    float val = 0, p, xp, x[10], fx[10], bd[10][10], h, s;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter values of x and f(x):\n");
    for (i = 0; i < n; i++) {
        scanf("%f%f", &x[i], &fx[i]);
    }

    printf("Enter the value at which derivative is needed: ");
    scanf("%f", &xp);

    h = x[1] - x[0]; // Step size
    s = (xp - x[n - 1]) / h;

    // Initialize backward difference table
    for (i = 0; i < n; i++) {
        bd[i][0] = fx[i];
    }

    // Compute backward differences
    for (j = 1; j < n; j++) {
        for (i = n - 1; i >= j; i--) {
            bd[i][j] = bd[i][j - 1] - bd[i - 1][j - 1];
        }
    }

    // Compute the first derivative using backward difference formula
    val = bd[n - 1][1]; // First backward difference term
    for (i = 2; i < n; i++) {
        float term = bd[n - 1][i];
        for (j = 1; j < i; j++) {
            term *= (s + j - 1);
        }
        val += (term / fact(i));
    }

    val /= h; // Divide by step size to get the derivative
    printf("Value of first derivative = %f\n", val);

    return 0;
}

