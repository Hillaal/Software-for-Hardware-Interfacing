/*
 ============================================================================
 Name        : lab1_ex1.c
 Author      : Ahmed Khaled Hilal
 Description : Code to calculate final Velocity and Distance covered
 ============================================================================
*/

#include<stdio.h>

int main(void){

float u,a,t;
double v,s;

printf("Enter initial velocity:");
scanf("%f",&u);

printf("Enter Acceleration:");
scanf("%f",&a);

printf("Enter elapsed time:");
scanf("%f",&t);

v=u+a*t;
s=(u*t)+(0.5*a*t*t);

printf("\nFinal Speed =%f",v);
printf("\nDistance =%f\n",s);


return 0;
}
