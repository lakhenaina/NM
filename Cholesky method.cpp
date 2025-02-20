#include<stdio.h>
#include<math.h>

int main() {
    float a[10][10], l[10][10], u[10][10];
    int i, j, k, n;
    
    // Input matrix dimension and elements
    printf("Enter Dimension of matrix: ");
    scanf("%d", &n);
    printf("Enter Elements of matrix: \n");
    
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%f", &a[i][j]);

    // Initialize L and U matrices to zero
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            l[i][j] = 0;
            u[i][j] = 0;
        }
    }

    // Perform LU Decomposition
    for(i = 0; i < n; i++) {
        // Upper Triangular Matrix
        for(j = i; j < n; j++) {
            u[i][j] = a[i][j];
            for(k = 0; k < i; k++) {
                u[i][j] -= l[i][k] * u[k][j];
            }
        }

        // Lower Triangular Matrix
        for(j = i; j < n; j++) {
            if(i == j)
                l[i][i] = 1;
            else {
                l[j][i] = a[j][i];
                for(k = 0; k < i; k++) {
                    l[j][i] -= l[j][k] * u[k][i];
                }
                l[j][i] /= u[i][i];
            }
        }
    }

    // Display L Matrix
    printf("***L Matrix***\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%f\t", l[i][j]);
        }
        printf("\n");
    }

    // Display U Matrix
    printf("***U Matrix***\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%f\t", u[i][j]);
        }
        printf("\n");
    }

    return 0;
}

