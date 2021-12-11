/*
 ============================================================================
 Name        : lab 4 solution 1
 Author      : Ahmed Khaled Hilal
 Description : software that display a decimal counter value on a seven segment display.
 ============================================================================
*/

#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

int main(void) {

	unsigned char count,pin,state,SEGMENT_DISPLAY;
	int i;

	GPIO_Init('A', 0 , OUTPUT, PUSH_PULL);
	GPIO_Init('A', 1 , OUTPUT, PUSH_PULL);
	GPIO_Init('A', 2 , OUTPUT, PUSH_PULL);
	GPIO_Init('A', 3 , OUTPUT, PUSH_PULL);
	GPIO_Init('A', 4 , OUTPUT, PUSH_PULL);
	GPIO_Init('A', 5 , OUTPUT, PUSH_PULL);
	GPIO_Init('A', 6 , OUTPUT, PUSH_PULL);


  while (1) {

	  for (count=0;count<10;count++){

			  switch(count){

				  case 0:
						 GPIO_WritePin('A', 0, 1);
						 GPIO_WritePin('A', 1, 1);
						 GPIO_WritePin('A', 2, 1);
						 GPIO_WritePin('A', 3, 1);
						 GPIO_WritePin('A', 4, 1);
						 GPIO_WritePin('A', 5, 1);
						 GPIO_WritePin('A', 6, 0);

				  break;

				  case 1:
						 GPIO_WritePin('A', 0, 0);
						 GPIO_WritePin('A', 1, 1);
						 GPIO_WritePin('A', 2, 1);
						 GPIO_WritePin('A', 3, 0);
						 GPIO_WritePin('A', 4, 0);
						 GPIO_WritePin('A', 5, 0);
						 GPIO_WritePin('A', 6, 0);
				  break;

				  case 2:
						 GPIO_WritePin('A', 0, 1);
						 GPIO_WritePin('A', 1, 1);
						 GPIO_WritePin('A', 2, 0);
						 GPIO_WritePin('A', 3, 1);
						 GPIO_WritePin('A', 4, 1);
						 GPIO_WritePin('A', 5, 0);
						 GPIO_WritePin('A', 6, 1);
				  break;

				  case 3:
						 GPIO_WritePin('A', 0, 1);
						 GPIO_WritePin('A', 1, 1);
						 GPIO_WritePin('A', 2, 1);
						 GPIO_WritePin('A', 3, 1);
						 GPIO_WritePin('A', 4, 0);
						 GPIO_WritePin('A', 5, 0);
						 GPIO_WritePin('A', 6, 1);
				  break;

				  case 4:
						 GPIO_WritePin('A', 0, 0);
						 GPIO_WritePin('A', 1, 1);
						 GPIO_WritePin('A', 2, 1);
						 GPIO_WritePin('A', 3, 0);
						 GPIO_WritePin('A', 4, 0);
						 GPIO_WritePin('A', 5, 1);
						 GPIO_WritePin('A', 6, 1);
				  break;

				  case 5:
						 GPIO_WritePin('A', 0, 1);
						 GPIO_WritePin('A', 1, 0);
						 GPIO_WritePin('A', 2, 1);
						 GPIO_WritePin('A', 3, 1);
						 GPIO_WritePin('A', 4, 0);
						 GPIO_WritePin('A', 5, 1);
						 GPIO_WritePin('A', 6, 1);
				  break;

				  case 6:
						 GPIO_WritePin('A', 0, 1);
						 GPIO_WritePin('A', 1, 0);
						 GPIO_WritePin('A', 2, 1);
						 GPIO_WritePin('A', 3, 1);
						 GPIO_WritePin('A', 4, 1);
						 GPIO_WritePin('A', 5, 1);
						 GPIO_WritePin('A', 6, 1);
				  break;

				  case 7:
						 GPIO_WritePin('A', 0, 1);
						 GPIO_WritePin('A', 1, 1);
						 GPIO_WritePin('A', 2, 1);
						 GPIO_WritePin('A', 3, 0);
						 GPIO_WritePin('A', 4, 0);
						 GPIO_WritePin('A', 5, 0);
						 GPIO_WritePin('A', 6, 0);
				  break;

				  case 8:
						 GPIO_WritePin('A', 0, 1);
						 GPIO_WritePin('A', 1, 1);
						 GPIO_WritePin('A', 2, 1);
						 GPIO_WritePin('A', 3, 1);
						 GPIO_WritePin('A', 4, 1);
						 GPIO_WritePin('A', 5, 1);
						 GPIO_WritePin('A', 6, 1);
				  break;

				  case 9:
						 GPIO_WritePin('A', 0, 1);
						 GPIO_WritePin('A', 1, 1);
						 GPIO_WritePin('A', 2, 1);
						 GPIO_WritePin('A', 3, 1);
						 GPIO_WritePin('A', 4, 0);
						 GPIO_WritePin('A', 5, 1);
						 GPIO_WritePin('A', 6, 1);
				  break;

		  }

		  for (i = 0; i < 1000000; i++){}

	  }


  }
  return 0;
}
