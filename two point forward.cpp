// c program for calculating derivative using two point forward difference formula
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define PI 3.1415
#define f(x)sin(x)+1
int main(){  
	float angle,h,x,d;
	printf("Enter Angle in degree\n");
	scanf("%f",&angle);
	printf("Enter increment h\n");
	scanf("%f",&h);
	x=PI/180*angle;
	d=((f(x+h))-(f(x)))/h;
	printf("Value of derivatives=%f\n",d);
	getch();
	return 0;
} 
