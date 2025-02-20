// c program for calculating derivatives using  two point backward differences formula
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x)2 *exp(x)  
int main(){
	float h,x,d;
	printf("Enter the value at which derivatives is required\n");
	scanf("%f",&x);
	printf("Enter increment h\n");
	scanf("%f",&h);
	d=((f(x))-(f(x-h)))/h;
	printf("Value of derivatives=%f\n",d);
	getch(); 
	return 0;
}
