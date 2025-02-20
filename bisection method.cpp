#include <stdio.h>
#include <conio.h>
#include <math.h>

#define f(x) ((x)*(x)*(x) - 3*(x) - 5)  
#define E 0.01

int main() {
    float x0, x1, x2, f0, f1, f2;
    int iteration = 0;

    repeat:  
    printf("Enter two initial guess values: ");
    scanf("%f %f", &x1, &x2);  

    f1 = f(x1);
    f2 = f(x2);

    if (f1 * f2 > 0) {
        printf("Error Guesse. Try again.\n");
        goto repeat;  
    } else {
        loop:  
        x0 = (x1 + x2) / 2;
        f0 = f(x0);

        if (f1 * f0 < 0) {
            x1 = x0;  
        } else {
            x2 = x0;  
        }

        if ((fabs(x2 - x1) / fabs(x2)) <= E) {  
            printf("The root is %.2f found in iteration %d\n", x0, iteration);
        } else {
            iteration++;
            goto loop;
        }
        getch();  
    }
    return 0;
}


