/*
 ============================================================================
 Name        : lab2_ex3.c
 Author      : Ahmed Khaled Hilal
 Description : Program to calculate and print terms of Fibonacci series
 ============================================================================
*/

#include<stdio.h>

int main(void){

    int terms,previous1=0,previous2=1,sum,i;

    do{
        printf("Enter Number of terms:");
        scanf("%d",&terms);
    } while (terms<0);          /* to ensure number entered is positive */

    printf("\n%d,%d",previous1,previous2);  /* print the first two terms */

    for(i=0;i<terms-2;i++){

        printf(",%d",sum);     /* print the remaining terms */

        previous1=previous2;
        previous2=sum;
        sum=previous1+previous2;
    }

    printf("\n");   /* add new empty line after the result as a padding */

return 0;
}
