/*
 ============================================================================
 Name        : lab1_ex3.c
 Author      : Ahmed Khaled Hilal
 Description : Code to show time elapsed (in seconds) in format hr:min:sec
 ============================================================================
*/


#include<stdio.h>

int main(void){

int t,hrs,min,sec;

printf("Enter total time elapsed in seconds:");
scanf("%d",&t);

hrs=t /3600;

t=t-(hrs*3600);
min=t/60;

t=t-(min*60);
sec=t;

printf("\n hr:min:sec \n %d:%d:%d\n",hrs,min,sec);

return 0;

}
