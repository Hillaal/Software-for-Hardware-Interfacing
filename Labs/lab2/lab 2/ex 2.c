/*
 ============================================================================
 Name        : lab2_ex2.c
 Author      : Ahmed Khaled Hilal
 Description : code to draw a rhombus
 ============================================================================
*/

#include<stdio.h>


int main(void){

int x,y;

for(y=0;y<9;y++){

    printf("\n");

    for(x=0;x<9;x++){

        if(x==0){
                printf(" ");  /*this is for padding on left side of terminal to start from second column*/
        }

        if((y == -(x-4)) || (y == (x-4)) || (y == 4+x ) || (y == (12-x)) ){
                printf("*");
        }

        else if(( (y > -(x-4)) && (y > (x-4))&& (y<=4) ) || ( (y < 4+x)  && (y < 12-x)&& (y>4) )) {
                printf("*");
        }
        else  printf(" ");


    }


}


return 0;
}
