/*
 ============================================================================
 Name        : lab2_ex1.c
 Author      : Ahmed Khaled Hilal
 Description : Program to perform generic rotate right and rotate left using bit masking
 ============================================================================
*/

#include<stdio.h>

#define left 0
#define right 1



int main(void){

    int x,cycles,rotation;    /*integers not characters so the variables don't overwrite each others in memory because of %d in scanf*/

    unsigned char number;  /*variable will take the value of x afterwards so that number is 8 bits */


    do{
        printf("Enter Positive 8 bits Number:");
        scanf("%d",&x);
    }
    while((x>255) || (x<0));    /* to ensure user entered positive 8 bits number */

    number=x; /*assign the int variable to char variable to have 8 bits variable*/


    printf("Enter No of Rotation Cycles:");
    scanf("%d",&cycles);


    do{
        printf("Enter 0 to rotate left and 1 to rotate right\n");
        scanf("%d",&rotation);
    }
    while((rotation != left) && (rotation != right));    /* to ensure user entered only 0 or 1
                                                                    and not different number */

    switch(rotation){
        case left:
            number = (number << cycles) | (number>>(8-cycles));
            break;

        case right:
            number = (number >> cycles) | (number<<(8-cycles));
            break;
        }


    printf("\nNumber after rotation = %d\n",number);


return 0;
}
