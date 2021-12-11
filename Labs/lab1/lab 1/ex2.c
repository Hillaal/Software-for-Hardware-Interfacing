/*
 ============================================================================
 Name        : lab1_ex2.c
 Author      : Ahmed Khaled Hilal
 Description : Code to calculate sum,average,product,max, min of three numbers
 ============================================================================
*/


#include<stdio.h>

int sum(int,int,int);
float average(int,int,int);
long product(int,int,int);
int max(int x,int y,int z);
int min(int x,int y,int z);

int main(void){

int x,y,z,s,Max,Min;
float avg;
long prod;


printf("Enter three different integers:\n");
scanf("%d%d%d",&x,&y,&z);

s=sum(x,y,z);
avg=average(x,y,z);
prod=product(x,y,z);
Max=max(x,y,z);
Min=min(x,y,z);

printf("\n Sum is:%d\n Average is:%f\n Product is:%ld\n Max is:%d\n Min is:%d\n",s,avg,prod,Max,Min);


return 0;
}

int sum(int x,int y,int z){
    return x+y+z;
    }

float average(int x,int y,int z){
    return (x+y+z)/(float)3 ;
    }

long product(int x,int y,int z){
    return x*y*z;
    }

int max(int x,int y,int z){
    int max;

   max=  x > y ?  x>z?  x:z   : y>z? y:z ;

    }

int min(int x,int y,int z){
    int min;

    min=  x < y ?  x<z?  x:z   : y<z? y:z ;

    }


