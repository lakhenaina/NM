#include <stdio.h>
#include <math.h>

#define MAX 10

// Function to perform Gauss-Jordan Elimination
void gaussJordan(float matrix[MAX][MAX], int n) {
    float ratio;
    
    // Augment the matrix with the identity matrix
    float augmented[MAX][2 * MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmented[i][j] = matrix[i][j];
            augmented[i][j + n] = (i == j) ? 1 : 0; // Identity matrix
        }
    }

    // Perform Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        // Make the diagonal element 1 and eliminate the column
        float pivot = augmented[i][i];
        if (pivot == 0) {
            printf("Singular Matrix! Cannot find inverse.\n");
            return;
        }

        // Divide the entire row by the pivot
        for (int j = 0; j < 2 * n; j++) {
            augmented[i][j] /= pivot;
        }

        // Eliminate all other elements in the current column
        for (int j = 0; j < n; j++) {
            if (i != j) {
                ratio = augmented[j][i];
                for (int k = 0; k < 2 * n; k++) {
                    augmented[j][k] -= ratio * augmented[i][k];
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    printf("The inverse matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            printf("%0.2f\t", augmented[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Input the dimension of the matrix
    printf("Enter the dimension of the matrix (n x n): ");
    scanf("%d", &n);

    float matrix[MAX][MAX];

    // Input the matrix
    printf("Enter the elements of the matrix row-wise:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Call the function to perform Gauss-Jordan elimination
    gaussJordan(matrix, n);

    return 0;
}

