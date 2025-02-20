#include<stdio.h>
#include<math.h>
#define f(x) (x + 3) // Define the function f(x)

int main() {
    float h, x0, x1, fx0, fx1, v;

    // Input lower and upper limits
    printf("Enter Lower & Upper Limit: ");
    scanf("%f%f", &x0, &x1);

    // Calculate step size
    h = x1 - x0;

    // Calculate function values at the limits
    fx0 = f(x0);
    fx1 = f(x1);

    // Apply trapezoidal rule: v = h/2 * (f(x0) + f(x1))
    v = (h / 2) * (fx0 + fx1);

    // Print the result
    printf("Value of Integration = %f\n", v);

    return 0;
}

