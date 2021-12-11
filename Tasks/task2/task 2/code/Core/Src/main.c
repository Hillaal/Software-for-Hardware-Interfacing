/*
 ============================================================================
 Name        : task 2
 Author      : Ahmed Khaled Hilal
 Description : RGB LED controller.
 ============================================================================
*/

#include "stm32f401cc_interface.h"

int main(void) {

	unsigned char color=1;
	int i;

	RCC_AHB1ENR |= (1<<1);  /* enable portB clock */

	GPIOB_MODER &= ~(3<<6);  /*make portB pin3 input*/
	GPIOB_PUPDR |= (1<<6);   /*Pull-UP configuration for pin3*/

	GPIOB_MODER |= (1<<10)|(1<<12)|(1<<14);  /*make portB pin 5,6,7 output*/

	/*GPIOB_OTYPER &= ~(1<<5) & ~(1<<6) & ~(1<<7); to make the pins push-pull but this is the default state*/

	GPIOB_ODR &= ~(1<<5) &~(1<<6) &~(1<<7); /*set the RGB led to first color black*/

  while (1) {

	  if(!(GPIOB_IDR & (1<<3))){     /*check if the button is pressed*/

		  for(i=0;i<50000;i++){}	/*delay before check the button again for debouncing*/

		  if(!(GPIOB_IDR & (1<<3))){	/*check again if the button is pressed*/

			  GPIOB_ODR &= ~(7<<5); 	/*clear the three bits to put next color*/
			  GPIOB_ODR |= (color<<5); 	/*set the RGB led to next color*/

			  color++;

			  if (8==color){
				  color=0;			/*only have 8 colors from 0 to 7*/
			  }
		  }

		  while (!(GPIOB_IDR & (1<<3))){} 	/*wait until the button is released before considering a new button press*/
	  }

  }
  return 0;
}
