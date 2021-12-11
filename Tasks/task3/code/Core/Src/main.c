/*
 ============================================================================
 Name        : task 3
 Author      : Ahmed Khaled Hilal
 Description : RGB LED controller.
 ============================================================================
*/
#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

int main(void) {

	unsigned char color=1;
	int i;

	GPIO_Init('B',3,INPUT,PULL_UP); /*initialize portB pin3 as input*/

	GPIO_Init('B',5,OUTPUT,PUSH_PULL);
	GPIO_Init('B',6,OUTPUT,PUSH_PULL);   /*initialize portB pin 5,6,7 as outputs*/
	GPIO_Init('B',7,OUTPUT,PUSH_PULL);

	GPIO_WritePin('B',5,0);
	GPIO_WritePin('B',6,0); /*set the RGB led to first color black*/
	GPIO_WritePin('B',7,0);

  while (1) {

	  if(GPIO_ReadPin('B',3)==0){     /*check if the button is pressed*/

		  for(i=0;i<50000;i++){}	/*delay nearly 50ms before check the button again for debouncing*/

		  if(GPIO_ReadPin('B',3)==0){	/*check again if the button is pressed*/
			  while (GPIO_ReadPin('B',3)==0){} /*wait to detect falling edge*/

			  GPIO_WritePin('B',5,0);
			  GPIO_WritePin('B',6,0);/*clear the three bits to put next color*/
			  GPIO_WritePin('B',7,0);

			  GPIO_WritePin('B',5,((1<<5)&(color<<5)));
			  GPIO_WritePin('B',6,((1<<6)&(color<<5)));	/*set the RGB led to next color*/
			  GPIO_WritePin('B',7,((1<<7)&(color<<5)));

			  color++;

			  if (8==color){
				  color=0;			/*only have 8 colors from 0 to 7*/
			  }

		  }

	  }

  }
  return 0;
}
