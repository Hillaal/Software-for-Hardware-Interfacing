/*
 ============================================================================
 Name        : task01.c
 Author      : Ahmed Khaled Hilal
 Description :  Code to calculate the exponential function using Taylor series.
 ============================================================================
*/

#include<stdio.h>

int main(void){

    int exp,iterations,counter,fact=1;
    double t=1,series=1;

    printf("Enter the Exponent:");
    scanf("%d",&exp);

    printf("\nEnter Number of Iterations:");
    scanf("%d",&iterations);

        if(0==iterations){

            printf("\n exponential result = %lf\n",series);
        }

        else {

             for(counter=1; counter<= iterations; counter++){
               t*=exp;
               fact *=counter;
               series+=t/fact;
            }

            printf("\n Exponential Result = %lf\n",series);
        }

return 0;
}
