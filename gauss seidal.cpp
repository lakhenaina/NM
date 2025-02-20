#include<stdio.h>
#include<conio.h>
#include<math.h>

int main() {
    int n, i, j, k;
    float sum, error, E[10], a[10][10], b[10], new_x[10], old_x[10];

    printf("Enter dimensions of the system of equations: ");
    scanf("%d", &n);

    printf("Enter coefficients row-wise:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter B vector:\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    printf("Enter accuracy limit: ");
    scanf("%f", &error); // Corrected the scanf statement to remove syntax error

    for(i = 0; i < n; i++) {
        new_x[i] = 0; // Initialize solution guesses to 0
    }

    while(1) {
        for(i = 0; i < n; i++) {
            sum = b[i];
            for(j = 0; j < n; j++) {
                if(i != j) {
                    sum -= a[i][j] * new_x[j];
                }
            }
            old_x[i] = new_x[i];
            new_x[i] = sum / a[i][i]; // Fixed index to use diagonal element of `a[i][i]`
            E[i] = fabs((new_x[i] - old_x[i]) / fabs(new_x[i])); // Fixed error calculation
        }

        // Check if all errors are within the accuracy limit
        for(i = 0; i < n; i++) {
            if(E[i] > error) {
                break; // If any error exceeds the limit, continue iteration
            }
        }
        if(i == n) {
            break; // If all errors are within the limit, exit loop
        }
    }

    printf("Solution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %6.2f\n", i + 1, new_x[i]);
    }

    getch();
    return 0;
}

