#include<stdio.h>
#include<math.h>

// Define the functions
#define f1(x,y,z) (z) // dy/dx = z
#define f2(x,y,z) (6 * (x)) // dz/dx = 6 * x

int main() {
    // Declare variables
    float xa, xb, ya, yb, x0, y0, z0, x, y, z, xp, h, sol, ny, nz, error, E, g[3], v[3], gs;
    int i;

    // Input values
    printf("Enter the initial x (xa): ");
    scanf("%f", &xa);
    printf("Enter the initial y (ya): ");
    scanf("%f", &ya);
    printf("Enter the final x (xb): ");
    scanf("%f", &xb);
    printf("Enter the final y (yb): ");
    scanf("%f", &yb);
    printf("Enter x at which the value is required (xp): ");
    scanf("%f", &xp);
    printf("Enter the step size (h): ");
    scanf("%f", &h);
    printf("Enter accuracy limit (E): ");
    scanf("%f", &E);

    // Initialize values
    x = xa;
    y = ya;
    g[1] = z = (yb - ya) / (xb - xa); // Initial guess for z
    printf("Initial guess g[1] = %f\n", g[1]);

    // First iteration
    while (x < xb) {
        ny = y + f1(x, y, z) * h;
        nz = z + f2(x, y, z) * h;
        x += h;
        y = ny;
        z = nz;
        if (fabs(x - xp) < 1e-6) { // Ensure precision for comparing floats
            sol = y;
        }
    }
    v[1] = y;

    // Adjust initial guess for g[2]
    if (y < yb)
        g[2] = z = 2 * g[1];
    else
        g[2] = z = 0.5 * g[1];
    printf("Adjusted guess g[2] = %f\n", g[2]);

    // Second iteration
    x = xa;
    y = ya;
    z = g[2];
    while (x < xb) {
        ny = y + f1(x, y, z) * h;
        nz = z + f2(x, y, z) * h;
        x += h;
        y = ny;
        z = nz;
        if (fabs(x - xp) < 1e-6) {
            sol = y;
        }
    }
    v[2] = y;

    // Iterative correction using the shooting method
    while (1) {
        x = xa;
        y = ya;
        gs = z = g[2] - (v[2] - yb) / (v[2] - v[1]) * (g[2] - g[1]);
        while (x < xb) {
            ny = y + f1(x, y, z) * h;
            nz = z + f2(x, y, z) * h;
            x += h;
            y = ny;
            z = nz;
            if (fabs(x - xp) < 1e-6) {
                sol = y;
            }
        }
        error = fabs(y - yb) / yb;
        v[1] = v[2];
        v[2] = y;
        g[1] = g[2];
        g[2] = gs;

        if (error < E) {
            printf("y(%f) = %f\n", xp, sol);
            break;
        }
    }

    return 0;
}

