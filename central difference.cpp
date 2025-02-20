#include<stdio.h>
#include<conio.h >
#include<math.h>

#define f(x) (2*(x)*(x) + 1) 

int main() {
    float h, x, d;
    
    printf("Enter the value at which the derivative is required: ");
    scanf("%f", &x);
    
    printf("Enter increment h: ");
    scanf("%f", &h);
    
    d = (f(x + h) - f(x - h)) / (2 * h); 
    printf("Value of derivative = %f\n", d);
    
    return 0;
}

