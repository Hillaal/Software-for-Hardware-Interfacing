/*
============================================================================
 Name        : lab 4 solution 2
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
		  for (pin=0;pin<7;pin++){

			  switch(count){

				  case 0:
						  SEGMENT_DISPLAY=0x3F;

						  state=((SEGMENT_DISPLAY & (0x01<<pin))>>pin);
						  GPIO_WritePin('A', pin, state);
				  break;

				  case 1:
					  SEGMENT_DISPLAY=0x06;
					  state=((SEGMENT_DISPLAY & (1<<pin))>>pin);
					  GPIO_WritePin('A', pin, state);
				  break;

				  case 2:
					  SEGMENT_DISPLAY=0x5B;
					  state=((SEGMENT_DISPLAY & (1<<pin))>>pin);
					  GPIO_WritePin('A', pin, state);
				  break;

				  case 3:
					  SEGMENT_DISPLAY=0x4F;
					  state=((SEGMENT_DISPLAY & (1<<pin))>>pin);
					  GPIO_WritePin('A', pin, state);
				  break;

				  case 4:
					  SEGMENT_DISPLAY=0x66;
					  state=((SEGMENT_DISPLAY & (1<<pin))>>pin);
					  GPIO_WritePin('A', pin, state);
				  break;

				  case 5:
					  SEGMENT_DISPLAY=0x6D;
					  state=((SEGMENT_DISPLAY & (1<<pin))>>pin);
					  GPIO_WritePin('A', pin, state);
				  break;

				  case 6:
					  SEGMENT_DISPLAY=0x7D;
					  state=((SEGMENT_DISPLAY & (1<<pin))>>pin);
					  GPIO_WritePin('A', pin, state);
				  break;

				  case 7:
					  SEGMENT_DISPLAY=0x07;
					  state=((SEGMENT_DISPLAY & (1<<pin))>>pin);
					  GPIO_WritePin('A', pin, state);
				  break;

				  case 8:
					  SEGMENT_DISPLAY=0x7F;
					  state=((SEGMENT_DISPLAY & (1<<pin))>>pin);
					  GPIO_WritePin('A', pin, state);
				  break;

				  case 9:
					  SEGMENT_DISPLAY=0x6F;
					  state=((SEGMENT_DISPLAY & (1<<pin))>>pin);
					  GPIO_WritePin('A', pin, state);
				  break;

			  }
		  }

		  for (i = 0; i < 1000000; i++){}

	  }


  }
  return 0;
}
