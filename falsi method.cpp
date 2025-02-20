#include <stdio.h>
#include <math.h>

#define g(x) (x * x - 5)  // The function for which we are finding the root
#define E 0.001  // Desired error tolerance

int main() {
    float x0, x1, x2, f0, f1, f2;
    int iteration = 0;
    
    // Input the initial guesses
    printf("Enter the initial guess values x0 and x1: ");
    scanf("%f %f", &x0, &x1);

    // Calculate the function values at x0 and x1
    f0 = g(x0);
    f1 = g(x1);

    // Check if initial guesses are valid (g(x0) and g(x1) should have opposite signs)
    if (f0 * f1 >= 0) {
        printf("Function values at x0 and x1 should have opposite signs.\n");
        return -1;  // Exit if the guesses do not bracket the root
    }

    do {
        // Calculate the new point x2 using the False Position formula
        x2 = x0 - (f0 * (x1 - x0)) / (f1 - f0);
        f2 = g(x2);

        // Print the current iteration values
        printf("Iteration %d: x2 = %f, f(x2) = %f\n", iteration + 1, x2, f2);

        // Check if the solution is within the desired tolerance
        if (fabs(f2) < E) {
            printf("The root is approximately: %f\n", x2);
            break;
        }

        // Update the interval for the next iteration
        if (f0 * f2 < 0) {
            x1 = x2;
            f1 = f2;
        } else {
            x0 = x2;
            f0 = f2;
        }

        iteration++;
    } while (fabs(f2) >= E);  // Repeat until the error tolerance is met

    return 0;
}

